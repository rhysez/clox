#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2); // Returns index of constant in pool. 
  writeChunk(&chunk, OP_CONSTANT); // Write opcode to next element of bytecode array. 
  writeChunk(&chunk, constant); // Write constant index operand so Clox knows where to find the constant to execute.
  writeChunk(&chunk, OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);

  return 0;
}