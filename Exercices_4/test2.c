#include <stdio.h>


int main(int argc, char *argv[]) {
	int a = 5;
	int *aPtr = &a;

	printf("Value of a = %d \n", a); // 5
        printf("Value of *aPtr = %d \n", *aPtr); //5
        printf("Value of aPtr  = %x \n", aPtr); // Memory location

	return 0;
}
