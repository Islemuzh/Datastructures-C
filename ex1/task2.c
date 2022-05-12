/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2                                                      *
 *                                                                          *
 * @author Islem                                                      		*
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

void count_vowels(char A[]) {

	int i;
	int nr_of_vowels = 0;

	for (i = 0; i < strlen(A); i++) {
		if (A[i] == 'A' || A[i] == 'a' || A[i] == 'E' || A[i] == 'e' || A[i] == 'I' || A[i] == 'i' || A[i] == 'O' || A[i] == 'o' || A[i] == 'U' || A[i] == 'u')
		{
			nr_of_vowels++;
		}
		
	}

	printf("%d", nr_of_vowels);

	return;
}

void BS(char A[]) {

	int i;
	int k = 0;
	char B[MAX_LENGTH + 1];

	for (i = 0; i < strlen(A); i++) {
		if (A[i] == 'A' || A[i] == 'a' || A[i] == 'E' || A[i] == 'e' || A[i] == 'I' || A[i] == 'i' || A[i] == 'O' || A[i] == 'o' || A[i] == 'U' || A[i] == 'u')
		{
			B[k] = A[i];
			B[k+1] = 'b';
			B[k+2] = A[i];
			k = k + 3;

		} else {
			B[k] = A[i];
			k++;
		}
		
		
	}

	int j;

	for (j = 0; j < strlen(B); j++) {
		printf("%c", B[j]);
	}
	

	return;
}

int main() {
	char input_string[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", input_string);

	//count_vowels(input_string);
	BS(input_string);


	return 0;
}


