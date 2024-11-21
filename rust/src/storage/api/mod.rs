//! This module contains the API for the `storage` feature.

use super::node::Node;
use std::path::Path;

/// An error that can occur when interacting with the storage.
pub enum StorageError {
    /// An error that occurs when reading or writing to the file system.
    Io(std::io::Error),
    /// An error that occurs when serializing or deserializing JSON.
    Json(serde_json::Error),
}

/// Retrieves a node by its path.
///
/// # Arguments
///
/// * `path` - A string slice that holds the path of the node.
///
/// # Returns
///
/// * `Result<Node, StorageError>` - A result that holds the node if found, otherwise an error.
pub fn get_node_by_path(path: impl AsRef<Path>) -> Result<Node, StorageError> {
    let json_file_path = path.as_ref().join("info.json");
    let json_file_content = std::fs::read_to_string(json_file_path).map_err(StorageError::Io)?;
    serde_json::from_str::<Node>(json_file_content.as_str()).map_err(StorageError::Json)
}

#[cfg(test)]
mod test {
    use super::get_node_by_path;
    use crate::storage::node::{Node, NodeName, NodeTerms, NodeType};
    use std::path::Path;

    #[test]
    fn check_three_schemas_and_non_existent() {
        let umkb = Node {
            name: NodeName {
                ar: "جامعة محمد خيضر بسكرة".to_string(),
                en: "University of Mohamed Khider Biskra".to_string(),
                fr: "Université Mohamed Khider Biskra".to_string(),
            },
            r#type: NodeType::University,
        };
        let sec = Node {
            name: NodeName {
                ar: "تخصص التحكم الكهربائي".to_string(),
                en: "Specialy of Electrical Control".to_string(),
                fr: "Spécialité de commande électrique".to_string(),
            },
            r#type: NodeType::Specialty {
                terms: NodeTerms {
                    per_year: 2,
                    slots: vec![7, 8, 9, 10],
                },
            },
        };
        let fst = Node {
            name: NodeName {
                ar: "كلية العلوم والتكنلوجيا".to_string(),
                en: "Faculty of Science and Technology".to_string(),
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
            let actual = get_node_by_path(Path::new("../_data").join(path)).ok();
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
