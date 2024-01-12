#[cfg(feature = "storage")]
use serde::Deserialize;
#[cfg(feature = "serde_derive")]
use serde::Serialize;

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
#[cfg(feature = "const")]
pub struct NodeName {
    pub ar: &'static str,
    pub en: &'static str,
    pub fr: &'static str,
}

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
#[cfg_attr(feature = "storage", derive(Deserialize))]
#[cfg(feature = "storage")]
pub struct NodeName {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

#[derive(Debug, PartialEq)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize),
    serde(tag = "type"),
    serde(rename_all = "UPPERCASE")
)]
#[cfg_attr(feature = "storage", derive(Deserialize))]
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

#[derive(Debug, PartialEq, Clone)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize),
    serde(rename_all = "camelCase")
)]
#[cfg_attr(feature = "storage", derive(Deserialize))]
pub struct NodeTerms {
    pub per_year: usize,
    #[cfg(feature = "const")]
    pub slots: &'static [i32],
    #[cfg(feature = "storage")]
    pub slots: Vec<i32>,
}

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
#[cfg_attr(feature = "storage", derive(Deserialize))]

pub struct Node {
    pub name: NodeName,
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: NodeType,
}
