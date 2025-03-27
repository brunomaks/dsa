#include <stdlib.h>
#include "../include/stack.h"

Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if(!newNode) {
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int pop(Node **stack) {
    Node *temp = *stack;
    int value = temp->value;
    *stack = temp->next;
    free(temp);
    return value;
}


bool push(Node **stack, int value) {
    Node *newNode = createNode(value);
    newNode->next = *stack;
    *stack = newNode;
}

int peek(Node *stack) {
    return stack->value;
}

bool isEmpty(Node *stack) {
    if(!stack) {
        return true;
    }
    return false;
}

void freeList(Node *head) {
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
