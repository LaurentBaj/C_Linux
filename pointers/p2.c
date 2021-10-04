#include <stdio.h>



int main() {

	int a = 2; // a = 2
	int b = a; // b = 2;

	int *p = &a; // 
	int sizeOfInt = sizeof(int); // 4 (bytes)
	// This means that a occupies four bytes

	int p0 = p; // 201
	int p1 = p + 1; // 205
	// Since a is int - memloc of p + 1 = 201 + 4

	printf("value of a: %d, b: %d, *p: %d\n", a, b, *p); // 2, 2, 2
	printf("Value of sizeInt: %d\n", sizeOfInt); // 4
	printf("p is %d, p0 is %d, p1: %d\n", p, p0, p1); // 200 200 204

	// p or p0 reffers to first byte of a - 00000000 00000000 000000000 >000000100
	// value of *p or *p0
	// p1 reffers to last byte of a -  >00000000 00000000 000000000 000000100
	// value of *p1 is therefore nothing (garbage val)

	char *q = (char*)p; // Type casting
	// We can't do this :
	// char *q = p;
	// *q reffers to val of second byte of p - 00000000 00000000  >000000000 000000100
	// *q is therefore nothing (garbage val)

        printf("Value of *q is first byte of a: %d\n", *q); // 2
	printf("Value of *(q + 1) is second byte a: %d\n", *(q + 1)); // 0
        printf("Value of *(q + 2) is third byte a: %d\n", *(q + 2)); // 0
        printf("Value of *(q + 3) is fourth byte a: %d\n", *(q + 3)); // 0

	// We change the value of a (dereference)
	*p = 257; // 0000000 00000000 00000001 00000001
	printf("Value of *q is first byte a: %d\n", *q); // 1
        printf("Value of *(q + 1) is second byte a: %d\n", *(q + 1)); // 1
        printf("Value of *(q + 2) is third byte a: %d\n", *(q + 2)); // 0
        printf("Value of *(q + 3) is fourth byte a: %d\n", *(q + 3)); // 0
}
