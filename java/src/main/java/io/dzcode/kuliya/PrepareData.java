package io.dzcode.kuliya;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Stream;

import org.json.JSONException;
import org.json.JSONObject;

public class PrepareData {

  public static final String INFO_JSON_FILE = "info.json";
  public static final String CHILDREN_JSON_OBJ_NAME = "children";
  public static final String ROOT_DATA_DIR_LOC = "_data/";
  public static final String MAIN_SAVE_JSON_LOC = "main.json";
  public static JSONObject mainObj;

  public static JSONObject directory2Object(final File folder) throws IOException {
    JSONObject mainJsonObj = new JSONObject();
    mainJsonObj.put(CHILDREN_JSON_OBJ_NAME, new JSONObject());
    String infoFilePath = folder + "/" + INFO_JSON_FILE;

    if (Files.exists(Paths.get(infoFilePath))) {
      mainJsonObj = readJsonFileData(infoFilePath);
      mainJsonObj.put(CHILDREN_JSON_OBJ_NAME, new JSONObject());

    }
    File[] relativePaths = folder.listFiles();
    for (final File fileEntry : relativePaths) {
      if (fileEntry.isDirectory()) {
        ((JSONObject) mainJsonObj.get(CHILDREN_JSON_OBJ_NAME)).put(fileEntry.getName(), directory2Object(fileEntry));
      }

    }
    //System.out.println(mainJsonObj);
    return mainJsonObj;
  }

  public static void loadData() throws IOException {
    File root = new File(ROOT_DATA_DIR_LOC);
    if (root != null) {
      if (Files.notExists(Paths.get(ROOT_DATA_DIR_LOC + MAIN_SAVE_JSON_LOC))) {
        mainObj = directory2Object(root);
        mainObj = mainObj.getJSONObject(CHILDREN_JSON_OBJ_NAME);
        writeJSON(mainObj, ROOT_DATA_DIR_LOC + MAIN_SAVE_JSON_LOC);
        System.out.println("✅ - data is ready on " + ROOT_DATA_DIR_LOC + MAIN_SAVE_JSON_LOC);
        //mainObj.showJsonAll();
      } else if (Files.exists(Paths.get(ROOT_DATA_DIR_LOC + MAIN_SAVE_JSON_LOC))) {

        mainObj = readJsonFileData(ROOT_DATA_DIR_LOC + MAIN_SAVE_JSON_LOC);
        System.out.println("Aleardy exists;");
      } else {
        System.err.println("error File may be locke or unknown error.");
      }
    }
  }

  private static JSONObject readJsonFileData(String path) throws IOException {
    StringBuilder stringBuilder = new StringBuilder();
    Stream<String> stream = Files.lines(Paths.get(path), StandardCharsets.UTF_8);
    stream.forEach(s -> stringBuilder.append(s));

    stream.close();
    return new JSONObject(stringBuilder.toString());

  }

  private static void writeJSON(JSONObject mainObj, String savePath) {

    try {
      Path path = Paths.get(savePath);
      // string -> bytes
      Files.write(path, mainObj.toString().getBytes(StandardCharsets.UTF_8));
    } catch (JSONException ex) {
      Logger.getLogger(PrepareData.class.getName()).log(Level.SEVERE, null, ex);
    } catch (Exception ex) {
      Logger.getLogger(PrepareData.class.getName()).log(Level.SEVERE, null, ex);

    }
  }

}
