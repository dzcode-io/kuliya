use std::io;
use thiserror::Error;

#[derive(Debug, Error)]
pub enum FetchError {
    #[error("json file was not read")]
    ReadJson(#[from] io::Error),
    #[error("json data was not deserialized")]
    Deserialize,
    #[error("unhandled error")]
    Unhandled,
}
