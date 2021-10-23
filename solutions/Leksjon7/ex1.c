// ex1.c: Lession 7, exercise 1
//
#include <stdio.h>

void MyFunc (void)
{
  static int iCounter = 0;
  printf ("iCounter=%d\n", ++iCounter);
}

int main(void)
{
   for (int i = 0; i < 10; i++) {
      MyFunc();
   }
}
