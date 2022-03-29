#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include "../test/add/add_test.h"
#include <stdio.h>


/**
 * @brief Main program
 * 
 * @return int 
 */

int main(){
   
   const struct CMUnitTest tests[] =
    {	
		cmocka_unit_test(add_test_1_2),
		cmocka_unit_test(add_test_2_2),
		cmocka_unit_test(add_test_3_2),
		
    };

	printf("Hello World");

    return cmocka_run_group_tests(tests, NULL, NULL);
}