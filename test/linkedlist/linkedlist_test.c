#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/doublylinkedlist.h"

static void test_init_linkedlist()
{
    struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
    assert_int_equal(linkedlist->size, 0);
}

static void test_linkedlist_is_empty_true(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  assert_true(linkedlist__is_empty(linkedlist));

}
static void test_linkedlist_is_empty_false(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_head(linkedlist, 1);
  assert_false(linkedlist__is_empty(linkedlist));  
}

static void test_linkedlist_insert_head_next(){
   struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_head(linkedlist, 1);
  linkedlist__insert_head(linkedlist, 2);

  assert_int_equal(linkedlist->head->value, 2);
  assert_int_equal(linkedlist->head->next->value, 1);
}

static void test_linkedlist_insert_head_prev(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_head(linkedlist, 1);
  linkedlist__insert_head(linkedlist, 2);

  struct NODE * traversal = linkedlist->head->next;

  assert_int_equal(traversal->value, 1);
  assert_int_equal(traversal->prev->value, 2);
}

static void test_linkedlist_insert_tail_prev(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_tail(linkedlist, 1);
  linkedlist__insert_tail(linkedlist, 2);

  assert_int_equal(linkedlist->tail->value, 2);
  assert_int_equal(linkedlist->tail->prev->value, 1);

}

static void test_linkedlist_delete_node(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_tail(linkedlist, 1);
  linkedlist__insert_tail(linkedlist, 2);
  linkedlist__insert_tail(linkedlist, 3);
  linkedlist__insert_tail(linkedlist, 4);
  linkedlist__insert_tail(linkedlist, 5);
  linkedlist__insert_tail(linkedlist, 6);
  linkedlist__insert_tail(linkedlist, 7);

  int value = linkedlist__delete_node(linkedlist, 3);
  assert_int_equal(value,3);

}

static void test_linkedlist_delete_head(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_tail(linkedlist, 1);
  linkedlist__insert_tail(linkedlist, 2);
  linkedlist__insert_tail(linkedlist, 3);
  linkedlist__insert_tail(linkedlist, 4);
  linkedlist__insert_tail(linkedlist, 5);
  linkedlist__insert_tail(linkedlist, 6);
  linkedlist__insert_tail(linkedlist, 7);

  int value = linkedlist__delete_head(linkedlist);
  assert_int_equal(value,1);

}

static void test_linkedlist_delete_tail(){
  struct LINKEDLIST* linkedlist = linkedlist__new_linkedlist();
  linkedlist__insert_tail(linkedlist, 1);
  linkedlist__insert_tail(linkedlist, 2);
  linkedlist__insert_tail(linkedlist, 3);
  linkedlist__insert_tail(linkedlist, 4);
  linkedlist__insert_tail(linkedlist, 5);
  linkedlist__insert_tail(linkedlist, 6);
  linkedlist__insert_tail(linkedlist, 7);

  int value = linkedlist__delete_tail(linkedlist);
  assert_int_equal(value,7);

}

int main(){
    const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_init_linkedlist),
      cmocka_unit_test(test_linkedlist_is_empty_true),
      cmocka_unit_test(test_linkedlist_is_empty_false),
      cmocka_unit_test(test_linkedlist_insert_head_next),
      cmocka_unit_test(test_linkedlist_insert_head_prev),
      cmocka_unit_test(test_linkedlist_insert_tail_prev),
      cmocka_unit_test(test_linkedlist_delete_node),
      cmocka_unit_test(test_linkedlist_delete_head),
      cmocka_unit_test(test_linkedlist_delete_tail),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
