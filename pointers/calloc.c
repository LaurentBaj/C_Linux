#include <stdio.h>
#include <stdlib.h>


int main()
{
	// Each index has a default val of 0 with Calloc

        int *p;
        int i = 1;

        // Allocates enough mem for one int from HEAP
        // Return memory address of value stored on H
        p = (int*)malloc(sizeof(int));
        *p = 3;
        printf("*p is: %d\n", *p);  // 3

        // We can also free this and allocate more mem to pointer
        free(p);
        p = (int*)calloc(20, sizeof(int)); // Allocate 20*4 bytes (int array)

        int *c = p + 20; // Memory address of last index
        while(p < c)
        {
                printf("Value of p[%d]: %d\n", i, *p);
                p++; i++;
        }
}

/*
*p is: 3
Value of p[1]: 0
Value of p[2]: 0
Value of p[3]: 0
Value of p[4]: 0
Value of p[5]: 0
Value of p[6]: 0
Value of p[7]: 0
Value of p[8]: 0
Value of p[9]: 0
Value of p[10]: 0
Value of p[11]: 0
Value of p[12]: 0
Value of p[13]: 0
Value of p[14]: 0
Value of p[15]: 0
Value of p[16]: 0
Value of p[17]: 0
Value of p[18]: 0
Value of p[19]: 0
Value of p[20]: 0
*/
