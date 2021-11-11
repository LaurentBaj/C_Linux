#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *program();
void *write_to_file(void *arg);

pthread_t main_thread, working_thread;
typedef struct file_handler
{
    FILE *file;
    char str[10];
    char buffer;
} file_handler;

int main()
{
    pthread_create(&main_thread, NULL, &program, NULL);
    pthread_join(main_thread, NULL);

    printf("\nText writer closed\n");
    return 0;
}

void *program()
{
    file_handler *fh = malloc(sizeof(file_handler));

    do
    {
        printf("Add new line to file (a) or quit (q)\n");
        scanf("%c", &fh->buffer);

        if (fh->buffer == 'q')
        {
            break;
        }
        else if (fh->buffer == 'a')
        {
            printf("Enter text: ");
            scanf("%s", fh->str);
            if (strlen(fh->str) < 10)
            {
                pthread_create(&working_thread, NULL, &write_to_file, fh);
                pthread_join(working_thread, NULL);
            }
            else
            {
                printf("\n(Text can't contain more than 10 letters)\n\n");
            }
        }

    } while (1);

    free(fh);
    pthread_join(working_thread, NULL);
}

void *write_to_file(void *arg)
{
    file_handler *fh = (file_handler *)arg;
    fh->file = fopen("text.txt", "a");

    fprintf(fh->file, "%s", "\n");
    fprintf(fh->file, "%s", fh->str);

    fclose(fh->file);
}