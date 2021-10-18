#include <stdio.h>
#include <stdlib.h>



int main()
{

	FILE *file, *fb; 
	file = fopen ("program.txt", "r");
	fb = fopen("prog.bin", "wb");
	double i;

	printf("program.txt file contets: \n");
	fscanf(file, "%lf", &i);   
	while (!feof (file))
    {  
    	fwrite(file, sizeof(double), 1, fb);
    	printf ("%lf\n", i);
        fscanf (file, "%lf", &i);
    }
	        
	fclose(fb);
	fb = fopen("prog.bin", "rb");

	printf("\n\nprog.bin file contets: \n");
	fread(&i, sizeof(double), 1, fb);   
	while (!feof(fb))
	{
		printf("%lf\n", i);
		fread(&i, sizeof(double), 1, fb);      		
	}
	
	fclose(file);
	fclose(fb);	
}
