use serde::{Deserialize, Serialize};
use serde_json::json;

#[derive(Debug, Serialize, Deserialize, PartialEq)]
pub struct NodeName {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

impl std::fmt::Display for NodeName {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"ar": self.ar, "en": self.en, "fr": self.fr});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq)]
#[serde(tag = "type")] // to flatten the enum to the parent struct
pub enum NodeType {
    #[serde(rename = "UNIVERSITY")]
    University,
    #[serde(rename = "ACADEMY")]
    Academy,
    #[serde(rename = "PRIVATE_SCHOOL")]
    PrivateSchool,
    #[serde(rename = "INSTITUTE")]
    Institute,
    #[serde(rename = "FACULTY")]
    Faculty,
    #[serde(rename = "DEPARTMENT")]
    Department,
    #[serde(rename = "SPECIALTY")]
    Specialty { terms: NodeTerms },
    #[serde(rename = "SECTOR")]
    Sector { terms: NodeTerms },
}

impl std::fmt::Display for NodeType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            NodeType::University => write!(f, "UNIVERSITY"),
            NodeType::Academy => write!(f, "ACADEMY"),
            NodeType::PrivateSchool => write!(f, "PRIVATE_SCHOOL"),
            NodeType::Institute => write!(f, "INSTITUTE"),
            NodeType::Faculty => write!(f, "FACULTY"),
            NodeType::Department => write!(f, "DEPARTMENT"),
            NodeType::Specialty { .. } => write!(f, "SPECIALTY"),
            NodeType::Sector { .. } => write!(f, "SECTOR"),
        }
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq, Clone)]
pub struct NodeTerms {
    #[serde(rename = "perYear")]
    pub per_year: usize,
    pub slots: Vec<usize>,
}

impl std::fmt::Display for NodeTerms {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"perYear": self.per_year, "slots": self.slots});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq)]
pub struct Node {
    pub name: NodeName,
    #[serde(flatten)]
    pub r#type: NodeType,
}

impl std::fmt::Display for Node {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", serde_json::to_string_pretty(&self).unwrap())
    }
}
