#include <stdio.h>
#include <stdlib.h>




typedef struct Node
{
    int x; 
    struct Node* next; 
} Node; 


void append(Node** root, int value)
{
    // Create node based on args  
    Node* new_node = malloc(sizeof(Node)); 
    if (new_node == NULL)
    {
        exit(1);     
    }
    new_node->next = NULL; 
    new_node->x = value; 

    // If Linked List is empty
    if (*root == NULL) 
    {
        *root = new_node; 
        return; 
    }

    // Traverse to tail and append 
    Node* curr = *root; 
    while (curr->next != NULL)
    {
        curr = curr->next;  
    }
    curr->next = new_node; 
}


int main()
{
    Node* root = NULL; 

    /*if (root == NULL) exit(2);  
    root->x = 15; 
    root->next = NULL;*/

    append(&root, -2);
    append(&root, 3);
    append(&root, 19);

    for (Node* curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }

    return 0; 
}