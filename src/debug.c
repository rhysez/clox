#include <stdio.h>

#include "debug.h"

// Iterates through the bytecode chunk and disassemble each instruction.
void disassembleChunk(Chunk* chunk, const char* name)
{
    printf("== %s ==\n", name);

    // Note: Here we do not increment offset directly in the loop.
    // Instead, disassembleInstruction returns the offset of the next instruction.
    for (int offset = 0; offset < chunk->count;)
    {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int simpleInstruction(const char* name, int offset)
{
    printf("%s\n", name);
    return offset + 1;
}

int disassembleInstruction(Chunk* chunk, int offset)
{
    printf("%04d ", offset);

    // Position (char) in chunk where current instruction lies.
    uint8_t instruction = chunk->code[offset];

    // This switch will determine which functions to run based on the instruction given.
    // If it's not a valid instruction, we throw an error.
    switch (instruction)
    {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}