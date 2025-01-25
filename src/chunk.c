#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk)
{
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

// Free chunk from memory and replace with empty chunk.
void freeChunk(Chunk *chunk)
{
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}

// If chunk does not have capacity for a new byte,
// Grow capacity to double of the previous capacity.
// Allocate a new array to 'code' field,
// Store the next byte at the next free element in the array,
// Finally, increment count.
void writeChunk(Chunk *chunk, uint8_t byte)
{
    if (chunk->capacity < chunk->count + 1)
    {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}