// ex3.c: Lession 5 - excersise 3. See exercises.txt
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

int main (int iArgC, char *apszArgV[])
{
   char *pcFile;
   long lSize;
   int iRc;

   if (iArgC < 2) {
      printf ("Usage: ex3 <word to encode>\n");
      return 1;
   }

   iRc = ReadTextFile ("adventures.txt", &pcFile, &lSize);
   if (iRc == OK) {
      char *pce = apszArgV[1]; // Start of string to encode:
      char *pc = pcFile;

      while (*pce && (pc != NULL) && (pc < (pcFile + lSize))) {
         pc = strchr (pc, *pce);
         if (pc != NULL) {
            // printf ("Found '%c' in pos %ld.\n", *pc, pc - pcFile);
            printf ("%ld ", pc - pcFile);
            pc += 10;
            pce++;
         }
      }
      printf("\n");

      if (*pce) printf ("We could not encode the entire word.\n");

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

