# CS / AI Industrial Research Undergrad Route

这份路线严格跟随 `KNOWLEDGE_MAP.md` 里的大地图：

```text
0. 预备层：数学 + 编程 + 数据结构
1. 四大硬核主干：算法 / 操作系统 / 体系结构 / 编译器
2. 系统工程主干：网络 / 数据库 / 分布式系统 / 存储性能
3. AI/ML Track：传统 ML -> 深度学习 -> Transformer -> LLM -> Agent
4. 工业实践层：项目 / research / 开源 / benchmark / debug / 部署 / 协作
```

当前定位：

```text
Current coordinate: Layer 0 起点
```

这不是坏位置。它只是说明接下来要先补“能看懂代码、会用工具、知道基本数学和数据结构”的地基，然后再正式进入 CS 四大主干。

## Baseline

当前估计：

| Area | Current State | Route Meaning |
| --- | --- | --- |
| Python | 能看懂一点，复杂项目会懵 | 从代码阅读和小改开始 |
| Git / terminal | 懂一点，但肌肉记忆不强 | 先练成日常工具 |
| Programming basics | 有项目接触，但概念不稳 | 补变量、函数、数据流、模块、错误 |
| Data structures | 零散 | 先掌握工程常用结构 |
| Math | 大概率需要重建 | 只补 CS/AI 最常用部分 |
| OS / DB / network / distributed / compiler | 基本在起点 | 先不硬啃实现，等 Layer 0 站稳 |
| ML / AI | 听过或接触过一些 | 等数学和编程地基更稳后系统进入 |
| AI collaboration | 明显强项 | 用来提速，但不替代 ownership |

一句话：

```text
项目实践被 AI 协作拔高了；现在要从 Layer 0 开始补独立 CS ownership。
```

## Operating Principle

每一层都按两个模式评分：

| Mode | Meaning |
| --- | --- |
| AI-assisted execution | 和 Codex/agents 配合时能不能推进 |
| Independent ownership | 不看答案时能不能解释、debug、重写小版、判断风险 |

路线目标不是回到古法手敲一切，而是：

```text
AI 提速学习和实现
自己掌握概念、代码路径、失败模式、验证边界
```

## Layer 0. 预备层：数学 + 编程 + 数据结构

目标：

```text
从“靠 agent 推项目”
变成“自己能读小项目、写小脚本、理解常见数据结构和 CS 数学语言”
```

### 0A. Tools And Repo Survival

Must own:

```text
pwd / ls / cd / rg / cat / sed
git status / git diff / git log / git add / git commit
python file.py
README / tests / config / entrypoint / dependency file
```

Exit criteria:

- 能说清自己在哪个目录。
- 能找到一个项目的入口文件。
- 能看出这次改了哪些文件。
- 能提交一个小改动。
- 能用 `rg` 找函数、类、配置、错误信息。

### 0B. Programming Basics

Primary language:

```text
Python first
Go / C only as systems-course reading language
```

Must own:

```text
variable / type / function / class
if / loop / exception
list / dict / set / tuple
module / import
file / json / http request
print log / breakpoint
```

Exit criteria:

- 能读一个 200-500 行的小 Python 项目。
- 能追一条输入到输出的数据流。
- 能做一个不超过 30 行的小改动。
- 能解释“这个函数拿什么输入、改什么状态、返回什么结果”。

### 0C. Data Structures

先不刷竞赛题。先把结构和用途建起来。

Must own:

| Structure | Human Model | Why It Matters |
| --- | --- | --- |
| list / array | 一排格子 | 顺序数据、遍历、索引 |
| dict / hash map | key -> value | 状态表、缓存、索引 |
| set | 去重和 membership | 判断是否见过 |
| stack | 后进先出 | 调用栈、解析、回溯 |
| queue | 先进先出 | 任务队列、调度、BFS |
| tree | 层级结构 | 文件树、AST、索引 |
| graph | 点和边 | 网络、依赖、路径 |
| heap / priority queue | 总能取最小/最大 | 调度、最短路、top-k |

Exit criteria:

