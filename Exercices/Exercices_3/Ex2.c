#include <stdio.h>


int main() {	

	int a, b, c, d;

	a = 5; 
	b = a++; 
	c = ++b; 
	d = b++; 	

	printf("%d\n", a); // 6
        printf("%d\n", b); // 7
        printf("%d\n", c); // 6
        printf("%d\n", d); // 6


	int x, y, z, w; 

	x = 10;
	y = 9;
	z = 8; 
	w = 7;

	if((x==y++) && (z==++x)){
        	w = 100;
        	printf("This is obviously true");
	}
	z = ++w+y++;  // 18

	printf("\n%d\n", x); // 10 
        printf("%d\n", y); // 11
        printf("%d\n", z); // 18
        printf("%d\n", w); // 8


	return 0;
}
