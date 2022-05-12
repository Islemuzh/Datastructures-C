#include <stdio.h>


int lomutoPartition(int A[], int l, int r) {
    int x = A[r];
    int i = l - 1;
    int temp;

    for (int j = l; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}

int hoarePartition(int A[], int l, int r) {
    int x = A[r];
    int i = l - 1;
    int j = r + 1;
    int temp;

    while (1) {
        while (A[j] > x) {
            j--;
        }
        while (A[i] < x) {
            i++;
        }
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        } else {
            return i;
        }
    }

}

void quickSort(int A[], int l, int r) {
    if (l < r) {
        int m = lomutoPartition(A, l, r);
        quickSort(A, l, m-1);
        quickSort(A, m+1, r);
    }
}

void main() {
    int A[100] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
    int l = 0;
    int r = 9;

    quickSort(A, l, r);

    for(int j = 0; j <= r; j++) {
        printf("%d ", A[j]);
    } 
}