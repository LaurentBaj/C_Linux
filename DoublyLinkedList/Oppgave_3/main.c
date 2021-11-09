#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int count;
    float price;
    struct Node *next;
    struct Node *prev;
} Node;

Node *find_node(Node *tail, float value);
void remove_node(Node *node);
void insert_after(Node *node, float value);
void append(Node **head, float value);
void init(Node **tail, Node **head, float value);
void deallocate(Node **tail, Node **head);

int main()
{
    char a = 'a', p = 'p', q = 'q';
    char buffer;

    /*do
    {
        printf("Do you want to quit?\n");
        scanf("%4s", &buffer);

        if (buffer == 'a')
        {
            printf("Triggered a\n");
        }
        else if (buffer == 'p')
        {
            printf("Triggered p\n");
        }

    } while (buffer != 'q');*/
    Node *tail = NULL;
    Node *head = NULL;

    init(&tail, &head, 7.2);
    append(&head, 3.14);

    for (Node *curr = tail; curr != NULL; curr = curr->next)
    {
        printf("%f\n", curr->price);
    }

    printf("Program finsihed executing\n");
    return 0;
}

void deallocate(Node **tail, Node **head)
{
    if (tail == NULL)
        return;

    Node *curr = *tail;
    while (curr->next != NULL)
    { // Jump to next and free previous node
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);

    *tail = NULL;
    *head = NULL;
}

void insert_beginning(Node **tail, float value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
        return;
    }

    new_node->price = value;
    new_node->prev = NULL;
    new_node->next = *tail;

    (*tail)->prev = new_node;
    *tail = new_node;
}

void init(Node **tail, Node **head, float value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(2);
        return;
    }

    new_node->price = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    *tail = new_node;
    *head = new_node;
}

void append(Node **head, float value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        exit(3);
        return;
    }

    new_node->price = value;
    new_node->next = NULL;

    new_node->prev = *head;
    (*head)->next = new_node;
    (*head) = new_node;
}

void insert_after(Node *node, float value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(4);
        return;
    }

    new_node->price = value;
    new_node->prev = node;
    new_node->next = node->next;

    if (node->next != NULL)
    {
        node->next->prev = new_node;
    }
    node->next = new_node;
}

void remove_node(Node *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    free(node);
}

Node *find_node(Node *tail, float value)
{
    for (Node *curr = tail; curr != NULL; curr = curr->next)
    {
        if (curr->price == value)
            return curr;
    }
    return NULL;
}