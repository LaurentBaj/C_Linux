#include <stdio.h>


// We already need to have a text file 



int main()
{
	char x;
	FILE *file;

	file = fopen("program.txt", "r");

	x = fgetc(file); // Get the first character in file
	fputc(x, stdout); // print x - H

	x = fgetc(file); // Increment + get next character
	putchar(x); // print x - e

	x = fgetc(file);
	putchar(x); // l


	fclose(file);

        putchar(x); // l
	fputc(file, stdout); // none, stream closed


/*
	fget(file) - get one character from file from file stream
	fputc(x, stdout) - print x in terminal from file stream
	putchar(x) - prints value to terminal

*/

