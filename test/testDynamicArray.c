#include <stdio.h>
#include <assert.h>
#include "../include/dynamicArray.h"

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

void test_resize() {
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
    printf("test_resize passed\n");
}

void test_destroyArray() {
    Array* array = createArray(10);
    assert(array != NULL);

    // Append some elements
    append(array, 10);
    append(array, 20);

    // Destroy the array
    destroy(array);

    // Ensure no use-after-free (this is just a basic check)
    printf("test_destroyArray passed\n");
}

int main() {
    test_createArray();
    test_append();
    test_get();
    test_resize();
    test_destroyArray();

    printf("All tests passed!\n");
    return 0;
}