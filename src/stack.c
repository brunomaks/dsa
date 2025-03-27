#include <stdlib.h>
#include <limits.h>
#include "../include/stack.h"

Node* createStack(int value) {
    Node *newNode = malloc(sizeof(Node));
    if(!newNode) {
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int pop(Node **stack) {
    if(!*stack) {
        return INT_MIN;
    }
    Node *temp = *stack;
    int value = temp->value;
    *stack = temp->next;
    free(temp);
    return value;
}


bool push(Node **stack, int value) {
    Node *newNode = createStack(value);
    if(!newNode) {
        return false;
    }
    newNode->next = *stack;
    *stack = newNode;
    return true;
}

int peek(Node *stack) {
    if(!stack) {
        return INT_MIN;
    }
    return stack->value;
}

bool isEmpty(Node *stack) {
    return stack == NULL;
}

void freeStack(Node *head) {
    if(!head) {
        return;
    }

    Node *temp = head;
    while(head) {
        head = head->next;
        free(temp);
        temp = head;
    }
}
