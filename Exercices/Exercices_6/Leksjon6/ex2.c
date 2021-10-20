// ex1.c: Lession 5 - excersise 2. See exercises.txt
//
// cl /Od /Zi ex1.c
// gcc -O2 ex1.c -o ex1
//
// -or- make TARGET=ex1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK         0
#define NOT_GOOD   1
#define EVEN_WORSE 2

int ReadTextFile (const char *pszFileName, char **ppcBuf, long *plSize);
char *FindFirstVowel (char *pc);

void main (void)
{
   char *pcFile;
   long lSize;
   int iRc;

   iRc = ReadTextFile ("smallbook.txt", &pcFile, &lSize);
   if (iRc == OK) {
      printf ("%ld bytes read.\n", lSize);

      // Find two consequtive vowels:
      char *pc = pcFile;
      while ((pc != NULL) && (pc < (pcFile + lSize))) {
         pc = FindFirstVowel(pc);
         if (pc != NULL) {
            if (*pc == *(pc + 1)) {
               printf ("Vowels: Found two '%c' in pos %ld.\n", *pc, pc - pcFile);
            }
            pc += 2;
         }
      }
      printf ("\n");

      // Find any letter which is immediately is followed by the same letter:
      for (pc = pcFile; pc < (pcFile + lSize); pc++) {
         if (*pc == *(pc + 1)) {
            printf ("Pairs: Found two '%c' in pos %ld.\n", *pc, pc - pcFile);
            pc++;
         }
      }
      printf ("\n");

      // Find any letter which is followed by the same letter in between m and n characters later:

      // int m = 1, n = 2;
      int m = 2, n = 5;

      for (pc = pcFile; pc < (pcFile + lSize); pc++) {
         for (char *pc2 = pc + m; (pc2 < (pc + n)) && (pc2 < (pcFile + lSize)); pc2++) {
            if (*pc == *pc2) {
               printf ("m-to-n pairs: Found two '%c' %ld spaced in pos %ld.\n", *pc, pc2 - pc, pc - pcFile);
            }
         }
      }

      // We're done ...

      free (pcFile);
   }
   else {
      printf ("Could not open or read the file.\n");
   }
}

char *FindFirstVowel (char *pc)
{
   if (pc != NULL) {
      while (*pc++) {
         if (strchr("aeiou", *pc)) {
            return pc;
         }
      }
   }
   return NULL;
}

// ReadBinary from ex1.c slightly revised:

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

