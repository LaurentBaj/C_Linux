#include <stdio.h>
#include <stdlib.h>




int main()
{

	char x[20], y, z;
	int a=77, b=78, c=79;
	FILE *file;
	
	file=fopen("text.txt", "w+");
	
	fputs("Welcome to Kristiania\n", file); // Put str into file
	fseek(file, 11, 0); // set cursor at pos 11 starting from 0
	fgets(x, 11, file); // Get from cursor + 11 chars AND put into x
	printf("%s\n", x); // Output of x: "Kristiania"
	
	fclose(file);
}
