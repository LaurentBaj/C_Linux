#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv[]) {
	int array[argc - 1];

	for (int i = 1; i < argc; i++) {
                array[i] = atoi(argv[i]);
        }

	for (int i = 1; i < argc; i++) {
                printf("%d\n", array[i]);
        }
}
