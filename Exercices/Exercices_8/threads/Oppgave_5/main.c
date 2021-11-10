#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *player1(void *arg)
{
    int *iptr = (int *)malloc(sizeof(int));
    *iptr = 3;
    return iptr;
}

int main()
{
    pthread_t t1;
    int *res = malloc(sizeof(int));

    pthread_create(&t1, NULL, &player1, NULL);
    pthread_join(t1, (void *)&res);

    printf("%d\n", *res);
    return 0;
}