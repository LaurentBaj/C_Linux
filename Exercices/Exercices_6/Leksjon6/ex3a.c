// ex3.c: Lession 5 - excersise 1. See exercises.txt
//
// cl /Od /Zi ex3.c
// gcc -O2 ex3.c -o ex3
//
// -or- make TARGET=ex3
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK         0
#define NOT_GOOD   1
#define EVEN_WORSE 2

int ReadTextFile (const char *pszFileName, char **ppcBuf, long *plSize);
char *FindFirstVowel (char *pc);

int main (int iArgC, char *apszArgV[])
{
   char *pcFile;
   long lSize;
   int iRc;

   if (iArgC < 2) {
      printf ("Usage: ex3 <numbers to decode>\n");
      return 1;
   }

   iRc = ReadTextFile ("adventures.txt", &pcFile, &lSize);
   if (iRc == OK) {
      char *pc = pcFile;

      for (int i = 1; i < iArgC; i++) {
         int iCode = atoi (apszArgV[i]);
         if (iCode != 0 && iCode < lSize) {
            printf ("%c", pcFile[iCode]);
         }
         else {
            printf ("\nCannot decode!");
         }
      }
      printf("\n");

      // We're done ...

      free (pcFile);
   }
   else {
      printf ("Could not open or read the file.\n");
   }
}

// ReadTextFile from ex2.c:

int ReadTextFile (const char *pszFileName, char **ppcBuf, long *plSize)
{
   int iRc = OK;
   long lSize, lBytesRead;
   FILE *f;

   f = fopen (pszFileName, "rb");
   if (f != NULL) {
      if (fseek(f, 0, SEEK_END) == 0) {
         lSize = ftell(f);
         rewind(f);
         // We got the size, allocate buffer:
         *ppcBuf = (char *) malloc(lSize + 1);
         if (*ppcBuf) {
            // Read the file in one chunk:
            lBytesRead = fread (*ppcBuf, sizeof(char), lSize, f);
            if (lBytesRead == lSize) {
               // We got it all !
               *plSize = lSize;
               (*ppcBuf)[lSize] = 0; // Add a terminating '\0'
            }
            else {
               iRc = NOT_GOOD;
               free (*ppcBuf);
               *ppcBuf = NULL;
            }
         }
         else {
            iRc = EVEN_WORSE;
         }
      }
      fclose(f);
   }
   return iRc;
}

