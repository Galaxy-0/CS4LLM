# CS / AI Math Map

这是一张数学能力地图，用来回答：

```text
哪些数学只是识字？
哪些数学是 CS 必须会？
哪些数学是算法分析要深挖？
哪些数学是 AI/ML 才需要？
《具体数学》到底放在哪里？
```

## Big Picture

```text
                         CS / AI 数学地图

┌───────────────────────────────────────────────────────────┐
│ A. 数学识字层：符号和对象                                  │
│ set / function / relation / logic / vector / probability   │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ B. CS 离散层：数据结构和算法语言                            │
│ graph / tree / induction / recursion / state machine       │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ C. 具体数学 / 算法分析层                                    │
│ sums / recurrences / asymptotics / generating functions    │
│ number theory / discrete probability                       │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ D. AI/ML 数学层                                             │
│ linear algebra / probability / calculus / optimization      │
└───────────────────────────────────────────────────────────┘
                              │
                              ▼
┌───────────────────────────────────────────────────────────┐
│ E. 研究与系统判断层                                         │
│ information theory / statistics / numerical stability       │
│ queueing / randomized algorithms / formal proof             │
└───────────────────────────────────────────────────────────┘
```

当前判断：

```text
如果 A 层概念你已经掌握很多，就不要在 set/function/relation 上磨太久。
重点应该转向 B 层验证、C 层算法分析工具、D 层 AI/ML 数学入口。
```

## Discrete Math vs Algorithms vs Concrete Mathematics

这三者关系很容易混。

| Area | 中文 | 它是什么 | 它不是什么 |
| --- | --- | --- | --- |
| Discrete Math | 离散数学 | CS 里离散对象的语言：集合、逻辑、图、树、关系、归纳、计数 | 不是算法实现本身 |
| Algorithms | 算法 | 解决问题的步骤和数据组织方式 | 不等于离散数学，但大量使用离散数学 |
| Concrete Mathematics | 具体数学 | 算法分析工具箱：求和、递推、渐近、生成函数、数论、离散概率 | 不是入门离散数学，也不是普通高数 |

一句话：

```text
离散数学告诉你“对象是什么”。
算法告诉你“怎么操作这些对象解决问题”。
具体数学告诉你“这个算法到底有多快、为什么是这个量级、递推怎么解”。
```

例子：

```text
Graph 是离散数学对象。
BFS 是图上的算法。
BFS 的 O(V + E) 分析是算法分析。
更复杂递推、求和、渐近分析，就是具体数学的地盘。
```

## Mastery Ladder

每个数学点都用这个梯子判断，不要只问“会不会”。

| Level | Name | Evidence |
| --- | --- | --- |
| 0 | 听过 | 见过词，但说不清 |
| 1 | 能识别 | 知道它属于哪类对象 |
| 2 | 能人话解释 | 能说它解决什么问题 |
| 3 | 能写小例子 | 能用 Python 或伪代码演示 |
| 4 | 能用于 CS 题 | 能在算法/系统/ML 中用它解释现象 |
| 5 | 能推导/证明 | 能做题、推导复杂度、证明性质 |
| 6 | 能设计取舍 | 能在真实系统/模型里判断 tradeoff |

当前阶段：

```text
A 层到 3-4 就够。
B 层到 3-4 就能进入算法和系统课。
C 层先到 2-3，后面算法分析时再冲 4-5。
D 层先到 2-3，进入 ML 时再冲 4。
```

## A. 数学识字层

如果你已经“概念掌握挺多”，这层可以快速扫过。

| Concept | Needed Level | Why |
| --- | ---: | --- |
| set | 3 | 去重、membership、状态集合 |
| function | 3 | 代码函数、映射、模型 |
| relation | 3 | 数据库表、图边、对象关系 |
| logic | 3 | 条件、断言、不变量 |
| notation | 2 | 看懂公式符号 |
| proof idea | 2 | 知道证明是在排除错误 |

Fast test:

```text
能解释 dict 为什么像有限函数。
能解释数据库表为什么像 relation。
能解释 if condition 和 logic 的关系。
```

通过就跳。

## B. CS 离散层

这是 CS 核心，不建议完全跳过，但可以用题和小代码验证。

| Concept | Needed Level | Where It Appears |
| --- | ---: | --- |
| graph | 4 | 网络、依赖、BFS/DFS、分布式拓扑 |
| tree | 4 | AST、B+ tree、文件树、搜索 |
| induction | 3-4 | 递归正确性、循环不变量 |
| recursion | 4 | DFS、parser、divide-and-conquer |
| counting | 3 | 复杂度、概率、组合 |
| state machine | 4 | TCP、Raft、parser、UI 状态 |
| invariant | 4 | OS/DB/Distributed correctness |

