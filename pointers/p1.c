#include <stdio.h>


int main() {

	int a = 2;
	int *p = &a;

	printf("Value of a: %d, *p: %d\n", a, *p); // Value of a: 2, *p: 2
	printf("Value of &a: %x, p: %x\n", &a, p); // Value of &a: bcc6ca8c, p: bcc6ca8c


	*p = 134; // Changes val of a

	printf("Value of a: %d, *p: %d\n", a, *p); // Value of a: 134, *p: 134
        printf("Value of &a: %x, p: %x\n", &a, p); // Value of &a: bcc6ca8c, p: bcc6ca8c
}
