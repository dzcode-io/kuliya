//! This module contains the API for the `static` feature.

use super::_auto_generated;
use super::node::Node;

/// Retrieves a node by its path.
///
/// # Arguments
///
/// * `path` - A string slice that holds the path of the node.
///
/// # Returns
///
/// * `Option<&Node>` - An optional reference to the node if found, otherwise `None`.
pub fn get_node_by_path(path: &str) -> Option<&Node> {
    _auto_generated::data::get_node_by_path(path)
}

/// Retrieves the children of a node by its path.
/// # Arguments
///
/// * `path` - A string slice that holds the path of the node.
///
/// # Returns
///
/// * `Vec<&Node>` - A vector of references to the children nodes.
pub fn get_node_children_by_path(path: &str) -> Vec<&Node> {
    _auto_generated::data::get_node_children_by_path(path)
}

#[cfg(test)]
mod test {
    use super::get_node_by_path;
    use crate::r#static::node::{Node, NodeName, NodeTerms, NodeType};

    #[test]
    fn check_three_schemas_and_non_existent() {
        let umkb = Node {
            code: "UMKB",
            name: NodeName {
                ar: "جامعة محمد خيضر بسكرة",
                en: "University of Mohamed Khider Biskra",
                fr: "Université Mohamed Khider Biskra",
            },
            r#type: NodeType::University,
        };
        let sec = Node {
            code: "SEC",
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
        };
        let fst = Node {
            code: "FST",
            name: NodeName {
                ar: "كلية العلوم والتكنلوجيا",
                en: "Faculty of Science and Technology",
                fr: "Faculté des Sciences et de la Technologie",
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
