use serde_json::{json, Value};
use std::{fs, io, path::Path};

fn copy_dir_all(src: impl AsRef<Path>, dst: impl AsRef<Path>) -> io::Result<()> {
    fs::create_dir_all(&dst)?;
    for entry in fs::read_dir(src)? {
        let entry = entry?;
        let ty = entry.file_type()?;
        if ty.is_dir() {
            copy_dir_all(entry.path(), dst.as_ref().join(entry.file_name()))?;
        } else {
            fs::copy(entry.path(), dst.as_ref().join(entry.file_name()))?;
        }
    }
    Ok(())
}

fn directory_to_object(dir: impl AsRef<Path>) -> Value {
    let info_path = dir.as_ref().join("info.json");
    let info_dot_json = match info_path.exists() {
        true => {
            let info = fs::read_to_string(info_path).unwrap();
            let info: Value = serde_json::from_str(info.as_str()).unwrap();
            let mut info = info.as_object().unwrap().clone();
            info.remove("$schema");
            Value::Object(info)
        }
        false => Value::Object(serde_json::Map::new()),
    };

    let sub_dirs = fs::read_dir(dir).unwrap();
    let children = sub_dirs
        .filter_map(|entry| {
            let entry = entry.unwrap();
            let ty = entry.file_type().unwrap();
            if ty.is_dir() {
                let file_name = entry.file_name().into_string().unwrap();
                Some((file_name, directory_to_object(entry.path())))
            } else {
                None
            }
        })
        .collect::<serde_json::Map<String, Value>>();

    json!({
        "info": info_dot_json,
        "children": children,
    })
}

fn generate_data_file() -> Result<(), io::Error> {
    let json_tree = directory_to_object("../_data");
    let json_tree = json_tree.get("children").unwrap();

    let data = format!(
        r##"// This is auto-generated file. Do not edit it manually.

use lazy_static::lazy_static;
use serde_json::Value;

lazy_static! {{
    pub static ref DATA: Value = {{
        let data = r#"
{}
        "#;
        serde_json::from_str(data).unwrap()
    }};
}}   
"##,
        serde_json::to_string_pretty(json_tree).unwrap()
    );

    fs::write("./src/_data.rs", data)?;
    Ok(())
}

fn main() {
    generate_data_file().unwrap();
    copy_dir_all(Path::new("../_data"), Path::new("./src/_data")).unwrap();
}
