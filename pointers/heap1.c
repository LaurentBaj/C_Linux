#include <stdio.h>
#include <stdlib.h>


int main()
{

	int a = 2; // goes on stack
	int *p;
	int i = 0;

	// Allocates enough mem for one int from HEAP
	// Return memory address of value stored on H
	p = (int*)malloc(sizeof(int));
	*p = 3;
	printf("*p is: %d\n", *p);  // 3

	// We can also free this and allocate more mem to pointer
	free(p);
	p = (int*)malloc(20 * sizeof(int)); // Allocate 20*4 bytes (int array)


	int *c = p + 20; // Memory address of last index
	while(p < c)
	{
		*p = (i * 2);
	        printf("Value of p[%d]: %d\n", i, *p);
		p++; i++;
	}
}
