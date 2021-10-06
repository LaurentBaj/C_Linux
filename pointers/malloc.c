#include <stdio.h>
#include <stdlib.h>


int main()
{

	int a = 2; // goes on stack
	int *p;
	int i = 1;

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

/*
*p is: 3
Value of p[1]: 2
Value of p[2]: 4
Value of p[3]: 6
Value of p[4]: 8
Value of p[5]: 10
Value of p[6]: 12
Value of p[7]: 14
Value of p[8]: 16
Value of p[9]: 18
Value of p[10]: 20
Value of p[11]: 22
Value of p[12]: 24
Value of p[13]: 26
Value of p[14]: 28
Value of p[15]: 30
Value of p[16]: 32
Value of p[17]: 34
Value of p[18]: 36
Value of p[19]: 38
Value of p[20]: 40
*/

