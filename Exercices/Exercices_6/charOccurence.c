#include <stdio.h>
#include <string.h>

void main (void) 
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 't';
   char *ret = str; 
   int counter = 0; 
   
   while (ret != NULL)
   {
   	ret = strchr(ret, ch); 
   	if (ret)
   	{
   		counter++;
   		printf("Position: %ld\n", (ret-str+1)); 
   		ret++;
   	}
   } 
   
   printf("The character |%c| occured - %d times \n", ch, counter); 
}

/* OUTPUT: 

	Position: 1
	Position: 2
	Position: 11
	Position: 13
	Position: 24
	The character |t| occured - 5 times 

*/
