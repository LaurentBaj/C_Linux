#include <stdio.h>
#include <stdlib.h>


int main()
{

	int a[5]={2, 4, 6, 8, 10};
	FILE *file;
	
	file=fopen("bfile.bin", "wb");
	
	fwrite(a, sizeof(int), 5, file);
	//// PARAMS
	// Content we want to fill the file with
	// Size of each element in array
	// How many of those elements (seems to traverse array)
	// Destination 
	
	fclose(file); 
}
