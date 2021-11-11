#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *program();
void *write_to_file(void *arg);
pthread_t main_thread, working_thread;
char str[2], buffer, quit[] = "Quit";
FILE *file;

int main()
{
    pthread_create(&main_thread, NULL, &program, NULL);
    pthread_join(main_thread, NULL);

    return 0;
}

void *write_to_file(void *arg)
{
    char *input = arg;
    file = fopen("text.txt", "a");
    fprintf(file, "%s", "\n");
    fprintf(file, "%s", input);
    fclose(file);
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
                pthread_create(&working_thread, NULL, &write_to_file, str);
                pthread_join(working_thread, NULL);
            }
            else
            {
                printf("Text can't contain more than 10 letters\n");
            }
        }

    } while (1);

    pthread_join(working_thread, NULL);
}