#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* createNode(int value);
bool insertFront(Node **head, int value);
bool insertEnd(Node *head, int value);
bool deleteNode(Node *head, int value);
Node* search(Node *head, int value);
void freeList(Node *head);

#endif