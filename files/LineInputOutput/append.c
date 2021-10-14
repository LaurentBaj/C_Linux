#include <stdio.h>



int main()
{

	FILE *file = NULL;
	char a='B', b='B';
	
	file = fopen("plain.txt", "a");
	
	fputc(a, file);
    fputc(a, file);
    
    fclose(file);
}
