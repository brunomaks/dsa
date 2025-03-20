#include <stdio.h>
#include "include/dynamicArray.h"

int main(void) {
    Array* dynamicArray = createArray(10);

    destroyArray(dynamicArray);
    return 0;
}