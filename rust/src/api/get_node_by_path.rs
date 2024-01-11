use crate::node::model::Node;

#[cfg(feature = "const")]
use crate::_auto_generated;

#[cfg(feature = "storage")]
use crate::api::storage;
#[cfg(feature = "storage")]
use std::path::Path;

#[cfg(feature = "const")]
pub fn get_node_by_path(path: &str) -> Option<&Node> {
    _auto_generated::data::get_node_by_path(path)
}

#[cfg(feature = "storage")]
pub fn get_node_by_path(path: impl AsRef<Path>) -> Result<Node, storage::StorageError> {
    storage::get_node_by_path(path)
}

#[cfg(test)]
mod test {
    use super::get_node_by_path;
    use crate::node::model::{Node, NodeName, NodeTerms, NodeType};
    #[cfg(feature = "storage")]
    use std::path::Path;

    #[test]
    fn check_three_schemas_and_non_existent() {
        let umkb = Node {
            name: NodeName {
                #[cfg(feature = "const")]
                ar: "جامعة محمد خيضر بسكرة",
                #[cfg(feature = "storage")]
                ar: "جامعة محمد خيضر بسكرة".to_string(),
                #[cfg(feature = "const")]
                en: "University of Mohamed Khider Biskra",
                #[cfg(feature = "storage")]
                en: "University of Mohamed Khider Biskra".to_string(),
                #[cfg(feature = "const")]
                fr: "Université Mohamed Khider Biskra",
                #[cfg(feature = "storage")]
                fr: "Université Mohamed Khider Biskra".to_string(),
            },
            r#type: NodeType::University,
        };
        let sec = Node {
            name: NodeName {
                #[cfg(feature = "const")]
                ar: "تخصص التحكم الكهربائي",
                #[cfg(feature = "storage")]
                ar: "تخصص التحكم الكهربائي".to_string(),
                #[cfg(feature = "const")]
                en: "Specialy of Electrical Control",
                #[cfg(feature = "storage")]
                en: "Specialy of Electrical Control".to_string(),
                #[cfg(feature = "const")]
                fr: "Spécialité de commande électrique",
                #[cfg(feature = "storage")]
                fr: "Spécialité de commande électrique".to_string(),
            },
            r#type: NodeType::Specialty {
                terms: NodeTerms {
                    per_year: 2,
                    #[cfg(feature = "const")]
                    slots: &[7, 8, 9, 10],
                    #[cfg(feature = "storage")]
                    slots: vec![7, 8, 9, 10],
                },
            },
        };
        let fst = Node {
            name: NodeName {
                #[cfg(feature = "const")]
                ar: "كلية العلوم والتكنلوجيا",
                #[cfg(feature = "storage")]
                ar: "كلية العلوم والتكنلوجيا".to_string(),
                #[cfg(feature = "const")]
                en: "Faculty of Science and Technology",
                #[cfg(feature = "storage")]
                en: "Faculty of Science and Technology".to_string(),
                #[cfg(feature = "const")]
                fr: "Faculté des Sciences et de la Technologie",
                #[cfg(feature = "storage")]
                fr: "Faculté des Sciences et de la Technologie".to_string(),
            },
            r#type: NodeType::Faculty,
        };

        let tests = vec![
            (
                "umkb",
                Some(&umkb),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"جامعة محمد خيضر بسكرة\",\"en\":\"University of Mohamed Khider Biskra\",\"fr\":\"Université Mohamed Khider Biskra\"},\"type\":\"UNIVERSITY\"}",
            ),
            (
                "umkb/fst",
                Some(&fst),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"كلية العلوم والتكنلوجيا\",\"en\":\"Faculty of Science and Technology\",\"fr\":\"Faculté des Sciences et de la Technologie\"},\"type\":\"FACULTY\"}",
            ),
            (
                "umkb/fst/dee/sec",
                Some(&sec),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"تخصص التحكم الكهربائي\",\"en\":\"Specialy of Electrical Control\",\"fr\":\"Spécialité de commande électrique\"},\"type\":\"SPECIALTY\",\"terms\":{\"perYear\":2,\"slots\":[7,8,9,10]}}",
            ),
            (
                "does/not/exist", None, 
                #[cfg(feature = "serde_derive")]
                "null"
            ),
        ];

        for test_case in tests {
            let path = test_case.0;
            let expected = test_case.1;
            #[cfg(feature = "const")]
            let actual = get_node_by_path(path);
            #[cfg(feature = "storage")]
            let actual = get_node_by_path(Path::new("../_data").join(path)).ok();
            #[cfg(feature = "storage")]
            let actual: Option<&Node> = actual.as_ref();

            assert_eq!(actual, expected);
            #[cfg(feature = "serde_derive")]
            {
                let expected_stringified = test_case.2;
                assert_eq!(
                    serde_json::to_string(&actual).unwrap(),
                    expected_stringified
                );
            }
        }
    }
}