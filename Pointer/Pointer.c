#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertList(struct Node *head, int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        return head;
    } else {
        struct Node *newNode = malloc(sizeof(struct Node));
        struct Node *current = head;
        newNode->data = data;
        newNode->next = NULL;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
  }
}

void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->next != NULL) {
            printf(" %d ->", current->data);
        } else {
            printf(" %d", current->data);
            printf("\n");
        }
        current = current->next;
  }
}

struct Node* groupingLinkedList(struct Node *head) {
  struct Node *odd = NULL;
  struct Node *even = NULL;
  struct Node *groupedList = NULL;
  struct Node *current = head;

  while (current != NULL) {
    if (current->data % 2 == 0) {
      even = insertList(even, current->data);
    } else {
      odd = insertList(odd, current->data);
    }
    current = current->next;
  }
  groupedList = odd;
  current = groupedList;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = even;
  return groupedList;
}


void swap_nodes(struct Node *prev, struct Node *cur) {
  // before swap: prev->cur->ne->temp
  // after swap: prev->ne->cur->temp
  struct Node * ne = cur->next;
  struct Node * temp = ne->next;
  prev->next = ne;
  ne->next = cur;
  cur->next = temp;
  return;
}

/* Bubble sort the given linked list */
struct Node * bubbleSort(struct Node *head) {

  /* early termination */
  if (head == NULL || head->next == NULL) return head;

  struct Node *dummy = malloc(sizeof(struct Node));
  dummy->next = head;
  struct Node *last = NULL;

  while(dummy->next != last){
    struct Node * prev = dummy;
    struct Node * cur = prev->next;
    while(cur->next != last) {
      if(cur->data > cur->next->data) {
        swap_nodes(prev, cur); // after swap, j = j->next;
      } else {
        cur = cur->next;
      }
      prev = prev->next;
    }
    last = cur; // elements from last are sorted.
  }
  head = dummy->next;
  free(dummy); // delete dummy node 
  return head;
}

void isAnagram(struct Node *s1, struct Node *s2) {
  struct Node *s1_cur = s1;
  struct Node *s2_cur = s2;
  while (s1_cur != NULL) {
    if (s1_cur->data != s2_cur->data) {
      printf("letter in s1 '%c' is not the same as in s2 '%c'.\n", s1_cur->data,
             s2_cur->data);
      printf("Not Anagram!\n");
      return;
    }
    s2_cur = s2_cur->next;
    s1_cur = s1_cur->next;
  }
  printf("Anagram!\n");
}

void main() {
    struct Node *s1 = NULL;
    s1 = insertList(s1, 1);
    s1 = insertList(s1, 5);
    s1 = insertList(s1, 7);
    s1 = insertList(s1, 12);
    s1 = insertList(s1, 14);
    s1 = insertList(s1, 15);
    displayList(s1);

    struct Node *s2 = NULL;
    s2 = insertList(s2, 5);
    s2 = insertList(s2, 1);
    s2 = insertList(s2, 15);
    s2 = insertList(s2, 12);
    s2 = insertList(s2, 14);
    s2 = insertList(s2, 7);
    displayList(s2);

    //struct Node *glist = groupingLinkedList(s1);
    //displayList(glist);

    s1 = bubbleSort(s1);
    s2 = bubbleSort(s2);
    isAnagram(s1, s2);
    displayList(s1);
    displayList(s2);
}