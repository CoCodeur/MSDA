#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../../include/stack.h"

static void test_init()
{
    assert_int_equal(1, 1);
}

int main(){
    const struct CMUnitTest tests[] = {
                cmocka_unit_test(test_init),
        };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
