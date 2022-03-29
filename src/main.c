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
	const struct CMUnitTest tests_adder[] =
    {
        cmocka_unit_test(add_test),
		
    };

    return cmocka_run_group_tests(tests_adder, NULL, NULL);
}
