use crate::{_auto_generated, node::model::Node};

#[cfg(feature = "const")]
pub fn get_node_by_path(path: &str) -> Option<&Node> {
    _auto_generated::data::get_node_by_path(path)
}

#[cfg(test)]
mod test {
    use crate::node::model::{Node, NodeName, NodeTerms, NodeType};

    use super::get_node_by_path;

    struct TestCase<'a> {
        path: &'a str,
        expected: Node,
    }

    impl<'a> TestCase<'a> {
        pub fn new(path: &'a str, expected: Node) -> Self {
            Self { path, expected }
        }
    }

    #[test]
    fn should_get_expected_info() {
        let tests: Vec<TestCase> = vec![
            TestCase::new(
                "umkb",
                Node {
                    name: NodeName {
                        ar: "جامعة محمد خيضر بسكرة",
                        en: "University of Mohamed Khider Biskra",
                        fr: "Université Mohamed Khider Biskra",
                    },
                    r#type: NodeType::University,
                },
            ),
            TestCase::new(
                "umkb/fst",
                Node {
                    name: NodeName {
                        ar: "كلية العلوم والتكنلوجيا",
                        en: "Faculty of Science and Technology",
                        fr: "Faculté des Sciences et de la Technologie",
                    },
                    r#type: NodeType::Faculty,
                },
            ),
            TestCase::new(
                "umkb/fst/dee/sec",
                Node {
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
                },
            ),
        ];

        for tc in tests {
            let actual = get_node_by_path(tc.path).unwrap();
            assert_node(&tc.expected, &actual);
        }
    }

    #[test]
    fn should_get_none_when_path_does_not_exist() {
        let res = get_node_by_path("does/not/exist");
        assert!(res.is_none());
    }

    fn assert_node(expected: &Node, actual: &Node) {
        assert_eq!(
            expected, actual,
            "Expected node to be '{:?}', but got '{:?}'",
            expected, actual
        );
    }
}
