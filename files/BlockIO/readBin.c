#include <stdio.h>
#include <stdlib.h>


int main()
{

	int b[20], i;
	FILE *file;
	
	file=fopen("bfile.bin", "rb");
	
	// There are only five elements in bfile 
	fread(b, sizeof(int), 5, file);
	
	for(int i=0;i<5; i++)
	{
		printf("%d\n", b[i]);
	}
	
	fclose(file); 
}
