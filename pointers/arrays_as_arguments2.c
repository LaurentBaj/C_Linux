#include <stdio.h>


int SumOfElements(int *A, int size) {

        int i, sum = 0;

        for(i = 0; i < size; i++) {
                sum += A[i];
        }

        return sum;
}


int main() {

        int A[] = {2, 3, 6, 7, 9, 24, 44, 22, 1};
        int size = sizeof(A)/sizeof(A[0]); // 9

        /*
                sizeof(A) = Elements in array * bytes (9 * 4 = 36)
                sizeof(A[0]) - refers to the size of an int
                sizeof(A)/sizeof(A[0]) = 36/4 = 9
        */

        int sum = SumOfElements(A, size);

        printf("The sum of array contents is: %d\n", sum);
}

