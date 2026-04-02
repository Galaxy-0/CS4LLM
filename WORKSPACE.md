# Workspace Guide

## Purpose

`CS4LLM` is organized as a workspace for multiple systems-oriented course projects.

The maintenance rule is simple:

- The top-level repository manages documents, notes, and shared helper scripts.
- Each course project keeps its own upstream, branches, and commit history.
- Task execution happens inside the child repository that owns the code.

## Project Map

| Path | Type | Focus | Current Role | Common Entry Points | Common Commands |
| --- | --- | --- | --- | --- | --- |
| `00-Archive-Early-Experiments` | plain directory | early C/compiler/network experiments | reference only | `00-Playground`, `02-Compilers`, `03-Networking`, `04-ProbLang` | none standardized |
| `06-MIT-6.S081-xv6-labs` | independent git repo | operating systems / xv6 | active | `conf/lab.mk`, `Makefile`, `kernel/`, `user/` | `make qemu`, `make grade` |
| `07-Stanford-CS144-Sponge` | placeholder directory | computer networks | waiting for official skeleton | `README.md` | not ready |
| `08-CMU-15-445-BusTub` | independent git repo | database systems | active | `README.md`, `src/`, `test/`, `CMakeLists.txt` | `mkdir build && cd build && cmake .. && make`, `ctest --output-on-failure` |
| `09-MIT-6.824-Distributed` | independent git repo | distributed systems | active | `Makefile`, `src/raft`, `src/kvraft`, `src/mr` | `cd src && go test ./...`, `make lab1`...`make lab5b` |
| `10-Stanford-CS143-Compiler` | placeholder directory | compilers | waiting for official skeleton | `README.md` | not ready |

## Practical Workflow

When working on a task, use this sequence:

1. Decide which child repository owns the task.
2. Work and commit inside that child repository.
3. Use the top-level repository only for workspace notes, task tracking, and helper scripts.
4. Avoid cross-project edits unless the change is purely documentation or tooling at the workspace level.

## Current Reality

- The outer repository currently acts as a shell for the workspace and is not the right place for code-level course commits.
- `xv6`, `BusTub`, and `6.824` are the main active code repositories.
- `CS144` and `CS143` are placeholders until official skeletons are added.
- Archive content is useful for discussion and experiments, but it should not be confused with the main course track.

## Status Script

Run the following from the workspace root:

```bash
bash scripts/repo-status.sh
```

The script reports:

- repository path
- whether it is an independent git repo or a placeholder/archive
- current branch
- configured upstream
- clean or dirty state
- most recent commit summary

Use it before switching contexts so we always know which repository is actually being modified.
