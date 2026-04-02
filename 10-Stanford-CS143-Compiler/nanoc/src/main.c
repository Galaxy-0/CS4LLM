#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "typecheck.h"
#include "ir.h"
#include "optimize.h"
#include "codegen.h"

static char* readFile(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "Cannot open %s\n", path); exit(1); }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    rewind(f);
    char* buf = malloc(sz + 1);
    fread(buf, 1, sz, f);
    buf[sz] = '\0';
    fclose(f);
    return buf;
}

int main(int argc, char** argv) {
    bool dumpAST = false, dumpIR = false, noOpt = false;
    const char* inputPath = NULL;
    const char* outputPath = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--ast") == 0) dumpAST = true;
        else if (strcmp(argv[i], "--ir") == 0) dumpIR = true;
        else if (strcmp(argv[i], "--no-opt") == 0) noOpt = true;
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
            outputPath = argv[++i];
        else inputPath = argv[i];
    }

    if (!inputPath) {
        fprintf(stderr, "Usage: nanoc [--ast] [--ir] [--no-opt] [-o output] <file.nano>\n");
        return 1;
    }

    char* source = readFile(inputPath);

    // 1. Parse → AST
    Node* program = parse(source);
    if (!program) {
        fprintf(stderr, "Parsing failed.\n");
        return 1;
    }

    if (dumpAST) {
        printf("=== AST ===\n");
        printAST(program, 0);
        printf("\n");
    }

    // 2. Type check
    if (!typecheck(program)) {
        fprintf(stderr, "Type checking failed.\n");
        return 1;
    }

    // 3. Generate IR
    IRProgram* ir = generateIR(program);

    if (dumpIR) {
        printf("=== IR (before optimization) ===\n");
        printIR(ir);
    }

    // 4. Optimize
    if (!noOpt) {
        optimize(ir);
    }

    if (dumpIR) {
        printf("=== IR (after optimization) ===\n");
        printIR(ir);
    }

    // 5. Codegen → ARM64 assembly
    // Derive output name from input if not specified
    char asmPath[256];
    if (outputPath) {
        snprintf(asmPath, sizeof(asmPath), "%s.s", outputPath);
    } else {
        // Replace .nano with .s
        snprintf(asmPath, sizeof(asmPath), "%s", inputPath);
        char* dot = strrchr(asmPath, '.');
        if (dot) strcpy(dot, ".s");
        else strcat(asmPath, ".s");
    }

    codegenARM64(ir, asmPath);

    // 6. Assemble and link
    char objPath[256], binPath[256];
    snprintf(objPath, sizeof(objPath), "%s", asmPath);
    char* dot = strrchr(objPath, '.');
    if (dot) strcpy(dot, ".o");

    if (outputPath) {
        snprintf(binPath, sizeof(binPath), "%s", outputPath);
    } else {
        snprintf(binPath, sizeof(binPath), "%s", inputPath);
        dot = strrchr(binPath, '.');
        if (dot) *dot = '\0';
    }

    char cmd[512];
    snprintf(cmd, sizeof(cmd), "as -o %s %s", objPath, asmPath);
    if (system(cmd) != 0) {
        fprintf(stderr, "Assembly failed.\n");
        return 1;
    }

    snprintf(cmd, sizeof(cmd), "ld -o %s %s -lSystem -L$(xcrun --show-sdk-path)/usr/lib -syslibroot $(xcrun --show-sdk-path) -arch arm64",
             binPath, objPath);
    if (system(cmd) != 0) {
        // Try simpler link command
        snprintf(cmd, sizeof(cmd),
                 "cc -o %s %s -arch arm64", binPath, objPath);
        if (system(cmd) != 0) {
            fprintf(stderr, "Linking failed.\n");
            return 1;
        }
    }

    printf("Compiled: %s → %s\n", inputPath, binPath);

    free(source);
    return 0;
}
