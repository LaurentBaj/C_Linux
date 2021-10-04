#include <stdio.h>


int main() {

	int A[] = {2, 4, 6, 8, 9};

	int *p = &A[0];

	printf("Value at the start is: %d\n", *p); // 2

	// We can dereference the next value in the array
        printf("Value at the second index is: %d\n", *(p + 1)); // 4

	// We can also do this:
	p = A; 
	printf("Value at the start is: %d\n", *p); // 2
	printf("Value at the start is: %d\n", *A); // 2
	printf("Value at the start is: %d\n", *(A + 1)); // 4
	// When we refer to the array then we refer to the base index

	printf("&A is: %d, &A[0] is: %d\n", &A, &A[0]);

	p++;
	printf("Value of *p now is: %d\n", *p); // 4
	// We've now jumped one byte ahead and p points to the next val
}
