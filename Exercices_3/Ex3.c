#include <stdio.h>
#include <stdlib.h>



// argv[] elements are char an need 
// to be coerced to Int by using atoi()


int main(int argc, char *argv[])
{
	int input = atoi(argv[1]);
	if (input == 0) {
		 printf("Please provide a non-zero integer as argumet!\n");
	} else {
		if ((input % 2) == 0) {
			printf("Number %d is read and it is even\n", input); 
		} else {
	       	        printf("Number %d is read and it is odd\n", input); 
		}
	}

}



