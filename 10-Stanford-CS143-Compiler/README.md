# Compiler Project — clox (Crafting Interpreters)

A complete bytecode virtual machine for the Lox language, implemented in C following *Crafting Interpreters* Part III.

## Build & Run

```bash
cd clox
make          # build
make test     # run all tests
./build/clox  # REPL
./build/clox tests/test_basic.lox  # run a file
```

## What's Implemented (Ch14-29)

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
- **Inheritance** — `<` syntax, `super` calls, method resolution via copy-down

## Project Structure

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
