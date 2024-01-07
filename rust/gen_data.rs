use serde::{Deserialize, Serialize};
use std::{fs, io, path::Path};

#[derive(Debug, Serialize, Deserialize)]
pub struct Name {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

#[derive(Debug, Serialize, Deserialize, PartialEq)]
pub enum Type {
    #[serde(rename = "UNIVERSITY")]
    University,
    #[serde(rename = "ACADEMY")]
    Academy,
    #[serde(rename = "PRIVATE_SCHOOL")]
    PrivateSchool,
    #[serde(rename = "INSTITUTE")]
    Institute,
    #[serde(rename = "FACULTY")]
    Faculty,
    #[serde(rename = "DEPARTMENT")]
    Department,
    #[serde(rename = "SPECIALTY")]
    Specialty,
    #[serde(rename = "SECTOR")]
    Sector,
}

impl ToString for Type {
    fn to_string(&self) -> String {
        match self {
            Type::University => format!("Type::University"),
            Type::Academy => format!("Type::Academy"),
            Type::PrivateSchool => format!("Type::PrivateSchool"),
            Type::Institute => format!("Type::Institute"),
            Type::Faculty => format!("Type::Faculty"),
            Type::Department => format!("Type::Department"),
            Type::Specialty => format!("Type::Specialty"),
            Type::Sector => format!("Type::Sector"),
        }
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq, Clone)]
pub struct Terms {
    #[serde(rename = "perYear")]
    pub per_year: usize,
    pub slots: Vec<usize>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Schema {
    pub name: Name,
    #[serde(rename = "type")]
    pub ty: Type,
    pub terms: Option<Terms>,
}

fn gen_static_refs(
    src: impl AsRef<Path>,
    dst: impl AsRef<Path>,
    gen_statics: &mut Vec<String>,
    count: &mut usize,
) -> io::Result<()> {
    for entry in fs::read_dir(src)? {
        let entry = entry?;
        let ty = entry.file_type()?;
        if ty.is_dir() {
            gen_static_refs(
                entry.path(),
                dst.as_ref().join(entry.file_name()),
                gen_statics,
                count,
            )?;
        } else {
            let info = fs::read_to_string(entry.path())?;
            if let Ok(schema) = serde_json::from_str::<Schema>(info.as_str()) {
                let mut res = String::new();
                res.push_str(
                    format!(
                        r#"
        Schema {{
            path: "{}",
            name: Name {{
                ar: "{}",
                en: "{}",
                fr: "{}",
            }},
            ty: {},"#,
                        entry
                            .path()
                            .to_str()
                            .unwrap()
                            .trim_end_matches("/info.json")
                            .trim_start_matches("../_data/"),
                        schema.name.ar,
                        schema.name.en,
                        schema.name.fr,
                        schema.ty.to_string()
                    )
                    .as_str(),
                );
                if let Some(terms) = &schema.terms {
                    res.push_str(
                        format!(
                            r#"
            terms: Some(Terms {{
                per_year: {},
                slots: vec![{}],
            }})
        }},"#,
                            terms.per_year,
                            terms
                                .slots
                                .iter()
                                .map(|e| format!("{}", e))
                                .collect::<Vec<String>>()
                                .join(", ")
                        )
                        .as_str(),
                    );
                } else {
                    res.push_str(
                        format!(
                            r#"
            terms: None,
        }},"#
                        )
                        .as_str(),
                    );
                }
                gen_statics.push(res);
                *count += 1;
            }
        }
    }
    Ok(())
}

fn generate_data_file(schemas: Vec<String>) -> Result<(), io::Error> {
    let data = format!(
        r##"// This is auto-generated file. Do not edit it manually.

use crate::{{Name, Schema, Terms, Type}};
use lazy_static::lazy_static;

lazy_static! {{
    pub static ref ENTRIES: [Schema; {}] = [{}];
}}
"##,
        schemas.len(),
        schemas.join(""),
    );

    fs::write("./src/_data.rs", data)?;
    Ok(())
}

fn main() {
    let mut schemas: Vec<String> = vec![];
    let mut count = 0;
    gen_static_refs(
        Path::new("../_data"),
        Path::new("./src/_data"),
        &mut schemas,
        &mut count,
    )
    .unwrap();
    generate_data_file(schemas).unwrap();
}
