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
   		ret++;
   		counter++; 
   	}
   } 
   
   printf("The character |%c| occured - %d times \n", ch, counter);
}


/* Output: 
	'The character |t| occured - 5 times'
*/
