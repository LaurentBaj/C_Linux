#include <stdio.h>

typedef struct // 48 bytes
{
	// Each property, no matter type, requires 8 bytes
	double length, width; // 8 bytes each, even if it was Int
	char name[30]; // requires 32 bytes
} rectangle;

typedef struct circle // 20
{
	int array[5]; // occupies 20 bytes
} circle;

typedef struct all // 72 = 48 + 20 + ?
{
	struct rectangle r;
	struct circle c;
} all;

int main()
{

	// if we ignorre 'typedef' then we have to do -> struct rectangle r1 = {5, 7};
	rectangle r1 = {5.3, 7.3, "Laurent"};
	printf("Length of r1: %f, Width of r1: %f\n", r1.length, r1.width); // Length of r1: 5.300000, Width of r1: 7.300000
	printf("r1 name: %s\n", r1.name); // r1 name: Laurent 
	printf("Size of Rectangle in bytes: %ld\n", sizeof(rectangle)); // Size of struct in bytes: 48
        printf("Size of double in bytes: %ld\n", sizeof(double));  // 8

	circle c1 = {2, 4, 6, 1, 34};
	printf("c1.array[1] is: %d\n", c1.array[1]); // 4
	printf("Size of circle struct %ld\n", sizeof(circle)); // 20 (one for each int)

	all a1 = {r1, c1};
	printf("Size of a1: %ld\n", sizeof(a1));
}
