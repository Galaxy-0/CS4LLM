# Layer 0 Math Route

这份文档回答三个问题：

```text
数学怎么补？
补到什么程度就够进入下一层？
每块数学到底有什么用？
```

当前定位：

```text
Current coordinate: Layer 0 / Math 起点
```

这里的数学不是为了考试，也不是为了证明自己是数学专业。它是 CS / AI 工业研究型本科地图里的底层语言。

## North Star

数学补强的目标不是“把高数、线代、概率完整学完”，而是：

```text
能把数学符号翻成代码和系统直觉
能看懂 CS/AI 资料里的基本公式
能知道一个算法、模型、系统为什么这样设计
能和 agent 讨论数学相关实现时不完全失去判断力
```

最重要的判断标准：

```text
看到公式不慌
能说人话
能写小例子
知道它在 CS/AI 里解决什么问题
```

## Four Levels

数学不要一次补到研究级。先分四层。

| Level | Name | Meaning | When Enough |
| --- | --- | --- | --- |
| M0 | 识字 | 看见符号知道大概在说什么 | 能读懂基础教程和我给的解释 |
| M1 | 工程够用 | 能把概念和代码、算法、系统联系起来 | 能进入算法、OS、DB、网络、编译器入门 |
| M2 | AI/ML 够用 | 能理解 loss、梯度、概率、矩阵运算 | 能进入 ML/DL/Transformer 主线 |
| M3 | 研究够用 | 能读论文、推导、做实验判断 | 后续 research / advanced AI |

近期目标只到：

```text
M1: 工程够用
部分 M2: AI/ML 入口够用
```

## What To Learn

### 1. Discrete Math

中文：离散数学。

先学：

```text
set
logic
function
relation
proof by induction
graph
tree
counting
state machine
```

补到什么程度：

- 能看懂集合、函数、关系、图这些符号。
- 能解释“为什么 tree/graph 是数据结构和算法的底层语言”。
- 能用归纳法的人话理解递归和循环不变量。
- 能把一个状态机画成节点和边。

有什么用：

| CS Area | Use |
| --- | --- |
| Data structures | set / tree / graph 是基本结构 |
| Algorithms | BFS/DFS、递归、复杂度分析 |
| Databases | relation 是关系数据库的数学底座 |
| Compilers | grammar、AST、状态机 |
| Distributed systems | state machine replication |
| Verification | invariant、proof、case analysis |

最低可交付：

```text
能解释 set / relation / graph / induction
能用 Python 写 set、dict、graph adjacency list
能用 BFS/DFS 走一个小 graph
```

### 2. Linear Algebra

中文：线性代数。

先学：

```text
scalar
vector
matrix
dot product
matrix multiplication
norm
projection intuition
eigenvalue / eigenvector intuition
SVD intuition
```

补到什么程度：

- 能把向量理解成“一排数字表示一个对象”。
- 能把矩阵理解成“批量变换或批量计算”。
- 能解释 dot product 是相似度或投影的核心操作。
- 能看懂 `X @ W + b` 这种 ML 公式。
- 暂时不要求手推复杂特征值题。

有什么用：

| CS / AI Area | Use |
| --- | --- |
| ML basics | 线性回归、逻辑回归 |
| Deep learning | tensor、batch、layer |
| Transformer | embedding、attention、矩阵乘法 |
| Search / recommendation | 向量相似度 |
| Graphics / robotics | 坐标变换 |
| Performance | 矩阵运算为什么适合 GPU |

最低可交付：

```text
能解释 vector / matrix / dot product / matrix multiplication
能用 Python/numpy 做一次 y = X @ w + b
能解释 embedding 相似度为什么常用 dot product 或 cosine
```

### 3. Probability And Statistics

中文：概率与统计。

先学：

```text
event
random variable
distribution
expectation
variance
conditional probability
Bayes rule
sampling
law of large numbers intuition
confidence / uncertainty intuition
```

补到什么程度：

- 能区分“一个值”和“一个随机变量”。
- 能解释分布是“可能结果和概率的整体”。
- 能解释期望不是保证发生，而是长期平均。
- 能看懂条件概率和贝叶斯更新的人话模型。
- 能理解测试、评估、A/B、模型输出都带不确定性。

有什么用：

| CS / AI Area | Use |
| --- | --- |
| ML | 分类概率、loss、评估 |
| LLM | token probability、sampling、temperature |
| Systems | failure rate、retry、tail latency |
| Distributed systems | randomized timeout、flaky test |
| Databases | cardinality estimation、query planning |
| Product analytics | conversion、experiment、confidence |

最低可交付：

```text
能解释 random variable / distribution / expectation / variance / conditional probability
能用 Python 模拟掷硬币和抽样平均
能解释为什么 LLM 输出是概率性的
```

### 4. Calculus

中文：微积分。

先学：

```text
function
limit intuition
derivative
partial derivative
gradient
chain rule
```

补到什么程度：

- 能把导数理解成“输入变化一点，输出怎么变”。
- 能把梯度理解成“多维空间里往哪里改能让目标变化最快”。
- 能理解 chain rule 是反向传播的基础。
- 不要求一开始做大量手算积分。

有什么用：

| CS / AI Area | Use |
| --- | --- |
| ML / DL | gradient descent、backprop |
| Optimization | loss 怎么下降 |
| Control / simulation | 连续系统变化 |
| Graphics / physics | 曲线、速度、加速度 |
| Numerical computing | 近似、误差、稳定性 |

