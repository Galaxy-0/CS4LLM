# Goal-Driven Operating Contract

This file turns the broad five-year ladder into a criteria-driven execution loop for `CS4LLM`.

The five-year ladder is the north star:

```text
高级独立全栈开发者 -> operator-founder -> VC / operator-investor
```

The Goal-Driven loop should not try to verify the whole five-year identity arc directly. It should verify near-term evidence that compounds toward that arc.

## Current Goal

Over the next 12 weeks, convert the existing CS/AI project artifacts into independently owned capability evidence, while starting a small but measurable founder loop.

## Why This Goal

The current assessment says:

```text
AI-assisted execution > Independent conceptual ownership
```

So the immediate work is not to open more projects. The immediate work is to turn existing projects into evidence that can survive four checks:

- Artifact: something exists in code/docs/demo form.
- Oral defense: you can explain it without hiding behind AI.
- Debug trial: you can reason when it breaks.
- External validation: someone outside the loop reacts, uses, pays, or gives signal.

## Criteria v0.1

The program is successful only if these criteria are checked against real evidence.

Criteria v0.1 is active by default until the user explicitly changes it.

### C1. Assessment Artifacts Exist And Stay Current

Evidence:

- `KNOWLEDGE_MAP.md` exists and maps the CS/AI territory.
- `ASSESSMENT.md` exists and records the two-mode scorecard.
- `GOAL.md` exists and defines the active Goal-Driven contract.

Verification:

```bash
test -f KNOWLEDGE_MAP.md
test -f ASSESSMENT.md
test -f GOAL.md
```

### C2. Every Work Cycle Has One Explicit Target

Each cycle must name exactly one target:

```text
Target:
Why now:
Criteria:
Verification:
Stop condition:
```

Good target examples:

- MapReduce review
- xv6 syscall/trap review
- BusTub Buffer Pool review
- clox VM review
- TCP reliable stream toy demo
- Aporia 5-minute playtest

Bad target examples:

- Become stronger at CS
- Think through founder route
- Improve product sense
- Study AI Infra broadly

Verification:

- The cycle has a written target block.
- The target has at least 3 criteria.
- At least 2 criteria are artifact/command/test based.

### C3. CS Module Completion Requires Four Evidence Types

A CS module is not considered reviewed until it has:

1. A one-page human explanation.
2. A code-path map or file-path walkthrough.
3. One failure/debug scenario.
4. One tiny experiment, test, or command output.

Verification:

- A review note exists for the module.
- The note includes all four sections.
- The command/test/experiment can be rerun or inspected.

Initial module queue:

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

### C4. Scores Can Only Move When Evidence Changes

No score in `ASSESSMENT.md` should be raised because of motivation, confidence, or vibes.

Allowed score-change evidence:

- Passing tests or demos.
- Written module review.
- Successful oral defense transcript or summary.
- Debug trial result.
- External user/customer/investor signal.

Verification:

- Any score update must include a short evidence note.
- If evidence is missing, keep the score unchanged.

### C5. Founder Loop Requires External Action

Founder progress is not measured by planning. It is measured by contact with reality.

Minimum 12-week evidence:

- 10 external touches.
- 3 deep conversations.
- 1 offer, price test, or explicit ask.
- 1 written case note or playtest report.

Verification:

- Each external touch has date, person/type, ask, response, and next step.
- The offer/price test records what was offered and what happened.

### C6. Master Verification Beats Worker Self-Report

When subagents or AI workers are used:

- Workers may explore, implement, summarize, or draft.
- The master must verify against criteria.
- "Done" is never accepted from narrative self-report alone.

Verification:

- The master checks files, commands, tests, diffs, screenshots, transcripts, or written artifacts.
- Failed criteria are restated before restart.

## Execution Loop

Each loop follows this shape:

```text
1. Normalize the target.
2. Freeze criteria.
3. Delegate or execute.
4. Verify against evidence.
5. Update score/artifacts only if criteria pass.
6. If criteria fail, restart with the exact remaining gap.
```

## Master / Worker Roles

Master:

- Holds the goal and criteria steady.
- Prevents vague expansion.
- Verifies evidence.
- Decides whether to continue, restart, or stop.

Worker:

- Reads code/docs.
- Produces review notes, patches, experiments, or tests.
- Reports evidence and gaps.

User:

- Owns the final learning.
- Attempts oral defense and explanations.
- Chooses whether to accept criteria changes.
- Performs external founder-loop actions when needed.

## First Concrete Target

Target:

```text
MapReduce review
```

Why now:

```text
It is the gentlest entry point into distributed systems and already exists in the 6.5840 repo.
```

Criteria:

1. Explain Coordinator, Worker, Task, Map, Reduce, retry in human language.
2. Walk through the relevant files in `09-MIT-6.5840-Distributed-Systems/src/mr`.
3. Describe one normal flow and one worker-failure flow.
4. Run or inspect one command/test/demo tied to MapReduce.
5. Produce a one-page review note.

Verification:

- The review note exists.
- The file walkthrough names concrete files/functions.
- The command/test output is recorded.
- The user can answer five oral-defense questions without reading a generated explanation.

## Criteria Change Rule

Criteria may change, but only before a cycle starts or after a failed verification.

Do not change criteria mid-cycle just because the work became uncomfortable.

## Prompt-To-Artifact Checklist

| Prompt Requirement | Artifact / Evidence | Status |
| --- | --- | --- |
| Build a knowledge map for the CS/AI learning route | `KNOWLEDGE_MAP.md` | done |
| Record a capability assessment with two-mode scoring | `ASSESSMENT.md` | done |
| Turn the five-year ladder into a near-term measurable contract | `GOAL.md` current goal and Criteria v0.1 | done |
| Keep the five-year ladder visible without making it the direct verifier | `GOAL.md` north star and 12-week goal separation | done |
| Define criteria even though they were initially unclear | `GOAL.md` C1-C6 | done |
| Make criteria evidence-based, not subjective | C1 command checks, C2 target blocks, C3 review evidence, C4 score-change evidence, C5 external-action evidence, C6 master verification | done |
| Provide the first concrete execution target | `GOAL.md` MapReduce review target | done |
| Wire new artifacts into the repo entry points | `README.md` Entry Points | done |

## Current Status

```text
Status: active
Next: run the first cycle, MapReduce review, using Criteria v0.1
```
