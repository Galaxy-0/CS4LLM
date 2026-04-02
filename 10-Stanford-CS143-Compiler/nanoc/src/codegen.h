#ifndef NANOC_CODEGEN_H
#define NANOC_CODEGEN_H

#include "ir.h"

// Generates ARM64 assembly and writes to outPath.
void codegenARM64(IRProgram* prog, const char* outPath);

#endif
