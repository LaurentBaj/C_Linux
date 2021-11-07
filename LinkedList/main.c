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

void insert_beginning(Node** root, int value)
{
    Node* new_node = malloc(sizeof(Node)); 
    if (new_node == NULL)
    {
        return 3; 
    }

    new_node->x = value; 

     // Switch places with root
    new_node->next = *root; 
    *root = new_node; 
}

// Free dynamic memory (Linked list contents)
void deallocate(Node** root)
{
    Node* curr = *root; 
    while(curr != NULL)
    {
        Node* aux = curr; 
        curr = curr->next; 
        free(aux); 
    }
    *root = NULL;  
}

// Add node to a specific index in list
// param1: index in list, param2: value
void insert_after(Node* node, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) return 4; 
    new_node->x = value; 

    new_node->next = node->next; 
    node->next = new_node;  
}

void print_list(Node** root)
{
    Node* curr = *root;
    while (curr != NULL)
    {
        printf("%d\n", curr->x); 
        curr = curr->next; 
    }
}

void insert_sorted(Node** root, int value)
{
    if (*root == NULL || (**root).x >= value)
    {
        insert_beginning(root, value); 
        return; 
    }

    // Traverse to where we want to insert after
    Node* curr = *root; 
    while (curr->next != NULL)
    {
        if (curr->next->x >= value)
        {
            break; // jump before next line
        }
        curr = curr->next; 
    }

    insert_after(curr, value); 
}


remove_element(Node **root, int value){
    if (*root == NULL) return;

    Node* to_remove; 

    if ((*root)->x == value)
    {
        to_remove = *root;
        *root = (*root)->next;
        free(to_remove); 
        return;
    }

    for (Node* curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->x == value)
        {
            to_remove = curr->next; 
            curr->next = curr->next->next; 
            free(to_remove); 
            return; 
        }
    } 
}

void count_nodes(Node **root)
{
    if (root == NULL) return; 
    int counter = 0; 

    Node* curr = *root; 
    while (curr != NULL) 
    {
        counter++; 
        curr = curr->next; 
    }

    printf("\nSize of linked list: %d\n", counter);
}

int main()
{
    Node* root = NULL; 

    insert_beginning(&root, 3);
    insert_beginning(&root, 2);
    insert_beginning(&root, 1);

    append(&root, 5);  
    insert_after(root->next->next, 4);
    insert_sorted(&root, 2); 

    remove_element(&root, 1);
    print_list(&root); 

    count_nodes(&root); 

    deallocate(&root); 
    return 0; 
}
