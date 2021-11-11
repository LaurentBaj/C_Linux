#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

char str[2], buffer, quit[] = "Quit";
FILE *file;
pthread_t main_thread, working_thread;

void *write_to_file(void *arg)
{
    FILE *temp = (FILE *)arg;
    temp = fopen("text.txt", "a");
    fprintf(temp, "%s", "\n");
    fprintf(temp, "%s", str);
    fclose(temp);
}

void *program()
{
    do
    {
        printf("Add new line to file (a) or quit (q)\n");
        scanf("%c", &buffer);

        if (buffer == 'q')
        {
            break;
        }
        else if (buffer == 'a')
        {
            printf("Enter text: ");
            scanf("%s", str);
            if (strlen(str) < 10)
            {
                pthread_create(&working_thread, NULL, &write_to_file, file);
            }
            else
            {
                printf("Text can't contain more than 10 letters\n");
            }
        }

    } while (1);

    pthread_join(working_thread, NULL);
}

int main()
{
    pthread_create(&main_thread, NULL, &program, NULL);
    pthread_join(main_thread, NULL);

    return 0;
}
