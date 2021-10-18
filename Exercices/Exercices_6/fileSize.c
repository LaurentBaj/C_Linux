#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

	FILE *f;
	int lSize = 0;

	f = fopen("tekst.txt", "r");
	if (f != NULL)
	{
		if (fseek(f, 0, SEEK_END) == 0)
		{
			lSize = ftell(f);
			printf("Size of file: %ld\n", lSize);
			rewind(f);
		}
	}

	fclose(f);
}
