#include <stdlib.h>
#include "../include/linkedList.h"

Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if(!newNode) {
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

bool insertFront(Node **head, int value) {
    if(!head) {
        return false;
    }

    Node *newNode = createNode(value);
    if(!newNode) {
        return false;
    }

    newNode->next = *head;
    *head = newNode;
    return true;
}

bool insertEnd(Node *head, int value) {
    if(!head) {
        return false;
    }

    Node *newNode = createNode(value);
    if(!newNode) {
        return false;
    }

    while(head->next) {
        head = head->next;
    }

    head->next = newNode;
    return true;
}

Node* search(Node *head, int value) {
    if(!head) {
        return false;
    }

    while(head) {
        if(head->value == value) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

bool deleteNode(Node *head, int value) {
    if(!head) {
        return false;
    }

    while(head->next) {
        Node *nextHead = head->next;
        if(nextHead->value == value) {
            head->next = nextHead->next;
            nextHead->next = NULL;
            free(nextHead);
            return true;
        }
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