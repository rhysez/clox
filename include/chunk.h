#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// A 'chunk' refers to a sequence of bytecode.

// Functions to be executed from instructions.
typedef enum {
    OP_RETURN, // Returns from the current function.
} Opcode;

// Bytecode instructions
typedef struct {
    int count; // The amount of allocated elements in use.
    int capacity; // The amount of elements we have allocated to the array.
    uint8_t* code; // A pointer to an array of unsigned 8-bit integers; AKA the opcode.
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif