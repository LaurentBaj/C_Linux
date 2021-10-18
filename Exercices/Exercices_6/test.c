#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

	FILE *f;
	char szLine[160];
	int iLine = 0;

	f = fopen("tekst.txt", "r");
	if (f != NULL)
	{
		while (!feof(f))
		{
			if (fgets(szLine, sizeof(szLine), f))
			{
		    	printf ("%3d: %s", ++iLine, szLine);
			}
		}
	}

	fclose(f);
}
