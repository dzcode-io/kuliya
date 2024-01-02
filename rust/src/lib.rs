use std::fs;

use serde::{Deserialize, Serialize};

const DATA_PREFIX_PATH: &'static str = "../_data";

#[derive(Debug, Serialize, Deserialize)]
struct Name {
    ar: String,
    en: String,
    fr: String,
}

#[derive(Debug, Serialize, Deserialize, PartialEq, Eq)]
enum Type {
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

impl std::fmt::Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Type::University => write!(f, "UNIVERSITY"),
            Type::Academy => write!(f, "ACADEMY"),
            Type::PrivateSchool => write!(f, "PRIVATE_SCHOOL"),
            Type::Institute => write!(f, "INSTITUTE"),
            Type::Faculty => write!(f, "FACULTY"),
            Type::Department => write!(f, "DEPARTMENT"),
            Type::Specialty => write!(f, "SPECIALTY"),
            Type::Sector => write!(f, "SECTOR"),
        }
    }
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Schema {
    name: Name,
    #[serde(rename = "type")]
    ty: Type,
}

pub fn get_node_by_path(path: &str) -> Option<Schema> {
    let fs_path = format!("{}/{}/info.json", DATA_PREFIX_PATH, path);
    let Ok(info) = fs::read_to_string(fs_path) else {
        return None;
    };
    let Ok(schema) = serde_json::from_str::<Schema>(info.as_str()) else {
        return None;
    };
    dbg!(&schema);
    Some(schema)
}

#[cfg(test)]
mod test {
    use crate::{get_node_by_path, Name, Schema, Type};

    struct TestCase<'a> {
        path: &'a str,
        expected: Schema,
    }

    impl<'a> TestCase<'a> {
        pub fn new(path: &'a str, expected: Schema) -> Self {
            Self { path, expected }
        }
    }

    #[test]
    fn should_get_expected_info() {
        let tests: Vec<TestCase> = vec![
            TestCase::new(
                "umkb",
                Schema {
                    name: Name {
                        ar: "جامعة محمد خيضر بسكرة".to_string(),
                        en: "University of Mohamed Khider Biskra".to_string(),
                        fr: "Université Mohamed Khider Biskra".to_string(),
                    },
                    ty: Type::University,
                },
            ),
            TestCase::new(
                "umkb/fst",
                Schema {
                    name: Name {
                        ar: "كلية العلوم والتكنلوجيا".to_string(),
                        en: "Faculty of Science and Technology".to_string(),
                        fr: "Faculté des Sciences et de la Technologie".to_string(),
                    },
                    ty: Type::Faculty,
                },
            ),
        ];

        for tc in tests {
            let actual = get_node_by_path(tc.path).unwrap();
            assert_schema(&tc.expected, &actual);
        }
    }

    #[test]
    fn should_get_none_when_path_does_not_exist() {
        let res = get_node_by_path("does/not/exist");
        assert!(res.is_none());
    }

    fn assert_schema(expected: &Schema, actual: &Schema) {
        assert_eq!(
            expected.name.ar, actual.name.ar,
            "Expected ar name to be '{}', but got '{}'",
            expected.name.ar, actual.name.ar
        );
        assert_eq!(
            expected.name.en, actual.name.en,
            "Expected en name to be '{}', but got '{}'",
            expected.name.en, actual.name.en
        );
        assert_eq!(
            expected.name.fr, actual.name.fr,
            "Expected fr name to be '{}', but got '{}'",
            expected.name.fr, actual.name.fr
        );
        assert_eq!(
            expected.ty, actual.ty,
            "Expected ty to be '{}', but got '{}'",
            expected.ty, actual.ty
        );
    }
}
