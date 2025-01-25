#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// If capacity is smaller than 8, set to 8. Else, double capacity.
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

// Reallocate memory at pointer to code,
// Starts by freeing the bytes * the old count.
// Next, allocates bytes * the new count.
// See definition of reallocate() for implementation.
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

// Calls reallocate but initiates new chunk to empty.
#define FREE_ARRAY(type, pointer, oldSize) \
    reallocate(pointer, sizeof(type) * oldSize, 0)

// Handles reallocating memory at a given memory address.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif