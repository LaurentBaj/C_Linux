#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	char szLine[160];
	int iLine = 0;
	
	f = fopen("program.txt", "r");
	if  (f != NULL)
	{
		while (!feof(f))
		{
			if (fgets  (szLine, sizeof(szLine), f))
			{ printf("%3d: %s", ++iLine, szLine); }
		}
		fclose(f);
	}    
  
	return 0;
}
