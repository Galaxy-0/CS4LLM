# Capability Assessment

这份文档用于客观盘点当前能力位置，并服务于五年目标：

```text
高级独立全栈开发者 -> operator-founder -> VC / operator-investor
```

它不是人格评价，也不是一次性定论。它是一个可更新的仪表盘：随着项目、用户、收入、复盘和 CS 掌握度变化而调整。

## Current One-Line Diagnosis

你当前更像：

> AI 协作增强型早期构建者。项目推进能力已经超过普通初学者，但 CS 概念主权、工程可靠性、真实用户验证和商业闭环还没有同步拉起来。

最核心的落差是：

```text
AI-assisted execution > Independent conceptual ownership
```

也就是说，和 AI/Agent 配合时，你能推进复杂项目；但脱离提示后，自己解释、debug、重写小版、做设计取舍的能力还需要系统补课。

## Two-Mode Scoring

以后所有能力都尽量分成两套分数：

| Mode | What It Measures | Why It Matters |
| --- | --- | --- |
| AI-assisted score | 和 Codex/Agent 配合时，能不能把复杂事推进出来 | 衡量你当前真实生产杠杆 |
| Independent ownership score | 不看答案时，能不能解释、debug、重写小版、设计取舍 | 衡量能力是否真正长在你身上 |

这两个分数都重要。AI-assisted score 是当代生产力，Independent ownership score 是长期护城河。

## Top-Level Scorecard

| Layer | Meaning | Current Estimate | Evidence / Caveat |
| --- | --- | ---: | --- |
| AI-assisted execution | 和 AI/Agent 配合时，能不能推进复杂项目 | 65-75 | 已能组织 workspace、拆提交、跑 CS lab、做文档体系；但仍依赖 AI 规划和解释 |
| Independent conceptual ownership | 不看答案，自己能不能解释、debug、重写小版 | 30-45 | 你自己反馈“似乎都不懂”；多个 CS 项目已有产物，但复盘和口述掌握不足 |
| Product shipping | 能不能把东西变成用户可用、稳定交付 | 45-60 | 有原型和项目推进能力；测试、部署、日志、用户入口、运行数据治理仍需补 |
| Founder loop | 能不能找人、验证、收费、复盘 | 25-40 | 有 founder 意识和产品判断；真实外部验证、报价、收费、案例密度不足 |
| VC readiness | 能不能形成 deal flow、判断力、资本信用 | 10-20 | 方向可通，但目前缺 operator 战绩、deal flow、memo 训练和资本信用 |

## Domain Matrix

| Domain | AI-Assisted | Independent | Current Read |
| --- | ---: | ---: | --- |
| Design / Product Sense | 70-80 | 60-70 | 约 5 年设计/交互底子，审美和产品判断是优势 |
| Frontend Implementation | 60-70 | 45-60 | 能落地，但需要更多稳定组件、状态、测试和性能实践证据 |
| Backend / Infra | 45-60 | 25-40 | 能在 AI 帮助下搭系统；独立设计、排障、运维经验仍偏薄 |
| AI Agent Engineering | 65-75 | 40-55 | 约 1 年 Agent/AI 应用经验，有方向感；eval、trace、fallback、成本控制需补 |
| CS Fundamentals | 55-70 | 25-40 | xv6/BusTub/6.5840/clox/nanoc 有产物；概念口述和独立 debug 是短板 |
| Engineering Reliability | 50-65 | 35-45 | 已开始用状态脚本、测试、提交整理；还需形成默认工程卫生 |
| Writing / Framing | 75-85 | 70-80 | 抽象、叙事、地图构建强，但容易替代实际交付 |
| User Discovery / Sales | 35-50 | 20-35 | founder 路线最大短板之一，需要触达、访谈、报价、成交训练 |
| Founder Judgment | 45-60 | 30-45 | 能看出产品/战略结构，但缺真实市场反馈校准 |
| VC / Investment Judgment | 25-40 | 10-25 | 有研究兴趣和 thesis 潜力；缺 deal flow、memo、反事实训练和 track record |

## CS Fundamentals Scorecard

使用 `KNOWLEDGE_MAP.md` 的 0-5 掌握度标尺：

```text
0 陌生
1 能跟着跑
2 能讲人话
3 能 debug
4 能重写小版
5 能设计取舍
```

| Module | Current Estimate | Near-Term Target | Notes |
| --- | ---: | ---: | --- |
| MapReduce | 1 | 3 | 先讲清 Coordinator / Worker / Task / retry |
| xv6 syscall / trap | 1-2 | 3 | 从用户程序进入内核的路径开始 |
| BusTub Buffer Pool | 1-2 | 3 | 重点是 page、pin count、dirty、eviction |
| B+ Tree | 1-2 | 3 | 重点是有序性、分裂、合并、借位不变量 |
| clox VM | 2 | 3 | bytecode chunk、stack VM、object、GC |
| nanoc pipeline | 2 | 3 | source -> AST -> typecheck -> IR -> assembly |
| TCP reliable stream | 0-1 | 3 | 当前网络线最大空白 |
| Raft leader election | 1 | 3 | 先讲选主，再讲日志 |
| Raft log replication | 1 | 3 | 容易“做过但没吃透”的核心模块 |
| KV request path | 1 | 3 | client -> server -> raft/apply -> reply |
| MVCC / transaction | 1 | 3 | 需要从可见性和并发冲突讲起 |
| Debug / performance basics | 1 | 3 | 需要故意练 failure-driven debugging |

