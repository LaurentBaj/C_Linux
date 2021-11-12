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

// Free heap
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

// Initialize cart (dll)
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

// Add product to head
void append(Node **head, float price, char *p_name, int iCount)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        exit(3);
        return;
    }

    // Provide unique product name
    char *n_name = malloc(sizeof(p_name));
    memcpy(n_name, p_name, sizeof(p_name));

    new_node->count = iCount;
    new_node->name = n_name;
    new_node->price = price;

    new_node->next = NULL;
    new_node->prev = *head;
    (*head)->next = new_node;
    (*head) = new_node;
}

// Remove single product
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

    free(node->name);
    free(node);
}

// Provide receipt
void print_dll(Node *node)
{
    float sum = 0;
    char receipt[100];
    memset(receipt, '=', 50);
    puts(receipt);
    puts("\n -- RECEIPT --");

    for (Node *curr = node->next; curr != NULL; curr = curr->next)
    {
        sum += (*curr).price * (*curr).count;
        printf("\nProduct: %s - Price: %f - Amount: %d\n",
               curr->name, curr->price, curr->count);
    }

    puts(receipt);
    printf("\nSum: %f$\n", sum);
    puts(receipt);
}

// Regret newly added product
void remove_last(Node **head)
{
    if (head == NULL)
    {
        exit(5);
        return;
    }

    Node *temp = *head;
    (*head)->prev->next = NULL; // Unchain head
    (*head) = temp;

    printf("\n%s has been removed from Cart\n", temp->name);
    free(temp->name);
    free(temp);
}

// FUNC DOES NOT WORK:
// This was supposed to delete all products with the same name
void remove_all_instances_of(Node *tail, char *value)
{
    if (tail = NULL)
    {
        exit(8);
        return;
    }

    // I can's seem to perform comparing ^value with (curr->name)
    Node *curr = tail;
    while (curr != NULL)
    {
        if (strcmp(curr->name, value) == 1)
        {
            remove_node(curr);
        }
    }
}
