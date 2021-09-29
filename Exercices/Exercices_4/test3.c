#include <stdio.h>

int main() {
	int a, b;
	int *aPtr = &a;
	int *bPtr = &b; 

	printf("Print two integers seperated by a space\n");
	scanf("%d %d", aPtr, bPtr); // Put input into these mem-locations
	printf("Input 1: %d, Input 2: %d \n", *aPtr, *bPtr);

	return 0;
}
