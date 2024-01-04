use crate::{Schema, _data::DATA};

pub fn get_node_by_path(path: &str) -> Option<Schema> {
    let path = path.trim_start_matches('/');
    let path = path.trim_end_matches('/');
    let path = path.split('/').collect::<Vec<_>>();

    let mut node = DATA.clone();

    for part in path {
        node = node.get(part)?.clone();
    }

    let node = node.get("info")?.clone();
    let node: Schema = serde_json::from_value(node).unwrap();

    Some(node)
}

#[cfg(test)]
mod test {
    use crate::api::get_node_by_path::get_node_by_path;

    #[test]
    fn check_umkb_info() {
        let result = get_node_by_path("umkb");

        assert_eq!(format!("{:?}", result), "Some(Schema { name: Name { ar: \"جامعة محمد خيضر بسكرة\", en: \"University of Mohamed Khider Biskra\", fr: \"Université Mohamed Khider Biskra\" }, ty: University, terms: None })");
    }

    #[test]
    fn check_non_valid_info() {
        let result = get_node_by_path("non-valid");

        assert_eq!(format!("{:?}", result), "None");
    }
}
