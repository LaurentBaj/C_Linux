#include <stdio.h>
#include <stdlib.h>



int *Add(int *a, int *b) 
{
	int *c = (int*)malloc(sizeof(int)); // This is better
	*c = (*a) + (*b);
	// int c = (*a + *b); We can't do this - read below
	return c;
}


int main() 
{

	int a=2, b=3;
	int *ptr = Add(&a, &b); // Only works with heap alloc, not stack
	printf("%d\n", *ptr);

	/*
		This does not work since when add returns the address
		of c, then main stores the address but the address does 
		not have a value since Add is popped of the stack 

		We can use Malloc to allocate space to heap instead
	*/
}
