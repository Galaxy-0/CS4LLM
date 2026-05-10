# CS4LLM Learning Route

这份路线从 `KNOWLEDGE_MAP.md` 出发，但按当前真实起点重新排序。

当前假设：

```text
Python: 能看懂一点，复杂项目会懵
Git / terminal: 懂一点，肌肉记忆不强
CS systems: 大部分还没有心智模型
ML / DB / 项目实践: 接触过一些，但 ownership 不稳
AI collaboration: 明显强项，已经能靠 agent 推进项目
```

所以这不是传统本科路线，也不是刷课路线。它的目标是：

```text
用 AI 协作提速，把已经被 agent 拔高的项目实践，压回自己的 CS 基础能力里。
```

## North Star

一年内追求的不是“记完本科所有知识点”，而是：

```text
看得懂项目 -> 讲得清系统 -> 找得到风险 -> 验证得了关键假设 -> 能和 agent 一起交付可靠东西
```

两套能力同时评分：

| Mode | Goal |
| --- | --- |
| AI-assisted execution | 能和 Codex/agents 配合推进复杂项目 |
| Independent ownership | 不看答案时，能解释、debug、重写小版、判断风险 |

短期重点是缩小二者差距。

## The Map, Reordered

基础地图仍然是：

```text
0. 编程 + 工具 + 数据结构
1. 算法 / OS / 体系结构 / 编译器
2. 网络 / 数据库 / 分布式 / 存储性能
3. ML / DL / LLM / Agent
4. 工业实践 / research / 开源 / 产品化
```

但对当前阶段，实际学习顺序应该是：

```text
工具链 -> Python 代码阅读 -> 数据结构人话模型
-> 六个系统故事 -> 代码路径 -> 不变量/失败模式 -> 验证/debug
-> 再回头系统补 OS/DB/Network/Distributed/Compiler/ML
```

原因很简单：先有“看懂和追踪”的能力，后面所有 CS 课才不会变成名词轰炸。

## Core Loop

每次学习只走这个小循环：

```text
1. Story: 这个东西解决什么现实问题？
2. Flow: 正常流程怎么走？
3. Code: 仓库里哪几个文件/函数体现它？
4. Risk: 什么必须永远为真？哪里会坏？
5. Verify: 用什么命令、测试、日志、实验检查？
6. Note: 写一页 ownership note。
```

不要一口吃完整门课。每次只拿下一个可以复述、可以验证的小块。

## Month 1: Build Handles

目标：

```text
从“CS 黑箱 + agent 推项目”
变成“能讲 6 个系统故事，并能在代码里找到一点抓手”
```

### Week 1. Python Reading + Git / Terminal

Focus:

- 读懂小型 Python 项目的入口、函数、数据流。
- 用 terminal 知道自己在哪、项目里有什么、改了什么。
- 用 Git 查状态、看 diff、提交、看历史。

Must know:

```text
pwd / ls / cd / rg / cat / sed
git status / git diff / git log / git add / git commit
python file.py
import / function / class / list / dict / exception / json
```

Practice:

- 找一个自己的小项目，回答：

```text
入口文件在哪？
配置从哪来？
主要数据结构是什么？
一个用户操作会经过哪些函数？
哪里可以加 print/log？
```

Stop condition:

```text
能打开一个小 Python 项目，讲清“入口 -> 数据 -> 函数 -> 输出”的粗路径。
```

### Week 2. Data Structures + MapReduce Story

Focus:

- 把常用数据结构翻成人话。
- 用 MapReduce 建立“任务调度 / worker / retry”的第一个分布式直觉。

Must know:

```text
list: 一排东西
dict/hash map: key -> value
set: 去重和 membership
queue: 排队任务
stack: 后进先出
tree: 层级结构
graph: 关系网络

MapReduce:
Coordinator / Worker / Task / Map / Reduce / intermediate files / timeout / retry
```

Practice:

- 在 `09-MIT-6.5840-Distributed-Systems` 里找 MapReduce 相关代码。
- 只追一条路径：

```text
Worker 问任务 -> Coordinator 分配 -> Worker 执行 -> Worker 汇报 -> Coordinator 记录完成
```

Stop condition:

```text
能讲清：为什么 Reduce 要等所有 Map 完成；worker 消失后为什么要重派；重派为什么可能带来重复执行风险。
```

