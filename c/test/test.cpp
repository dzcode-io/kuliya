#include <CppUTest/TestHarness_c.h>
#include <CppUTest/CommandLineTestRunner.h>

#include "test.h"

TEST_GROUP(KuliyaSchemaTests){
    void setup(){} void teardown(){}};

TEST(KuliyaSchemaTests, GetExistingSchema)
{
    kuliya_schema *res = get_node_by_path("umkb");
    CHECK(res != NULL);
    CHECK_EQUAL_C_STRING("جامعة محمد خيضر بسكرة", res->name.ar);
    CHECK_EQUAL_C_STRING("University of Mohamed Khider Biskra", res->name.en);
    CHECK_EQUAL_C_STRING("Université Mohamed Khider Biskra", res->name.fr);
    CHECK_EQUAL(UNIVERSITY, res->type);
}

TEST(KuliyaSchemaTests, GetNullForNonExistingSchema)
{
    kuliya_schema *res = get_node_by_path("does/not/exist");
    CHECK(res == NULL);
}

int main(int argc, char **argv)
{
    return RUN_ALL_TESTS(argc, argv);
}
