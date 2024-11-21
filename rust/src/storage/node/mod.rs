use nest_struct::nest_struct;
use serde::Deserialize;
#[cfg(feature = "serde_derive")]
use serde::Serialize;

#[nest_struct]
#[derive(Debug, PartialEq, Deserialize)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct Node {
    pub name: nest! {
        pub ar: String,
        pub en: String,
        pub fr: String,
    },
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: nest! {
        #[derive(Debug, PartialEq, Deserialize)]
        #[cfg_attr(feature = "serde_derive", derive(Serialize), serde(tag = "type"), serde(rename_all = "UPPERCASE"))]
        pub enum NodeType {
            University,
            Academy,
            PrivateSchool,
            Institute,
            Faculty,
            Department,
            Specialty {
                terms: nest! {
                    #[derive(Debug, PartialEq, Clone, Deserialize)]
                    #[cfg_attr(feature = "serde_derive", derive(Serialize), serde(rename_all = "camelCase"))]
                    pub struct NodeTerms {
                        pub per_year: usize,
                        pub slots: Vec<i32>,
                    }
                }
            },
            Sector { terms: NodeTerms },
        }
    },
}
