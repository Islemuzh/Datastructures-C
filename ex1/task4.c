/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 4                                     *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

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

void gap_timestamps(int A[], int n){

	int i;
	int gap = 0;
	int curr_gap;

	selectionSort(A, n);

	for (i = 0; i < n - 1; i++) {
		curr_gap = A[i+1] - A[i];
		if (curr_gap > gap) {
			gap = curr_gap;
		}
	}

	printf("%d", gap);


	return;
}

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}

	gap_timestamps(timestamps, pos);


	return 0;
}