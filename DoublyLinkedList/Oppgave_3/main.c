#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int x;
    struct Node *next;
    struct Node *prev;
} Node;

Node *find_node(Node *tail, int value);
void remove_node(Node *node);
void insert_after(Node *node, int value);
void append(Node **head, int value);
void init(Node **tail, Node **head, int value);
void deallocate(Node **tail, Node **head);

int main()
{
    char key1[] = "Quit", key2[] = "Purchase";
    char key3[] = "Add", key4[] = "Delete";
    char buffer[30];

    do
    {
        printf("Do you want to quit?\n");
        scanf("%4s", buffer);

        if (strcmp(key2, buffer) == 0)
        {
            printf("LOL!\n");
        }

    } while (strcmp(key1, buffer) != 0);

    printf("Correct answer!\n");
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
int count;
float price;

void insert_beginning(Node **tail, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
        return;
    }

    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = *tail;

    (*tail)->prev = new_node;
    *tail = new_node;
}

void init(Node **tail, Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(2);
        return;
    }

    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    *tail = new_node;
    *head = new_node;
}

void append(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        exit(3);
        return;
    }

    new_node->x = value;
    new_node->next = NULL;

    new_node->prev = *head;
    (*head)->next = new_node;
    (*head) = new_node;
}

void insert_after(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(4);
        return;
    }

    new_node->x = value;
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

Node *find_node(Node *tail, int value)
{
    for (Node *curr = tail; curr != NULL; curr = curr->next)
    {
        if (curr->x == value)
            return curr;
    }
    return NULL;
}