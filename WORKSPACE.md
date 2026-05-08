# Workspace Guide

## Purpose

`CS4LLM` is organized as a workspace for multiple systems-oriented course projects.

The maintenance rule is simple:

- The top-level repository manages documents, notes, shared helper scripts, and workspace-tracked practice code such as CS143.
- Independent child repositories keep their own upstream, branches, and commit history.
- Task execution happens inside the directory that owns the code; commits happen either in that child repo or, for workspace-tracked directories, in the top-level repo.

## Project Map

| Path | Type | Focus | Current Role | Common Entry Points | Common Commands |
| --- | --- | --- | --- | --- | --- |
| `00-Archive-Early-Experiments` | plain directory | early C/compiler/network experiments | reference only | `00-Playground`, `02-Compilers`, `03-Networking`, `04-ProbLang` | none standardized |
| `06-MIT-6.S081-xv6-labs` | independent git repo | operating systems / xv6 | active | `conf/lab.mk`, `Makefile`, `kernel/`, `user/` | `make qemu`, `make grade` |
| `07-Stanford-CS144-Sponge` | placeholder directory | computer networks | waiting for official skeleton | `README.md` | not ready |
| `08-CMU-15-445-BusTub` | independent git repo | database systems | active | `README.md`, `src/`, `test/`, `CMakeLists.txt` | `mkdir build && cd build && cmake .. && make`, `ctest --output-on-failure` |
| `09-MIT-6.5840-Distributed-Systems` | independent git repo | distributed systems | active | `Makefile`, `src/raft`, `src/kvraft`, `src/mr` | `cd src && go test ./mr ./kvsrv ./raft ./kvraft ./shardctrler ./shardkv`, `make lab1`...`make lab5b` |
| `10-Stanford-CS143-Compiler` | workspace-tracked directory | compilers | active local practice | `README.md`, `clox/`, `nanoc/` | `cd clox && make test`, `cd nanoc && make test` |

## Practical Workflow

When working on a task, use this sequence:

1. Decide which directory owns the task.
2. If it is an independent child repo, work and commit inside that repo.
3. If it is workspace-tracked code such as CS143 or top-level docs/scripts, commit in the top-level repository.
4. Avoid cross-project edits unless the change is documentation or workspace tooling.

## Current Reality

- The outer repository currently acts as a shell for the workspace and is not the right place for code-level course commits.
- `xv6`, `BusTub`, and `6.5840` are the main active independent code repositories.
- `CS143` is an active workspace-tracked compiler practice area with `clox` and `nanoc`.
- `CS144` is a placeholder until the official skeleton is added.
- Archive content is useful for discussion and experiments, but it should not be confused with the main course track.

## Status Script

Run the following from the workspace root:

```bash
bash scripts/repo-status.sh
```

The script reports:

- repository path
- whether it is an independent git repo, workspace-tracked code, placeholder, or archive
- current branch
- configured upstream
- clean or dirty state
- ahead/behind sync state for independent git repositories
- most recent commit summary

Use it before switching contexts so we always know which repository is actually being modified.
