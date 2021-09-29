#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

	int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);
        int d = atoi(argv[4]);

	int *ptr1 = &a;
        int *ptr2 = &b;
        int *ptr3 = &c;
        int *ptr4 = &d;

	int array[2][2] ={ {*ptr1, *ptr2}, {*ptr3, *ptr4} }; 

	int j, i;
	for (i = 0; i < 2; i++) {

		for (j = 0; j < 2; j++) {
			printf("%d\n", (array[i][j]));
		}
	}

	return 0;
}
