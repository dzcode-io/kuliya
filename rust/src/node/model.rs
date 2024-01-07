#[cfg(feature = "serde_derive")]
use serde::{Deserialize, Serialize};

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct NodeName<'a> {
    #[cfg(feature = "const")]
    pub ar: &'a str,
    #[cfg(feature = "const")]
    pub en: &'a str,
    #[cfg(feature = "const")]
    pub fr: &'a str,
}

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
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
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct NodeTerms {
    pub per_year: usize,
    #[cfg(feature = "const")]
    #[cfg_attr(feature = "serde_derive", serde(skip_deserializing))]
    pub slots: &'static [i32],
}

#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize, Deserialize))]
pub struct Node {
    #[cfg_attr(feature = "serde_derive", serde(borrow))]
    pub name: NodeName<'static>,
    pub r#type: NodeType,
}
