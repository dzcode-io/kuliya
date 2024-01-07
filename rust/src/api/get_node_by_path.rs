use crate::{_auto_generated, node::model::Node};

#[cfg(feature = "const")]
pub fn get_node_by_path(path: &str) -> Option<&Node> {
    _auto_generated::data::get_node_by_path(path)
}

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
                        ar: "جامعة محمد خيضر بسكرة",
                        en: "University of Mohamed Khider Biskra",
                        fr: "Université Mohamed Khider Biskra",
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
                        ar: "كلية العلوم والتكنلوجيا",
                        en: "Faculty of Science and Technology",
                        fr: "Faculté des Sciences et de la Technologie",
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
                        ar: "تخصص التحكم الكهربائي",
                        en: "Specialy of Electrical Control",
                        fr: "Spécialité de commande électrique",
                    },
                    r#type: NodeType::Specialty {
                        terms: NodeTerms {
                            per_year: 2,
                            slots: &[7, 8, 9, 10],
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

        for test_case in tests {
            let path = test_case.0;
            let expected = test_case.1;
            let actual = get_node_by_path(path);
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
