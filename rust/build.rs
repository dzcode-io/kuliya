#[cfg(feature = "static")]
mod r#static {
    use serde_json::Value;
    use std::{fs, io, path::Path};

    fn dir_tree_to_list(dir: impl AsRef<Path>) -> (String, String, String) {
        let info_path = dir.as_ref().join("info.json");
        let node_dir = match info_path.exists() {
            true => {
                let info = fs::read_to_string(&info_path).unwrap();
                let info: Value = serde_json::from_str(info.as_str()).unwrap();
                let mut info = info.as_object().unwrap().clone();
                info.remove("$schema");

                let path = dir.as_ref().display().to_string();
                Some((
                    path.split("_data/").last().unwrap_or(&path).to_string(),
                    Value::Object(info),
                ))
            }
            false => None,
        };

        let this_node = match &node_dir {
            Some((_, info)) => {
                let path = dir.as_ref().display().to_string();
                let path = path.split("_data/").last().unwrap_or(&path);
                let code = path.replace('/', "_").to_uppercase();

                format!(
                    r#"const {}: Node = Node {{
    code: "{}",
    name: NodeName {{
        en: {},
        ar: {},
        fr: {},
    }},
    r#type: {},
}};
"#,
                    code,
                    code,
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
                                    r#"NodeType::{} {{
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

        let this_match = match &node_dir {
            Some((path, _)) => {
                format!(
                    "        \"{}\" => Some(&{}),\n",
                    path,
                    path.replace('/', "_").to_uppercase()
                )
            }
            None => String::new(),
        };

        let sub_dirs = fs::read_dir(&dir).unwrap();
        let mut children_names = Vec::new();
        let mut children: Vec<(String, String, String)> = sub_dirs
            .filter_map(|entry| {
                let entry = entry.unwrap();
                let ty = entry.file_type().unwrap();
                if ty.is_dir() {
                    let path = entry.path();
                    children_names.push(
                        path.display()
                            .to_string()
                            .split("_data/")
                            .last()
                            .map(|s| s.replace('/', "_").to_uppercase())
                            .unwrap(),
                    );
                    Some(dir_tree_to_list(path))
                } else {
                    None
                }
            })
            .collect();
        // to ensure deterministic output on different platforms
        children.sort();

        let this_children_match = match &node_dir {
            Some((path, _)) => {
                format!(
                    r#"        "{}" => vec![{}],
"#,
                    path,
                    children_names
                        .iter()
                        .map(|name| format!("&{}", name))
                        .collect::<Vec<String>>()
                        .join(", ")
                )
            }
            None => String::new(),
        };

        let mut constants = String::new();
        let mut matches = String::new();
        let mut children_matches = String::new();
        for (c, m, chm) in &children {
            constants.push_str(c);
            matches.push_str(m);
            children_matches.push_str(chm);
        }

        (
            format!("{}{}", this_node, constants),
            format!("{}{}", this_match, matches),
            format!("{}{}", this_children_match, children_matches),
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
}}

pub fn get_node_children_by_path(path: &str) -> Vec<&Node> {{
    match path {{
{}        _ => vec![],
    }}
}}
"##,
            string_tree.0, string_tree.1, string_tree.2
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

    pub fn main() {
        if Path::new("../_data").exists() {
            generate_data_file().unwrap();
        } else {
            println!("No _data directory found. Skipping data generation.");
        }
    }
}

fn main() {
    #[cfg(feature = "static")]
    r#static::main();
}
