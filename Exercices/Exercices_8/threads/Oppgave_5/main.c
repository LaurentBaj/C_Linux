#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

char str[10];

void *routine(void *arg)
{
    FILE *temp = (FILE *)arg;
    temp = fopen("text.txt", "a");
    fprintf(temp, "%s", "\n");
    fprintf(temp, "%s", str);
    fclose(temp);
}

int main()
{
    FILE *f1;
    pthread_t t1, t2;
    char buffer;

    do
    {
        printf("Enter text: ");
        scanf("%s", str);

        if (pthread_create(&t1, NULL, &routine, f1) != 0)
        {
            return 1;
        }
    } while (buffer != 'q');

    if (pthread_join(t1, NULL) != 0)
    {
        return 2;
    }

    printf("%c\n", buffer);
    return 0;
}