#include <stdio.h>
#include "tools.h"




void second (void); 


int main ()
{
	printf("This is printed from main\n");
	second(); 
	int sum = add(20, 40);
	printf("%d\n", sum); 
	
	return 0;
}


/* RUN:

	gcc combine.c externFunc.c -o ce


*/
