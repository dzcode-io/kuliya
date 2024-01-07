use serde::{Deserialize, Serialize};
use serde_json::json;

#[derive(Debug, Serialize, Deserialize)]
pub struct Name {
    pub ar: String,
    pub en: String,
    pub fr: String,
}

impl std::fmt::Display for Name {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"ar": self.ar, "en": self.en, "fr": self.fr});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq)]
pub enum Type {
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
    Specialty,
    #[serde(rename = "SECTOR")]
    Sector,
}

impl std::fmt::Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Type::University => write!(f, "UNIVERSITY"),
            Type::Academy => write!(f, "ACADEMY"),
            Type::PrivateSchool => write!(f, "PRIVATE_SCHOOL"),
            Type::Institute => write!(f, "INSTITUTE"),
            Type::Faculty => write!(f, "FACULTY"),
            Type::Department => write!(f, "DEPARTMENT"),
            Type::Specialty => write!(f, "SPECIALTY"),
            Type::Sector => write!(f, "SECTOR"),
        }
    }
}

#[derive(Debug, Serialize, Deserialize, PartialEq, Clone)]
pub struct Terms {
    #[serde(rename = "perYear")]
    pub per_year: usize,
    pub slots: Vec<usize>,
}

impl std::fmt::Display for Terms {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let obj = json!({"perYear": self.per_year, "slots": self.slots});
        write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap())
    }
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Schema {
    pub name: Name,
    pub r#type: Type,
    pub terms: Option<Terms>,
}

impl std::fmt::Display for Schema {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if self.terms.is_some() {
            let obj = json!({
                "name": self.name,
                "type": self.r#type,
                "terms": self.terms.clone().unwrap()
            });
            return write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap());
        } else {
            let obj = json!({
                "name": self.name,
                "type": self.r#type
            });
            return write!(f, "{}", serde_json::to_string_pretty(&obj).unwrap());
        }
    }
}
