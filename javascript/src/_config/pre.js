const fse = require("fs-extra");
const path = require("path");

const mainJsonPath = path.join(__dirname, "../_data/main.json");
if (!fse.pathExistsSync(mainJsonPath)) {
  console.log("creating placeholder file main.json");
  fse.ensureFileSync(mainJsonPath);
  fse.writeJSON(mainJsonPath, {});
} else {
  console.log("main.json exists");
}
