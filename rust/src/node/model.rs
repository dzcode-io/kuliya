#[cfg(feature = "serde_derive")]
use serde::{Deserialize, Serialize};

#[cfg(feature = "const")]
#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct NodeName<'a> {
    pub ar: &'a str,
    pub en: &'a str,
    pub fr: &'a str,
}

#[cfg(feature = "storage")]
#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct NodeName {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

#[cfg(any(feature = "const", feature = "storage"))]
#[derive(Debug, PartialEq)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize, Deserialize),
    serde(tag = "type")
)]
pub enum NodeType {
    #[cfg_attr(feature = "serde_derive", serde(rename = "UNIVERSITY"))]
    University,
    #[cfg_attr(feature = "serde_derive", serde(rename = "ACADEMY"))]
    Academy,
    #[cfg_attr(feature = "serde_derive", serde(rename = "PRIVATE_SCHOOL"))]
    PrivateSchool,
    #[cfg_attr(feature = "serde_derive", serde(rename = "INSTITUTE"))]
    Institute,
    #[cfg_attr(feature = "serde_derive", serde(rename = "FACULTY"))]
    Faculty,
    #[cfg_attr(feature = "serde_derive", serde(rename = "DEPARTMENT"))]
    Department,
    #[cfg_attr(feature = "serde_derive", serde(rename = "SPECIALTY"))]
    Specialty { terms: NodeTerms },
    #[cfg_attr(feature = "serde_derive", serde(rename = "SECTOR"))]
    Sector { terms: NodeTerms },
}

#[derive(Debug, PartialEq, Clone)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize, Deserialize),
    serde(rename_all = "camelCase")
)]
pub struct NodeTerms {
    pub per_year: usize,
    #[cfg(feature = "const")]
    pub slots: &'static [i32],
    #[cfg(feature = "storage")]
    pub slots: Vec<i32>,
}

#[cfg(any(feature = "const", feature = "storage"))]
#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct Node {
    #[cfg(feature = "const")]
    #[cfg_attr(feature = "serde_derive", serde(borrow))]
    pub name: NodeName<'static>,
    #[cfg(feature = "storage")]
    pub name: NodeName,
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: NodeType,
}
