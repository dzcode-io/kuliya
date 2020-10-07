const fse = require("fs-extra");
const path = require("path");

const mainJsonPath = path.join(__dirname, "../_data/main.json");
if (!fse.pathExistsSync(mainJsonPath)) fse.writeJSON(mainJsonPath, {});
