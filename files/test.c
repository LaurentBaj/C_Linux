#include <stdio.h>


int main()
{
	int a=1234, b=2222, c;
	FILE *file = NULL;


	// if file exists: overwrite, else -> overwrite contents
	file = fopen("test.txt", "r");

        fscanf(file, "%d", &c); // put file contents in c
	printf("%d\n", c);

	fclose(file);
}
