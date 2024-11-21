//! Node module contains the Node struct and its nested structs for the `static` feature.

use nest_struct::nest_struct;
#[cfg(feature = "serde_derive")]
use serde::Serialize;

#[nest_struct]
/// A Node is a struct that contains the name and the type of the node
#[derive(Debug, PartialEq)]
#[cfg_attr(feature = "serde_derive", derive(Serialize))]
pub struct Node {
    /// Node name
    pub name: nest! {
        /// A NodeName is a struct that contains the name of the node in three languages
        #[derive(Debug, PartialEq)]
        #[cfg_attr(feature = "serde_derive", derive(Serialize))]
        pub struct NodeName {
            /// Arabic name
            pub ar: &'static str,
            /// English name
            pub en: &'static str,
            /// French name
            pub fr: &'static str,
        }
    },
    /// Node type information
    #[cfg_attr(feature = "serde_derive", serde(flatten))]
    pub r#type: nest! {
        /// A NodeType is an enum that represents the type of the node
        #[derive(Debug, PartialEq)]
        #[cfg_attr(feature = "serde_derive", derive(Serialize), serde(tag = "type"), serde(rename_all = "UPPERCASE"))]
        pub enum NodeType {
            /// University is the highest level of education in Algeria
            University,
            /// Academy is a type of university
            Academy,
            /// School is also a type of university
            PrivateSchool,
            /// Institute is a type of university
            Institute,
            /// Faculty is level 2 in the hierarchy
            Faculty,
            /// Department is level 3 in the hierarchy
            Department,
            /// Specialty is level 4 in the hierarchy
            Specialty {
                /// Terms information for the specialty
                terms: nest! {
                    /// A NodeTerms is a struct that contains the number of terms per year and the slot placement for each term
                    #[derive(Debug, PartialEq, Clone)]
                    #[cfg_attr(feature = "serde_derive", derive(Serialize), serde(rename_all = "camelCase"))]
                    pub struct NodeTerms {
                        /// Number Terms per year
                        pub per_year: usize,
                        /// Slot placement for each term
                        pub slots: &'static [i32],
                    }
                }
            },
            /// Sector is same level as Specialty
            Sector {
                /// Terms information for the sector
                terms: NodeTerms
            },
        }
    },
}
