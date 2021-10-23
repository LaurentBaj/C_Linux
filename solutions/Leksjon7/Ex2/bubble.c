// bubble.c: Lession 7, exercise 2
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble.h"

static void Swap (char **ppszA, char **psszB);

// Run through the elements and swap when you find a[i-1] > a[i].
// Keep doing this until you cannot swap anymore.

void BubbleSort (char *apszArray[], int iSze)
{
   int bHasSwapped = TRUE;
   while (bHasSwapped) {
      bHasSwapped = FALSE;
      for (int i = 1; i < iSze; i++) {
         if (strcasecmp(apszArray[i-1], apszArray[i]) > 0) {
            Swap (&apszArray[i-1], &apszArray[i]);
            bHasSwapped = TRUE;
            // PrintArray (apszArray, iSze);
         }
      }
   }
}

static void Swap (char **ppA, char **ppB)
{
   char *pTmp;
   pTmp = *ppA;
   *ppA = *ppB;
   *ppB = pTmp;
}
