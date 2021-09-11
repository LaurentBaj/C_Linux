#include <stdio.h>


int sum(int a, int b); 

int main(int argc, char *argv[])
{
	int result = sum(atoi(argv[1]), atoi(argv[2])); 
	printf("%d\n", result); 
   
	return 0;
}



int sum(int a, int b) {
	return (a + b); 
}
