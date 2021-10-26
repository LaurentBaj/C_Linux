#include <stdio.h>


typedef enum Color {
    RED, BLUE, YELLOW
} Color; 


int main ()
{
    Color c1 = RED, c2 = BLUE, c3 = YELLOW; 
    printf("%d - %d - %d\n", c1, c2, c3); // 0 - 1 - 2
}