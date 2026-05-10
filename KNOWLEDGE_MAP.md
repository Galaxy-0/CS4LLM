# CS4LLM Knowledge Map

这份文档是 `CS4LLM` 的知识大地图。它不是课程大纲，也不是背诵清单，而是用来回答三个问题：

- 我现在学的东西在 CS 地图上的哪个位置？
- 仓库里的项目分别对应哪些能力区？
- 下一步应该复盘什么，而不是被一堆名词压住？

本仓库的目标是 CS 快速补课和系统工程判断力训练。个人 founder / VC / 职业路线放在 `TODO` 仓库中维护。

## The Whole Map

```text
                         CS / AI 工业研究型本科地图

┌───────────────────────────────────────────────────────────┐
│ 0. 预备层：数学 + 编程 + 数据结构                         │
│ 微积分 / 线代 / 概率 / 离散数学 / C-Python-Go / DS         │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ 1. 四大硬核主干：真正的 CS 骨架                            │
│ 算法        操作系统        体系结构        编译器           │
│ Algorithms  OS             Architecture    Compilers        │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ 2. 系统工程主干：能造真实系统                               │
│ 网络        数据库        分布式系统        存储/性能         │
│ Networks    Databases     Distributed       Storage/Perf     │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ 3. AI/ML Track：从传统 ML 到 Agent                          │
│ 线性回归 -> SVM/HMM -> CNN/RNN -> Transformer -> LLM -> Agent│
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ 4. 工业实践层：co-op / research / 开源 / 产品化             │
│ 实习、paper、系统项目、benchmark、debug、部署、协作          │
└───────────────────────────────────────────────────────────┘
```

## Current Position

当前坐标先诚实标在：

```text
Layer 0 起点：预备层 / 数学 + 编程 + 数据结构
```

这表示：

- Python、Git、terminal 有一点基础，但还没有稳定肌肉记忆。
- AI 协作和项目推进强于独立 CS ownership。
- OS、数据库、网络、分布式、编译器、AI/ML 都先按后续层级推进，不抢跑。
- 当前主线看 [LEARNING_ROUTE.md](./LEARNING_ROUTE.md)：先补 Layer 0，再进入四大硬核主干。
- Layer 1 的四大硬核主干已展开为 [CS_CORE_TREE.md](./CS_CORE_TREE.md)，作为后续索引，不代表当前马上开啃。

## Repository Coverage

| Map Area | Repo Path | Current Role | Human Translation |
| --- | --- | --- | --- |
| Operating Systems | `06-MIT-6.S081-xv6-labs` | active independent repo | 程序怎么进入内核，内核怎么管理进程、内存、文件和设备 |
| Networks | `07-Stanford-CS144-Sponge` | placeholder | 数据怎么可靠地从一台机器走到另一台机器 |
| Databases | `08-CMU-15-445-BusTub` | active independent repo | 数据库怎么管理页、索引、查询执行和事务 |
| Distributed Systems | `09-MIT-6.5840-Distributed-Systems` | active independent repo | 多台机器怎么分工、复制、容错，并对外表现得像一个系统 |
| Compilers | `10-Stanford-CS143-Compiler` | workspace-tracked practice | 代码怎么被读懂、变成 IR/字节码/机器指令并执行 |
| Early Experiments | `00-Archive-Early-Experiments` | archive | 早期 C、网络、编译器和概率语言探索材料 |
| Route / Roadmap / Standards | `LEARNING_ROUTE.md`, `CS_CORE_TREE.md`, `MATH_MAP.md`, `MATH_ROUTE.md`, `ROADMAP.md`, `00_CS_Undergrad_Standard.md` | reference | 当前学习路线、四大硬核主干树、数学地图、数学路线、长期方向和能力基准 |

## Mastery Scale

用这个小标尺给每个模块打状态，不用装懂，也不用因为陌生而焦虑。

| Level | Name | Meaning |
| --- | --- | --- |
| 0 | 陌生 | 名词听过，但不知道它解决什么问题 |
| 1 | 能跟着跑 | 能运行项目或测试，但主要靠提示推进 |
| 2 | 能讲人话 | 能不用代码解释角色、流程和失败场景 |
| 3 | 能 debug | 能根据日志、测试失败和状态变化定位问题 |
| 4 | 能重写小版 | 能脱离课程骨架写一个玩具实现 |
| 5 | 能设计取舍 | 能比较不同设计，讲清正确性、性能和复杂度权衡 |

目标不是所有模块都到 5。近期目标是：核心模块先从 1 推到 2。

## Later Project Coordinates

These project coordinates are not the active starting point. They become useful after Layer 0 is stable enough to read code and follow small system flows.

