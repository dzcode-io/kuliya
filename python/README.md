# kulya_python

`kulya_python` is a Python package designed to facilitate access to structured JSON data as part of the Kulya project. It allows you to retrieve information from a centralized JSON file.

## Installation

To install `kulya_python`, you can use `pip`:

```bash
pip install kulya_python
```

## Usage

Here is a simple example of how to use the kulya_python package:

```python
from kulya_python import getNodeByPath

# Example usage to retrieve a specific node
node = getNodeByPath('umkb/fst')
print(node.getNameFr())
```

## Developers

If you want to reload the data.json (because \_data changed), set `DEVELOPMENT_MODE` to True and call `getNodeByPath(anypath)` below utils.py

## How to publish the package

Get into the root folder where `pyproject.toml` is and do these steps :
`py -m build`
`pip install -U packaging` (debug for twine)
`py -m pip install --upgrade twine`
`py -m twine upload  dist/*` put your API token when asked
You can then access to the package with
`pip install [package-name]`

## Project Structure

    kulya_python/: Main package directory.
        utils.py: Contains utility functions, including getNodeByPath.
        node.py: Defines the Node class used to encapsulate JSON data.
        data.json: Centralized JSON file containing the necessary data.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
Contact
