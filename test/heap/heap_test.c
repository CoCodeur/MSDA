#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>


static void test_init()
{
    assert_int_equal(1, 1);
}

int main(int argc, char **argv)
{
    const UnitTest tests[] =
    {
            unit_test(test_init),
    };

    return run_tests(tests);
}