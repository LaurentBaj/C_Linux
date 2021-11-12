#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TOOLS_H_
#define __TOOLS_H_

typedef struct Node
{
    char *name;
    int count;
    float price;
    struct Node *next;
    struct Node *prev;
} Node;

void deallocate(Node **tail, Node **head);
void init(Node **tail, Node **head, float value);
void append(Node **head, float price, char *p_name, int iCount);
void remove_node(Node *node);
void print_dll(Node *node);
void remove_last(Node **head);

void remove_all_instances_of(Node *tail, char *value);

#endif