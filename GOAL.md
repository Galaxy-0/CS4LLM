# CS4LLM Goal Contract

This repository has one job:

> Use AI agents to speed-run CS fundamentals until the user can collaborate with agents at an engineer / architect level, with enough conceptual ownership to judge reliability instead of trusting generated code blindly.

This is not the home for the user's full personal five-year plan. Founder / VC / career strategy belongs in the TODO repository.

## Boundary

In scope for `CS4LLM`:

- CS fundamentals catch-up.
- Systems project review.
- Agent-assisted engineering judgment.
- Reliability concepts: invariants, failure modes, tests, debug paths.
- Course/project artifacts: xv6, BusTub, 6.5840, CS144, compilers.

Out of scope for `CS4LLM`:

- Personal identity planning.
- Founder operating plan.
- VC / operator-investor roadmap.
- Commercial strategy and user acquisition plans.

Those belong in:

```text
/Users/galaxy/Project/GalaxyAI/TODO
```

## Current Goal

Build a fast CS catch-up system that converts existing project artifacts into usable engineering and architecture judgment.

The goal is not to return to pre-AI "hand-code everything" learning.

The goal is:

```text
AI writes faster -> user understands the critical risks -> verification catches failures -> project reliability becomes judgeable.
```

## Criteria v0.2

### C1. Keep The Repository Focused On CS Learning

The top-level docs should describe `CS4LLM` as a CS catch-up and systems-learning workspace.

Verification:

```bash
rg -n "CS fundamentals|CS catch-up|engineer / architect|systems" README.md GOAL.md KNOWLEDGE_MAP.md ASSESSMENT.md
```

### C2. Separate Personal Strategy From CS4LLM

Founder / VC / personal five-year planning should not be the active goal of this repo.

Verification:

```bash
rg -n "founder|VC|operator-investor|five-year" GOAL.md ASSESSMENT.md
```

Allowed mentions:

- A short boundary note saying that those topics live in `TODO`.
- Historical references in archived material.

### C3. Every CS Review Cycle Has One Concrete Target

Each cycle must name exactly one target:

```text
Target:
Why now:
Concepts:
Reliability risk:
Verification:
Stop condition:
```

Good examples:

- MapReduce review
- xv6 syscall/trap review
- BusTub Buffer Pool review
- clox VM review
- TCP reliable stream toy demo
- Raft leader election review

Bad examples:

- Become good at CS
- Study all networking
- Become architect-level
- Improve coding fundamentals broadly

### C4. A Module Is Done Only With Four Evidence Types

A CS module is reviewed when it has:

1. Human explanation: what problem it solves.
2. Code path: which files/functions implement it.
3. Failure mode: how it breaks.
4. Verification: test, command, toy demo, or inspected output.

### C5. Scores Move Only When Evidence Changes

Scores in `ASSESSMENT.md` should not move because of motivation or confidence.

Allowed score-change evidence:

- A review note.
- A passed test/demo.
- A debug trial.
- A successful oral defense summary.
- A project patch that adds reliability checks.

### C6. Agent Collaboration Must Preserve User Judgment

Agents may generate code, docs, tests, summaries, and review notes.

The user must still own:

- Main invariant.
- Main failure mode.
- What verification actually proves.
- Whether a design is reliable enough.

The master agent must verify outputs against criteria instead of accepting worker self-report.

## First Target

```text
Target: MapReduce review
Why now: It is the gentlest bridge from ordinary task dispatch to distributed systems.
Concepts: Coordinator, Worker, Task, Map, Reduce, retry, intermediate files.
Reliability risk: tasks can be lost, duplicated, or reduced before all map outputs exist.
Verification: inspect src/mr, run or inspect a MapReduce test/demo, produce one review note.
Stop condition: user can explain normal flow and worker-failure flow in plain language.
```

## Operating Rule

When the work starts to feel abstract or heavy, shrink the cycle.

Prefer:

```text
one module -> one risk -> one explanation -> one verification
```

Avoid:

```text
one life plan -> all CS -> all reliability -> all career strategy
```

## Current Status

```text
Status: active
Next: run the first cycle, MapReduce review.
```
