#include <stdio.h>


int main () {
   int a = 2; 
   printf("%d\n", a);  // Prints value of var
   
   // Point to memory location of a var
   // * shows that is is a pointer - & point to address 
   int *pointer = &a; 
   printf("The memory location of a is %x\n", pointer); // %x gives hex - returns address in mem 

   // Get value of a by pointing to the pointer of a
   printf("Value of a is %d\n", *pointer); 

   // Change the value using 
   *pointer = 21; 
   printf("The pointer points to the value of a which is %d and %d\n", a, *pointer); 
   return 0; 
} 
