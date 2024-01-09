#[cfg(feature = "storage")]
use crate::Node;

#[cfg(feature = "storage")]
pub fn get_node_by_path(data_path: &'static str, path: &str) -> Result<Node, std::io::Error> {
    let fs_path = format!("{}/{}/info.json", data_path, path);
    let info = std::fs::read_to_string(fs_path)?;
    let Ok(node) = serde_json::from_str::<Node>(info.as_str()) else {
        return Err(std::io::Error::new(
            std::io::ErrorKind::Other,
            "json was not deserialized",
        ));
    };
    Ok(node)
}
