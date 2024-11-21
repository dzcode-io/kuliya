use serde::Serialize;

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct NodeName {
    pub ar: &'static str,
    pub en: &'static str,
    pub fr: &'static str,
}

#[derive(Debug, PartialEq)]
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

#[derive(Debug, PartialEq, Clone)]
#[cfg_attr(
    feature = "serde_derive",
    derive(Serialize),
    serde(rename_all = "camelCase")
)]
pub struct NodeTerms {
    pub per_year: usize,
    pub slots: &'static [i32],
}

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct Node {
    pub name: NodeName,
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: NodeType,
}