- 能说出每个结构解决什么问题。
- 能用 Python 写小例子。
- 看到代码里用 `dict/list/queue` 时，能说它在存什么状态。

### 0D. Algorithms Warmup

先建立基本算法语言，不急着刷深题。

Must own:

```text
complexity: O(1), O(log n), O(n), O(n log n), O(n^2)
search: linear search, binary search
sorting: selection/merge/quick 的直觉
recursion
BFS / DFS
basic dynamic programming intuition
```

Exit criteria:

- 能解释为什么有些代码慢。
- 能看懂简单递归。
- 能用 BFS/DFS 解决一个小图/树问题。
- 能说出复杂度的大概量级。

### 0E. Math For CS/AI

不需要先完整重读数学系课程，只补会在 CS/AI 中反复遇到的语言。

Must own:

| Math | First Target |
| --- | --- |
| Discrete math | set, relation, graph, induction, logic |
| Linear algebra | vector, matrix, dot product, norm, eigen intuition |
| Probability | random variable, distribution, expectation, variance, Bayes |
| Calculus | derivative, gradient, chain rule |
| Optimization | loss, gradient descent, local/global minima |

Exit criteria:

- 能读懂 ML 里的向量、矩阵、概率、梯度符号。
- 能解释一个算法为什么用 graph/set/relation。
- 能把数学公式翻成代码直觉。

## Layer 0 First Month

这个月只做 Layer 0，不正式开系统课。

### Week 1. Terminal / Git / Python Reading

目标：

```text
能打开一个小 Python 项目，找到入口、运行它、查看改动。
```

Deliverable:

```text
notes/00-layer0-week1.md
```

Template:

```text
Project:
Entry point:
How to run:
Key files:
One data flow:
Git commands used:
Still confusing:
```

### Week 2. Python Basics And Data Flow

目标：

```text
能解释变量、函数、list/dict、模块、错误处理在一个小项目里的作用。
```

Deliverable:

```text
一个 50-100 行 Python 小脚本
一页代码阅读 note
```

### Week 3. Data Structures

目标：

```text
list / dict / set / stack / queue / tree / graph 都有一个人话模型和一个 Python 小例子。
```

Deliverable:

```text
notes/00-data-structures.md
```

### Week 4. Algorithms And Math Handles

目标：

```text
能解释复杂度、递归、BFS/DFS、向量/矩阵/概率/梯度的最小直觉。
```

Deliverable:

```text
notes/00-algorithms-math-handles.md
```

Month 1 stop condition:

```text
不是“学完 CS”。
是站稳 Layer 0 的入口：
能读小代码、用工具、讲常见数据结构、知道数学和算法在后面会怎么用。
```

## Layer 1. 四大硬核主干

进入条件：

```text
Layer 0 的工具、Python 阅读、数据结构、复杂度直觉基本可用。
```

四门主干不是按课程孤立学，而是交叉推进。

| Mainline | Core Question | Repo / Evidence |
| --- | --- | --- |
| Algorithms | 如何组织数据和步骤，让问题可计算、可扩展？ | 小题、复杂度 note、数据结构实现 |
| Operating Systems | 程序如何使用 CPU、内存、文件、设备？ | `06-MIT-6.S081-xv6-labs` |
| Architecture | 代码如何在硬件和内存层次上运行？ | CSAPP-style notes / tiny C demos |
| Compilers | 代码如何被读懂、转换、执行？ | `10-Stanford-CS143-Compiler` |

Layer 1 exit criteria:

- 能讲清 process/thread/memory/file/syscall。
- 能解释 cache/locality/pointer/memory layout 的基本影响。
- 能解释 source -> token -> AST -> bytecode/IR -> execution。
- 能用复杂度分析一个简单实现。

## Layer 2. 系统工程主干

进入条件：

```text
至少能读懂小型系统代码，并能解释 OS/architecture/compiler 的基本连接。
```

| Mainline | Core Question | Repo / Evidence |
| --- | --- | --- |
| Networks | 数据如何可靠地从一台机器到另一台？ | `07-Stanford-CS144-Sponge` / TCP note |
| Databases | 数据如何被索引、缓存、查询、并发更新？ | `08-CMU-15-445-BusTub` |
| Distributed Systems | 多台机器如何分工、复制、容错？ | `09-MIT-6.5840-Distributed-Systems` |
| Storage / Performance | 系统为什么慢，哪里会丢数据？ | benchmark / profiling / debug diary |

