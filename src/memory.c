#include <stdlib.h>
#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    // Reallocate memory at the given pointer.
    void* result = realloc(pointer, newSize);
    
    // If we run out of memory, result will return NULL. 
    if (result == NULL) exit(1);

    return result;
}