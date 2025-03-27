#include <stdio.h>
#include <limits.h>
#include "tests.h"
#include "../include/stack.h"

void testCreateNodeStack() {
    Node *node = createStack(10);
    assert(node != NULL); // Check if node was created
    assert(node->value == 10); // Check if value is correct
    assert(node->next == NULL); // Check if next is NULL
    freeStack(node);
    printf("testCreateNode passed\n");
}

void test_push() {
    Node *stack = NULL;
    assert(push(&stack, 10));
    assert(push(&stack, 20));
    assert(push(&stack, 30));
    assert(peek(stack) == 30);
    printf("test_push passed\n");
    freeStack(stack);
}

// Test 3: Peek top element
void test_peek() {
    Node *stack = NULL;
    push(&stack, 42);
    assert(peek(stack) == 42);
    freeStack(stack);
    printf("test_peek passed\n");
}

// Test 4: Pop elements and validate order (LIFO)
void test_pop() {
    Node *stack = NULL;
    push(&stack, 100);
    push(&stack, 200);
    push(&stack, 300);
    
    assert(pop(&stack) == 300);
    assert(pop(&stack) == 200);
    assert(pop(&stack) == 100);
    assert(isEmpty(stack));

    printf("test_pop passed\n");
}

// Test 5: Pop from an empty stack
void test_pop_empty() {
    Node *stack = NULL;
    assert(pop(&stack) == INT_MIN);
    printf("test_pop_empty passed\n");
}

// Test 6: Peek from an empty stack
void test_peek_empty() {
    Node *stack = NULL;
    assert(peek(stack) == INT_MIN);
    printf("test_peek_empty passed\n");
}

// Test freeStack
void testFreeStack() {
    Node *stack = createStack(10);
    push(&stack, 20);
    push(&stack, 30);

    freeStack(stack); // Free the entire list
    // No assertions here, but valgrind or similar tools can check for memory leaks
    printf("testFreeList passed\n");
}

void runStackTests() {
    printf(":::::::::Stack tests:::::::::\n");
    testCreateNodeStack();
    test_peek();
    test_peek_empty();
    test_push();
    test_pop();
    test_pop_empty();
    testFreeStack();
    printf(":::::::::Stack tests:::::::::\n\n");
}


