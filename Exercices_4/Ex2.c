#include <stdio.h>


int main() {

int *pInt;
char *pChar;
short *pShort;
double *pDouble;

printf("The size of pointers are %ul, %ul, %ul, %ul respectively \n",
       sizeof(pInt), sizeof(pChar), sizeof(pShort), sizeof(pDouble));

printf("The size of variables are %lu, %lu, %lu, %lu respectively \n",
       sizeof(*pInt), sizeof(*pChar), sizeof(*pShort), sizeof(*pDouble));

}
