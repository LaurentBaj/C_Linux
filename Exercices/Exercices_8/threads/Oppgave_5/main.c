#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *routine(void *arg)
{
    int *p = (int *)arg;
    *p = 2;
    return (void *)p;
}

int main()
{
    FILE *f1, *f2;
    pthread_t t1, t2;
    int *i = malloc(sizeof(int));

    if (pthread_create(&t1, NULL, &routine, i) != 0)
    {
        return 1;
    }

    if (pthread_join(t1, (void *)&i) != 0)
    {
        return 2;
    }

    printf("%d\n", *i);
    return 0;
}