import json
import os
from importlib.resources import files
from .node import Node

READ_JSON_NAME = "info.json"
TARGET_JSON_FILE = "data.json"
DEVELOPMENT_MODE = False

"""
A function that consumes all the files in "_data" and create a single JSON file with the data and the corresponding path.
"""
def directoryToOneJsonFile(path: str):
    try:
        targetFile = open(TARGET_JSON_FILE, "w", encoding="utf-8")
        targetFile.write("{")
        for folder_name, subfolders, filenames in os.walk(path):
            for filename in filenames:
                if filename == READ_JSON_NAME:
                    file = open(folder_name + "\\" + filename, "r", encoding="utf-8")
                    formatted_path = (
                        folder_name.split("_data")[1].replace("\\", "/").strip("/")
                    )
                    targetFile.write('"' + formatted_path + '":')
                    targetFile.write(file.read())
                    targetFile.write(",")
                    file.close()
        targetFile.write('"":{}')
        targetFile.write("}")

    except OSError as e:
        raise FileNotFoundError(f"Error with the file : {e}")

"""
A function that consumes "data.json" to return the information of the path given in parameter with a Node object.
Essientially, it converts the JSON data into a Node object.
"""
def getNodeByPath(path: str) -> Node:
    if DEVELOPMENT_MODE:
        directoryToOneJsonFile("../../../_data/")
    try:
        if DEVELOPMENT_MODE:
            file = open(TARGET_JSON_FILE, "r", encoding="utf-8")
        else:
            data_path = files("kulya_python").joinpath("data.json")
            file = open(data_path, "r", encoding="utf-8")
        fileText = file.read()
        file.close()
        pythonData = json.loads(fileText)
        if path in pythonData:
            print(pythonData[path])
            node = Node(
                pythonData[path]["name"]["ar"],
                pythonData[path]["name"]["en"],
                pythonData[path]["name"]["fr"],
                pythonData[path]["type"],
            )
        else:
            raise KeyError(f"Path '{path}' not found in JSON data.")
        return node
    except OSError as e:
        raise FileNotFoundError(f"Error with the file : {e}")
