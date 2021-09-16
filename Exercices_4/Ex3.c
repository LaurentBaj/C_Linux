#include <stdio.h>


int main() {
	int a,b;
	printf("Type two integers seperated with space\n");

	int *p = &a;
	int *q = &b;

	scanf("%d %d", p, q);
	printf("The numbers are %d, %d \n", *p, *q);

	return 0; 
}
