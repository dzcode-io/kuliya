import { Node } from "../_config/types";
import fse from "fs-extra";
import { join } from "path";

const dataDirectoryPath = join(__dirname, "../../../_data"); // _data folder path

// scan a dir for dirs and convert them into nodes:
const directory2Object = async (directoryPath: string) => {
  let nodeObject: Node = { children: {} };

  const infoFilePath = join(directoryPath, "info.json");
  if (fse.existsSync(infoFilePath)) {
    nodeObject = { ...nodeObject, ...(await fse.readJSON(infoFilePath)) };
  }

  const relativePaths = await fse.readdir(directoryPath);
  for (const relativePath of relativePaths) {
    const fullPath = join(directoryPath, relativePath);
    // only directories:
    if (fse.statSync(fullPath).isDirectory()) {
      nodeObject.children[relativePath] = await directory2Object(fullPath);
    }
  }

  return nodeObject;
};

// bootstrap everything in an asynchronous fashion:
const loadData = async () => {
  const mainDataObject = await directory2Object(dataDirectoryPath);
  const mainJsonFilePath = join(__dirname, "../../src/_data/main.json");
  fse.writeJSON(mainJsonFilePath, mainDataObject.children);
  // finished:
  console.log(`✅ - data is ready on ${mainJsonFilePath}`);
};

// starting:
console.log("🏗  - preparing data...");
loadData();
