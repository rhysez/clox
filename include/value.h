#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// ValueArray stores constant values.
// It behaves the same as our Chunk's bytecode array. 

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif