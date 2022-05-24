#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------
//Reverse a LinkedList, head and tail are given as a node list
//----------------------------------------------------------------

struct list {
    struct node* head;
    struct node* tail;
};

struct node {
    int val;
    struct node* next;
};

void reverseList(struct list* l) {
    struct node* curr = l->head;
    struct node* tmp = NULL;
    l->tail = l->head;
    l->head = NULL;

    while (curr != NULL) {
        tmp = curr->next;
        curr->next = l->head;
        l->head = curr;
        curr = tmp;
    }
}