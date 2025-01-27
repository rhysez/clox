#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2); // Returns index of constant in pool. 
  writeChunk(&chunk, OP_CONSTANT, 123); // Write instruction (opcode) to next element of bytecode array. 
  writeChunk(&chunk, constant, 123); // Write constant operand to next element of bytecode array.
  writeChunk(&chunk, OP_RETURN, 123); // Add our return instruction to next element in bytecoe array.
  disassembleChunk(&chunk, "test chunk"); // Iterate through the chunk and execute instructions.
  freeChunk(&chunk); // Free the chunk from memory.

  return 0;
}
