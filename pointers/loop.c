#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *A = (int*)malloc(sizeof(int) * 10);

	int i=0;
	while(i < 10)
	{
		A[i] = i + 1;
		i++;
	}

	int *C = A + 10;
	while(A < C)
	{
		printf("%d\n", *(A));
		A++;
	}
}
