#include <stdio.h>


typedef enum failCode
{
    writeError,
    readError,
    fileExist
} failCode;


void printError(failCode f)
{
    char* errorMessage[] =
    {
        "Error: Writing to File",
        "Error: Reading from File",
        "Error: File doesn't exist"
    };
    printf("%s\n", errorMessage[(int)f]);
}


int main()
{
    failCode f1 = writeError; 
    printError(f1); 
}