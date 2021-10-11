#include <stdio.h>
#include <string.h>

int length(char *array);



int main()
{
	char array[] = "Me Too!";
	printf("%s\n",  array);
	printf("%ld - %d\n", strlen(array), length(array));
}



int length(char *array) 
{
	int i=0;
	while(*array != '\0') 
	{ 
		i++; 
		array++; 
	}
	return i;
}
