#include <stdlib.h>
#include <stdio.h>
#include "../../include/doublylinkedlist.h"

static struct NODE * linkedlist__new_node(int value){
    struct NODE* node = (struct NODE*) malloc(sizeof(struct NODE));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

struct LINKEDLIST * linkedlist__new_linkedlist(){
    struct LINKEDLIST* linkedlist = (struct LINKEDLIST* ) malloc(sizeof(struct LINKEDLIST));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->size = 0;

    return linkedlist;
}

int linkedlist__is_empty(struct LINKEDLIST * linkedlist){
    return linkedlist->size == 0;
}

void linkedlist__insert_head(struct LINKEDLIST * linkedlist, int value){
    struct NODE * node = linkedlist__new_node(value);

    if(linkedlist__is_empty(linkedlist)){
        linkedlist->head = linkedlist->tail = node;
    }

    else if(linkedlist->size == 1){
        struct NODE **head = &linkedlist->head;
        struct NODE **tail = &linkedlist->tail;
        *head = node;
        (*head)->next = (*tail);
        (*tail)->prev = (*head);
    }

    else{
        struct NODE **head = &linkedlist->head;
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    }

    linkedlist->size++;
}

void linkedlist__insert_tail(struct LINKEDLIST * linkedlist, int value){
    struct NODE * node = linkedlist__new_node(value);

    if(linkedlist__is_empty(linkedlist)){
        linkedlist->head = linkedlist->tail = node;
    }
    else if(linkedlist->size == 1){
        struct NODE **head = &linkedlist->head;
        struct NODE **tail = &linkedlist->tail;
        *tail = node;
        (*tail)->prev = (*head);
        (*head)->next = (*tail);
    }    
    else{
        struct NODE **tail = &linkedlist->tail;
        node->prev = *tail;
        (*tail)->next = node;
        *tail = node;
    }

    linkedlist->size++;
}

int linkedlist__delete_node(struct LINKEDLIST * linkedlist, int value){

    if(linkedlist__is_empty(linkedlist)){return -1;}

    int data;
    if(linkedlist->head->value == value){
        data = linkedlist__delete_head(linkedlist);
        return data;
        
    }
    else if(linkedlist->tail->value == value){
        data = linkedlist__delete_tail(linkedlist);
        return data;
    }
    else {
        struct NODE * traversal = linkedlist->head;
        while(traversal !=NULL){
            if(traversal->value == value){
                traversal->prev->next = traversal->next;
                traversal->next->prev = traversal->prev;
                linkedlist->size--;
                data = traversal->value;
                free(traversal);
                return data;
            }
            traversal = traversal->next;
        }
    }
    return -1;  
}

int linkedlist__delete_head(struct LINKEDLIST * linkedlist){

    if(linkedlist__is_empty(linkedlist)){printf("Linkedlist empty"); return -1;}

    else {
        int data = linkedlist->head->value;
        struct NODE * head = linkedlist->head;
        linkedlist->head = head->next;
        linkedlist->head->prev = NULL;
        linkedlist->size--;
        free(head);
        return data;
    }
    
     
}

int linkedlist__delete_tail(struct LINKEDLIST * linkedlist){
    
    if(linkedlist__is_empty(linkedlist)){printf("Linkedlist empty"); return -1;}

    else {
        int data = linkedlist->tail->value;
        struct NODE * tail = linkedlist->tail;
        linkedlist->tail = tail->prev;
        linkedlist->tail->next = NULL;
        linkedlist->size--;
        free(tail);
        return data;
    }
}


void linkedlist__clear_node(struct NODE** head)
{
    printf("Deleting %d\n", (*head)->value);
    if (*head == NULL) {
        return;
    }
 
    if ((*head)->next) {
        linkedlist__clear_node(&((*head)->next));
    }
 
    free(*head);
 
    *head = NULL;
    
}

void linkedlist__destroy(struct LINKEDLIST **linkedlist){
    linkedlist__clear_node(&(*linkedlist)->head);
    (*linkedlist)->size = 0;
    free(*linkedlist);
    *linkedlist = NULL;
}

void linkedlist__display(struct LINKEDLIST *linkedlist){
    struct NODE * traversal = linkedlist->head;
    while(traversal!=NULL){
        printf("%d <-> ", traversal->value);
        traversal = traversal->next;
    }
    printf("NULL");
}