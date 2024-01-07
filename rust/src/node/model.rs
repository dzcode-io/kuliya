#[derive(Debug, PartialEq)]
pub struct NodeName {
    pub ar: &'static str,
    pub en: &'static str,
    pub fr: &'static str,
}

#[derive(Debug, PartialEq)]
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
pub struct NodeTerms {
    pub per_year: usize,
    pub slots: &'static [i32],
}

#[derive(Debug, PartialEq)]
pub struct Node {
    pub name: NodeName,
    pub r#type: NodeType,
}
