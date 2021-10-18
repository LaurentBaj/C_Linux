#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

	FILE *f = fopen("dec.txt", "r");
	int lSize;
	
	
	if(f != NULL)
	{
	
		if (fseek(f, 0, SEEK_END) == 0)
		{
			lSize = ftell(f);
			printf("Size of file: %d\n", lSize);
			rewind(f);
		}
		
		double d[lSize];
		
		fread(d, sizeof(double), 1, f);
		
	}
}