Fast test:

```text
用 adjacency list 表示一个 graph。
写 BFS 或 DFS。
解释递归为什么需要 base case。
解释一个循环不变量。
画一个 TCP/Raft/UI 的简单状态机。
```

Visualization:

```text
visualizations/bfs-dfs-animation.html
```

这层如果能过，离散数学入门就不是瓶颈。

## C. 具体数学 / 算法分析层

这就是你之前说的《具体数学》所在位置。

它不是“离散数学 = 算法问题”那么简单，而是更偏：

```text
算法复杂度、递推式、求和式、离散概率、数论工具
```

| Topic | Needed Level | Use |
| --- | ---: | --- |
| sums | 4 | 循环复杂度、平均成本 |
| recurrences | 4 | 分治算法、递归复杂度 |
| asymptotics | 4 | O/Theta/Omega、增长量级 |
| floors/ceilings | 3 | 整数边界、分页、二分 |
| generating functions | 2-3 | 组合计数，先了解 |
| number theory | 2-3 | hash、crypto、randomness |
| discrete probability | 3-4 | randomized algorithms、hashing |

Concrete Mathematics first target:

```text
不用整本啃完。
先拿下：
1. sums
2. recurrences
3. asymptotic notation
4. floors / ceilings
5. basic discrete probability
```

可以暂缓：

```text
generating functions 深水区
复杂数论
高阶组合恒等式
```

Fast test:

```text
能算 1 + 2 + ... + n 是 O(n^2)。
能解释 binary search 为什么是 O(log n)。
能解 T(n)=2T(n/2)+n 的直觉。
能区分 O(n), O(n log n), O(n^2) 的增长。
```

## D. AI/ML 数学层

这层服务 AI/ML track。

| Topic | Needed Level Now | Later For ML |
| --- | ---: | ---: |
| vector / matrix | 3 | 4 |
| dot product | 3 | 4 |
| probability distribution | 3 | 4 |
| expectation / variance | 3 | 4 |
| derivative / gradient | 2-3 | 4 |
| chain rule | 2 | 4 |
| optimization / loss | 2-3 | 4 |

Fast test:

```text
能解释 embedding 为什么是 vector。
能解释 dot product 可以表示相似度。
能解释 LLM token 是从概率分布里采样。
能解释 gradient descent 是调参数让 loss 下降。
```

## E. 研究与系统判断层

这层以后再开，不是当前主线。

| Topic | Why Later |
| --- | --- |
| information theory | LLM loss、compression、perplexity |
| statistics | 实验、A/B test、模型评估 |
| queueing theory | 系统延迟、吞吐、排队 |
| randomized algorithms | hash、load balancing、sampling |
| formal methods | invariant、spec、proof |
| numerical stability | ML/system numerical bugs |

Current rule:

```text
先识别，不深挖。
遇到具体项目或论文需要时再拉升。
```

## What You Probably Need Next

基于当前对话，如果你说 A 层概念已经掌握不少，那么下一步不是重学“集合是什么”，而是做一个快速定位：

```text
1. B 层：graph/tree/recursion/invariant/state machine 是否能用？
2. C 层：sums/recurrences/asymptotics 是否能做算法分析？
3. D 层：vector/matrix/probability/gradient 是否能进入 ML？
```

推荐顺序：

```text
Step 1: B 层 fast test
Step 2: C 层 Concrete Mathematics mini-track
Step 3: D 层 AI/ML math handles
```

## Concrete Mathematics Mini-Track

如果要开始《具体数学》，不要从“我要啃完整本”开始。

先用四周小目标：

```text
Week C1: sums and products
Week C2: recurrences
Week C3: asymptotics
Week C4: discrete probability + review
```

每周交付：

```text
1 页 note
3 个例题
1 个 Python 小模拟或小验证
1 个 CS 应用说明
```

Done means:

```text
能看懂常见算法复杂度推导。
能听懂为什么某个递归是 log n 或 n log n。
能和 Codex 讨论算法复杂度，不只是接受答案。
```

## Next Diagnostic

不用问卷，直接口试式 fast test：

```text
1. graph / tree / recursion / invariant / state machine
2. sum / recurrence / asymptotic
3. vector / matrix / distribution / gradient
```

如果第一组能过，离散数学基础就基本不用重学，直接进入具体数学 mini-track。
