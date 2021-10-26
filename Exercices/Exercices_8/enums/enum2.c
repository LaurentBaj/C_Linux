#include <stdio.h>


typedef enum Color {
    RED = 'r' 
} Color; 

int main ()
{
    Color c1 = RED;  
    printf("%d\n", c1); // 114 (ASCII-value of 'r')
}