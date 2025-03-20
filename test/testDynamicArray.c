#include <stdio.h>
#include "tests.h"
#include "../include/dynamicArray.h"

#define assert(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed, file %s, line %d\n", \
                     __FILE__, __LINE__); \
        } \
    } while (0)

void test_createArray() {
    Array* array = createArray(10);
    assert(array != NULL);
    assert(array->size == 0);
    assert(array->capacity == 10);
    destroy(array);
    printf("test_createArray passed\n");
}

void test_append() {
    Array* array = createArray(2);
    assert(array != NULL);

    // Append elements
    append(array, 10);
    append(array, 20);

    // Check size and capacity
    assert(array->size == 2);
    assert(array->capacity >= 2);

    // Check values
    assert(get(array, 0) == 10);
    assert(get(array, 1) == 20);

    destroy(array);
    printf("test_append passed\n");
}

void test_get() {
    Array* array = createArray(5);
    assert(array != NULL);

    // Append elements
    append(array, 10);
    append(array, 20);
    append(array, 30);

    // Test valid access
    assert(get(array, 0) == 10);
    assert(get(array, 1) == 20);
    assert(get(array, 2) == 30);

    // Test out-of-bounds access (should return -1)
    assert(get(array, 3) == -1);

    destroy(array);
    printf("test_get passed\n");
}

void test_grow() {
    Array* array = createArray(2);
    assert(array != NULL);

    // Append elements to trigger resize
    append(array, 10);
    append(array, 20);
    append(array, 30);

    // Check capacity after resize
    assert(array->capacity > 2); // Capacity should have increased

    // Check values
    assert(get(array, 0) == 10);
    assert(get(array, 1) == 20);
    assert(get(array, 2) == 30);

    destroy(array);
    printf("test_grow passed\n");
}

void test_shrink() {
    Array *array = createArray(4);

    append(array, 10);
    append(array, 20);
    append(array, 30);

    // Delete elements to trigger resize
    delete(array, 2);
    delete(array, 1);

    assert(array->capacity == 2);

    assert(get(array, 0) == 10);
    destroy(array);
    printf("test_shrink passed\n");
}

void test_delete() {
    Array *array = createArray(3);

    append(array, 10);
    append(array, 20);
    append(array, 30);

    assert(get(array, 0) == 10);
    assert(get(array, 1) == 20);
    assert(get(array, 2) == 30);

    // Delete elements
    delete(array, 2);
    delete(array, 1);

    // Check if two elements were deleted, should equal to -1
    assert(get(array, 0) == 10);
    assert(get(array, 1) == -1);
    assert(get(array, 2) == -1);
    destroy(array);
    printf("test_delete passed\n");
}

void test_destroyArray() {
    Array* array = createArray(10);
    assert(array != NULL);

    // Append some elements
    append(array, 10);
    append(array, 20);

    // Destroy the array
    destroy(array);
    printf("test_destroyArray passed\n");
}

void runDynamicArrayTests() {
    printf(":::::::::Dynamic Array:::::::::\n");
    test_createArray();
    test_append();
    test_get();
    test_delete();
    test_grow();
    test_shrink();
    test_destroyArray();
    printf(":::::::::Dynamic Array:::::::::\n\n");
}