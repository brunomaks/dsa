#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Array;

Array* createArray(size_t initial_capacity);
bool append(Array *array, int value);
bool insert(Array *array, size_t index, int value);
int get(Array *array, size_t index);
bool delete(Array *array, size_t index);
void destroy(Array *array);

#endif