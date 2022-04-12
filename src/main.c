#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedlist.h"

/**
 * @brief Main program
 *
 * @return int
 */

int main(){

   struct LINKEDLIST * linkedlist = linkedlist__new_linkedlist();

   linkedlist__insert_head(linkedlist, 1);
   linkedlist__insert_head(linkedlist, 2);
   linkedlist__insert_head(linkedlist, 3);
   linkedlist__insert_head(linkedlist, 4);
   linkedlist__insert_head(linkedlist, 5);
   linkedlist__insert_head(linkedlist, 6);
   linkedlist__insert_head(linkedlist, 7);

   

   linkedlist__destroy(&linkedlist);

   printf("%p", linkedlist);




   return 0;
}
