#include <stdio.h>

int main() {
    //Input: Array A with n integers
    int n = 5;
    int A[] = {4, 1, 8, 5, 3};

    int i, j, temp;

    for (i = n; i > 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (A[j] < A[j-1])
            {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
            
        }
        
    }
    //Output: Second largest integer in Array A
    printf("%d\n", A[n-2]);
    
}