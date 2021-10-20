// ex1.c: Lession 5 - excersise 1. See exercises.txt
//
// cl /Od /Zi ex1.c
// gcc -O2 ex1.c -o ex1
//
// -or- make TARGET=ex1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

#define OK         0
#define NOT_GOOD   1
#define EVEN_WORSE 2

int ReadBinary (const char *pszFileName, BYTE **ppbyBuf, long *plSize);

void main (void)
{
   FILE *fb, *ft;
   double lfNum;

   // Make the binary file of doubles:

   fb = fopen ("doubles.dat", "wb");
   if (fb != NULL) {
      for (int i = 0; i < 100; i++) {
         lfNum = (double) i;
         fwrite (&lfNum, sizeof(double), 1, fb);
      }
      fclose (fb);
   }

   // Re-open it and read double-by-double, and write them back
   // to a text file:

   fb = fopen ("doubles.dat", "rb");
   if (fb != NULL) {
      ft = fopen ("doubles.txt", "w");
      if (ft != NULL) {
         while (!feof(fb)) {
            // Read one double - if we got one, write as text
            if (fread (&lfNum, sizeof(double), 1, fb) == 1) {
               fprintf (ft, "%lf\n", lfNum);
            }
         }
         fclose (ft);
      }
      fclose (fb);
   }

   // Re-open the text file, read in the doubles and produce
   // a new binary file.

   ft = fopen ("doubles.txt", "r");
   if (ft != NULL) {
      fb = fopen ("doubles2.dat", "wb");
      if (fb != NULL) {
         while (!feof(ft)) {
            if (fscanf (ft, "%lf", &lfNum) == 1) {
               fwrite (&lfNum, sizeof(double), 1, fb);
            }
         }
         fclose(fb);
      }
      fclose(ft);
   }

   // When finished, "doubles.dat" and "doubles2.dat" should be
   // 100% equal byte-byte-byte. This goes beyond the excersice,
   // but still, let's test that:

   BYTE *pbyFile1, *pbyFile2;
   long lSize1, lSize2;
   int iRc;

   iRc = ReadBinary ("doubles.dat", &pbyFile1, &lSize1);
   if (iRc == OK) {
      iRc = ReadBinary ("doubles2.dat", &pbyFile2, &lSize2);
      if (iRc == OK) {
         if (lSize1 == lSize2) {
            if (memcmp (pbyFile1, pbyFile2, lSize1) == 0) {
               printf ("The files are identical.\n");
            }
            else {
               printf ("The files are different.\n");
            }
         }
         else {
            printf ("The files are of different size.\n");
         }
         free (pbyFile2);
      }
      else {
         printf ("Could not open doubles2.dat.\n");
      }
      free (pbyFile1);
   }
   else {
      printf ("Could not open doubles.dat.\n");
   }
}

int ReadBinary (const char *pszFileName, BYTE **ppbyBuf, long *plSize)
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
         *ppbyBuf = (BYTE *)malloc (lSize);
         if (*ppbyBuf) {
            // Read the file in one chunk:
            lBytesRead = fread (*ppbyBuf, sizeof(BYTE), lSize, f);
            if (lBytesRead == lSize) {
               // We got it all !
               *plSize = lSize;
            }
            else {
               iRc = NOT_GOOD;
               free (*ppbyBuf);
               *ppbyBuf = NULL;
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

