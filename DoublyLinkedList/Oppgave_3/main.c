#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/tools.h"

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

    printf("Welcome to this emulated online store!\n");
    printf("Enter 'a' to add new items, 'r' to remove last added item\n\n");

    // Program
    do
    {
        printf("\nEnter action: ");
        scanf("%c", &buffer);

        if (buffer == 'a') // add product
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
        else if (buffer == 'r') // Regret last product added
        {
            remove_last(&head);
        }
        /* Remove all instances of a product - function does not work
        else if (buffer == 'x')
        {
            printf("Delete all: ");
            scanf(%s, buffer);
            remove_all_instance_of(&head, buffer);
        } */
    } while (buffer != 'q');

    // Create receipt + free heap
    print_dll(tail);
    deallocate(&tail, &head);
    return 0;
}
