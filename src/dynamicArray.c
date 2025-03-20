#include <stdlib.h>
#include "../include/dynamicArray.h"

#define GROWTH_FACTOR 1.5
#define SHRINK_FACTOR 2

void destroy(Array *array);
bool grow(Array *array);
bool shrink(Array *array);
bool sget(Array *array, size_t index, int *result);

Array* createArray(size_t initial_capacity) {
    if(initial_capacity < 1) {
        return NULL;
    }

    Array *dynamicArray = malloc(sizeof(Array));
    if(!dynamicArray) {
        return NULL;
    }

    int *data = malloc(initial_capacity * sizeof(int));
    if(!data) {
        free(dynamicArray);
        return NULL;
    }

    dynamicArray->data = data;
    dynamicArray->size = 0;
    dynamicArray->capacity = initial_capacity;

    return dynamicArray;
}


bool append(Array *array, int value) {
    if(!array) {
        return false;
    }

    if(array->size >= array->capacity ) {
        if(!grow(array)) {
            return false;
        }
    }

    array->data[array->size++] = value;

    return true;
}

bool insert(Array *array, size_t index, int value) {
    if(!array) {
        return false;
    }

    if(index >= array->capacity - 1) {
        return false;
    }

    if(array->size + 1 >= array->capacity) {
        if(!grow(array)) {
            return false;
        }
    }

    // shift the elements to the right
    for(size_t i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }

    array->size++;
    array->data[index] = value;
    return true;
}


int get(Array *array, size_t index) {
    int val;
    if(!sget(array, index, &val)) {
        return -1;
    }
    return val;
}

bool delete(Array *array, size_t index) {
    if(!array) {
        return false;
    }

    if(index >= array->size) {
        return false;
    }

    for(size_t i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->size--;

    if(array->size < (array->capacity / 2)) {
        shrink(array);
    }
    return true;
}


// safe get handles out of bounds access
bool sget(Array *array, size_t index, int *result) {
    if(!array) {
        return false;
    }

    if(index >= array->size) {
        return false;
    }

    if(!result) {
        return false;
    }

    *result = array->data[index];
    return true;
}

bool shrink(Array *array) {
    int newSize = array->capacity / SHRINK_FACTOR;

    int *data = realloc(array->data, newSize * sizeof(int));
    if(!data) {
        return false;
    }

    array->data = data;
    array->capacity = newSize;

    return true;
}

bool grow(Array *array) {
    int newSize = array->capacity * GROWTH_FACTOR;

    int *data = realloc(array->data, newSize * sizeof(int));
    if(!data) {
        return false;
    }

    array->data = data;
    array->capacity = newSize;

    return true;
}

void destroy(Array *array) {
    free(array->data);
    free(array);
}

