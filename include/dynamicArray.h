#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct DynamicArray Array;

Array* createArray(size_t initial_capacity);
void append(Array* array, int value);
void insert(Array* array, size_t index, int value);
int get(Array* array, size_t index);
void destroyArray(Array* array);

#endif