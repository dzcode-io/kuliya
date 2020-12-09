package io.dzcode.kuliya;

import org.json.JSONObject;

public class Node extends JSONObject {

  public Node(String nameAr, String nameEn, String nameFr, String univ) {
    JSONObject nameObj = new JSONObject();
    nameObj.put("ar", nameAr);
    nameObj.put("en", nameEn);
    nameObj.put("fr", nameFr);
    this.put("name", nameObj);
    this.put("type", univ);
  }

  @Override
  public boolean equals(Object obj) {

    if (obj == null)
      return false;
    int hash1 = ((JSONObject) obj).toString().hashCode();
    int hash2 = ((JSONObject) this).toString().hashCode();

    System.out.println(((JSONObject) obj).toString());
    System.out.println(((JSONObject) this).toString());

    return hash1 == hash2;
  }

}
