#include <stdio.h>



// The address of a is not the same as the variable passed to it
// We can only alter a var within the stack it exists
// When main function (in stack) reaches increment1, it performs the operation on another var
// Then the stack pops (having done nothing to the contents of main) and main function continues
void increment1(int x) { x = x+1; }


// With a return type we can directly alter variable passed to it
int increment2(int x) { return x+1; }



// We can refer to a variable in main from another stack if we have its address
void incrementByReference(int *x) {
	*x = *x + 1;
}


int main() {

	int a  = 2;
	increment1(a); // Does nothing - Call by value
	printf("Value of a: %d\n", a); // 2

	a = increment2(a);
	printf("Value of a: %d\n", a); // 3

	int b = 2;
	incrementByReference(&b); // Call by reference - we pass address
	printf("Value of b: %d\n", b); // 3
}
