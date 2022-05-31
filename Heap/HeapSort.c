#include <stdio.h>


int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void heapify(int A[], int i, int s) {
    int m = i;
    int l = left(i);
    int r = right(i);
    int temp;

    if (l <= s && A[l] > A[m]) {
        m = l;
    }
    if (r <= s && A[r] > A[m]) {
        m = r;
    }
    if (i != m) {
        temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        heapify(A, m, s);
    }
}


void buildHeap(int A[], int n) {
    for (int i = n/2; i >= 0; i--) {
        heapify(A, i, n);
    }
}


void heapSort(int A[], int n) {
    int s = n;
    int temp;

    buildHeap(A, n);

    for (int i = n; i >= 1; i--) {
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        s--;
        heapify(A, 0, s);
    }

    for(int j = 0; j <= n; j++) {
        printf("%d ", A[j]);
    } 
}

void main(){
    int A[100] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
    int n = 9;
 
    return heapSort(A, n);
}


//extras

void heapify_d(int A[], int i, int n, int d) {
    int max = i;

    // checking d children nodes from right to left
    for(int j = d*i+d; j > d*i; j--) {
        if(j < n && A[max] < A[j]) {
            max = j;
        }
    }

    if(max != i) {
        int tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;

        heapify_d(A, max, n, d);
    }

}


void buildMaxHeap(int A[], int n) {
    for(int i = (n/2)-1; i >= 0; i--) {
        heapify(A,i,n);
    }
}

void buildMaxHeap_d(int A[], int n, int d) {
    for(int i = (n/d)-1; i >= 0; i--) {
        heapify_d(A, i, n, d);
    }
}