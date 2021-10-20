#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main (void)
{

	FILE *fb, *ft;
	double num;
   
	
	// Bin-file with doubles
	fb = fopen ("doubles.dat", "wb");
	if (fb != NULL)
	{
		for (int i = 20; i < 30; i++)
		{
			num = (double) i;
			fwrite (&num, sizeof(double), 1, fb);
		}
		fclose (fb);
	}
	
	
	// Read from bin
	// stdout contents
	fb = fopen ("doubles.dat", "rb");
	if (fb != NULL)
	{
		// 'read' bin contents into buffer arr
		// and then print buffer contents
		/* THIS WORKS AS WELL
		double buffer[10];
		fread (buffer, sizeof(buffer), 1, fb);
		for (int i = 0; i < 10; i++)
		{
			printf("%lf\n", buffer[i]); 
		}
		*/
		while (!feof(fb))
		{
			// As long as there is content (true) - put that into num
			if (fread(&num, sizeof(double), 1, fb) == 1) 
			{
				printf("%lf\n", num);  
			}
		}
		fclose (fb); 
	}
	
	
	// Put Bin contents into text file 
	fb = fopen ("doubles.dat", "rb");
	if (fb != NULL)
	{
		ft = fopen("program.txt", "w");
		while (!feof(fb))
		{
			if (fread(&num, sizeof(double), 1, fb) == 1)
			{
				fprintf(ft, "%lf\n", num); 
			}
		}
		fclose (ft);
	}
	fclose (fb); 
}
