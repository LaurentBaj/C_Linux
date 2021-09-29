#include <stdio.h>


int main(int argc, char *argv[]) {
	int counter = (argc - 1);
	printf("Amount of words: %d\n", counter); 
	for (int i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	return 0;
}
