# CS4LLM Assessment

This assessment is scoped to `CS4LLM`.

It measures one thing:

> Can the user use AI agents to learn CS fundamentals quickly enough to collaborate at an engineer / architect level, while retaining enough conceptual ownership to judge reliability?

Personal founder / VC / career strategy is intentionally out of scope here. Keep that in the TODO repository.

## Core Diagnosis

The current gap is:

```text
AI-assisted project execution > independent CS ownership
```

That is not a failure. It is the normal shape of AI-accelerated learning.

The risk is also clear:

```text
If the user cannot explain the invariants, failure modes, and verification boundaries, agent-generated systems become hard to trust.
```

So this repository should not try to recreate old-school hand-coding education. It should train modern engineering judgment:

```text
know what matters -> ask agents for leverage -> verify the dangerous parts -> learn the concept in context
```

## Two-Mode Scoring

Every capability should be scored in two modes:

| Mode | What It Measures | Why It Matters |
| --- | --- | --- |
| AI-assisted score | With Codex/agents, can the user move the project forward? | Measures real current leverage |
| Independent ownership score | Without reading an answer, can the user explain, debug, and judge the system? | Measures whether the knowledge is internalized |

## Current Top-Level Scores

| Layer | Current Estimate | Notes |
| --- | ---: | --- |
| AI-assisted CS/project execution | 65-75 | Can organize repos, run tests, split commits, use agents, and produce artifacts |
| Independent CS conceptual ownership | 30-45 | Many systems projects exist, but oral explanation/debug ownership is still thin |
| Engineering reliability judgment | 35-50 | Starting to form through tests/status scripts, but not yet a default instinct |
| Architecture judgment with agents | 40-55 | Good high-level taste, still needs stronger invariants/failure-mode grounding |
| Traditional from-scratch implementation | 25-40 | Not the primary goal, but toy reimplementation is still useful for key concepts |

## CS Module Scorecard

Scale:

```text
0 = 陌生
1 = 能跟着跑
2 = 能讲人话
3 = 能 debug
4 = 能重写小版
5 = 能设计取舍
```

| Module | Current Estimate | Near-Term Target | Why It Matters |
| --- | ---: | ---: | --- |
| MapReduce | 1 | 3 | Distributed task dispatch, retry, intermediate data |
| xv6 syscall / trap | 1-2 | 3 | How programs cross into the OS |
| BusTub Buffer Pool | 1-2 | 3 | Memory/disk boundary and database reliability |
| B+ Tree | 1-2 | 3 | Ordered storage, page structure, index invariants |
| clox VM | 2 | 3 | How source-level programs become runtime execution |
| nanoc pipeline | 2 | 3 | Compiler stages: source -> AST -> typecheck -> IR -> assembly |
| TCP reliable stream | 0-1 | 3 | Biggest missing systems area |
| Raft leader election | 1 | 3 | How machines choose a coordinator |
| Raft log replication | 1 | 3 | How machines agree on ordered operations |
| KV request path | 1 | 3 | User request -> replicated state machine -> reply |
| MVCC / transaction | 1 | 3 | Database correctness under concurrency |
| Debug / performance basics | 1 | 3 | How to investigate failures without guessing |

## What Engineer / Architect Level Means Here

For this repo, "engineer / architect level" does not mean memorizing all CS theory.

It means the user can look at an agent-generated or agent-assisted system and answer:

1. What are the main states?
2. What invariant must always hold?
3. What happens if this process crashes or retries?
4. What happens if two things happen concurrently?
5. What data can be lost, duplicated, or corrupted?
6. What test/log/trace proves this risk is controlled?
7. What part is safe to let AI generate, and what part must be reviewed by the user?

## Evidence Protocol

A module can raise its score only with evidence.

| Evidence Type | Required Question |
| --- | --- |
| Artifact | Is there code, a note, a diagram, a toy demo, or command output? |
| Explanation | Can the user explain the concept in plain language? |
| Code path | Can the user name the files/functions involved? |
| Failure mode | Can the user describe one concrete way it breaks? |
| Verification | Is there a test, command, trace, or inspection that checks the claim? |

No evidence, no score increase.

## Baseline Diagnostic

Use [BASELINE_QUESTIONNAIRE.html](./BASELINE_QUESTIONNAIRE.html) for the fillable first-month diagnostic. The Markdown source version is [BASELINE_QUESTIONNAIRE.md](./BASELINE_QUESTIONNAIRE.md).

It measures five practical dimensions:

1. Map and mental model.
2. Code path and local navigation.
3. Invariant and failure mode.
4. Verification and debug loop.
5. Agent collaboration and architecture judgment.

Each dimension should be scored twice:

```text
Pass A: independent, no search and no AI
Pass B: AI-assisted, after Codex/repo help
```

The gap between Pass A and Pass B is a useful signal. A large gap means the user has strong leverage with agents but still needs more internal ownership.

## Current 8-Module Sprint

Do not open more tracks until these are reviewed at Level 2-3:

```text
1. MapReduce
2. xv6 syscall/trap
3. BusTub Buffer Pool
4. clox VM
5. TCP reliable stream
6. Raft leader election
7. Raft log replication
8. KV request path
```

## Recommended Cycle Shape

Each review cycle should stay small:

```text
Target:
Concept:
Reliability risk:
Files to inspect:
Command/test/demo:
One-page note:
Oral-defense questions:
```

Example:

```text
Target: MapReduce
Concept: Coordinator assigns map/reduce tasks to workers.
Reliability risk: worker crashes can leave tasks stuck forever.
Files to inspect: src/mr/coordinator.go, src/mr/worker.go, src/mr/rpc.go
Command/test/demo: run or inspect test-mr.sh behavior
One-page note: explain normal flow and retry flow
Oral-defense questions: why reduce waits for all map tasks; how retry works
```

## Out-Of-Scope Redirect

If a conversation drifts into personal career strategy, founder route, or VC planning, move it to:

```text
/Users/galaxy/Project/GalaxyAI/TODO/knowledge/career/
```

`CS4LLM` should only keep the CS learning implications.
