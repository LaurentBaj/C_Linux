#include <stdio.h>
#include <stdlib.h>

void BubbleSort (int aiArray[], int size);
void Swap (int *pi, int *pj);
void PrintArray (int aiArray[], int size);

int main (int argc, char *argv[])
{
   int *aiNumbers = NULL;
   int count = argc - 1;

   if (count < 2) {
      printf ("Usage: ex4 <number1> <number2> ... <numberN>\n");
      return 1;
   }

   // Allocate memory and test if Ok:
   aiNumbers = (int *) malloc (count * sizeof(int));
   if (aiNumbers == NULL) return 1;

   // Obtain numbers from command line:
   for (int i = 0; i < count; i++) {
      aiNumbers[i] = atoi(argv[i + 1]);
   }

   // Sort the numbers:
   BubbleSort (aiNumbers, iCount);

   // Print the numbers:
   PrintArray (aiNumbers, iCount);

   free (aiNumbers);

   return 0;
}

// Use preprocessor defines to make more readable constants:

#define FALSE 0
#define TRUE  1

// Run through the elements and swap when you find a[i-1] > a[i].
// Keep doing this until you cannot swap anymore.

void BubbleSort (int aiArray[], int size)
{
   int bHasSwapped = TRUE;
   while (bHasSwapped) {
      bHasSwapped = FALSE;
      for (int i = 1; i < iSze; i++) {
         if (aiArray[i-1] > aiArray[i]) {
            Swap (&aiArray[i-1], &aiArray[i]);
            bHasSwapped = TRUE;
            // PrintArray (aiArray, iSze);
         }
      }
   }
}

void Swap (int *pi, int *pj)
{
   int iTmp = *pi;
   *pi = *pj;
   *pj = iTmp;
}

void PrintArray (int aiArray[], int iSze)
{
   printf ("%d: ", iSze);
   for (int i = 0; i < iSze; i++) {
      printf ("%d ", aiArray[i]);
   }
   printf ("\n");
}

