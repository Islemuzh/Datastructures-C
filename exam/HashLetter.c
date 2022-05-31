#include <math.h>
#include <stdio.h>
#include <string.h>

#define m 7

void init(int A[]) {
  int i;
  for (i = 0; i < m; i++) { 
    A[i] = 0; 
  }
}

int h(int k, int i) {
  int h1 = (k % m) + 1;
  int h2 = (m-1)-(k % (m-1));
  return (int)(h1 + i * h2) % m;
}

void insert(int A[], int key) {
  int counter = 0;
  int hkey;
  do {
    hkey = h(key, counter);
  } while(A[hkey] != 0 && counter++ < m);
  A[hkey] = key;
}

int search(int A[], int key) {
  int counter = 0;
  int hkey;
  do {
    hkey = h(key, counter);
  } while(A[hkey] != key && A[hkey] != 0 && counter++ < m);
  if (A[hkey] == key) { return hkey; }
	else { return -1; }
}

void printHash(int A[]) {
  int i;
  printf("Table size: %d\n", m);
  for (i = 0; i < m; i++) {
    if (A[i] != 0) {
      printf("i: %d\tkey: %d\n", i, A[i]);
    }
  }
}

int shareLetters(char* s, char* t) {
  int len_s = strlen(s), len_t = strlen(t);
  int A[26];
  init(A);

  for (int i = 0; i < len_s; ++i) {
    insert(A, s[i]);
  }
  for (int i = 0; i < len_t; ++i) {
    if (search(A, t[i]) == -1) {
      return 0;
    }
  }

  init(A);

  for (int i = 0; i < len_t; ++i) {
    insert(A, t[i]);
  }
  for (int i = 0; i < len_s; ++i) {
    if (search(A, s[i]) == -1) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int A[m];
  init(A);

  printf("%d\n", shareLetters("tea", "ate"));
  printf("%d\n", shareLetters("rat", "car"));
  printf("%d\n", shareLetters("abcd", "abc"));
  printf("%d\n", shareLetters("abc", "abcd"));
  printf("%d\n", shareLetters("abc", "aabbcc"));
}
