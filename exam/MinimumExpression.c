#include <stdio.h>

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int minimum_expression(int arr[], int n) {
  int first[n + 1], second[n], third[n - 1];
  int int_max = 99999;
  for (int i = 0; i <= n - 2; i++) {
    first[i] = int_max;
    second[i] = int_max;
    third[i] = int_max;
  }
  first[n - 1] = int_max;
  first[n] = int_max;
  second[n - 1] = int_max;
  // first[n+1] stores the minimal value of A[s]
  int i = 0;
  for (i=n-1;i>=0;i--) {
      first[i] = min(first[i+1], arr[i]);
  }
  for (i=n-2;i>=0;i--) {
      second[i] = min(second[i+1], first[i+1]*arr[i]);
  }
  for (i=n-3;i>=0;i--) {
      third[i] = min(third[i+1], second[i+1]-arr[i]);
  }
  return third[0];
}

int main() {
  int arr[100];
  int i = 0;
  int length = 0;
  printf("Values of the array separated by spaces (non-number to stop): ");
  while (scanf("%d", &arr[i]) == 1) {
    i++;
  }
  length = i;
  int min_val = minimum_expression(arr, length);
  printf("The minimal value is %d\n",min_val);
}