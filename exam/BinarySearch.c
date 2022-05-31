#include <stdio.h>
#include <stdlib.h>

int binarySearch(int l, int r, int A[], int k) {
  if (l > r){ //terminating condition
      return -1;
  }
  int mid = (l + r) / 2;
  if (A[mid] == k){ //if its the element we are looking for
      return mid;
  }
  if (A[mid] < k){ //if we are left to the element
      return binarySearch(mid+1, r, A, k);
  }
  if (A[mid] > k){ //if we are right to the element
      return binarySearch(l, mid-1, A, k);
  }
}

int main() {
  int n = 7;
  int k = 10;
  int A[7] = {1, 4, 6, 7, 8, 10, 12}; 
  printf("k = %d\n", k);
  printf("index of value k = %d\n", binarySearch(0,(n-1), A, k));
}