#![cfg(feature = "const")]
use serde_json::Value;
use std::{fs, io, path::Path};

fn dir_tree_to_list(dir: impl AsRef<Path>) -> (String, String) {
    let info_path = dir.as_ref().join("info.json");
    let info_dot_json = match info_path.exists() {
        true => {
            let info = fs::read_to_string(&info_path).unwrap();
            let info: Value = serde_json::from_str(info.as_str()).unwrap();
            let mut info = info.as_object().unwrap().clone();
            info.remove("$schema");
            Some(Value::Object(info))
        }
        false => None,
    };
    let this_node = match &info_dot_json {
        Some(info) => {
            let path = dir.as_ref().display().to_string();
            let path = path.split("_data/").last().unwrap_or(&path);

            format!(
                r#"const {}: Node = Node {{
    name: NodeName {{
        en: {},
        ar: {},
        fr: {},
    }},
    r#type: {},
}};
"#,
                path.replace('/', "_").to_uppercase(),
                info.get("name").unwrap().get("en").unwrap(),
                info.get("name").unwrap().get("ar").unwrap(),
                info.get("name").unwrap().get("fr").unwrap(),
                match &info.get("type").unwrap() {
                    Value::String(s) => {
                        let ty = s
                            .chars()
                            .enumerate()
                            .map(|(i, c)| {
                                if i == 0 {
                                    c.to_uppercase().to_string()
                                } else {
                                    c.to_lowercase().to_string()
                                }
                            })
                            .collect::<String>();

                        match ty.as_str() {
                            "Specialty" | "Sector" => format!(
                                r#"NodeType::{}{{
        terms: NodeTerms {{
            per_year: 2,
            slots: &[7, 8, 9, 10],
        }},
    }}"#,
                                ty
                            ),

                            _ => format!("NodeType::{}", ty),
                        }
                    }
                    _ => "".to_string(),
                }
            )
        }
        None => String::new(),
    };

    let this_match = match &info_dot_json {
        Some(_) => {
            let path = dir.as_ref().display().to_string();
            let path = path.split("_data/").last().unwrap_or(&path);
            format!(
                "        \"{}\" => Some(&{}),\n",
                path,
                path.replace('/', "_").to_uppercase()
            )
        }
        None => String::new(),
    };

    let sub_dirs = fs::read_dir(&dir).unwrap();
    let children = sub_dirs.filter_map(|entry| {
        let entry = entry.unwrap();
        let ty = entry.file_type().unwrap();
        if ty.is_dir() {
            Some(dir_tree_to_list(entry.path()))
        } else {
            None
        }
    });

    let mut constants = String::new();
    let mut matches = String::new();
    children.for_each(|(c, m)| {
        constants.push_str(&c);
        matches.push_str(&m);
    });

    (
        format!("{}{}", this_node, constants),
        format!("{}{}", this_match, matches),
    )
}

fn generate_data_file() -> Result<(), io::Error> {
    let string_tree = dir_tree_to_list("../_data");

    let data = format!(
        r##"// This is auto-generated. Do not edit manually.

use super::super::node::{{Node, NodeName, NodeType, NodeTerms}};

{}
pub fn get_node_by_path(path: &str) -> Option<&Node> {{
    match path {{
{}        _ => None,
    }}
}}"##,
        string_tree.0, string_tree.1
    );
    fs::create_dir_all("./src/static/_auto_generated")?;
    fs::write("./src/static/_auto_generated/data.rs", data)?;
    fs::write(
        "./src/static/_auto_generated/mod.rs",
        r#"// This is auto-generated. Do not edit manually
pub mod data;
"#,
    )?;
    Ok(())
}

fn main() {
    generate_data_file().unwrap();
}
