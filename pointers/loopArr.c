#include <stdio.h>

int main() {

	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (int i = 0; i < sizeof(A)/4; i++)
	{
		printf("%d\n", *(A+i));
	}
}
