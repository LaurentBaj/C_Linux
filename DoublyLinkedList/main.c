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


void insert_after(Node* node, int value)
{
    Node* new_node = malloc(sizeof(Node)); 
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


void remove_node(Node* node)
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


Node* find_node(Node* tail, int value)
{
    for (Node* curr = tail; curr != NULL; curr = curr->next)
    {
        if (curr->x == value) return curr; 
    } 
    return NULL; 
}



int main()
{
    Node* tail = NULL; 
    Node* head = NULL; 
    
    init(&tail, &head, 7); 
    insert_beginning(&tail, 3); 
    insert_beginning(&tail, 1); 
    insert_after(tail->next, 5); 
    remove_node(tail->next); 
    
    /* Need to do this upon removal of tail or head
    Node* aux = tail->next; 
    remove_node(tail); 
    tail = aux;  */

    Node* found = find_node(tail, 4); 
    if (found == NULL)
    {
        printf("Node was not found\n"); 

    }
    else 
    {
        printf("\nValue: %d; Next: %p\n", found->x, found->next); 
    }

    for (Node* curr = tail; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x); 
    }

    deallocate(&tail, &head); 
    return 0; 
}