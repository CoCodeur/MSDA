#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include "../test/add/add_test.h"


/**
 * @brief Main program
 * 
 * @return int 
 */

int main(){
   
   const struct CMUnitTest tests[] =
    {
		cmocka_unit_test(add_test),
		cmocka_unit_test(add_test_2),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);

}
