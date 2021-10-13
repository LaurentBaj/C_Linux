#include <stdio.h>


int main()
{
	int a=1234, b=5678;
	FILE *file = NULL;

	file = fopen("test.txt", "r");

	fprintf(file, "%d ", a);
        fprintf(file, "%d ", b);
        fprintf(file, "%s ", "Hello World!");

	fclose(file);
}
