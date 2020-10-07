import { getNodeByPath } from "./index";

describe("Test getNodeByPath Typescript support", () => {
  test('expect to get UMKB info when path="umkb"', () => {
    const node = getNodeByPath("umkb");

    expect(node).toMatchObject({
      name: {
        ar: "جامعة محمد خيضر بسكرة",
        en: "University of Mohamed Khider Biskra",
        fr: "Université Mohamed Khider Biskra",
      },
      type: "UNIVERSITY",
    });
  });

  test('expect to get UMKB/FST info when path="umkb/fst"', () => {
    const node = getNodeByPath("umkb/fst");

    expect(node).toMatchObject({
      name: {
        ar: "كلية العلوم والتكنلوجيا",
        en: "Faculty of Science and Technology",
        fr: "Faculté des Sciences et de la Technologie",
      },
      type: "FACULTY",
    });
  });

  test('expect to get undefined when path="does/not/exist"', () => {
    const node = getNodeByPath("does/not/exist");

    expect(node).toBe(undefined);
  });
});
