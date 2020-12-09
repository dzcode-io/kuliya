package io.dzcode.kuliya;

import static org.junit.Assert.*;

import org.junit.Test;

public class SearchTest {

  @Test
  public void testGetNodeByPath1() throws Exception {
    PrepareData.loadData();

    Node umkbNode = new Node("جامعة محمد خيضر بسكرة", "University of Mohamed Khider Biskra",
        "Université Mohamed Khider Biskra", "UNIVERSITY");
    String path = "umkb";
    Node resNode = Search.getNodeByPath(path);

    assertTrue(resNode.equals(umkbNode));

  }

  @Test
  public void testGetNodeByPath2() throws Exception {

    PrepareData.loadData();

    Node fstNode = new Node("كلية العلوم والتكنلوجيا", "Faculty of Science and Technology",
        "Faculté des Sciences et de la Technologie", "FACULTY");
    String path = "umkb/fst";
    Node resNode = Search.getNodeByPath(path);

    assertTrue(resNode.equals(fstNode));

  }

  @Test
  public void testGetNodeByPath3() throws Exception {

    PrepareData.loadData();

    String path = "do/not/exist/fst";
    Node resNode = Search.getNodeByPath(path);

    assertTrue(resNode == null);
  }

}
