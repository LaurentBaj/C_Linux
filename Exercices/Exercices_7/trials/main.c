#include <stdio.h>
#include "tools.h"



int main ()
{
	printf("This is printed from main\n");
	second(); 
	int sum = add(20, 50);
	char s = add(2, 3);
	printf("%d - %d\n", s, sum); 
	
	return 0;
}


/* RUN:

	gcc main.c tools.c -o main


*/
