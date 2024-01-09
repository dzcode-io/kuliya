use crate::node::model::Node;

#[cfg(feature = "const")]
use crate::_auto_generated;

#[cfg(feature = "storage")]
use crate::api::storage;

#[cfg(feature = "const")]
pub fn get_node_by_path(path: &str) -> Option<&Node> {
    _auto_generated::data::get_node_by_path(path)
}

#[cfg(feature = "storage")]
pub fn get_node_by_path(data_path: &'static str, path: &str) -> Result<Node, std::io::Error> {
    storage::get_node_by_path(data_path, path)
}

#[cfg(any(feature = "const", feature = "storage"))]
#[cfg(test)]
mod test {
    use crate::node::model::{Node, NodeName, NodeTerms, NodeType};

    use super::get_node_by_path;

    #[test]
    fn check_three_schemas_and_non_existent() {
        let tests = vec![
            (
                "umkb",
                Some(&Node {
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
                }),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"جامعة محمد خيضر بسكرة\",\"en\":\"University of Mohamed Khider Biskra\",\"fr\":\"Université Mohamed Khider Biskra\"},\"type\":\"University\"}",
            ),
            (
                "umkb/fst",
                Some(&Node {
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
                }),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"كلية العلوم والتكنلوجيا\",\"en\":\"Faculty of Science and Technology\",\"fr\":\"Faculté des Sciences et de la Technologie\"},\"type\":\"Faculty\"}",
            ),
            (
                "umkb/fst/dee/sec",
                Some(&Node {
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
                }),
                #[cfg(feature = "serde_derive")]
                "{\"name\":{\"ar\":\"تخصص التحكم الكهربائي\",\"en\":\"Specialy of Electrical Control\",\"fr\":\"Spécialité de commande électrique\"},\"type\":{\"Specialty\":{\"terms\":{\"per_year\":2,\"slots\":[7,8,9,10]}}}}",
            ),
            (
                "does/not/exist", None, 
                #[cfg(feature = "serde_derive")]
                "null"
            ),
        ];

        for tc in tests {
            #[cfg(feature = "const")]
            {
                let actual = get_node_by_path(tc.path).unwrap();
                assert_node(&tc.expected, &actual);
            }
            #[cfg(feature = "storage")]
            {
                let actual = get_node_by_path("../_data", tc.path).unwrap();
                assert_node(&tc.expected, &actual);
            }
        }
    }

    #[test]
    fn should_get_none_when_path_does_not_exist() {
        #[cfg(feature = "const")]
        {
            let res = get_node_by_path("does/not/exist");
            assert!(res.is_none());
        }
        #[cfg(feature = "storage")]
        {
            let res = get_node_by_path("../_data", "does/not/exist");
            assert!(res.is_err());
        }
    }

    fn assert_node(expected: &Node, actual: &Node) {
        assert_eq!(
            expected, actual,
            "Expected node to be '{:?}', but got '{:?}'",
            expected, actual
        );
    }
}
