#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>
#include "add_test.h"
#include "../../include/add.h"

void add_test(void **state){
     assert_true(add(1,2) == 3);
}
void add_test_2(void **state){
     assert_true(add(1,21) == 3);
}