### Week 3. Buffer Pool + TCP

Focus:

- 建立“内存和磁盘之间有缓存层”的数据库直觉。
- 建立“两台机器之间传数据会丢、乱序、重复”的网络直觉。

Must know:

```text
Buffer Pool:
page / frame / pin count / dirty flag / eviction / disk

TCP:
sequence number / ack / retransmission / ordering / duplicate / timeout
```

Practice:

- 在 BusTub 里找 Buffer Pool 的核心文件和测试。
- 用人话解释一次 page fetch：

```text
要读 page -> 先看内存有没有 -> 没有就从磁盘读 -> 放进 frame -> pin 住 -> 用完 unpin
```

- TCP 先不急着写完整协议，只讲可靠字节流的故事。

Stop condition:

```text
能讲清：正在被使用的 page 为什么不能被随便淘汰；网络包丢了为什么需要编号、确认、重传。
```

### Week 4. Syscall + VM + Raft First Touch

Focus:

- 连接“用户程序”和“操作系统”。
- 连接“源代码”和“运行时执行”。
- 第一次碰 Raft：只讲选 leader，不讲完整共识。

Must know:

```text
Syscall:
user program / trap / kernel / handler / return

VM:
source / bytecode / stack / instruction pointer / object

Raft:
leader / follower / candidate / term / vote / heartbeat
```

Practice:

- xv6 只追一个 syscall/trap 的故事。
- clox 只追一条 bytecode 执行路径。
- Raft 只讲 leader election：

```text
没有 leader -> 节点超时 -> 变 candidate -> 请求投票 -> 赢了变 leader -> 发 heartbeat
```

Stop condition:

```text
能分别用 3-5 句话讲 syscall、VM、Raft election 的正常流程和一个失败场景。
```

## Month 1 Deliverables

月末只需要 6 页 ownership notes：

```text
01-mapreduce.md
02-syscall.md
03-buffer-pool.md
04-vm.md
05-tcp.md
06-raft-election.md
```

每页只填：

```text
Module:
It solves:
Normal flow:
Key data/state:
One invariant:
One failure mode:
One verification:
Files/functions I touched or inspected:
Still confusing:
```

达标标准：

```text
不用背定义，能用人话复述。
不用独立写完整实现，但能找入口、说风险、跑一个验证。
```

## Months 2-3: From Story To Code Path

目标：

```text
从“能讲故事”
推进到“能追代码路径，能让 agent 帮忙但自己知道在查什么”
```

Tracks:

| Track | Scope | Evidence |
| --- | --- | --- |
| Python / Go / C reading | 读小模块、函数调用、结构体/类、错误处理 | 每周追 2 条代码路径 |
| Data structures | list/dict/set/queue/tree/graph/hash/B+ tree | 每个结构写一个用途和一个坑 |
| OS basics | process, syscall, file, virtual memory, lock | xv6 2-3 个路径复盘 |
| DB basics | page, buffer, index, transaction, MVCC | BusTub buffer + B+ tree ownership note |
| Distributed basics | RPC, retry, idempotency, leader, log | MapReduce + Raft election/log replication |
| Testing/debug | log, assertion, minimal reproduction, flaky test | 每个模块至少一个验证实验 |

Suggested rhythm:

```text
Mon: story + concept
Tue: code path
Wed: failure mode
Thu: verification/test
Fri: one-page note
Weekend: optional review or rest
```

Month 3 stop condition:

```text
能拿一个 agent patch，问出 3-5 个有效问题：
状态在哪里？
不变量是什么？
失败模式是什么？
测试覆盖了什么？
还有什么没证明？
```

## Months 4-6: Agent-Era Junior Engineer Base

目标：

```text
能和 Codex 稳定推进中等复杂项目，并开始拥有可靠性判断。
```

Core modules:

| Area | What To Own |
| --- | --- |
| Programming | 能读 Python/Go/C 小模块，能做小改，知道错误从哪冒出来 |
| Algorithms | complexity, sorting/search, recursion, BFS/DFS, basic DP |
| OS | process/thread, syscall, virtual memory, file, lock |
| Network | HTTP, TCP, timeout, retry, backoff, idempotency |
| Database | index, buffer pool, transaction, isolation, MVCC |
| Distributed | MapReduce, Raft election, Raft log, replicated KV |
| Compiler/VM | lexer, parser, AST, bytecode, stack VM |

