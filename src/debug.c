#include <stdio.h>
#include "value.h"
#include "debug.h"

// Iterates through the bytecode chunk and disassemble each instruction.
void disassembleChunk(Chunk* chunk, const char* name)
{
    printf("== %s ==\n", name);

    // Note: Here we do not increment offset directly in the loop.
    // Instead, disassembleInstruction returns the offset of the next instruction.
    // Offset is then continually updated as Clox traverses the chunk's bytecode.
    for (int offset = 0; offset < chunk->count;)
    {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int constantInstruction(const char* name, Chunk* chunk, int offset)
{
    uint8_t constant = chunk->code[offset + 1]; // We find the next byte in chunk, which is our constant.
    printf("%-16s %4d", name, constant);
    printValue(chunk->constants.values[constant]);  
    printf("\n");
    return offset + 2; 
    // OP_RETURN is 2 bytes, 1 for the opcode and 1 for the operand.
    // So we return offset + 2, so get the operand value. 
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
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}