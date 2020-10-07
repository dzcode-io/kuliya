import { Node } from "../_config/types";
import get from "lodash/fp/get";
import mainJson from "../_data/main.json";

export const getNodeByPath: (path: string) => Node = (path: string) => {
  return get(path.replace(/\//g, ".children."), mainJson);
};
