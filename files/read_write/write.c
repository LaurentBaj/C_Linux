#include <stdio.h>
#include <stdlib.h>



int main()
{
	int num; 
	FILE *file;
	
	file = fopen("program.txt", "w");
	
	if (file == NULL)
	{
		printf("Error: filepath is incorrect\n");
		exit(1);
	}
	
	printf("Enter a number\n");
	scanf("%d", &num);
	
	fprintf(file, "%d\n", num);
	fclose(file); 
}
