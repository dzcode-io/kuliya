use std::fs;

use serde::{Deserialize, Serialize};

static DATA_FOLDER: &'static str = "src/_data";
static CARGO_MANIFEST_DIR: &'static str = env!("CARGO_MANIFEST_DIR");

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

#[derive(Debug, Serialize, Deserialize, PartialEq)]
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

pub fn get_node_by_path(path: &str) -> Option<Schema> {
    let fs_path = format!("{}/{}/{}/info.json", CARGO_MANIFEST_DIR, DATA_FOLDER, path);
    let Ok(info) = fs::read_to_string(fs_path) else {
        return None;
    };
    let Ok(schema) = serde_json::from_str::<Schema>(info.as_str()) else {
        return None;
    };
    Some(schema)
}

#[cfg(test)]
mod test {
    use crate::{get_node_by_path, Name, Schema, Terms, Type};

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
                    terms: None,
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
                    terms: None,
                },
            ),
            TestCase::new(
                "umkb/fst/dee/sec",
                Schema {
                    name: Name {
                        ar: "تخصص التحكم الكهربائي".to_string(),
                        en: "Specialy of Electrical Control".to_string(),
                        fr: "Spécialité de commande électrique".to_string(),
                    },
                    ty: Type::Specialty,
                    terms: Some(Terms {
                        per_year: 2,
                        slots: vec![7, 8, 9, 10],
                    }),
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
            "Expected ty to be '{:?}', but got '{:?}'",
            expected.ty, actual.ty
        );
        assert_eq!(
            expected.terms, actual.terms,
            "Expeted terms to be '{:?}', but got '{:?}'",
            expected.terms, actual.terms
        )
    }
}
