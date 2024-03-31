#include "test.h"

int test_get_existing_schema(void)
{
    kuliya_schema *res = get_node_by_path("umkb");
    if (res == NULL)
        return 1;

    assert(STR_EQ(res->name.ar, "جامعة محمد خيضر بسكرة") && "arabic names were not equal");
    assert(STR_EQ(res->name.en, "University of Mohamed Khider Biskra") && "english names were not equal");
    assert(STR_EQ(res->name.fr, "Université Mohamed Khider Biskra") && "french names were not equal");
    assert(res->type == UNIVERSITY && "schema types were not equal");

    return 0;
}

int test_get_null_for_non_existing_schema(void)
{
    kuliya_schema *res = get_node_by_path("does/not/exist");
    if (res == NULL)
        return 0;

    return 1;
}

int main(void)
{
    test(test_get_existing_schema, "get existing schema");
    test(test_get_null_for_non_existing_schema, "get null for non existing schema");
    printf("\n\tPASSED: %d\tFAILED: %d\n", tests_passed, tests_failed);
    return (tests_failed > 0);
}
