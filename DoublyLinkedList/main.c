#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int x;
    struct Node* next;
    struct Node* prev;
} Node;


void deallocate(Node** tail, Node** head)
{
    if (tail == NULL) return; 

    Node* curr = *tail; 
    while (curr->next != NULL)
    { // Jump to next and free previous node
        curr = curr->next; 
        free(curr->prev); 
    }
    free(curr); 

    *tail = NULL;
    *head = NULL;
}

void insert_beginning(Node** tail, int value)
{
    Node* new_node = malloc(sizeof(Node)); 
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


void init(Node** tail, Node** head, int value)
{
    Node* new_node = malloc(sizeof(Node));
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


void append(Node** head, int value)
{
    Node* new_node = malloc(sizeof(Node)); 

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


int main()
{
    Node* tail = NULL; 
    Node* head = tail; 
    
    init(&tail, &head, 7); 
    insert_beginning(&tail, 3); 
    insert_beginning(&tail, 1); 
    append(&head, 5); 

    for (Node* curr = tail; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x); 
    }

    deallocate(&tail, &head); 
    return 0; 
}