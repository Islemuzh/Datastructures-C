/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                    *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>

void selectionSort(int A[], int n) {

	int i, j, k;
	int temp;

	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[k])
			{
				k = j;
			}
			
		}
		temp = A[i];
		A[i] = A[k];
		A[k] = temp;
	}
	return;
}

void evenOddSelectionSort(int A[], int n){

	selectionSort(A, n);

	int E[n];
	int O[n];

	int i;
	int j = 0;
	int k = 0;

	for (i = 0; i < n; i++) {
		if (A[i] % 2 == 0) {
			E[j] = A[i];
			j++;
		} else {
			O[k] = A[i];
			k++;
		}
	}

	int l, m;

	printf("\nEven: ");

	for (l = 0; l < j; l++) {
		printf("%d", E[l]);
		printf(", ");
	}

	printf("\nOdd: ");

	for (m = 0; m < k; m++) {
		printf("%d", O[m]);
		printf(", ");
	}
	
	return;
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop):");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");
	
	printf("Result: ");
	evenOddSelectionSort(A, n);
}

// Linux, Mac: gcc task4.c -o task4; ./task4
