#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *dice()
{
    int value = (rand() % 6) + 1;
    int *p = malloc(sizeof(int));
    *p = value;
    return (void *)p;
}

int main()
{
    srand(time(NULL));
    pthread_t t1;
    int *res;

    pthread_create(&t1, NULL, &dice, NULL);
    pthread_join(t1, (void **)&res);

    printf("%d\n", *res);

    return 0;
}