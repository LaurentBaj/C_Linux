#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *routine(void *arg)
{
    FILE *temp = (FILE *)arg;
    temp = fopen("text.txt", "w");
    fprintf(temp, "%s", "Hva faen?");
    fclose(temp);
}

int main()
{
    FILE *f1;
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine, f1) != 0)
    {
        return 1;
    }

    if (pthread_join(t1, NULL) != 0)
    {
        return 2;
    }

    return 0;
}