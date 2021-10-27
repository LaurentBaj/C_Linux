#include <stdio.h>


// Unlike structs, unions do not increase in size since they don't store 
// each value correctly. The last change to the union is stored


typedef union INTFLOAT
{
    int i;
    float f; 
} INTFLOAT; 



int main()
{
    INTFLOAT intfloat;
    intfloat.f = 3.14; 

    printf("%f - %d\n", intfloat.f, intfloat.i); // 3.14 - address
    printf("%d\n", sizeof(intfloat)); // 4


    intfloat.i = 2; 
    printf("%f - %d\n", intfloat.f, intfloat.i); // 0.00 - 2
    printf("%d\n", sizeof(intfloat)); // 4
}