最低可交付：

```text
能解释 derivative / partial derivative / gradient / chain rule
能用一维函数画出 slope
能用一个小例子解释 gradient descent 为什么能下降 loss
```

### 5. Optimization

中文：优化。

先学：

```text
objective
loss
parameter
gradient descent
learning rate
local minimum
global minimum
convexity intuition
regularization intuition
```

补到什么程度：

- 能说清“模型训练就是调参数让 loss 下降”。
- 能解释 learning rate 太大或太小会怎样。
- 能知道 convex 问题比较好，non-convex 问题更复杂。
- 能理解 regularization 是限制模型别乱拟合。

有什么用：

| CS / AI Area | Use |
| --- | --- |
| ML / DL | 训练模型 |
| LLM | pretraining、finetuning、RLHF/RLAIF 的底层语言 |
| Product | 指标优化和 tradeoff |
| Systems | latency / throughput / cost tradeoff |
| Search / ranking | optimize objective |

最低可交付：

```text
能解释 loss / parameter / gradient descent / learning rate
能用 Python 对 y = (x - 3)^2 做一个梯度下降小 demo
```

### 6. Information Theory

中文：信息论。

这块不是第一阶段必修，放在 AI/ML track 前后补。

先学：

```text
entropy
cross entropy
KL divergence
surprisal
compression intuition
```

补到什么程度：

- 能解释 entropy 是不确定性。
- 能解释 cross entropy 为什么常用于分类和语言模型。
- 能把 LLM 的 next token prediction 和概率分布联系起来。

有什么用：

| AI Area | Use |
| --- | --- |
| Classification | cross entropy loss |
| LLM | next-token prediction |
| Evaluation | perplexity |
| Compression | 信息和编码 |

最低可交付：

```text
能解释 entropy / cross entropy / perplexity 的人话版本
能知道它们和 LLM 训练有什么关系
```

## Priority Order

当前不按学校课程顺序补，而按 CS/AI 使用频率补：

```text
1. Discrete math
2. Linear algebra
3. Probability
4. Calculus
5. Optimization
6. Information theory
```

理由：

- 离散数学最直接支撑 CS 基础、数据结构、算法、编译器、数据库。
- 线代和概率是 AI/ML 的大门。
- 微积分和优化是理解训练过程的关键。
- 信息论等到分类、语言模型、cross entropy 出现时再补，性价比更高。

## First Pass Plan

### Week M1. Discrete Math Handles

目标：

```text
集合、函数、关系、图、树、归纳法、状态机都有一个人话模型和一个 Python 小例子。
```

Daily shape:

```text
Day 1: set / logic / function
Day 2: relation / graph / tree
Day 3: induction / recursion / invariant
Day 4: BFS / DFS as graph traversal
Day 5: state machine
Day 6: review with one mini note
Day 7: rest or retest
```

Output:

```text
notes/math/01-discrete-math-handles.md
```

### Week M2. Linear Algebra Handles

目标：

```text
vector、matrix、dot product、matrix multiplication 能翻成代码和 ML 直觉。
```

Output:

```text
notes/math/02-linear-algebra-handles.md
```

### Week M3. Probability Handles

目标：

```text
random variable、distribution、expectation、variance、conditional probability、Bayes 都能说人话。
```

Output:

```text
notes/math/03-probability-handles.md
```

### Week M4. Calculus And Optimization Handles

目标：

```text
derivative、gradient、chain rule、loss、gradient descent 能连接到模型训练。
```

Output:

```text
notes/math/04-calculus-optimization-handles.md
```

## Definition Of Done

第一轮数学不追求做难题。每块达到这个标准就先过：

```text
1. Human words: 能用人话解释。
2. Tiny example: 能举一个小例子。
3. Python sketch: 能写或读一个 10-30 行小代码。
4. CS/AI use: 能说它在 CS/AI 哪块有用。
5. Confusion list: 知道自己还不懂什么。
```

## What Not To Do Yet

先不要碰：

- 复杂积分技巧。
- 复变函数。
- 偏微分方程。
- 严格测度论概率。
- 大量手算线性代数题。
- 数学竞赛式证明。

这些不是永远不学，而是现在不是最高杠杆。

## How It Connects Back To The Big Map

| Big Map Layer | Math Needed |
| --- | --- |
| Layer 0 编程 + DS | 离散数学、复杂度、基本图论 |
| Layer 1 算法 | 离散数学、归纳法、复杂度、图 |
| Layer 1 OS/体系结构 | 二进制、地址、数量级、概率直觉 |
| Layer 1 编译器 | 形式语言、语法树、状态机 |
| Layer 2 网络/分布式 | 概率、状态机、图、延迟分布 |
| Layer 2 数据库 | 关系、树、概率估计、优化 |
| Layer 3 AI/ML | 线代、概率、微积分、优化、信息论 |
| Layer 4 工业实践 | 指标、实验、tradeoff、可靠性判断 |

## First Session

先从离散数学开第一刀：

```text
Topic: set / function / relation
Goal: 建立“数学对象如何变成代码里的数据结构”的直觉
Tiny code: Python set / dict / relation-as-list-of-pairs
Output: notes/math/01-discrete-math-handles.md 的第一小节
```

最小问题：

```text
集合是什么？
函数是什么？
关系是什么？
为什么 dict 像一个函数？
为什么数据库表像一组关系？
```
