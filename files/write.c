#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   // START FILE ACTIONS
   fptr = fopen("program.txt","w"); // Create/overwrite file - 'w' for write

   if(fptr == NULL) // Do this if filepath is incorrect
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);


   // END FILE ACTIONS
   fprintf(fptr,"%d\n",num);  // Print file content
   fclose(fptr);

   return 0;
}
