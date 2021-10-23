// ex4.c: Lession 7, exercise 4
//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void *myalloc (const char *fmt, ...)
{
   int iSze = 0;
   void *pvRet = NULL;

   va_list ap;
   va_start(ap, fmt);

   // Check "char T" or "char F"
   if (strlen(fmt) == 6 && strncmp(fmt, "char", 4) == 0) {
      iSze = va_arg(ap, int);
      char *pc = malloc (iSze);
      if (pc != NULL) {
         if (fmt[5] == 'T') {
            int iInit = va_arg(ap, int);
            for (int i = 0; i < iSze; i++) {
               pc[i] = iInit;
            }
         }
         pvRet = pc;
      }
   }

   // Check "int T" or "char F"
   else if (strlen(fmt) == 5 && strncmp(fmt, "int", 3) == 0) {
      iSze = va_arg(ap, int);
      int *pi = malloc (iSze * sizeof(int));
      if (pi != NULL) {
         if (fmt[4] == 'T') {
            int iInit = va_arg(ap, int);
            for (int i = 0; i < iSze; i++) {
               pi[i] = iInit;
            }
         }
         pvRet = pi;
      }
   }

   // Check "double T" or "double F"
   else if (strlen(fmt) == 8 && strncmp(fmt, "double", 6) == 0) {
      iSze = va_arg(ap, int);
      double *pdf = malloc (iSze * sizeof(double));
      if (pdf != NULL) {
         if (fmt[7] == 'T') {
            double dfInit = va_arg(ap, double);
            for (int i = 0; i < iSze; i++) {
               pdf[i] = dfInit;
            }
         }
         pvRet = pdf;
      }
   }

   va_end(ap);
   return pvRet;
}

int main(void)
{
   //Gives you an array with 10 ints and all are 4
   int *pi = (int *) myalloc ("int T", 10, 4);
   if (pi != NULL) {
      printf ("\nGot it: ");
      for (int i = 0; i < 10; i++) {
         printf ("%d ", pi[i]);
      }
      free (pi);
   }

   //Gives you a float array with 20 floats unintialized
   double *pdf = (double *) myalloc ("fumble F", 20);
   if (pdf != NULL) {
      printf ("\nGot it: ");
      for (int i = 0; i < 20; i++) {
         printf ("%lf ", pdf[i]);
      }
      free (pdf);
   }
}