| Area | Current Coordinate | Next Useful Step |
| --- | --- | --- |
| MapReduce | 已有 6.5840 实现提交 | 讲清 Coordinator / Worker / Task / retry |
| Raft | 已有 6.5840 实现提交 | 先讲清 leader election，再讲 log replication |
| KV Service | 已有 kvsrv / kvraft / shardkv 实现提交 | 讲清一次 Put/Get 从 client 到 server 的路径 |
| xv6 | 多个 lab 分支已有完成提交 | 从 syscall/trap 路径开始复盘 |
| BusTub | P0-P4 已有完成提交 | 从 buffer pool 和 B+ tree 不变量开始复盘 |
| clox | VM 测试可跑 | 讲清 bytecode chunk、stack VM、object/GC |
| nanoc | sample 编译链可跑 | 讲清 source -> AST -> typecheck -> IR -> assembly |
| CS144 / Networking | skeleton 尚未加入 | 下一块大空白，适合作为后续新主线 |
| AI/ML/Agent | 尚未纳入主线仓库 | 仅保留为未来应用方向；本仓库先补 CS 系统骨架 |

## Later Six-Point Review Path

Use this after Layer 0, not as the first month mainline.

接下来先不要开太多新门。按这六个点复盘，可以把 CS 骨架慢慢串起来。

```text
A. MapReduce：调度与任务
B. xv6 syscall：程序怎么进入内核
C. BusTub Buffer Pool：内存和磁盘怎么换页
D. clox VM：代码怎么变成指令执行
E. TCP：数据怎么可靠地从一台机器到另一台
F. Raft：多台机器怎么同意一件事
```

这个顺序的用意是先建立直觉，再进入抽象：

| Step | Why First |
| --- | --- |
| MapReduce | 最像现实世界的派活系统，容易用人话讲 |
| xv6 syscall | 把“程序”和“操作系统”接起来 |
| Buffer Pool | 把“内存”和“磁盘”接起来 |
| clox VM | 把“代码文本”和“运行时执行”接起来 |
| TCP | 把“两台机器通信”接起来 |
| Raft | 把“多台机器一致行动”接起来 |

## One-Page Mental Models

这些是第一轮复盘时允许使用的“粗糙翻译”。先有直觉，再补术语。

| Term | Human Version |
| --- | --- |
| Coordinator | 调度员，负责派活和记状态 |
| Worker | 工人，负责领活、干活、汇报 |
| RPC | 远程调用，看起来像调用函数，实际跨机器发消息 |
| Task | 一份可分配的工作 |
| Retry | 工人没按时交活，就把任务重新派出去 |
| Syscall | 用户程序请求内核帮忙做事 |
| Trap | CPU 从用户态切到内核态的入口 |
| Page | 固定大小的数据块 |
| Buffer Pool | 数据库放 page 的内存缓存 |
| B+ Tree | 适合磁盘页访问的有序索引结构 |
| VM | 执行字节码的小机器 |
| Bytecode | 比源代码更低级、比机器码更抽象的指令 |
| Log | 操作记录本 |
| Snapshot | 把一长串历史压成一个当前状态 |
| Leader | 当前负责对外协调的一台机器 |
| Consensus | 多台机器对同一件事达成一致 |

## Review Template

每复盘一个模块，只填这 7 行。不要一开始写长文。

```text
Module:
Level now:
It solves:
Main roles:
Normal flow:
Failure flow:
Most important invariant:
Next tiny experiment:
```

示例：

```text
Module: MapReduce
Level now: 1
It solves: 把很多输入文件分给多个 worker 处理，再把中间结果汇总成最终输出。
Main roles: Coordinator, Worker, Map task, Reduce task, intermediate files.
Normal flow: Worker 问任务 -> 做 Map -> 写中间文件 -> 汇报 -> 做 Reduce -> 写结果。
Failure flow: Worker 太久没汇报，Coordinator 把任务重新变成可分配。
Most important invariant: Reduce 只能在所有 Map 都完成后开始。
Next tiny experiment: 故意让一个 worker 退出，看任务是否会重新分配。
```

## How To Use This Map

- 累的时候只看 `The Whole Map` 和 `One-Page Mental Models`。
- 想复盘时，从 `Six-Point Review Path` 选一个点。
- 想判断自己懂没懂，用 `Mastery Scale`。
- 想落笔时，只填 `Review Template`，不要写论文。
- 想推进仓库时，先运行 `bash scripts/repo-status.sh`，确认自己在哪个项目里动手。

这张地图会随着学习继续更新。它的作用不是证明你懂了多少，而是让你不用在一堆名词里迷路。
