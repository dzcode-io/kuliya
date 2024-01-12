#![cfg(feature = "storage")]

use crate::Node;
use std::path::Path;

pub enum StorageError {
    Io(std::io::Error),
    Json(serde_json::Error),
}

pub fn get_node_by_path(path: impl AsRef<Path>) -> Result<Node, StorageError> {
    let json_file_path = path.as_ref().join("info.json");
    let json_file_content = std::fs::read_to_string(json_file_path).map_err(StorageError::Io)?;
    serde_json::from_str::<Node>(json_file_content.as_str()).map_err(StorageError::Json)
}
