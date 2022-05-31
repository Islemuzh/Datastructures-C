#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------
|   Hashing with chaining
|
|
*----------------------------------------------------------------*/


#define m 365

struct Node {
    int data;
    struct Node *next;
};

struct Node *HT[m];

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

int calculateListLength(struct Node *head) {
    int length = 0;
    struct Node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

struct Node *insertList(struct Node *head, int data) {
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

void printHashTable() {
    int i;
    printf("Table size %d\n", m);
    for (i = 0; i < m; i++) {
        if (HT[i] != NULL) {
            printf("i: %d\t, length: %d\t", i, calculateListLength(HT[i]));
            displayList(HT[i]);
        }
    }
}

int hash(int key) {

    return key % m;
}

void insertHT(int value) {
    HT[hash(value)] = insertList(HT[hash(value)], value);
}

//sets pointer to NULL, but nodes are still in memory, would have to free() all
void clearHT() {
    int i;
    for (i = 0; i < m; i++) {
        HT[i] = NULL;
    }
}


// exercise

int find_num_shared_birthday() {
    int i = 0;
    int length;
    int num_shared_birthday = 0;
    for (i = 0; i < m; i++) {
        if (HT[i] != NULL) {
            length = calculateListLength(HT[i]);
            if (length > 1) {
                num_shared_birthday += 1;
            }
        }
    }
    return num_shared_birthday;
}

int find_num_people_with_shared_birthday() {
    int i = 0;
    int length;
    int num_shared_birthday = 0;
    for (i = 0; i < m; i++) {
        if (HT[i] != NULL) {
            length = calculateListLength(HT[i]);
            if (length > 1) {
                num_shared_birthday += length;
            }
        }
    }
    return num_shared_birthday;
}

int main() {

    srand(time(NULL));
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    insertHT(rand());
    printHashTable();
    printf("%d\n", find_num_people_with_shared_birthday());
    printf("%d\n", find_num_shared_birthday());
    return 0;
}