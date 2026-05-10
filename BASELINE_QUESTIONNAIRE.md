# CS4LLM Baseline Questionnaire

This is the first-month diagnostic for `CS4LLM`.

The goal is not to prove that the user already knows CS. The goal is to locate the current shape of understanding so the next month can stay small, concrete, and measurable.

Use this questionnaire before studying a module. Then repeat a shorter version after one month.

## What This Measures

Five dimensions:

| Dimension | Short Name | What It Measures |
| --- | --- | --- |
| D1 | Map and model | Can you place a concept on the CS map and explain what problem it solves? |
| D2 | Code path | Can you enter a real repo, find the moving parts, and trace a request or state change? |
| D3 | Invariant and failure | Can you name what must stay true and how the system breaks? |
| D4 | Verification and debug | Can you design a test, log, trace, or experiment that checks the claim? |
| D5 | Agent collaboration | Can you use Codex/agents for leverage while keeping judgment instead of blindly trusting output? |

These dimensions are intentionally practical. They are the minimum shape of "independent CS ownership" for agent-era engineering.

## Two-Pass Rule

Score every dimension in two passes.

| Pass | Rule | Meaning |
| --- | --- | --- |
| A. Independent | No search, no asking AI, no reading answers. You may say "I do not know." | Measures internal ownership. |
| B. AI-assisted | After Pass A, use Codex, repo search, notes, and tests for up to 20 minutes. | Measures agent-assisted execution and learning speed. |

The useful signal is not only the score. The useful signal is the gap:

```text
small independent score + large assisted jump = good learning leverage, weak ownership
medium independent score + medium assisted jump = usable ownership, still much to sharpen
high independent score + small assisted jump = already internalized
```

## Scoring Rubric

Each question is scored from 0 to 4.

| Score | Meaning |
| ---: | --- |
| 0 | Blank, wrong direction, or only "I do not know." |
| 1 | Recognizes terms but cannot explain the mechanism. |
| 2 | Can explain the normal flow in plain language. |
| 3 | Can name concrete state, code path, test, or failure behavior. |
| 4 | Can explain invariant, failure mode, verification, and a design tradeoff. |

Each dimension has 3 questions:

```text
dimension raw score = Q1 + Q2 + Q3, max 12
dimension 0-100 score = raw / 12 * 100
```

Interpretation:

| Score | Interpretation |
| ---: | --- |
| 0-20 | Mostly unknown. Start with mental models. |
| 21-40 | Can follow with help. Needs slow examples. |
| 41-60 | Can explain basics. Ready for guided repo review. |
| 61-80 | Can debug and verify with scaffolding. |
| 81-100 | Can teach, review, or rebuild a small version. |

## Fast Version

If tired, answer only these five questions first:

```text
D1-Q1, D2-Q1, D3-Q1, D4-Q1, D5-Q1
```

That gives a rough first radar. The full version can come later.

## Pass A Instructions

Answer in short paragraphs. Do not polish.

Good answer shape:

```text
Q:
My answer:
Confidence: low / medium / high
```

Saying "I do not know" is valid. It is better than producing fog.

## D1. Map And Mental Model

### D1-Q1. Place The Modules

Without looking anything up, place each item on the CS knowledge map and write one sentence for what problem it solves:

```text
MapReduce
xv6 syscall / trap
BusTub Buffer Pool
clox VM
TCP reliable stream
Raft leader election
```

### D1-Q2. Explain One Normal Flow

Pick one and explain the normal flow in plain language:

```text
A. MapReduce: input files -> workers -> map -> intermediate files -> reduce -> output
B. xv6 syscall: user program -> trap -> kernel handler -> return to user
C. clox VM: source code -> bytecode -> stack VM execution -> result
```

Use roles and state changes, not definitions.

### D1-Q3. Connect A Real Request

Imagine a user calls:

```text
Put("x", "1")
```

In a replicated key-value service, which CS areas might be involved?

Mention anything you can about:

```text
program/runtime, operating system, network, Raft/distributed systems, storage/database
```

It is okay if this is rough.

## D2. Code Path And Local Navigation

### D2-Q1. Find MapReduce Retry

If you need to inspect how MapReduce handles a crashed or slow worker, what files, functions, logs, tests, or search keywords would you look for?

You do not need exact names. The important part is your navigation strategy.

### D2-Q2. Trace One Request

Pick one module and trace input to output:

