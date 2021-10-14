#include <stdio.h>



int main()
{
	char a='A', b='B';
	FILE *file = NULL;

	file = fopen("program.txt", "w");

	fputc(a, file);
        fputc(b, file);

	fclose(file);
}
