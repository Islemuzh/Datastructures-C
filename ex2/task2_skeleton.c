/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

// TODO: your implementation
int second_smallest_rec(int arr[MAX_LENGTH], int i, int pos) {
	if (i == 2)
	{
		printf("%d", arr[1]);
		return arr[1];
	}
	else
		{
		int i, j, k;
		int temp;

		k = i;
		for (j = i + 1; j <= pos; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}

		}
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;

		return second_smallest_rec(arr, i+1, pos);

	}
}


int main() {
	printf("Values of array separated by spaces (non-number to stop): ");
	int arr[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &arr[pos]) == 1) {
		pos++;
	}
	// variable pos will contain number of integers read in from user

	// TODO: your implementation
	int i = 0;
	int res = second_smallest_rec(arr, i, pos);
	return res;
}
