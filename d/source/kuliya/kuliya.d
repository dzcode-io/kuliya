module kuliya.kuliya;

import kuliya.data;

public
{
	/++
	Get kuliya schema node by a given path.
	Params:
	    path = Kuliya path based on the location for `info.json` file in `_data/` folder (.eg `"usto/fmi"`).
	Returns:
		Pointer to kuliya schema if the path exists.
	+/
	Schema* getNodeByPath(string path)
	{
		return _getNodeByPath(path);
	}
}

/// Get existing schema by path
unittest
{
	Schema* schema = getNodeByPath("umkb");
	assert(schema !is null);
	assert(schema.name.ar == "جامعة محمد خيضر بسكرة");
	assert(schema.name.en == "University of Mohamed Khider Biskra");
	assert(schema.name.fr == "Université Mohamed Khider Biskra");
	assert(schema.type == Type.UNIVERSITY);
}

/// Get null for non-existing schema by path
unittest
{
	Schema* schema = getNodeByPath("does/not/exist");
	assert(schema is null);
}

/// Get Schema with terms by path
unittest
{
	Schema* schema = getNodeByPath("umkb/fst/dee/sec");
	assert(schema !is null);
	assert(schema.terms !is null);
	assert(schema.terms.perYear == 2);
	assert(schema.terms.slots.length == 4);
	assert(schema.terms.slots[0] == 7);
	assert(schema.terms.slots[1] == 8);
	assert(schema.terms.slots[2] == 9);
	assert(schema.terms.slots[3] == 10);
}
