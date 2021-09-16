
#include <stdio.h>

int a, b;  // Static memory

void main (void)
{
   int i, j;
   printf("Addresses of global variables: %p %p\n", &a, &b); // Stick memory
   printf("Addresses of local variables: %p %p\n", &i, &j); // Stick memory
}

