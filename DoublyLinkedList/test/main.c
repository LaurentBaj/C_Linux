/* memset example */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "almost every programmer should know memset!";
    memset(str, str, 6);
    puts(str);
    return 0;
}