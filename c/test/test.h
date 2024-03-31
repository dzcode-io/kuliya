#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>
#include <assert.h>
#include <kuliya.h>

#include "helpers/my_string.h"

static int tests_passed = 0;
static int tests_failed = 0;

/* Test runner */
static void test(int (*func)(void), const char *name)
{
    int res = func();
    if (res == 0)
    {
        tests_passed++;
    }
    else
    {
        tests_failed++;
        printf("FAILED: %s\n", name);
    }
}

#endif /* __TEST_H__ */