```text
A. MapReduce worker asks for work and reports completion
B. xv6 user program calls a syscall
C. BusTub fetches a page through the buffer pool
D. clox executes a function call
E. Raft client command becomes replicated state
```

Write the approximate path as:

```text
entry -> state change -> internal call -> output/reply
```

### D2-Q3. Enter An Unknown Repo

You open a course repo you barely know. How do you find:

```text
1. the main executable or test entry
2. the core source files
3. the smallest command that proves something works
4. the place to add a log or assertion
```

Give your practical sequence.

## D3. Invariant And Failure Mode

### D3-Q1. MapReduce Invariant

For MapReduce:

```text
Why must Reduce wait until all Map tasks are complete?
What can go wrong if a worker dies halfway through a task?
What can go wrong if the same task runs twice?
```

Name one invariant in one sentence.

### D3-Q2. Buffer Pool Or B+ Tree Invariant

Pick one:

```text
A. Buffer Pool: page pin count, dirty flag, eviction
B. B+ Tree: sorted keys, leaf links, split/merge behavior
```

What must stay true? What failure would corrupt data or return wrong results?

### D3-Q3. Raft Or TCP Failure

Pick one:

```text
A. Raft: stale leader, split vote, lost log entry, duplicated command
B. TCP: packet loss, reorder, duplicate packet, receiver buffer
```

Explain one failure mode and the mechanism that is supposed to control it.

## D4. Verification And Debug Loop

### D4-Q1. Prove Worker Retry

Design one small experiment to check that MapReduce reassigns work after a worker dies or gets stuck.

Answer:

```text
setup:
action:
expected observation:
what this proves:
what this does not prove:
```

### D4-Q2. Debug A Flaky Systems Test

A distributed systems test fails once every ten runs.

What do you inspect first?

Mention:

```text
logs, state variables, timing, concurrency, test seed, minimal reproduction
```

You do not need a perfect answer. I want your default debug instinct.

### D4-Q3. Passing Tests Are Not Proof

Pick any module.

What does a passing test prove? What does it not prove?

Give one example of a bug that could still exist after tests pass.

## D5. Agent Collaboration And Architecture Judgment

### D5-Q1. Ask An Agent Without Losing Ownership

Write a prompt you would give Codex to review one CS module.

The prompt should force the agent to return:

```text
main concept
code path
main invariant
failure mode
verification command or experiment
what the user must be able to explain
```

### D5-Q2. Review An Agent Patch

Codex gives you a patch for Raft, Buffer Pool, or MapReduce.

Before accepting it, what do you check?

Mention:

```text
invariant, failure mode, tests, code path, concurrency or retry behavior, rollback plan
```

### D5-Q3. Plan The First Month

Using the knowledge map, choose the first three modules for the next month.

For each module, define:

```text
why now:
stop condition:
evidence:
```

Keep it small enough that it could actually be done.

## Scoring Sheet

Fill this after Pass A. Fill it again after Pass B.

| Dimension | Questions | Pass A Raw /12 | Pass A /100 | Pass B Raw /12 | Pass B /100 | Notes |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| D1 Map and model | D1-Q1 to Q3 |  |  |  |  |  |
| D2 Code path | D2-Q1 to Q3 |  |  |  |  |  |
| D3 Invariant and failure | D3-Q1 to Q3 |  |  |  |  |  |
| D4 Verification and debug | D4-Q1 to Q3 |  |  |  |  |  |
| D5 Agent collaboration | D5-Q1 to Q3 |  |  |  |  |  |

## Result Template

Use this after I score the answers.

```text
Date:
Pass:

D1 Map and model:
D2 Code path:
D3 Invariant and failure:
D4 Verification and debug:
D5 Agent collaboration:

Strongest dimension:
Weakest dimension:
Largest AI-assisted jump:
Biggest reliability risk:

Next 7 days:
Module:
Concept:
Risk:
Verification:
Stop condition:
```

## One-Month Retest

After one month, do not repeat all questions. Use this shorter retest:

```text
1. Explain MapReduce normal and failure flow.
2. Trace one code path in xv6, BusTub, clox, TCP, or Raft.
3. Name one invariant and two failure modes for the current module.
4. Design one verification experiment.
5. Ask Codex for help, then state what you still personally own.
```

The one-month win condition is not "finish CS undergrad."

The win condition is:

```text
I can look at a CS systems module, find the core path, name the invariant, describe a failure, and verify one claim with agent help.
```
