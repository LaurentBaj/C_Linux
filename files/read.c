#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   if ((fptr = fopen("/home/laurent/Work/C_Linux/files/program.txt","r")) == NULL){
       printf("Error! opening file\n");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   // I don't get how fptr is set to program.txt
   fscanf(fptr,"%d", &num);  

   printf("Value of n=%d\n", num);
   fclose(fptr); 
  
   return 0;
}
