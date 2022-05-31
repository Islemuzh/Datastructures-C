#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*----------------------------------------------------------------
|   Double Hashing
|
|
*----------------------------------------------------------------*/


#define m 7  //Change value m to size of hash table
#define OCC 0
#define EMP -1
#define DEL -2

struct HTElement {
    int value;
    int status;  //OCC or EMP or DEL
};

void init(struct HTElement A[]){
    for (int i = 0; i < m; i++) {
        A[i].value = 0;
        A[i].status = EMP;
    }
}

int hash(int k, int i) {

    int h1 = ((k % m) + 1);
    int h2 = ((m - 1) - (k % (m - 1)));
    return (int) (h1 + i * h2) % m;
}

void insert(struct HTElement A[], int key) {
    int counter = 0;
    int hkey;
    do {
        hkey = hash(key, counter);
    } while (A[hkey].status == OCC && counter++ < m);
    A[hkey].value = key;
    A[hkey].status = OCC;
}

void delete(struct HTElement A[], int key) {
    int counter = 0;
    int hkey;
    do {
        hkey = hash(key, counter);
        if (A[hkey].value == key) {
            A[hkey].status = DEL;
        }
    } while (A[hkey].value != key && A[hkey].status == OCC && counter++ < m);
}

int search(struct HTElement A[], int key) {
    int counter = 0;
    int hkey;
    do {
        hkey = hash(key, counter);
    } while (A[hkey].value != key && A[hkey].status == OCC && counter++ < m);
    if (A[hkey].value == key) {
        return hkey;
    } else {
        return -1;
    }
}

void printHashTable(struct HTElement A[]) {
    int i;
    printf("Table size: %d\n", m);
    for (i = 0; i < m; i++) {
        if (A[i].status == OCC) {
            printf("i: %d\tkey: %d\n", i, A[i].value);
        }
    }
}

int main() {

    struct HTElement A[m];

    init(A);

    insert(A, 5);
    insert(A, 1);
    insert(A, 12);
    insert(A, 4);
    insert(A, 24);
    insert(A, 9);
    insert(A, 8);

    printHashTable(A);

    printf("The key you are looking for is at hkey: %d", search(A, 4));

    return 0;
}