Deliverables:

- 10-15 ownership notes.
- 3 toy rebuilds:

```text
toy MapReduce scheduler
toy LRU/cache or buffer pool
toy bytecode VM or parser
```

- 1 debug diary:

```text
bug:
symptom:
hypothesis:
experiment:
result:
fix:
what I learned:
```

Stop condition:

```text
给一个中等模块，你能和 agent 一起完成：理解 -> 修改 -> 测试 -> 复盘，而不是只等 agent 给答案。
```

## Months 7-12: Strong Practical CS Core

目标：

```text
接近工程可用的 CS 本科核心，不追求每门课满分，但关键系统能判断。
```

Deepen:

| Area | Target |
| --- | --- |
| Algorithms | 能解释复杂度和常用算法选择，不以刷题为主 |
| Architecture | cache/locality/memory hierarchy，知道性能为什么差 |
| OS | 并发、锁、死锁、调度、虚拟内存、文件系统 |
| Network | TCP 深一点，HTTP/HTTPS，抓包，连接池 |
| DB | B+ tree, query execution, transaction/MVCC |
| Distributed | Raft log replication, snapshot, sharding, exactly-once vs at-least-once |
| Compiler | parser/typecheck/IR/codegen/VM/GC |
| ML | 线性回归、逻辑回归、反向传播、Transformer 基础，先追可解释实现 |

Deliverables:

- 每个核心区至少一个 toy project 或 deep review。
- 能对自己的项目做一次 architecture review：

```text
data model
request path
state ownership
failure modes
observability
test plan
```

Stop condition:

```text
能看一个真实项目，画出主要数据流和风险点，并指导 agent 写/改/测关键模块。
```

## Months 12-24: Independent Ownership

目标：

```text
逐步接近扎实本科核心 ownership，并把 CS 能力迁移回真实项目。
```

At this level:

- 可以从 scratch 写小版系统。
- 能解释 tradeoff，而不是只知道某个标准答案。
- 能读论文/课程资料，并把 idea 落到代码或实验。
- 能做系统设计、性能分析、故障复盘。
- 能判断 agent 在哪里可靠、哪里需要人工审查。

Suggested capstones:

```text
mini database with buffer pool + B+ tree + transaction sketch
mini distributed KV with Raft-backed replication
mini language with parser + bytecode VM
mini network stack / reliable stream
agent-assisted app with explicit reliability review
```

## Skill Targets

Use these as rough goals, not exam scores.

| Skill | Now | 1 Month | 3 Months | 6 Months | 12 Months |
| --- | ---: | ---: | ---: | ---: | ---: |
| Python / code reading | 20-35 | 35-50 | 45-60 | 55-70 | 65-80 |
| Git / terminal | 25-40 | 45-60 | 55-70 | 65-80 | 75-85 |
| CS mental models | 10-20 | 30-45 | 40-55 | 55-70 | 65-80 |
| Code path tracing | 5-15 | 20-35 | 35-50 | 50-65 | 60-75 |
| Invariants / failure modes | 5-15 | 20-35 | 35-50 | 50-65 | 60-75 |
| Verification / debug | 10-25 | 30-45 | 40-55 | 55-70 | 65-80 |
| AI-assisted execution | 50-65 | 60-75 | 65-80 | 75-85 | 80-90 |

The key metric is not that every number rises equally. The key metric is:

```text
Independent ownership catches up enough that AI-assisted execution becomes trustworthy.
```

## Session Template

Use this for every learning session:

```text
Date:
Module:
Time spent:

Story:
Normal flow:
Code path:
State / data structures:
Invariant:
Failure mode:
Verification:
What Codex helped with:
What I personally understand now:
Still confusing:
Next tiny step:
```

## Anti-Goals

Do not do these in the first month:

- Start five full courses at once.
- Turn every unknown word into a separate rabbit hole.
- Pretend agent-generated code means independent understanding.
- Chase ML/LLM depth before code reading and systems basics have handles.
- Measure progress by hours watched instead of notes, code paths, and verification.

## Next Step

Start with Week 1:

```text
Pick one small Python project.
Find the entry point.
Trace one operation.
Use git/terminal to inspect the repo.
Write the first ownership note.
```

Then move to MapReduce as the first CS systems story.
