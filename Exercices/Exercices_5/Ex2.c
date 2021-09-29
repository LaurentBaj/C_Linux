#include <stdio.h>
#include <stdlib.h>




int main (int argc, char *argv)
{
	int counter=-1;
	while (*argv++ != '\0') ++counter;
	printf ("%d\n", counter);

	return 0;
}


