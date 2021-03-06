#include <stdio.h>
#include <stdlib.h>


// Realloc realocates values from one array to another
// You can, by your self, change the size of the new array


int main()
{
	int n;
	printf("Enter size of array\n");
	scanf("%d", &n);
	int *A = (int*)malloc(sizeof(int) * n);

	// Populate A
	for(int i = 0; i < n; i++) { A[i] = (i + 1); }

	// New array  B - Twice the size of A - populated with half of vals from A
        int *B = (int*)realloc(A, 2*n*sizeof(int));

	// Print B
	for(int i = 0; i < (2 * n); i++) { printf("%d\n", B[i]); }
	/* If we input 4 - B will in this case have 8 slots
	   Everything after index 3 will be garbage values

		1
		2
		3
		4
		0 - garbage
		0 - garbage
		132401 - garbage
		0 - garbage

	   We could define the size of B however we'd like
           and would only copy over a number of items from A
	   based on the size of B
	*/
}
