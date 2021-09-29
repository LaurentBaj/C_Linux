#include <stdio.h>
#include <string.h>


void swap(int a, int b, char *array[]);
void bubbleSort(char *array[], int size);
void print(char *array[], int size);


int main(int argc, char *argv[]) {
	bubbleSort(argv, argc);
	return 0;
}




// FUNCTIONS
void swap(int a, int b, char *array[]) {
	char temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void print(char *array[], int size) {
	for (int i = 1; i < size; i++) {
		printf("%s", array[i]);
	}
}

void bubbleSort(char *array[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < (size - 1); j++) {
			if (strcmp(array[j], array[j + 1]) == 1) {
				swap(j, j + 1, array);
			}
		}
	}
	print(array, size);
}

