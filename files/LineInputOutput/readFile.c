#include <stdio.h>
#include <stdlib.h> 


int main()
{

	char x;
	FILE *file;
	
	file=fopen("plain.txt", "r");
	
	if (file == NULL)
	{
		printf("File does not exist");
		exit(1);	
	} 
	else 
	{
		x=fgetc(file);		
		while (x != EOF)
		{
			fputc(x, stdout);
			x=fgetc(file);
		}		
	}

	fclose (file);
}