Layer 2 exit criteria:

- 能解释 TCP reliable stream。
- 能解释 buffer pool、B+ tree、transaction/MVCC。
- 能解释 MapReduce、Raft election、Raft log replication。
- 能对一个系统说出主要不变量、失败模式、验证方式。

## Layer 3. AI/ML Track

进入条件：

```text
编程、数据结构、线代、概率、微积分直觉可用。
```

推荐顺序：

```text
linear regression
logistic regression
SVM / tree models / HMM intuition
neural network + backprop
CNN / RNN historical context
Transformer
LLM training / inference / eval
RAG / tool use / AI Agent
SWE Agent
```

Layer 3 exit criteria:

- 能把模型写成输入、参数、loss、优化、评估。
- 能解释反向传播和梯度下降的人话模型。
- 能读懂 Transformer 的主要数据流。
- 能搭建和评估一个小 AI agent，而不是只调用 API。

## Layer 4. 工业实践层

这层不是最后才开始，而是贯穿全程。但它不替代基础层。

Evidence:

```text
real project
tests
debug diary
benchmark
architecture note
postmortem
open-source contribution
research note
deployment note
```

Layer 4 exit criteria:

- 能把 CS 知识迁移到真实项目。
- 能用 agent 产出代码，同时自己判断可靠性。
- 能复盘 failure、性能、架构、用户影响。

## Timeline

这是推荐节奏，不是死线。

| Time | Main Focus | Expected Outcome |
| --- | --- | --- |
| Month 1 | Layer 0 entry | 工具、Python 阅读、数据结构、算法/数学 handles |
| Months 2-3 | Layer 0 completion | 能读小项目、写小脚本、理解基本 DS/algorithm/math |
| Months 4-6 | Layer 1 start | 算法 + OS + architecture + compiler 入门 |
| Months 7-12 | Layer 1 deepen + Layer 2 start | 系统课主干开始连起来 |
| Months 13-18 | Layer 2 deepen | 网络/数据库/分布式有工程判断 |
| Months 19-24 | Layer 3 AI/ML + Layer 4 projects | AI track 和真实项目合流 |

## Score Targets

Rough estimates:

| Skill | Now | 1 Month | 3 Months | 6 Months | 12 Months |
| --- | ---: | ---: | ---: | ---: | ---: |
| Tools / Git / terminal | 25-40 | 45-60 | 60-70 | 70-80 | 80+ |
| Python / code reading | 20-35 | 35-50 | 50-60 | 60-70 | 75+ |
| Data structures | 10-25 | 25-40 | 45-60 | 60-70 | 75+ |
| Algorithms | 5-20 | 15-30 | 35-50 | 50-65 | 65+ |
| CS math | 5-20 | 15-30 | 35-50 | 45-60 | 60+ |
| Systems mental models | 5-15 | 10-25 | 25-40 | 40-55 | 60+ |
| Verification / debug | 10-25 | 20-35 | 35-50 | 50-65 | 70+ |
| AI-assisted execution | 50-65 | 60-75 | 65-80 | 75-85 | 80-90 |

Key metric:

```text
Independent ownership steadily catches up to AI-assisted execution.
```

## Session Template

Use this for every session:

```text
Date:
Layer:
Topic:
Time spent:

Concept in human words:
Tiny example:
Code or command used:
What I can explain without Codex:
What Codex helped with:
One confusion:
Next tiny step:
```

## Anti-Goals For The First Month

- 不开 OS/DB/Distributed 的硬核实现。
- 不同时刷五门课。
- 不把 AI 生成项目误认为自己已经懂 CS。
- 不追求“本科速通”的爽感。
- 不用问卷折磨自己。

## Immediate Next Step

Start here:

```text
Layer: 0
Topic: terminal + git + Python project reading
Task: pick one small Python project, find entry point, run it, trace one data flow
Output: notes/00-layer0-week1.md
```