## Five-Year Ladder

### Stage 1: 高级独立全栈开发者

Target window: 0-18 months.

Definition:

> 能独立从需求、设计、前后端、数据、部署、日志、测试、支付、用户反馈跑通一个真实产品闭环。

Current blockers:

- CS 概念主权不足，做过的系统还没压成可解释知识
- 后端/infra/部署/运维经验不够硬
- 工程可靠性体系还不是默认动作
- AI Agent 的 eval / trace / fallback / cost control 还需要产品化

Minimum proof:

- 1 个稳定在线产品或服务
- 3-5 个真实用户/客户案例
- 每个项目有测试、日志、部署、错误处理和复盘
- CS 核心模块至少 8 个达到 Level 2-3

### Stage 2: Operator-Founder

Target window: 12-36 months.

Definition:

> 能找到真实痛点，做出可用产品/服务，拿到用户反馈和收入，并持续迭代。

Current blockers:

- 外部动作太少
- 报价/收费训练不足
- 容易把大理论和身份规划放在用户验证前面
- 需要把抽象能力压成具体交付、案例和收入

Minimum proof:

- 20-50 次用户访谈
- 5 个 AI Agent / workflow 客户案例
- 3-5 万人民币累计收入作为第一阶段信号
- 一条清晰的服务或产品定位
- 每周固定复盘用户、收入、交付、失败假设

### Stage 3: VC / Operator-Investor

Target window: 36-60 months.

Definition:

> 不是“想当 VC”，而是成为好 founder 愿意交流、投资人愿意听你推荐项目的人。

Current blockers:

- 缺 operator 战绩
- 缺系统 deal flow
- 缺投资 memo 和反事实判断训练
- 缺资本信用和 track record

Minimum proof:

- 垂直 thesis：AI Agent / AI Workflow / 独立开发者基础设施 / 小团队 AI 应用生态
- 100 个项目追踪数据库
- 30 篇投资 memo
- 50 次 founder 深访
- scout / angel / 推荐项目的早期 track record

## Scoring Protocol

每次评估一个能力，尽量不要只靠感觉。用四类证据：

| Evidence Type | Question | Weight |
| --- | --- | ---: |
| Artifact | 你做出了什么？代码、产品、文档、demo | 30% |
| Oral Defense | 你能不能不用代码讲清楚？ | 25% |
| Debug Trial | 坏了你能不能定位？ | 25% |
| External Validation | 用户/客户/他人是否验证？ | 20% |

对 CS 模块尤其要防止两个幻觉：

- 只看 artifact：AI 帮你做出来，不等于你真懂。
- 只看口头理解：讲得漂亮，不等于能交付。

## 12-Week Diagnostic Plan

近期不建议继续开很多新项目。先把已有项目变成自己的能力。

| Week | Diagnostic Focus | Output |
| --- | --- | --- |
| 1 | MapReduce | 45 分钟口试 + 代码路径复盘 + 1 页总结 |
| 2 | xv6 syscall/trap | 从用户调用到内核返回画出路径 |
| 3 | BusTub Buffer Pool | 写出核心不变量和 3 个失败场景 |
| 4 | clox VM | 讲清 bytecode、stack、object、GC |
| 5 | TCP reliable stream | 补网络空白，做一个 toy sliding-window demo |
| 6 | Raft election | 讲清 term、vote、timeout、split vote |
| 7 | Raft log replication | 讲清 log matching、commit、apply |
| 8 | KV request path | 讲清一次 Put/Get 的全链路 |
| 9 | Engineering reliability | 给一个现有项目补测试、日志、错误边界 |
| 10 | Product shipping | 选一个项目做 5 分钟用户入口 |
| 11 | Founder loop | 做 10 次触达、3 次深聊、1 次报价 |
| 12 | Assessment refresh | 重评所有分数，更新本文件 |

## Current Priority

当前最优先的不是“再证明自己聪明”，而是：

```text
1. 把 AI 协作下做出来的项目，转化成自己能讲、能 debug 的理解。
2. 把抽象产品想法，转化成真实用户能试、能评价、能付费的交付。
3. 把 founder / VC 的身份想象，转化成每周可计量的外部动作。
```

一句话：

> 先从 AI-assisted builder，变成拥有概念主权和交付闭环的 independent operator。Founder 和 VC 路线要从这里长出来。
