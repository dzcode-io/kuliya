#![recursion_limit = "512"]

mod _data;
// pub mod api;

use serde::{Deserialize, Serialize};
use serde_json::json;

#[derive(Debug, Serialize, Deserialize)]
pub struct Name<'a> {
    pub ar: &'a str,
    pub en: &'a str,
    pub fr: &'a str,
}

impl std::fmt::Display for Name<'static> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"ar": self.ar, "en": self.en, "fr": self.fr});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
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

#[derive(Debug, Serialize, Deserialize, PartialEq, Clone)]
pub struct Terms {
    #[serde(rename = "perYear")]
    pub per_year: usize,
    pub slots: Vec<usize>,
}

impl std::fmt::Display for Terms {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"perYear": self.per_year, "slots": self.slots});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Schema {
    #[serde(skip_serializing)]
    pub path: &'static str,
    #[serde(borrow)]
    pub name: Name<'static>,
    #[serde(rename = "type")]
    pub ty: Type,
    pub terms: Option<Terms>,
}

impl std::fmt::Display for Schema {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if self.terms.is_some() {
            let obj = json!({
                "name": self.name,
                "type": self.ty,
                "terms": self.terms.clone().unwrap()
            });
            return write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap());
        } else {
            let obj = json!({
                "name": self.name,
                "type": self.ty
            });
            return write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap());
        }
    }
}

pub fn get_node_by_path(path: &str) -> Option<&Schema> {
    for entry in _data::ENTRIES.iter() {
        if entry.path == path {
            return Some(entry);
        }
    }
    None
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
                    path: "umkb",
                    name: Name {
                        ar: "جامعة محمد خيضر بسكرة",
                        en: "University of Mohamed Khider Biskra",
                        fr: "Université Mohamed Khider Biskra",
                    },
                    ty: Type::University,
                    terms: None,
                },
            ),
            TestCase::new(
                "umkb/fst",
                Schema {
                    path: "umkb/fst",
                    name: Name {
                        ar: "كلية العلوم والتكنلوجيا",
                        en: "Faculty of Science and Technology",
                        fr: "Faculté des Sciences et de la Technologie",
                    },
                    ty: Type::Faculty,
                    terms: None,
                },
            ),
            TestCase::new(
                "umkb/fst/dee/sec",
                Schema {
                    path: "umkb/fst/dee/sec",
                    name: Name {
                        ar: "تخصص التحكم الكهربائي",
                        en: "Specialy of Electrical Control",
                        fr: "Spécialité de commande électrique",
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
