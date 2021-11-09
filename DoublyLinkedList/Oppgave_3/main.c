#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    // Initialize shopping cart (dll)
    Node *tail = NULL;
    Node *head = NULL;
    init(&tail, &head, 7.2);

    // Buffers
    char buffer;
    float b_price;
    int b_count;
    char *b_name;

    do
    {
        printf("\nEnter action: \n");
        scanf("%4s", &buffer);

        if (buffer == 'a')
        {
            printf("Enter product name: ");
            scanf("%s", b_name);
            printf("Enter price: ");
            scanf("%f", &b_price);
            printf("Enter amount: ");
            scanf("%d", &b_count);

            append(&head, b_price, b_name, b_count);
            printf("%dx - %s has been added to list\n", b_count, b_name);
        }
        else if (buffer == 'p')
        {
            printf("Triggered p\n");
        }

    } while (buffer != 'q');

    for (Node *curr = tail; curr != NULL; curr = curr->next)
    {
        printf("Product: %s - Price: %f - Amount: %d\n",
               curr->name, curr->price, curr->count);
    }

    deallocate(&tail, &head);
    printf("\nProgram finsihed executing\n");
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
        free(curr->name); // Free allocated name from n
        free(curr->prev); // Free allocated N's
    }
    free(curr); // Free last node

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

void append(Node **head, float price, char *p_name, int iCount)
{
    Node *new_node = malloc(sizeof(Node));
    char *n_name = malloc(sizeof(p_name));
    memcpy(n_name, p_name, sizeof(p_name));

    if (new_node == NULL)
    {
        exit(3);
        return;
    }

    new_node->count = iCount;
    new_node->name = n_name;
    new_node->price = price;
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