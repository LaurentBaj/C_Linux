#include <stdio.h>



int main()
{
        char x;
        FILE *file = fopen("program.txt", "r");

	for(int i=0; i<12; i++)
	{
		x = fgetc(file);
		putchar(x); // HHHHHHHHHHHH
	}

	printf("\n");
	fclose(file);
}
