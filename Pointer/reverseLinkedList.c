#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------
//head and tail are given as a node list
//----------------------------------------------------------------

struct list {
    struct node* head;
    struct node* tail;
};

struct node {
    int val;
    struct node* next;
};

//----------------------------------------------------------------
//Reverse LinkedList
//----------------------------------------------------------------

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

//----------------------------------------------------------------
//Split LinkedList into even and odd list
//----------------------------------------------------------------

void even_odd_split(struct list* l, struct list* o, struct list* e) {
    struct node* curr = l->head;

    while (curr != NULL) {
        if (curr->val % 2 == 0) {
            if (e->head == NULL) {
                e->head = curr;
            } else {
                e->tail->next = curr;
            }
            e->tail = curr;
            curr = curr->next;
            e->tail->next = NULL;
        } else {
            if (o->head == NULL) {
                o->head = curr;
            } else {
                o->tail->next = curr;
            }
            o->tail = curr;
            curr = curr->next;
            o->tail->next = NULL;
        }
    }
    l->head = NULL;
}