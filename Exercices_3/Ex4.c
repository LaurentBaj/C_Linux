#include <stdio.h>



int main()
{
	int i;

	for (i = 99; i > 1; i--) {
		printf("\n%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
		printf("%d Take one down and pass it around, %d bottles of beer on the wall.\n", 1, i - 1); 
	} 

	printf("\n%d bottle of beer on the wall, %d bottle of beer. Take one down and pass it around, no more bottles of beer on the wall.\n", i, i); 
	printf("\nNo more bottles of beer on the wall, no more bottles of beer.\n");
	printf("We've taken them down and passed them around; now we're drunk and passed out!\n\n");


	return 0;
} 
