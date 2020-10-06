import { getNodeByPath } from "../../dist/getNodeByPath";

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
});
