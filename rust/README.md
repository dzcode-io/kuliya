# kuliya

Algeria's college hierarchy dataset as a crate with useful APIs.

Example

```rust
use kuliya::r#static::api::get_node_by_path;

let faculty_of_science_and_technology = get_node_by_path("umkb/fst");

assert_eq!(faculty_of_science_and_technology.is_some(), true);

let faculty_of_science_and_technology = faculty_of_science_and_technology.unwrap();

assert_eq!(faculty_of_science_and_technology.name.ar, "كلية العلوم والتكنلوجيا");

// when the path is not found, the function returns None
let non_existing_node = get_node_by_path("umkb/fst/unknown");

assert_eq!(non_existing_node.is_none(), true);
```

License: MIT
