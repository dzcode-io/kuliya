package io.dzcode.kuliya;

import org.json.JSONObject;

public class Search {
  public static Node getNodeByPath(String path) {

    JSONObject resObj = PrepareData.mainObj;

    if (resObj != null) {
      path = path.replaceAll("/", ".children.");
      for (String pathParts : path.split("\\.")) {
        if (resObj.has(pathParts))
          resObj = resObj.getJSONObject(pathParts);
        else
          return null;
      }
      //System.out.println(">>" + resObj.getJSONObject("name").get("en"));
      String nameAr = (String) resObj.getJSONObject("name").get("ar");
      String nameEn = (String) resObj.getJSONObject("name").get("en");
      String nameFr = (String) resObj.getJSONObject("name").get("fr");
      String univ = resObj.getString("type");
      return new Node(nameAr, nameEn, nameFr, univ);
    }
    return null;

  };

}
