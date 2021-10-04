#include <stdio.h>




void Print(char *C) {
	while (*C != '\0') {
		printf("%c", *C);
		C++; // Increment by 1 byte and get next val
	}
	printf("\n");
}




int main() {
	char array[] = "Hello World!";
	Print(array);
}
