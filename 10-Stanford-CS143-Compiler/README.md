# Compiler Projects

This directory tracks local compiler practice projects. It is workspace-tracked rather than an independent course skeleton repository.

## clox

```bash
cd clox
make          # build
make test     # run all tests
./build/clox  # REPL
./build/clox tests/test_basic.lox  # run a file
```

A complete bytecode virtual machine for the Lox language, implemented in C following *Crafting Interpreters* Part III.

### What's Implemented (Ch14-29)

- **Bytecode chunks** — dynamic array of instructions + constant pool + line info
- **Stack-based VM** — instruction dispatch loop with runtime type checking
- **Scanner** — on-demand lexer for all Lox tokens
- **Pratt parser** — precedence climbing compiler, single-pass
- **Tagged union values** — bool, nil, number, obj (heap-allocated)
- **Strings** — heap-allocated, FNV-1a hashed, interned
- **Hash table** — open addressing with linear probing, tombstone deletion
- **Variables** — global (hash table) and local (stack slots), block scoping
- **Control flow** — if/else, while, for, and/or short-circuit
- **Functions** — first-class, closures with upvalue capture
- **Garbage collector** — mark-sweep, tri-color marking, GC stress test mode
- **Classes** — instances, fields, methods, `this`, `init` constructors
- **Inheritance** - `<` syntax, `super` calls, method resolution via copy-down

### Project Structure

```
clox/
  src/
    main.c        — REPL and file runner
    scanner.c/h   — lexer
    compiler.c/h  — Pratt parser + bytecode emitter
    vm.c/h        — virtual machine
    chunk.c/h     — bytecode container
    object.c/h    — heap objects (string, function, closure, class, instance)
    table.c/h     — hash table
    value.c/h     — tagged union Value type
    memory.c/h    — allocator + GC
    debug.c/h     — disassembler
    common.h      — shared includes and debug flags
  tests/          — .lox test scripts
  Makefile
```

## nanoc

```bash
cd nanoc
make          # build
make test     # compile and run sample programs
./build/nanoc --ast --ir tests/simple.nano
```

A compact C-like compiler practice project with a full source-to-native pipeline:

- Lexer and parser for `.nano` source files
- AST construction and printing
- Type checking for integer and boolean programs
- IR generation and optimization passes
- ARM64 assembly code generation
- Assemble/link step to produce local executables on macOS

### Project Structure

```
nanoc/
  src/
    lexer.c/h      - tokenizer
    parser.c/h     - parser and AST builder
    ast.c/h        - syntax tree structures and printer
    typecheck.c/h  - semantic checks
    ir.c/h         - intermediate representation
    optimize.c/h   - IR optimization
    codegen.c/h    - ARM64 assembly generation
    main.c         - compiler driver
  tests/           - .nano sample programs
  Makefile
```
