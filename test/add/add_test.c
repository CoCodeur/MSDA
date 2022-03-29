#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include "../../include/add.h"

void add_test_1_2(void **state){
     assert_true(add(1,2) == 3);
}
void add_test_2_2(void **state){
     assert_true(add(2,2) == 4);
}
void add_test_3_2(void **state){
     assert_true(add(3,2) == 5);
}



int main(){
    const struct CMUnitTest tests[] = {
                cmocka_unit_test(add_test_1_2),
                cmocka_unit_test(add_test_2_2),
                cmocka_unit_test(add_test_3_2),
        };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

