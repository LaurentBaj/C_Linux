#include <stdio.h>


int main () {

	int x = 5;
	int *p = &x;

	printf("Address of x: %d, address of p: %d\n", &x, p);  // Same address

	*p = 6;
	int **q = &p;

        printf("Value of **q is: %d, and *q: %d, q is: %d\n", **q, *q, q);
	// Value of **q is: 6, *q: 1917369252, q is: 1917369256

	**q = *p + 2;
	printf("Value of x is:%d\n", x); // 8
	// Here we are dereferencing the dereference
}
