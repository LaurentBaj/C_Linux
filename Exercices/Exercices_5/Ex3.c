#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintVowels (char *pc)
{
  if (pc != NULL) {
    while (*pc++) {
      if (strchr("aeiou", *pc)) {
        printf ("%c\n", *pc);
      }
    }
  }
}

int main (int argc, char *argv[])
{
  printf ("%s\n", argv[1]);
  PrintVowels (argv[1]);
}



