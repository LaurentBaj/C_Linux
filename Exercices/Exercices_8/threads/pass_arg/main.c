#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};

void *routine(void *arg)
{
    int index = *(int *)arg;
    printf("%d ", fibonacci[index]);
    free(arg);
}

int main()
{
    pthread_t th[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
    }

    for (int i = 0; i < 10; i++)
    {
        pthread_join(th[i], NULL);
    }

    printf("\n");
    return 0;
}