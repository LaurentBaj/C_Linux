#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b);
void Print(int A[], int length);
void bubbleSort(char **inputs, int A[], int length, int inputLength);
void toIntArray(char **A, int B[], int length);


int main(int argc, char *argv[])
{
	int array[argc - 1];
	bubbleSort(argv, array, argc-1, argc);
}

// Sort Int Array based on user input
void bubbleSort(char **inputs, int A[], int length, int inputLength)
{
        toIntArray(inputs, A, inputLength);
	for (int i=0; i<length; i++)
	{
        	for (int j=0; j<(length-1); j++)
	        {
	 	       if (A[j] > A[j+1]) swap(&A[j], &A[j+1]);
	        }
	}
	Print(A, length);
}

// Map Char array to empty int Array
void toIntArray(char **A, int B[], int length)
{
	for (int i = 1; i < length; i++)
        {
                B[i-1] = atoi(*(A+i));
        }
}

// Swap two indexes in array
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Print sorted array
void Print(int A[], int length)
{
	for (int i=0; i<length; i++)
        {
                printf("%d\n", A[i]);
        }
}
