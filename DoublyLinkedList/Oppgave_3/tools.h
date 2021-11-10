#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TOOLS_H_
#define __TOOLS_H_

void deallocate(Node **tail, Node **head);
void insert_beginning(Node **tail, float value);
void init(Node **tail, Node **head, float value);
void append(Node **head, float price, char *p_name, int iCount);
void insert_after(Node *node, float value);
void remove_node(Node *node);
Node *find_node(Node *tail, float value);
void print_dll(Node *node);
void remove_last(Node **head);
void remove_all_instances_of(Node *tail, char *value);

#endif