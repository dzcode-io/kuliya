use std::io;

#[derive(Debug)]
pub enum FetchError {
    ReadJson(io::Error),
    Deserialize,
    Unhandled,
}
