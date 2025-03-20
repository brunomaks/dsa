#include <stdio.h>
#include "include/dynamicArray.h"

int main(void) {
    Array* dynamicArray = createArray(10);
    if(!dynamicArray) {
        printf("Failed to instantiate a dynamic array\n");
        return 0;
    }
    append(dynamicArray, 1);
    append(dynamicArray, 2);
    append(dynamicArray, 3);

    printf("%d, ", get(dynamicArray, 0));
    printf("%d, ", get(dynamicArray, 1));
    printf("%d, ", get(dynamicArray, 2));
    printf("%d, ", get(dynamicArray, 3));

    insert(dynamicArray, 0, 100);

    printf("%d, ", get(dynamicArray, 0));
    printf("%d, ", get(dynamicArray, 1));
    printf("%d, ", get(dynamicArray, 2));
    printf("%d, ", get(dynamicArray, 3));


    destroy(dynamicArray);
    return 0;
}