#include "test.h"

int test_shadow(void)
{
    return get_node_by_path("shadow/path");
}

int main(void)
{
    test(test_shadow, "a shadow test");
    printf("\n\tPASSED: %d\tFAILED: %d\n", tests_passed, tests_failed);
    return (tests_failed > 0);
}
