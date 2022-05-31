#include <stdio.h>

void move(int array[100], int n, int m) {
  int * p, array_end;
  array_end = * (array + n - 1);
  for (p = array + n - 1; p > array; p--) {
    *p = *(p - 1);
  }
  *array = array_end;
  m--;
  if (m > 0) {
    move(array, n, m);
  }
}

int main() {
  int n, m, i;
  int numbers[100] = {12, 43, 65, 67, 8, 2, 7, 11};
  n = 8;
  m = 4;
  move(numbers, n, m);
  for (i=0;i<n;i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  return 0;
}