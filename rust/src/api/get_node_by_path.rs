use crate::node::model::Node;
use std::fs;

static DATA_FOLDER: &'static str = "src/_data";
static CARGO_MANIFEST_DIR: &'static str = env!("CARGO_MANIFEST_DIR");

pub fn get_node_by_path(path: &str) -> Option<Node> {
    let fs_path = format!("{}/{}/{}/info.json", CARGO_MANIFEST_DIR, DATA_FOLDER, path);
    let Ok(info) = fs::read_to_string(fs_path) else {
        return None;
    };
    let Ok(node) = serde_json::from_str::<Node>(info.as_str()) else {
        return None;
    };
    Some(node)
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
                        ar: "جامعة محمد خيضر بسكرة".to_string(),
                        en: "University of Mohamed Khider Biskra".to_string(),
                        fr: "Université Mohamed Khider Biskra".to_string(),
                    },
                    r#type: NodeType::University,
                    terms: None,
                },
            ),
            TestCase::new(
                "umkb/fst",
                Node {
                    name: NodeName {
                        ar: "كلية العلوم والتكنلوجيا".to_string(),
                        en: "Faculty of Science and Technology".to_string(),
                        fr: "Faculté des Sciences et de la Technologie".to_string(),
                    },
                    r#type: NodeType::Faculty,
                    terms: None,
                },
            ),
            TestCase::new(
                "umkb/fst/dee/sec",
                Node {
                    name: NodeName {
                        ar: "تخصص التحكم الكهربائي".to_string(),
                        en: "Specialy of Electrical Control".to_string(),
                        fr: "Spécialité de commande électrique".to_string(),
                    },
                    r#type: NodeType::Specialty,
                    terms: Some(NodeTerms {
                        per_year: 2,
                        slots: vec![7, 8, 9, 10],
                    }),
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
            expected.r#type, actual.r#type,
            "Expected ty to be '{:?}', but got '{:?}'",
            expected.r#type, actual.r#type
        );
        assert_eq!(
            expected.terms, actual.terms,
            "Expeted terms to be '{:?}', but got '{:?}'",
            expected.terms, actual.terms
        )
    }
}
