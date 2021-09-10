#include <stdio.h>
#include <stdlib.h>





// argv[] elements are char an need 
// to be coerced to Int by using atoi()

int main(int argc, char *argv[])
{
	if (atoi(argv[1]) % 2 == 0) { 
		printf("Input number is even\n");
	} else {
		printf("Input number is odd\n"); 
	}

   	 return 0;
}



