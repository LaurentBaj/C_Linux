#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

typedef struct Node
{
    char *name;
    int count;
    float price;
    struct Node *next;
    struct Node *prev;
} Node;

Node *find_node(Node *tail, float value);
void remove_node(Node *node);
void insert_after(Node *node, float value);
void append(Node **head, float price, char *p_name, int iCount);
void init(Node **tail, Node **head, float value);
void deallocate(Node **tail, Node **head);
void print_dll(Node *node);
void remove_last(Node **head);
void remove_all_instances_of(Node *tail, char *value);

int main()
{
    // Initialize shopping cart (dll)
    Node *tail = NULL;
    Node *head = NULL;
    init(&tail, &head, 0);

    // Buffers
    char buffer, *b_name;
    float b_price, sum;
    int b_count;

    // Program
    do
    {
        printf("\nEnter action: ");
        scanf("%c", &buffer);

        if (buffer == 'a')
        {
            printf("\nEnter product name: ");
            scanf("%s", b_name);
            printf("Enter price: ");
            scanf("%f", &b_price);
            printf("Enter amount: ");
            scanf("%d", &b_count);

            append(&head, b_price, b_name, b_count);
            printf("%dx - %s has been added to list\n", b_count, b_name);
        }
        else if (buffer == 'r')
        {
            remove_last(&head);
        }
    } while (buffer != 'q');

    // Create receipt + free heap
    print_dll(tail);
    deallocate(&tail, &head);
    return 0;
}