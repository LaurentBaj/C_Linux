#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

int main (int argc, char **argv)
{
    int input1 = atoi(argv[1]); 
    int input2 = atoi(argv[2]);

    printf("%d + %d = %d\n", input1, input2, add(input1, input2));
    printf("%d - %d = %d\n", input1, input2, sub(input1, input2));

    return 0;
}