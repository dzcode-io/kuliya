use serde::Deserialize;
#[cfg(feature = "serde_derive")]
use serde::Serialize;

#[derive(Debug, PartialEq, Deserialize)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct NodeName {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

#[derive(Debug, PartialEq, Deserialize)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize),
    serde(tag = "type"),
    serde(rename_all = "UPPERCASE")
)]
pub enum NodeType {
    University,
    Academy,
    PrivateSchool,
    Institute,
    Faculty,
    Department,
    Specialty { terms: NodeTerms },
    Sector { terms: NodeTerms },
}

#[derive(Debug, PartialEq, Clone, Deserialize)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize),
    serde(rename_all = "camelCase")
)]
pub struct NodeTerms {
    pub per_year: usize,
    pub slots: Vec<i32>,
}

#[derive(Debug, PartialEq, Deserialize)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct Node {
    pub name: NodeName,
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: NodeType,
}
