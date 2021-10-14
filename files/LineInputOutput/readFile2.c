#include <stdio.h>
#include <stdlib.h>




int main()
{

	FILE *file1, *file2; 
	char x;
	
	file1=fopen("plain.txt", "r");
	file2=fopen("someText.txt", "w");
	
	if (file1==NULL || file2==NULL)
	{
		printf("A file does not exist\n");
	}
	else 
	{
		x=fgetc(file1);
		while(x != EOF)
		{
			fputc(x, file2);
			x=getc(file1);
		}
	}
	
	fclose(file1);
	fclose(file2);
}
