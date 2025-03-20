#include <stdio.h>
#include "../include/linkedList.h"

#define assert(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed, file %s, line %d\n", \
                     __FILE__, __LINE__); \
        } \
    } while (0)

void testCreateNode() {
    Node *node = createNode(10);
    assert(node != NULL); // Check if node was created
    assert(node->value == 10); // Check if value is correct
    assert(node->next == NULL); // Check if next is NULL
    freeList(node);
    printf("testCreateNode finished successfully.\n");
}

// Test insertFront
void testInsertFront() {
    Node *head = NULL;

    // Insert first node
    assert(insertFront(&head, 10)); // Check if insertion succeeds
    assert(head != NULL); // Check if head is updated
    assert(head->value == 10); // Check if value is correct
    assert(head->next == NULL); // Check if next is NULL

    // Insert second node
    assert(insertFront(&head, 20));
    assert(head->value == 20); // New head should have value 20
    assert(head->next->value == 10); // Next node should have value 10

    freeList(head);
    printf("testInsertFront finished successfully.\n");
}

// Test insertEnd
void testInsertEnd() {
    Node *head = createNode(10); // Create a list with one node

    // Insert at the end
    assert(insertEnd(head, 20));
    assert(head->next != NULL); // Check if next node was created
    assert(head->next->value == 20); // Check if value is correct
    assert(head->next->next == NULL); // Check if next is NULL

    freeList(head);
    printf("testInsertEnd finished successfully.\n");
}

// Test search
void testSearch() {
    Node *head = createNode(10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    // Search for existing values
    Node *result = search(head, 20);
    assert(result != NULL); // Check if node was found
    assert(result->value == 20); // Check if value is correct

    result = search(head, 30);
    assert(result != NULL);
    assert(result->value == 30);

    // Search for non-existing value
    result = search(head, 40);
    assert(result == NULL); // Check if NULL is returned for non-existing value

    freeList(head);
    printf("testSearch finished successfully.\n");
}

// Test deleteNode
void testDeleteNode() {
    Node *head = createNode(10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    // Delete middle node
    assert(deleteNode(head, 20)); // Check if deletion succeeds
    assert(head->next->value == 30); // Check if list is updated

    // Delete last node
    assert(deleteNode(head, 30));
    assert(head->next == NULL); // Check if list is updated

    // Delete non-existing node
    assert(!deleteNode(head, 40)); // Check if deletion fails for non-existing value

    freeList(head);
    printf("testDeleteNode finished successfully.\n");
}

// Test freeList
void testFreeList() {
    Node *head = createNode(10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    freeList(head); // Free the entire list
    // No assertions here, but valgrind or similar tools can check for memory leaks
    printf("testFreeList finished successfully.\n");
}

int main() {
    testCreateNode();
    testInsertFront();
    testInsertEnd();
    testSearch();
    testDeleteNode();
    testFreeList();

    return 0;
}
