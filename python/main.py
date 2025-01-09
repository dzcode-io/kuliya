import sys
import json

# A node which contains the data from the JSON file in a python format
class Node:
  def __init__(self, nameAr: str, nameEn: str, nameFr: str, univ: str):
    self.nameAr = nameAr
    self.nameEn = nameEn
    self.nameFr = nameFr
    self.univ = univ

  def getNameAr(self):
    return self.nameAr
  
  def getNameEn(self):
    return self.nameEn

  def getNameFr(self):
    return self.nameFr
  
  def getUniv(self):
    return self.univ

# Converts the data from the 
def getNodeByPath(path: str) -> Node:
  try:
    file = open(path, "r")
    fileText = file.read()
    pythonData = json.loads(fileText)
    node = Node(pythonData["name"]["ar"], pythonData["name"]["en"], pythonData["name"]["fr"], pythonData["type"])
    return node
  except OSError as e:
    raise FileNotFoundError(f"Error with the file : {e}")


def main():
  try:
    node = getNodeByPath(sys.argv[1])
  except FileNotFoundError as e:
    print(e)

main()