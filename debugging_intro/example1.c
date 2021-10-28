#include <stdio.h>
#include <stdlib.h>


// Debugging with gdb repetition
int main()
{
    int a[10];  
    int age = 2;
    *(a + age) = age; 

    printf("Whalecum to program with bug: \n");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
    a[9] = age; 

    for (int i = 0; i < 10; i++)
    {
        *(a + i) = i+1;  
    }

    printf("a should be freed %d\n", *(a+9)); 
    return 0; 
}