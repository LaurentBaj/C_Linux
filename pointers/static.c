#include <stdio.h>



int Square(int x);
int SquareOfSum(int x, int y);



// Global Memory - Exists in Static/Global stack of the App Memory
int total; 



/* All these below run on frames on the stack memory*/
int main()  // Main frame/stack
{
	int a=2, b=3;
	total = SquareOfSum(a, b);
	printf("Result: %d\n", total);
}


int Square(int x)  // New stack - runs first after main starts
{
	return (x*x);
}

int SquareOfSum(int x, int y)  // New stack - runs afterwards
{
	return Square(x * y);
}


