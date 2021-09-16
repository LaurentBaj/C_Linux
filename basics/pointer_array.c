#include <stdio.h>


int main() {
	int numbers[5];
	int *pointer = numbers; // numbers[0]

	int i = 0;

	// Fill emtpy array
	for(;pointer < &numbers[5]; pointer++) {
		*pointer = i;
		i++; 
	} 

	// Print
	for(int i = 0; i < 5; i++) {
		printf("%d\n", numbers[i]);
	} 
}
