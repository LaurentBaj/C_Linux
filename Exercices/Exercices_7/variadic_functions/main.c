#include <stdio.h>
#include <stdarg.h> // provides variables: va_start, va_arg, va_end


int print_ints(int num, ...)
{    
    va_list args; 
    va_start(args, num); 
    for (int i = 0; i < num; i++)
    {
        int value = va_arg(args, int); 
        printf("%d\n", value);
    }
    va_end(args); 
}


int main()
{
    // First argument is amount of el's we want to print 
    print_ints(6, 2, 1, 5, 7, 5, 34, 2, 5); 
}


/* Output: 
    2
    1
    5
    7
    5
    34
*/