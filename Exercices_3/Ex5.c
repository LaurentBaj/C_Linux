#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	/*	Create random number 
	srand(time(NULL));
	int a = rand() % 100;
	printf("%d", a)*/;
	

	int i, j; 
	for (i = 2; i < 20; i++) {
		for (j = 2; j < 20; j++) {
			if (i % j ==  0) {
				if (i == i) {}
				else {
					printf("\n%d is not a prime\n", i); 
					break; 
				}
			}
		}
	}


	return(0);
}


