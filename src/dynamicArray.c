#include <stdlib.h>
#include "../include/dynamicArray.h"

struct DynamicArray {
    int *data;
    size_t size;
    size_t capacity;
};

Array* createArray(size_t initial_capacity) {
    if(initial_capacity < 1) {
        return NULL;
    }
    Array *dynamicArray = malloc(sizeof(Array));

    int *data = malloc(initial_capacity * sizeof(int));

    dynamicArray->data = data;
    dynamicArray->size = 0;
    dynamicArray->capacity = initial_capacity;

    return dynamicArray;
}


void append(Array* array, int value);
void insert(Array* array, size_t index, int value);
int get(Array* array, size_t index);


void destroyArray(Array* array) {
    free(array->data);
    free(array);
}