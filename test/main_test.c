#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include "./add/add_test.h"

int test()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(add_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}