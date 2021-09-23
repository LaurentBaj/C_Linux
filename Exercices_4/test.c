#include <stdio.h>


int main(int argc, char *argv[]) {
        printf("Amount of strings in array %d\n", argc - 1);
	for (int i = 1; i < argc; i++) {
		printf("%d: %s\n",i, argv[i]);
	} 
}

