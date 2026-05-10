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
| AI-assisted CS/project execution | 50-65 | Can use agents to push projects farther than the independent foundation currently supports |
| Layer 0 ownership | 15-30 | Python, Git, terminal, data structures, and CS math are still being stabilized |
| Independent CS conceptual ownership | 5-20 | Current honest coordinate is the Layer 0 starting point |
| Engineering reliability judgment | 10-25 | Testing/debug ideas are present, but not yet an independent habit |
| Architecture judgment with agents | 30-45 | Can discuss direction with agents, but needs stronger foundations before judging systems deeply |
| Traditional from-scratch implementation | 10-25 | Useful only in small toy exercises for now |

## Layer Scorecard

Scale:

```text
0 = 陌生
1 = 能跟着跑
2 = 能讲人话
3 = 能 debug
4 = 能重写小版
5 = 能设计取舍
```

| Layer / Module | Current Estimate | Near-Term Target | Why It Matters |
| --- | ---: | ---: | --- |
| Terminal / Git | 1 | 2-3 | Repo survival and daily learning workflow |
| Python reading | 1 | 2-3 | Ability to read small projects and trace data flow |
| Programming basics | 1 | 2-3 | Variables, functions, modules, errors, state |
| Data structures | 0-1 | 2 | Needed before algorithms, databases, compilers, and systems |
| Algorithms warmup | 0-1 | 2 | Complexity, recursion, BFS/DFS, basic problem-solving |
| CS math handles | 0-1 | 2 | Discrete math, linear algebra, probability, calculus intuition |
| Debug / verification basics | 1 | 2 | Ability to check claims instead of trusting generated output |
| MapReduce / xv6 / BusTub / Raft / TCP / Compiler projects | 0-1 independent, higher with agent help | Later Layer 1-2 target | Existing artifacts are useful later, but not the current active sprint |

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

Use [BASELINE_QUESTIONNAIRE.html](./BASELINE_QUESTIONNAIRE.html) only if a structured form is useful. The Markdown source version is [BASELINE_QUESTIONNAIRE.md](./BASELINE_QUESTIONNAIRE.md). The default path can also be direct Q&A with Codex.

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

## Current Layer 0 Sprint

Do not make systems projects the main sprint until Layer 0 is usable.

```text
1. Terminal / Git survival
2. Python project reading
3. Programming basics
4. Data structures
5. Algorithms warmup
6. CS math handles
7. Debug / verification basics
```

## Recommended Cycle Shape

Each review cycle should stay small:

```text
Target:
Layer:
Concept in human words:
Tiny example:
Code or command:
One-page note:
What I can explain without Codex:
```

Example:

```text
Target: Python project reading
Layer: 0
Concept in human words: Find where a program starts and how data moves through functions.
Tiny example: Trace one command or user action from entry point to output.
Code or command: rg for main/if __name__, run the script, inspect one function.
One-page note: entry point, key files, one data flow, still confusing.
What I can explain without Codex: what input enters, what state changes, what output appears.
```

## Out-Of-Scope Redirect

If a conversation drifts into personal career strategy, founder route, or VC planning, move it to:

```text
/Users/galaxy/Project/GalaxyAI/TODO/knowledge/career/
```

`CS4LLM` should only keep the CS learning implications.
