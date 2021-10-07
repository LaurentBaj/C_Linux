#include<stdio.h>



int Add(int a, int b)
{
	return a + b;
}


void PrintHello(char *name)
{
	printf("Hello, %s\n", name);
}


int main()
{
	int x=2, y=3;
	int (*p) (int, int); // func pointer
	p = Add;
	printf("%d\n", p(x, y));

	void (*ptrHello)(char*);
	ptrHello = PrintHello;
	ptrHello("Laurent"); 

}


/* Output:
	5
	Hello, Laurent
*/

