#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* createStack(int value);
int pop(Node **stack);
bool push(Node **stack, int value);
int peek(Node *stack);
bool isEmpty(Node *stack);
void freeStack(Node *head);

#endif


