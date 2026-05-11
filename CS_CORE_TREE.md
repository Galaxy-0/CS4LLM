# Layer 1 Core CS Tree / 第 1 层 CS 核心树

这份文件展开 `CS / AI 工业研究型本科地图` 的第 1 层。主树节点已经采用 `English / 中文` 的双语形式；[CS_CORE_BILINGUAL_GLOSSARY.md](./CS_CORE_BILINGUAL_GLOSSARY.md) 只是备用术语索引。

```text
1. 四大硬核主干：真正的 CS 骨架
Algorithms / 算法 / Operating Systems / 操作系统 / Computer Architecture / 计算机体系结构 / Compilers / 编译器
```

它不是“这个月就要啃完”的清单，而是后续学习时反复定位的深层地图。当前仓库主线仍然是先把 Layer 0 的数学、编程、数据结构、测试和工程手感补稳。

## Goal-Driven Contract

Goal:

```text
产出一份覆盖 Algorithms / OS / Architecture / Compilers 的深层知识树，作为后续 CS 骨架学习的长期索引。
```

Criteria:

1. 每个主干都要有 Layer 0 前置条件、核心概念树、实践项目、退出标准。
2. 层级要从“入门心智模型”逐步深入到“系统实现与工程判断”。
3. 每棵树都要标出与另外三棵树的交叉关系。
4. 不能只像课程目录，要能回答“这个东西补到什么程度、有什么用、怎么练”。
5. 作为后续学习地图，它允许丰富，但每个分支都要能落到 toy project、代码阅读、测试或 benchmark。

## Top-Level View

```text
Layer 1. Core CS Trunk / 第 1 层：CS 核心主干
├── Algorithms / 算法
│   ├── Algorithm analysis / 算法分析
│   ├── Data structures / 数据结构
│   ├── Paradigms / 算法范式
│   ├── Sorting / searching / selection / 排序 / 搜索 / 选择
│   ├── Graph algorithms / 图算法
│   ├── String algorithms / 字符串算法
│   ├── Randomized / probabilistic algorithms / 随机化 / 概率算法
│   ├── Complexity / NP / 复杂性 / NP
│   ├── Approximation / online / streaming / 近似 / 在线 / 流式算法
│   ├── Numeric / geometric / algebraic algorithms / 数值 / 几何 / 代数算法
│   ├── Parallel / external-memory / distributed algorithms / 并行 / 外存 / 分布式算法
│   └── Algorithm engineering / 算法工程
├── Operating Systems / 操作系统
│   ├── OS model / OS 模型
│   ├── Process / thread / execution context / 进程 / 线程 / 执行上下文
│   ├── Syscall / trap / interrupt / 系统调用 / 陷入 / 中断
│   ├── Memory / virtual memory / 内存 / 虚拟内存
│   ├── Scheduling / 调度
│   ├── Synchronization / concurrency / 同步 / 并发
│   ├── Filesystems / 文件系统
│   ├── I/O / devices / drivers / I/O / 设备 / 驱动
│   ├── Networking at OS boundary / OS 边界内的网络
│   ├── Security / isolation / 安全 / 隔离
│   ├── Virtualization / containers / 虚拟化 / 容器
│   ├── Observability / debugging / performance / 可观测性 / 调试 / 性能
│   └── Reliability / production behavior / 可靠性 / 生产行为
├── Computer Architecture / 计算机体系结构
│   ├── Digital logic / 数字逻辑
│   ├── Data representation / 数据表示
│   ├── ISA / assembly / 指令集架构 / 汇编
│   ├── Datapath / control / 数据通路 / 控制
│   ├── Pipelining / hazards / 流水线 / 冒险
│   ├── Memory hierarchy / cache / 存储层次 / 缓存
│   ├── Virtual memory boundary / 虚拟内存边界
│   ├── Performance modeling / 性能建模
│   ├── SIMD / multicore / GPU / SIMD / 多核 / GPU
│   ├── Storage / I/O boundary / 存储 / I/O 边界
│   └── Security / microarchitecture / 安全 / 微架构
└── Compilers / 编译器
    ├── Language implementation overview / 语言实现总览
    ├── Language design / 语言设计
    ├── Lexing / 词法分析
    ├── Parsing / 语法分析
    ├── AST / frontend representation / AST / 前端表示
    ├── Semantic analysis / 语义分析
    ├── Type systems / 类型系统
    ├── IR / 中间表示
    ├── Optimization / 优化
    ├── Code generation / 代码生成
    ├── Runtime systems / 运行时系统
    ├── VM / bytecode / interpreter / 虚拟机 / 字节码 / 解释器
    ├── GC / memory management / 垃圾回收 / 内存管理
    ├── JIT / dynamic optimization / JIT / 动态优化
    └── Tooling / diagnostics / tests / 工具链 / 诊断 / 测试
```

## 1. Algorithms / 算法

算法不是“刷题技巧”，而是把问题变成可计算结构的语言。它给 OS、体系结构、编译器、数据库、分布式系统提供共同的建模方式。

```text
Algorithms / 算法
├── A0. Layer 0 Prerequisites / Layer 0 前置基础
│   ├── Discrete math / 离散数学
│   │   ├── set / relation / function / mapping / 集合 / 关系 / 函数 / 映射
│   │   ├── logic / predicate / proof / 逻辑 / 谓词 / 证明
│   │   ├── induction / strong induction / 归纳法 / 强归纳
│   │   ├── invariant / 不变量
│   │   ├── recurrence / 递推式
│   │   └── graph / tree / DAG / 图 / 树 / 有向无环图
│   ├── Probability basics / 概率基础
│   │   ├── random variable / 随机变量
│   │   ├── expectation / variance / 期望 / 方差
│   │   ├── conditional probability / 条件概率
│   │   └── Bayes / Markov / Chebyshev / Chernoff intuition / 贝叶斯 / 马尔可夫 / 切比雪夫 / 切尔诺夫界直觉
│   ├── Programming basics / 编程基础
│   │   ├── Python for experiment / visualization / 用于实验的 Python / 可视化
│   │   ├── C/C++/Rust for memory and data structure reality / 用于理解内存和真实数据结构的 C/C++/Rust
│   │   ├── Java/Go for engineering interfaces / 用于工程接口的 Java/Go
│   │   └── tests / logs / debugging / profiling / 测试 / 日志 / 调试 / 性能剖析
│   └── Basic structures / 基础数据结构
│       ├── array / linked list / 数组 / 链表
│       ├── stack / queue / deque / 栈 / 队列 / 双端队列
│       ├── hash table / 哈希表
│       ├── binary tree / heap / 二叉树 / 堆
│       └── graph representation / 图表示
├── A1. Algorithm Analysis / 算法分析
│   ├── Computation models / 计算模型
│   │   ├── RAM model / 随机访问机模型
│   │   ├── Word RAM model / 字长随机访问机
│   │   ├── comparison model / 比较模型
│   │   └── pointer machine model / 指针机模型
│   ├── Asymptotic complexity / 渐进复杂度
│   │   ├── O / Omega / Theta / 大 O / Ω 下界 / Θ 紧界
│   │   ├── little-o / little-omega / 小 o / 小 ω
│   │   ├── O(1), O(log n), O(n), O(n log n), O(n^2), O(2^n) / 常见复杂度增长阶
│   │   └── multi-variable complexity: O(V + E), O(n + m) / 多变量复杂度：O(V + E), O(n + m)
│   ├── Recurrences / 递推式
│   │   ├── expansion / 展开法
│   │   ├── recursion tree / 递归树
│   │   ├── Master Theorem / 主定理
│   │   └── common recurrence patterns / 常见递推模式
│   ├── Correctness / 正确性
│   │   ├── loop invariant / 循环不变量
│   │   ├── recursive invariant / 递归不变量
│   │   ├── greedy-choice property / 贪心选择性质
│   │   ├── optimal substructure / 最优子结构
│   │   ├── exchange argument / 交换论证
│   │   └── cut property / 割性质
│   ├── Amortized analysis / 摊还分析
│   │   ├── aggregate method / 聚合法
│   │   ├── accounting method / 记账法
│   │   └── potential method / 势能法
│   └── Lower bounds / 下界
│       ├── comparison sorting lower bound / 比较排序下界
│       ├── information-theoretic intuition / 信息论直觉
│       └── reduction-based lower bound / 基于归约的下界
├── A2. Data Structures / 数据结构
│   ├── Linear structures / 线性结构
│   │   ├── array / dynamic array / 数组 / 动态数组
│   │   ├── linked list / intrusive list / 链表 / 侵入式链表
│   │   ├── stack / 栈
│   │   ├── queue / 队列
│   │   └── deque / monotonic queue / 双端队列 / 单调队列
│   ├── Hashing / 哈希
│   │   ├── hash function / 哈希函数
│   │   ├── chaining / 拉链法
│   │   ├── open addressing / 开放寻址
│   │   ├── load factor / rehashing / 负载因子 / 重哈希
│   │   ├── Bloom filter / 布隆过滤器
│   │   ├── Count-Min Sketch / 计数最小草图
│   │   └── consistent hashing / 一致性哈希
│   ├── Trees / 树结构
│   │   ├── binary tree / 二叉树
│   │   ├── BST / 二叉搜索树
│   │   ├── AVL / Red-Black / Treap / Splay / AVL 树 / 红黑树 / 树堆 / 伸展树
│   │   ├── B-tree / B+ tree / B 树 / B+ 树
│   │   ├── segment tree / 线段树
│   │   ├── Fenwick tree / 树状数组
│   │   ├── interval tree / 区间树
│   │   ├── order statistic tree / 顺序统计树
│   │   ├── trie / radix tree / Patricia trie / 前缀树 / 基数树 / Patricia 压缩前缀树
│   │   └── suffix tree as advanced entrance / 后缀树进阶入口
│   ├── Heap / priority queue / 堆 / 优先队列
│   │   ├── binary heap / 二叉堆
│   │   ├── d-ary heap / d 叉堆
│   │   ├── binomial / Fibonacci / pairing heap / 二项堆 / 斐波那契堆 / 配对堆
│   │   └── indexed priority queue / 带索引优先队列
│   ├── Disjoint Set Union / 并查集
│   │   ├── make-set / find / union / 建集合 / 查找代表元 / 合并集合
│   │   ├── path compression / 路径压缩
│   │   └── union by rank / size / 按秩合并 / 大小
│   ├── Persistent structures / 持久化数据结构
│   │   ├── path copying / 路径复制
│   │   ├── structural sharing / 结构共享
│   │   └── immutable map / versioned state / 不可变映射 / 版本化状态
│   └── Cache-friendly structures / 缓存友好数据结构
│       ├── AoS vs SoA / 数组套结构体 vs 结构体拆数组
│       ├── bitset / roaring bitmap / 位集合 / Roaring 位图
│       ├── compact representation / 紧凑表示
│       ├── arena allocator / arena 分配器
│       └── compressed sparse row / 压缩稀疏行
├── A3. Algorithmic Paradigms / 算法范式
│   ├── Brute force / enumeration / 暴力搜索 / 枚举
│   │   ├── subset enumeration / 子集枚举
│   │   ├── permutation enumeration / 排列枚举
│   │   ├── pruning / 剪枝
│   │   └── brute force as oracle / 暴力解作正确性基准
│   ├── Divide and conquer / 分治
│   │   ├── merge sort / 归并排序
│   │   ├── quicksort / quickselect / 快速排序 / 快速选择
│   │   ├── binary search / 二分搜索
│   │   ├── closest pair / 最近点对
│   │   ├── Karatsuba / Karatsuba 乘法
│   │   └── FFT entrance / FFT 入口
│   ├── Greedy / 贪心
│   │   ├── interval scheduling / 区间调度
│   │   ├── Huffman coding / 霍夫曼编码
│   │   ├── MST / 最小生成树
│   │   ├── Dijkstra condition / Dijkstra 适用条件
│   │   ├── matroid intuition / 拟阵直觉
│   │   └── failed greedy examples / 贪心失败案例
│   ├── Dynamic programming / 动态规划
│   │   ├── memoization / tabulation / 记忆化 / 表格法
│   │   ├── state / transition / base case / 状态 / 转移 / 基础情况
│   │   ├── path reconstruction / 路径还原
│   │   ├── LIS / LCS / edit distance / 最长递增子序列 / 最长公共子序列 / 编辑距离
│   │   ├── knapsack / 背包问题
│   │   ├── interval DP / tree DP / bitmask DP / 区间 DP / 树形 DP / 状态压缩 DP
│   │   ├── DP on DAG / DAG 上的 DP
│   │   └── optimization: monotonic queue / CHT / divide-and-conquer / Knuth / 优化问题：单调队列 / 凸包优化 / 分治 / Knuth 优化
│   ├── Backtracking / constraint solving / 回溯 / 约束求解
│   │   ├── DFS search tree / DFS 搜索树
│   │   ├── constraint propagation / 约束传播
│   │   ├── exact cover / Dancing Links / 精确覆盖 / 舞蹈链
│   │   ├── SAT / CSP entrance / 布尔可满足性 / CSP entrance
│   │   └── branch and bound / 分支定界
│   ├── Reduction / transformation / 归约 / 转换
│   │   ├── problem reduction / 问题归约
│   │   ├── graph modeling / 图建模
│   │   ├── flow modeling / 流建模
│   │   ├── shortest path modeling / 最短路建模
│   │   ├── SAT / ILP modeling / 布尔可满足性 / ILP modeling
│   │   └── NP-completeness entrance / NP 完全性入口
│   └── Randomization / 随机化
│       ├── Las Vegas vs Monte Carlo / 拉斯维加斯算法 vs 蒙特卡洛算法
│       ├── randomized quicksort / select / 随机快速排序 / select
│       ├── skip list / treap / 跳表 / 树堆
│       ├── random sampling / 随机抽样
│       └── probabilistic verification / 概率验证
├── A4. Sorting / Selection / Searching / 排序 / 选择 / 搜索
│   ├── Comparison sorting / 比较排序
│   │   ├── insertion / selection / bubble / 插入排序 / 选择排序 / 气泡
│   │   ├── merge sort / quicksort / heapsort / 归并排序 / 快速排序 / 堆排序
│   │   ├── introsort / 内省排序
│   │   └── timsort / TimSort 排序
│   ├── Non-comparison sorting / 非比较排序
│   │   ├── counting sort / 计数排序
│   │   ├── radix sort / 基数排序
│   │   └── bucket sort / 桶排序
│   ├── Sorting properties / 排序性质
│   │   ├── stable vs unstable / 稳定 vs 不稳定
│   │   ├── in-place vs out-of-place / 原地 vs 非原地
│   │   ├── external sorting / 外部排序
│   │   ├── parallel sorting / 并行排序
│   │   └── cache-aware sorting / 缓存感知排序
│   ├── Selection / 选择
│   │   ├── min / max / 最小值 / 最大值
│   │   ├── kth element / 第 k 个元素
│   │   ├── quickselect / 快速选择
│   │   ├── median of medians / 中位数的中位数
│   │   └── top-k / streaming top-k / 前 k 个 / 流式前 k 个
│   └── Searching / 搜索
│       ├── linear search / 线性搜索
│       ├── binary search / 二分搜索
│       ├── binary search on answer / 答案二分
│       ├── exponential / interpolation / ternary search / 指数搜索 / 插值搜索 / 三分搜索
│       └── parametric search entrance / 参数搜索入口
├── A5. Graph Algorithms / 图算法
│   ├── Representation / 表示方式
│   │   ├── adjacency matrix / 邻接矩阵
│   │   ├── adjacency list / 邻接表
│   │   ├── edge list / 边列表
│   │   ├── CSR / 压缩稀疏行
│   │   └── implicit / dynamic graph / 隐式图 / 动态图
│   ├── Traversal / 遍历
│   │   ├── BFS / 广度优先搜索
│   │   ├── DFS / 深度优先搜索
│   │   ├── connected components / 连通分量
│   │   ├── bipartite checking / 二分图检查
│   │   ├── topological sort / 拓扑排序
│   │   └── cycle detection / 环检测
│   ├── Shortest paths / 最短路
│   │   ├── BFS / 广度优先搜索
│   │   ├── Dijkstra / Dijkstra 算法
│   │   ├── Bellman-Ford / Bellman-Ford 算法
│   │   ├── Floyd-Warshall / Floyd-Warshall 算法
│   │   ├── Johnson / Johnson 算法
│   │   ├── A* / A* 搜索
│   │   └── bidirectional search / 双向搜索
│   ├── MST / 最小生成树
│   │   ├── Kruskal / Kruskal 算法
│   │   ├── Prim / Prim 算法
│   │   ├── Boruvka / Boruvka 算法
│   │   ├── cut property / 割性质
│   │   └── cycle property / 环性质
│   ├── Connectivity / 连通性
│   │   ├── Tarjan SCC / Tarjan 强连通分量
│   │   ├── Kosaraju / Kosaraju 算法
│   │   ├── articulation points / 割点
│   │   ├── bridges / 桥
│   │   └── condensation graph / 缩点图
│   ├── Flow / matching / 流 / 匹配
│   │   ├── max flow / 最大流
│   │   ├── min cut / 最小割
│   │   ├── Dinic / Dinic 算法
│   │   ├── push-relabel / 预流推进
│   │   ├── min-cost max-flow / 最小费用最大流
│   │   ├── bipartite matching / 二分图匹配
│   │   ├── Hopcroft-Karp / Hopcroft-Karp 算法
│   │   └── Hungarian algorithm / 匈牙利算法
│   └── Advanced graph ideas / 高级图概念
│       ├── graph coloring / 图着色
│       ├── dominator tree / 支配树
│       ├── dataflow fixed point / 数据流不动点
│       ├── PageRank / random walk / PageRank / 随机游走
│       ├── tree decomposition entrance / 树分解入口
│       └── dynamic graph entrance / 动态图入口
├── A6. String Algorithms / 字符串算法
│   ├── String basics / 字符串基础
│   │   ├── ASCII / UTF-8 / Unicode / ASCII 编码 / UTF-8 编码 / Unicode
│   │   ├── byte array vs string / 字节数组 vs 字符串
│   │   ├── prefix / suffix / substring / subsequence / 前缀 / 后缀 / 子串 / 子序列
│   │   └── lexicographic order / 字典序
│   ├── Pattern matching / 模式匹配
│   │   ├── naive matching / 朴素匹配
│   │   ├── KMP / KMP 算法
│   │   ├── Z algorithm / Z 算法
│   │   ├── Rabin-Karp / Rabin-Karp 算法
│   │   ├── Boyer-Moore / Boyer-Moore 算法
│   │   └── Aho-Corasick / Aho-Corasick 自动机
│   ├── Suffix structures / 后缀结构
│   │   ├── suffix array / 后缀数组
│   │   ├── LCP array / 最长公共前缀数组
│   │   ├── suffix tree / 后缀树
│   │   ├── suffix automaton / 后缀自动机
│   │   ├── FM-index / FM 索引
│   │   └── Burrows-Wheeler Transform / Burrows-Wheeler 变换
│   ├── Diff / sequence alignment / 差异比较 / 序列比对
│   │   ├── Levenshtein distance / Levenshtein 距离
│   │   ├── edit distance DP / 编辑距离动态规划
│   │   ├── LCS / 最长公共子序列
│   │   └── Myers diff / Myers diff 算法
│   └── Compiler connection / 编译器连接点
│       ├── regex engine / 正则引擎
│       ├── NFA / DFA / 非确定有限自动机 / 确定有限自动机
│       ├── lexer / 词法分析器
│       ├── CYK / Earley / CYK 算法 / Earley 解析算法
│       └── LL / LR parsing entrance / LL 解析 / LR parsing entrance
├── A7. Randomized / Probabilistic Algorithms / 随机化 / 概率算法
│   ├── Randomization basics / 随机化基础
│   │   ├── expected runtime / 期望运行时间
│   │   ├── high-probability bound / 高概率界
│   │   ├── independence / 独立性
│   │   └── probability amplification / 概率放大
│   ├── Randomized algorithms / 随机化算法
│   │   ├── randomized quicksort / select / 随机快速排序 / select
│   │   ├── skip list / treap / 跳表 / 树堆
│   │   ├── Miller-Rabin / Miller-Rabin 素性测试
│   │   ├── randomized min cut / 随机最小割
│   │   └── randomized load balancing / 随机负载均衡
│   ├── Sampling / estimation / 抽样 / 估计
│   │   ├── reservoir sampling / 水塘抽样
│   │   ├── Monte Carlo simulation / 蒙特卡洛模拟
│   │   ├── HyperLogLog / 基数估计算法
│   │   ├── MinHash / 最小哈希
│   │   └── locality-sensitive hashing / 局部敏感哈希
│   └── Probabilistic data structures / 概率数据结构
│       ├── Bloom filter / 布隆过滤器
│       ├── Counting Bloom filter / 计数布隆过滤器
│       ├── Cuckoo filter / Cuckoo 过滤器
│       ├── Count-Min Sketch / 计数最小草图
│       └── quotient filter entrance / Quotient 过滤器入口
├── A8. Complexity / NP / 复杂性 / NP
│   ├── Problem types / 问题类型
│   │   ├── decision / 决策问题
│   │   ├── search / 搜索问题
│   │   ├── optimization / 优化
│   │   └── language recognition / 语言识别
│   ├── Complexity classes / 复杂度类
│   │   ├── P / NP / co-NP / P 类 / NP 类 / co-NP 类
│   │   ├── EXP / PSPACE entrance / EXP 类 / PSPACE 入口
│   │   ├── RP / BPP / RP 类 / BPP 类
│   │   └── parameterized complexity / 参数化复杂性
│   ├── Reductions / 归约
│   │   ├── many-one reduction / 多一归约
│   │   ├── polynomial-time reduction / 多项式时间归约
│   │   └── reduction chain / 归约链
│   ├── NP-completeness / NP 完全性
│   │   ├── SAT / 3-SAT / 布尔可满足性 / 3-SAT
│   │   ├── CLIQUE / VERTEX-COVER / INDEPENDENT-SET / 团问题 / 点覆盖 / 独立集
│   │   ├── HAMILTONIAN-CYCLE / 哈密顿回路
│   │   ├── TSP / 旅行商问题
│   │   ├── SUBSET-SUM / PARTITION / KNAPSACK / 子集和 / 划分问题 / 背包问题
│   │   └── SET-COVER / graph coloring / exact cover / 集合覆盖 / 图着色 / 精确覆盖
│   └── Engineering response / 工程应对策略
│       ├── exact exponential / 精确指数算法
│       ├── branch and bound / 分支定界
│       ├── SAT / SMT / ILP / 布尔可满足性 / 同步多线程 / 指令级并行
│       ├── approximation / 近似算法
│       ├── heuristics / 启发式
│       ├── local search / 局部搜索
│       └── parameterized algorithms / 参数化算法
├── A9. Approximation / Online / Streaming / 近似 / 在线 / 流式算法
│   ├── Approximation / 近似算法
│   │   ├── approximation ratio / 近似比
│   │   ├── PTAS / FPTAS / 多项式时间近似方案 / 完全多项式时间近似方案
│   │   ├── LP relaxation / rounding / 线性规划松弛 / 舍入
│   │   ├── set cover / 集合覆盖
│   │   ├── vertex cover / 点覆盖
│   │   └── knapsack FPTAS / 背包 FPTAS
│   ├── Online algorithms / 在线算法
│   │   ├── competitive analysis / 竞争分析
│   │   ├── caching / paging / 缓存 / 分页
│   │   ├── ski rental / 滑雪租赁问题
│   │   ├── online scheduling / 在线调度
│   │   └── load balancing / 负载均衡
│   ├── Streaming / 流式算法
│   │   ├── one-pass constraints / 单遍约束
│   │   ├── sublinear memory / 亚线性内存
│   │   ├── heavy hitters / 高频项
│   │   ├── approximate quantiles / 近似分位数
│   │   ├── distinct count / 去重计数
│   │   └── sliding window / 滑动窗口
│   └── System uses / 系统应用
│       ├── telemetry aggregation / 遥测聚合
│       ├── observability metrics / 可观测性指标
│       ├── rate limiting / 限流
│       ├── abuse detection / 滥用检测
│       └── cache admission / 缓存准入
├── A10. Numeric / Geometric / Algebraic Algorithms / 数值 / 几何 / 代数算法
│   ├── Numeric / 数值算法
│   │   ├── floating point / 浮点数
│   │   ├── numerical stability / 数值稳定性
│   │   ├── root finding / 求根
│   │   ├── Gaussian elimination / 高斯消元
│   │   ├── matrix multiplication / 矩阵乘法
│   │   └── sparse matrix / 稀疏矩阵
│   ├── Computational geometry / 计算几何
│   │   ├── orientation test / 方向测试
│   │   ├── line segment intersection / 线段相交
│   │   ├── convex hull / 凸包
│   │   ├── sweep line / 扫描线
│   │   ├── closest pair / 最近点对
│   │   └── kd-tree / quad tree / R-tree / k-d 树 / 四叉树 / R 树
│   └── Algebraic / 代数算法
│       ├── fast exponentiation / 快速幂
│       ├── modular arithmetic / 模运算
│       ├── Euclidean algorithm / 欧几里得算法
│       ├── primality testing / 素性测试
│       ├── FFT / NTT / FFT / 数论变换
│       └── polynomial multiplication / 多项式乘法
├── A11. Parallel / External-Memory / Distributed Algorithms / 并行 / 外存 / 分布式算法
│   ├── Parallel / 并行算法
│   │   ├── work / span / 工作量 / 跨度
│   │   ├── fork-join / 分叉-合并
│   │   ├── parallel prefix sum / 并行前缀和
│   │   ├── map-reduce / MapReduce 分布式计算模型
│   │   └── parallel sort / BFS / 并行排序 / 广度优先搜索
│   ├── External memory / 外存算法
│   │   ├── I/O model / I/O 模型
│   │   ├── block transfer / 块传输
│   │   ├── external merge sort / 外部归并排序
│   │   ├── B-tree / B 树
│   │   └── cache-oblivious algorithms / 缓存无关算法
│   ├── Distributed algorithm entrance / 分布式算法入口
│   │   ├── leader election / 领导者选举
│   │   ├── consistent hashing / 一致性哈希
│   │   ├── sharding / 分片
│   │   ├── gossip / Gossip 协议
│   │   └── fault model / 故障模型
│   └── GPU / vector algorithms / GPU / 向量算法
│       ├── data parallelism / 数据并行
│       ├── reduction / 归约
│       ├── matrix multiplication / 矩阵乘法
│       └── memory coalescing / 内存合并访问
└── A12. Algorithm Engineering / 算法工程
    ├── From pseudocode to reliable code / 从伪代码到可靠实现
    │   ├── edge cases / 边界情况
    │   ├── overflow / 溢出
    │   ├── deterministic output / 确定性输出
    │   ├── memory ownership / 内存所有权
    │   └── stable API / 稳定 API
    ├── Testing / verification / 测试 / 验证
    │   ├── unit tests / 单元测试
    │   ├── property-based tests / 性质测试
    │   ├── fuzzing / 模糊测试
    │   ├── brute-force oracle / 暴力正确性基准
    │   ├── differential testing / 差分测试
    │   └── invariant checks / 不变量检查
    ├── Performance / 性能
    │   ├── benchmark / 基准测试
    │   ├── profiler / 性能剖析器
    │   ├── constant factor / 常数因子
    │   ├── allocation cost / 分配成本
    │   ├── branch prediction / 分支预测
    │   ├── cache locality / 缓存局部性
    │   └── vectorization / parallel overhead / 向量化 / 并行开销
    └── AI-assisted workflow / AI 辅助学习流程
        ├── ask AI for multiple solutions / 让 AI 给多个解法
        ├── ask AI for counterexamples / 让 AI 给反例
        ├── generate oracle / random tests / 生成正确性基准 / 随机测试
        ├── generate benchmark harness / 生成 benchmark 框架
        └── human must explain sample, failure, invariant, rewrite / human must explain sample，failure，不变量，rewrite
```

### Algorithms Practice Spine

```text
Phase A. 可证明的基础算法
├── Big-O / recurrence / correctness / 大 O / 递推式 / 正确性
├── sorting / binary search / basic structures / sorting / 二分搜索 / basic structures
├── BFS / DFS / Dijkstra / MST / 广度优先搜索 / 深度优先搜索 / Dijkstra 算法 / 最小生成树
└── output: 20 core implementations with tests / 输出：20 个带测试的核心实现

Phase B. 范式迁移
├── greedy / 贪心
├── dynamic programming / 动态规划
├── divide and conquer / 分治
├── backtracking / 回溯
└── reductions / 归约

Phase C. 系统可用算法
├── hash table / 哈希表
├── B-tree / B 树
├── LRU cache / 最近最少使用缓存
├── external sort / 外部排序
├── string matching / 字符串匹配
└── priority scheduler / 优先级调度器

Phase D. 困难问题与工程策略
├── NP-completeness / NP 完全性
├── approximation / 近似算法
├── online / 在线算法
├── randomized / 随机化算法
└── streaming / 流式算法

Phase E. 跨主干融合
├── OS scheduler + online algorithms / OS 调度器 + 在线算法
├── compiler CFG + graph algorithms / 编译器控制流图 + 图算法
├── architecture cache + data layout / 体系结构缓存 + 数据布局
└── database/search index + trees/string algorithms / 数据库或搜索索引 + 树和字符串算法
```

### Algorithms Exit Criteria

- 能对常见算法写出正确性证明和复杂度分析。
- 能区分 worst-case、average-case、expected、amortized。
- 能从零实现核心数据结构与算法，并配测试、oracle、benchmark。
- 能把实际问题抽象为图、序列、集合、状态空间、流网络或约束系统。
- 能识别可能 NP-hard 的需求，并提出可运行的工程替代方案。

## 2. Operating Systems / 操作系统

OS 是把裸硬件变成可用抽象的系统：进程、文件、虚拟内存、socket、权限、调度、持久化、隔离。

```text
Operating Systems / 操作系统
├── O0. Layer 0 Prerequisites / Layer 0 前置基础
│   ├── Systems C / 系统级 C 语言
│   │   ├── pointer / array / struct / function pointer / pointer / 数组 / struct / function pointer
│   │   ├── stack / heap / memory layout / 栈 / 堆 / memory layout
│   │   ├── malloc / free / 动态分配 / 释放
│   │   ├── undefined behavior / 未定义行为
│   │   └── compile / link / object file / library / compile / link / 目标文件 / library
│   ├── Data structures / 数据结构
│   │   ├── linked list / 链表
│   │   ├── queue / 队列
│   │   ├── heap / 堆
│   │   ├── tree / 树
│   │   ├── hash table / 哈希表
│   │   └── bitmap / 位图
│   ├── Architecture / 体系结构
│   │   ├── privilege level / 权限级别
│   │   ├── interrupt / 中断
│   │   ├── cache / TLB / MMU / 缓存 / TLB / MMU
│   │   ├── DMA / 直接内存访问
│   │   ├── atomic instruction / 原子指令
│   │   └── memory barrier / 内存屏障
│   └── Compiler/runtime basics / 编译器 / 运行时基础
│       ├── ABI / 应用二进制接口
│       ├── calling convention / 调用约定
│       ├── stack frame / 栈帧
│       ├── ELF / Mach-O / ELF 格式 / Mach-O 格式
│       ├── loader / 加载器
│       └── dynamic linking / 动态链接
├── O1. OS Overall Model / OS 总体模型
│   ├── Core responsibilities / 核心职责
│   │   ├── abstraction: process / file / virtual memory / socket / 抽象：进程 / 文件 / 虚拟内存 / 套接字
│   │   ├── multiplexing: CPU / memory / disk / network / multiplexing：中央处理器 / 访存 / disk / 网络
│   │   ├── isolation: address space / privilege / capability / 隔离：地址空间 / privilege / capability
│   │   ├── persistence: filesystem / journal / cache / persistence：filesystem / journal / 缓存
│   │   ├── concurrency: interrupt / thread / lock / scheduler / concurrency：中断 / 线程 / lock / 调度器
│   │   └── reliability: crash recovery / observability / 可靠性：crash recovery / 可观测性
│   ├── Kernel architecture / 内核架构
│   │   ├── monolithic kernel / 单体内核
│   │   ├── microkernel / 微内核
│   │   ├── hybrid kernel / 混合内核
│   │   ├── exokernel / library OS / 外核 / 库操作系统
│   │   ├── unikernel / 单用途内核
│   │   └── Linux / xv6 / BSD / seL4 comparison / Linux / xv6 / BSD / seL4 对比
│   └── Resource lifecycle / 资源生命周期
│       ├── process / 进程
│       ├── page / 页
│       ├── file descriptor / 文件描述符
│       ├── inode / 索引节点
│       └── socket / 套接字
├── O2. Process / Thread / Execution Context / 进程 / 线程 / 执行上下文
│   ├── Process model / 进程模型
│   │   ├── address space / 地址空间
│   │   ├── file descriptor table / 文件描述符表
│   │   ├── signal handlers / 信号处理器
│   │   ├── credentials / 凭据
│   │   ├── cwd / environment / 当前工作目录 / 环境变量
│   │   ├── parent-child relationship / 父子进程关系
│   │   └── zombie / orphan process / 僵尸进程 / 孤儿进程
│   ├── Process lifecycle / 进程生命周期
│   │   ├── fork / 创建子进程
│   │   ├── exec / 替换当前进程镜像
│   │   ├── wait / 等待并回收子进程
│   │   ├── exit / 进程退出
│   │   ├── clone / Linux 创建进程或线程的底层接口
│   │   └── copy-on-write fork / 写时复制 fork
│   ├── Threads / 线程
│   │   ├── kernel thread vs user thread / 内核线程 vs 用户线程
│   │   ├── 1:1 / M:N threading / 一对一 / 多对多线程模型
│   │   ├── pthreads / POSIX 线程库
│   │   ├── thread-local storage / 线程局部存储
│   │   └── stack per thread / 每个线程独立栈
│   ├── Context switch / 上下文切换
│   │   ├── register save / restore / 寄存器保存恢复
│   │   ├── kernel stack / 内核栈
│   │   ├── trap frame / 陷入帧
│   │   ├── address space switch / 地址空间切换
│   │   ├── TLB flush / ASID / PCID / TLB 刷新 / 地址空间标识 / 进程上下文 ID
│   │   └── lazy FPU state / 惰性保存浮点单元状态
│   └── Signals / 信号
│       ├── signal delivery / 信号投递
│       ├── signal mask / 信号屏蔽字
│       ├── async-signal-safe / 异步信号安全
│       └── signal vs interrupt vs exception / 信号 vs 中断 vs 异常
├── O3. Syscall / Trap / Interrupt / 系统调用 / 陷入 / 中断
│   ├── User mode / kernel mode / 用户态 / 内核态
│   │   ├── privilege rings / 权限环
│   │   ├── syscall ABI / 系统调用 ABI
│   │   ├── syscall number / arguments / 系统调用号 / 参数
│   │   └── return value / errno / 返回值 / errno
│   ├── Trap types / 陷入类型
│   │   ├── syscall / 系统调用
│   │   ├── page fault / 缺页
│   │   ├── divide-by-zero / 除零异常
│   │   ├── illegal instruction / 非法指令异常
│   │   ├── breakpoint / 断点
│   │   ├── timer interrupt / 定时器中断
│   │   └── device interrupt / 设备中断
│   ├── Trap path / 陷入路径
│   │   ├── CPU saves minimal state / CPU 保存最小现场
│   │   ├── switch to kernel stack / 切换到内核栈
│   │   ├── build trap frame / 构造陷入帧
│   │   ├── dispatch handler / 分发处理函数
│   │   ├── validate user pointer / 校验用户指针
│   │   ├── copyin / copyout / 从用户空间拷入 / 拷出到用户空间
│   │   └── return to user mode / 返回用户态
│   ├── Interrupts / 中断
│   │   ├── interrupt controller / 中断控制器
│   │   ├── top half / bottom half / 中断上半部 / 下半部
│   │   ├── softirq / workqueue / 软中断 / 工作队列
│   │   ├── interrupt latency / 中断延迟
│   │   └── preemption boundary / 抢占边界
│   └── Security boundary / 安全边界
│       ├── parameter validation / 参数校验
│       ├── TOCTOU / 检查时到使用时竞态
│       ├── seccomp / 系统调用过滤机制
│       └── capability checks / 能力检查
├── O4. Memory / Virtual Memory / 内存 / 虚拟内存
│   ├── Physical memory / 物理内存
│   │   ├── page frame / 页框
│   │   ├── free list / 空闲链表
│   │   ├── buddy allocator / 伙伴分配器
│   │   ├── slab / slub allocator / slab 分配器 / slub 分配器
│   │   ├── per-CPU cache / 每 CPU 缓存
│   │   └── NUMA basics / NUMA 基础
│   ├── Virtual address space / 虚拟地址空间
│   │   ├── user/kernel split / 用户/内核地址空间划分
│   │   ├── text / data / bss / heap / stack / mmap / 代码段 / 数据段 / 未初始化数据段 / 堆 / 栈 / 内存映射
│   │   ├── guard page / 保护页
│   │   ├── ASLR / 地址空间布局随机化
│   │   └── VMA / 虚拟内存区域
│   ├── Page table / 页表
│   │   ├── multi-level page table / 多级页表
│   │   ├── PTE flags / 页表项标志
│   │   ├── huge pages / 大页
│   │   ├── TLB / 地址翻译缓存
│   │   ├── page walk / 页表遍历
│   │   └── page fault handling / 缺页处理
│   ├── Demand paging / 按需分页
│   │   ├── lazy allocation / 惰性分配
│   │   ├── zero page / 零页
│   │   ├── copy-on-write / 写时复制
│   │   ├── memory-mapped file / mmap / 内存映射文件 / 内存映射
│   │   ├── swap / swap / 交换空间 / 交换空间
│   │   ├── page replacement / 页面置换
│   │   └── working set / thrashing / 工作集 / 抖动
│   ├── Kernel memory / 内核内存
│   │   ├── direct mapping / 直接映射
│   │   ├── kernel heap / 内核堆
│   │   ├── vmalloc / vmalloc 区
│   │   ├── memory pinning / 内存钉住
│   │   └── DMA-safe memory / DMA 安全内存
│   └── Memory safety / 内存安全
│       ├── use-after-free / 释放后使用
│       ├── double free / 重复释放
│       ├── buffer overflow / 缓冲区溢出
│       ├── stack overflow / 栈溢出
│       ├── ASAN / KASAN / 地址消毒器 / 内核地址消毒器
│       └── guard pages / 保护页
├── O5. Scheduling / 调度
│   ├── Goals / 目标
│   │   ├── throughput / 吞吐量
│   │   ├── latency / 延迟
│   │   ├── fairness / 公平性
│   │   ├── responsiveness / 响应性
│   │   ├── deadline / 截止期
│   │   ├── energy efficiency / 能效
│   │   └── cache affinity / 缓存亲和性
│   ├── Algorithms / 算法
│   │   ├── FCFS / 先来先服务
│   │   ├── SJF / SRTF / 最短作业优先 / 最短剩余时间优先
│   │   ├── Round Robin / 时间片轮转
│   │   ├── Priority Scheduling / 优先级调度
│   │   ├── MLFQ / 多级反馈队列
│   │   ├── Lottery / Stride / 彩票调度 / 步幅调度
│   │   ├── EDF / 最早截止期优先
│   │   └── RMS / 速率单调调度
│   ├── Linux-style scheduling / Linux 风格调度
│   │   ├── CFS / 完全公平调度器
│   │   ├── virtual runtime / 虚拟运行时间
│   │   ├── red-black tree runqueue / 红黑树运行队列
│   │   ├── nice value / nice 值
│   │   ├── scheduler class / 调度类
│   │   ├── realtime scheduling / 实时调度
│   │   ├── CPU affinity / CPU 亲和性
│   │   └── cgroups CPU controller / cgroups CPU 控制器
│   ├── Multiprocessor scheduling / 多处理器调度
│   │   ├── per-CPU run queues / 每 CPU 运行队列
│   │   ├── work stealing / 工作窃取
│   │   ├── cache locality / 缓存局部性
│   │   ├── NUMA awareness / NUMA 感知
│   │   └── preemption / 抢占
│   └── Priority pathologies / 优先级问题
│       ├── starvation / 饥饿
│       ├── priority inversion / 优先级反转
│       ├── priority inheritance / 优先级继承
│       └── convoy effect / 护航效应
├── O6. Synchronization / Concurrency / 同步 / 并发
│   ├── Problems / 问题
│   │   ├── race condition / 竞态条件
│   │   ├── critical section / 临界区
│   │   ├── atomicity / visibility / ordering / 原子性 / 可见性 / 顺序性
│   │   ├── deadlock / 死锁
│   │   ├── livelock / 活锁
│   │   └── starvation / 饥饿
│   ├── Atomic / memory model / 原子操作 / 内存模型
│   │   ├── CAS / 比较并交换
│   │   ├── test-and-set / 测试并设置
│   │   ├── fetch-add / 取后加
│   │   ├── acquire / release / 获取语义 / 释放语义
│   │   ├── memory barrier / 内存屏障
│   │   └── cache coherence / 缓存一致性
│   ├── Locks / 锁
│   │   ├── spinlock / 自旋锁
│   │   ├── mutex / 互斥锁
│   │   ├── reader-writer lock / 读写锁
│   │   ├── seqlock / 顺序锁
│   │   ├── RCU / 读复制更新
│   │   ├── futex / 快速用户态互斥
│   │   └── lock-free vs wait-free / 无锁 vs 等待自由
│   ├── Condition synchronization / 条件同步
│   │   ├── semaphore / 信号量
│   │   ├── condition variable / 条件变量
│   │   ├── monitor / 管程
│   │   ├── wait queue / 等待队列
│   │   └── completion / 完成
│   └── Kernel concurrency / 内核并发
│       ├── interrupt disable / 关闭中断
│       ├── preemption disable / 关闭抢占
│       ├── per-CPU data / 每 CPU 数据
│       ├── workqueue / 工作队列
│       ├── reference counting / 引用计数
│       └── lifetime management / 生命周期管理
├── O7. Filesystems / 文件系统
│   ├── File abstraction / 文件抽象
│   │   ├── file descriptor / 文件描述符
│   │   ├── open file table / 打开文件表
│   │   ├── inode / 索引节点
│   │   ├── dentry / 目录项
│   │   ├── path lookup / 路径查找
│   │   ├── hard link / symbolic link / 硬链接 / 符号链接
│   │   └── sparse file / 稀疏文件
│   ├── Disk layout / 磁盘布局
│   │   ├── superblock / 超级块
│   │   ├── inode table / inode 表
│   │   ├── data blocks / 数据块
│   │   ├── bitmap / 位图
│   │   ├── extents / 区段
│   │   └── indirect blocks / 间接块
│   ├── File operation path / 文件操作路径
│   │   ├── open / 打开
│   │   ├── read / write / 读 / 写
│   │   ├── lseek / 移动文件偏移
│   │   ├── fsync / fsync / 同步落盘 / 同步落盘
│   │   ├── rename / 重命名
│   │   ├── unlink / 解除链接
│   │   ├── page cache / 页缓存
│   │   └── writeback / 写回
│   ├── Crash consistency / 崩溃一致性
│   │   ├── journaling / 日志记录
│   │   ├── WAL / 预写日志
│   │   ├── copy-on-write FS / 写时复制文件系统
│   │   ├── ordered writes / 有序写入
│   │   └── fsck / 文件系统检查
│   └── VFS / 虚拟文件系统
│       ├── mount namespace / 挂载命名空间
│       ├── procfs / sysfs / tmpfs / proc 文件系统 / sysfs / 内存临时文件系统
│       ├── device files / 设备文件
│       └── FUSE / 用户态文件系统
├── O8. I/O / Devices / Drivers / I/O / 设备 / 驱动
│   ├── I/O models / I/O 模型
│   │   ├── programmed I/O / 程序控制 I/O
│   │   ├── interrupt-driven I/O / 中断驱动 I/O
│   │   ├── DMA / 直接内存访问
│   │   ├── MMIO / 内存映射 I/O
│   │   ├── polling / 轮询
│   │   ├── blocking / non-blocking / 分块 / 非阻塞
│   │   └── async I/O / 异步 I/O
│   ├── Driver model / 驱动模型
│   │   ├── device discovery / 设备发现
│   │   ├── probe / remove / 探测 / 移除
│   │   ├── character device / 字符设备
│   │   ├── block device / 块设备
│   │   ├── network device / 网络设备
│   │   ├── ioctl / I/O 控制
│   │   └── sysfs / sys 虚拟文件系统
│   ├── Block I/O / 块 I/O
│   │   ├── request queue / 请求队列
│   │   ├── elevator scheduling / 电梯调度
│   │   ├── merge / split requests / 合并 / 拆分请求
│   │   ├── NVMe queues / NVMe 队列
│   │   └── completion path / 完成路径
│   └── Event I/O / 事件 I/O
│       ├── select / I/O 多路复用接口
│       ├── poll / I/O 多路复用接口
│       ├── epoll / Linux 高并发事件通知机制
│       ├── kqueue / BSD 事件通知机制
│       ├── io_uring / Linux 异步 I/O 接口
│       └── readiness vs completion / 就绪 vs 完成
├── O9. Networking at OS Boundary / OS 边界内的网络
│   ├── Socket abstraction / Socket 抽象
│   │   ├── socket / bind / listen / accept / connect / 套接字 / 绑定 / 监听 / 接受连接 / 连接
│   │   ├── send / recv / 发送 / 接收
│   │   ├── blocking / non-blocking socket / 分块 / non-blocking socket
│   │   ├── socket options / 套接字选项
│   │   └── backlog / 待连接队列
│   ├── Network stack / 网络协议栈
│   │   ├── NIC driver / 网卡驱动
│   │   ├── Ethernet / ARP / IP / ICMP / 以太网 / 地址解析协议 / 互联网协议 / ICMP 协议
│   │   ├── UDP / TCP / UDP 协议 / TCP 协议
│   │   ├── routing table / 路由表
│   │   └── firewall hooks / 防火墙钩子
│   ├── TCP in OS / OS 中的 TCP
│   │   ├── connection state machine / 连接状态机
│   │   ├── retransmission / 重传
│   │   ├── congestion control / 拥塞控制
│   │   ├── flow control / 流量控制
│   │   ├── socket buffers / 套接字缓冲区
│   │   ├── TIME_WAIT / TIME_WAIT 状态
│   │   └── SYN backlog / SYN 半连接队列
│   └── Packet path / 数据包路径
│       ├── interrupt / NAPI / 中断 / NAPI
│       ├── skb / socket buffer 结构
│       ├── protocol dispatch / 协议分发
│       ├── socket buffer / socket 缓冲区
│       ├── wakeup application / 唤醒应用
│       └── zero-copy / 零拷贝
├── O10. Security / Isolation / 安全 / 隔离
│   ├── Permissions / 权限
│   │   ├── UID / GID / 用户 ID / 组 ID
│   │   ├── file permissions / 文件权限
│   │   ├── setuid / setuid 权限
│   │   ├── capabilities / 能力机制
│   │   ├── ACL / 访问控制列表
│   │   └── LSM / Linux 安全模块
│   ├── Process isolation / 进程隔离
│   │   ├── virtual address space / 虚拟地址空间
│   │   ├── kernel/user boundary / 内核 / 用户边界
│   │   ├── credentials / 凭据
│   │   ├── namespaces / 命名空间
│   │   └── cgroups / cgroups / 控制组 / 控制组
│   ├── Syscall attack surface / 系统调用攻击面
│   │   ├── validation / 校验
│   │   ├── seccomp-bpf / 基于 BPF 的系统调用过滤
│   │   ├── sandboxing / 沙箱
│   │   ├── TOCTOU / 检查时到使用时竞态
│   │   └── privilege escalation / 权限提升
│   └── Hardening / 安全加固
│       ├── ASLR / 地址空间布局随机化
│       ├── NX / DEP / 不可执行位 / 数据执行保护
│       ├── stack canary / 栈金丝雀
│       ├── W^X / 写和执行互斥
│       ├── SMEP / SMAP / 内核防执行用户页 / 内核防访问用户页
│       └── CFI / 控制流完整性
├── O11. Virtualization / Containers / 虚拟化 / 容器
│   ├── Virtualization / 虚拟化
│   │   ├── trap-and-emulate / 陷入并模拟
│   │   ├── hardware virtualization / 硬件虚拟化
│   │   ├── hypervisor / 虚拟机监控器
│   │   ├── VM exit / 虚拟机退出
│   │   ├── shadow page table / 影子页表
│   │   ├── nested page table / 嵌套页表
│   │   └── virtio / virtio 半虚拟化设备
│   ├── Containers / 容器
│   │   ├── namespaces: pid / mount / network / ipc / uts / user / 命名空间：进程 ID / mount / 网络 / 每周期指令数 / 主机名命名空间 / 用户命名空间
│   │   ├── cgroups: cpu / memory / io / pids / 控制组：中央处理器 / 访存 / io / pids
│   │   ├── union filesystem / 联合文件系统
│   │   ├── rootfs / 根文件系统
│   │   ├── runtime / 运行时
│   │   └── OCI / 开放容器倡议
│   └── Resource accounting / 资源统计 / 限制
│       ├── CPU quota / CPU 配额
│       ├── memory limit / 内存限制
│       ├── OOM killer / OOM 杀手
│       ├── PSI / 压力停顿信息
│       └── blkio throttling / 块 I/O 限速
├── O12. Observability / Debugging / Performance / 可观测性 / 调试 / 性能
│   ├── Tools / 工具
│   │   ├── strace / ltrace / 系统调用跟踪 / 库调用跟踪
│   │   ├── gdb / 调试器
│   │   ├── perf / 性能工具
│   │   ├── ps / top / htop / 进程查看 / 进程监控 / 交互式进程监控
│   │   ├── vmstat / iostat / pidstat / 虚拟内存统计 / I/O 统计 / 进程统计
│   │   ├── ss / tcpdump / socket 状态查看 / 抓包工具
│   │   ├── procfs / proc 文件系统
│   │   └── sysfs / sys 虚拟文件系统
│   ├── Kernel debugging / 内核调试
│   │   ├── printk / 内核打印
│   │   ├── panic / oops / 内核恐慌 / 内核 oops
│   │   ├── stack trace / 调用栈跟踪
│   │   ├── ftrace / 函数跟踪
│   │   ├── kprobes / uprobes / 内核探针 / 用户态探针
│   │   └── eBPF / 扩展 Berkeley Packet Filter
│   ├── Performance method / 性能分析方法
│   │   ├── CPU-bound vs IO-bound / CPU 受限 vs I/O 受限
│   │   ├── latency vs throughput / 延迟 vs 吞吐量
│   │   ├── flame graph / 火焰图
│   │   ├── off-CPU analysis / 非 CPU 时间分析
│   │   ├── lock contention / 锁竞争
│   │   ├── page fault analysis / 缺页分析
│   │   ├── syscall overhead / 系统调用开销
│   │   └── tail latency / 尾延迟
│   └── OS bug types / OS bug 类型
│       ├── race / deadlock / race / 死锁
│       ├── memory leak / UAF / 内存泄漏 / 释放后使用
│       ├── fd leak / 文件描述符泄漏
│       ├── stuck process / 卡住的进程
│       ├── high syscall rate / 高系统调用频率
│       ├── IO wait / I/O 等待
│       └── packet loss / 丢包
└── O13. Reliability / Production Behavior / 可靠性 / 生产行为
    ├── Crash consistency / 崩溃一致性
    │   ├── write ordering / 写入顺序
    │   ├── journaling / 日志记录
    │   ├── WAL / 预写日志
    │   ├── atomic commit / 原子提交
    │   ├── replay / 重放
    │   └── fsync discipline / fsync 规范
    ├── Fault containment / 故障隔离
    │   ├── process isolation / 进程隔离
    │   ├── supervisor / restart / 监督进程 / 重启
    │   ├── watchdog / 看门狗
    │   ├── health check / 健康检查
    │   └── resource limits / 资源限制
    ├── Resource exhaustion / 资源耗尽
    │   ├── memory pressure / 内存压力
    │   ├── OOM killer / OOM 杀手
    │   ├── fd exhaustion / 文件描述符耗尽
    │   ├── process limit / 进程数限制
    │   ├── disk full / 磁盘满
    │   ├── inode exhaustion / inode 耗尽
    │   └── port exhaustion / 端口耗尽
    └── Service lifecycle / 服务生命周期
        ├── boot process / 启动过程
        ├── init / systemd / 初始化进程 / systemd
        ├── logs / 日志
        ├── crash loop / 崩溃循环
        └── graceful shutdown / 优雅关闭
```

### OS Practice Spine

```text
Phase A. Unix Process Lab / Unix 进程实验
├── mini shell / 迷你 shell
├── pipeline / redirection / job control / 流水线 / redirection / job control
└── strace report / 系统调用跟踪报告

Phase B. xv6 Kernel Lab / xv6 内核实验
├── syscall tracing / 系统调用跟踪
├── scheduler modification / 调度器修改
├── lazy allocation / 惰性分配
├── COW fork / 写时复制 fork
└── filesystem extension / 文件系统扩展

Phase C. Memory + Concurrency Runtime / 内存 + 并发运行时
├── toy malloc / 玩具 malloc 分配器
├── coroutine / thread scheduler / 协程 / thread scheduler
├── mutex / condvar / futex simulator / 互斥锁 / condvar / futex simulator
└── race / deadlock tests / 竞态 / 死锁测试

Phase D. Filesystem + Crash Lab / 文件系统 + 崩溃实验
├── toy block device / 玩具块设备
├── inode filesystem / inode 文件系统
├── journal / recovery simulator / 日志 / 恢复模拟器
└── crash-safe file update / 崩溃安全文件更新

Phase E. Linux Observability Lab / Linux 可观测性实验
├── profile CPU-bound program / 剖析 CPU 受限程序
├── debug fd leak / 调试文件描述符泄漏
├── debug memory pressure / 调试内存压力
├── trace syscall latency / 跟踪系统调用延迟
└── observe network packet path / 观察网络包路径

Phase F. Container Lab / 容器实验
├── namespaces / 命名空间
├── cgroups / cgroups / 控制组 / 控制组
├── rootfs / 根文件系统
├── seccomp / 系统调用过滤机制
└── veth networking / veth 虚拟网卡网络
```

### OS Exit Criteria

- 能区分 syscall、trap、interrupt、context switch、page fault。
- 能解释进程、线程、文件、socket、虚拟内存的生命周期。
- 能在 xv6 中添加 syscall、改 scheduler、实现 lazy/COW memory。
- 能实现 toy shell、toy malloc、toy scheduler、toy filesystem、mini container。
- 能用 Linux 工具定位 CPU、memory、IO、network、lock 问题。

## 3. Computer Architecture / 计算机体系结构

体系结构是“代码如何在机器上真实运行”的地图。它把算法的复杂度、OS 的抽象、编译器的后端全部拉回到寄存器、指令、cache、TLB、流水线和 I/O。

```text
Computer Architecture / 计算机体系结构
├── R0. Layer 0 Prerequisites / Layer 0 前置基础
│   ├── Binary / hex / two's complement / 二进制 / 十六进制 / 补码
│   ├── bit operations / 位运算
│   ├── Boolean algebra / 布尔代数
│   ├── state machine / 状态机
│   ├── C pointer / array / struct / layout / C 指针 / 数组 / 结构体 / 布局
│   ├── Python simulator / Python 模拟器
│   └── API / ABI / ISA / microarchitecture distinction / API / ABI / ISA / 微架构区别
├── R1. Digital Logic / 数字逻辑
│   ├── Boolean algebra / 布尔代数
│   │   ├── AND / OR / NOT / XOR / NAND / NOR / 与 / 或 / 非 / 异或 / 与非 / 或非
│   │   ├── truth table / 真值表
│   │   └── De Morgan / 德摩根律
│   ├── Combinational logic / 组合逻辑
│   │   ├── logic gates / 逻辑门
│   │   ├── MUX / 多路选择器
│   │   ├── decoder / encoder / 解码器 / 编码器
│   │   ├── adder / 加法器
│   │   ├── comparator / 比较器
│   │   └── shifter / 移位器
│   ├── Sequential logic / 时序逻辑
│   │   ├── latch / 锁存器
│   │   ├── flip-flop / 触发器
│   │   ├── clock / 时钟
│   │   ├── register / 寄存器
│   │   ├── counter / 计数器
│   │   └── FSM / 有限状态机
│   ├── HDL boundary / 硬件描述语言边界
│   │   ├── Verilog / VHDL idea / Verilog / VHDL 基本概念
│   │   ├── simulation vs synthesis / 仿真 vs 综合
│   │   └── wire / reg / always / assign / Verilog 常用构造
│   └── Pitfalls / 常见坑
│       ├── combinational loop / 组合环
│       ├── latch inference / 锁存器推断
│       ├── setup / hold / 建立时间 / 保持时间
│       └── critical path / 关键路径
├── R2. Data Representation / 数据表示
│   ├── Integer / 整数表示
│   │   ├── unsigned / signed / 无符号整数 / 有符号整数
│   │   ├── two's complement / 补码
│   │   ├── overflow / 溢出
│   │   ├── sign / zero extension / sign / 零扩展
│   │   └── endianness / 字节序
│   ├── Floating point / 浮点数
│   │   ├── IEEE 754 / 浮点数标准
│   │   ├── sign / exponent / fraction / 符号位 / 指数 / 尾数
│   │   ├── normalized / denormalized / 规格化数 / 非规格化数
│   │   ├── NaN / Infinity / 非数 / 无穷大
│   │   ├── rounding / 舍入
│   │   └── non-associativity / 不可结合性
│   ├── Character / encoding / 字符 / 编码
│   │   ├── ASCII / ASCII / ASCII 编码 / ASCII 编码
│   │   ├── UTF-8 / UTF-8 / UTF-8 编码 / UTF-8 编码
│   │   └── code point vs bytes / 码点与字节对比
│   ├── Data layout / 数据布局
│   │   ├── alignment / 对齐
│   │   ├── padding / 填充
│   │   ├── struct layout / 结构体布局
│   │   ├── AoS vs SoA / 数组套结构体 vs 结构体拆数组
│   │   └── pointer / address / object representation / pointer / address / 对象表示
│   └── Bit-level techniques / 位级技巧
│       ├── mask / shift / 掩码 / 移位
│       ├── packing / unpacking / 打包 / 解包
│       ├── bitmap / 位图
│       ├── popcount / 位计数
│       └── clz / ctz / 前导零计数 / 尾随零计数
├── R3. ISA / Assembly / 指令集架构 / 汇编
│   ├── ISA role / ISA 角色
│   │   ├── software-hardware contract / 软硬件契约
│   │   ├── instruction / register / memory model / 指令 / 寄存器 / 内存模型
│   │   ├── exception / privilege level / 异常 / 权限级别
│   │   └── ISA vs microarchitecture / 指令集架构 vs 微架构
│   ├── Representative ISA / 代表性 ISA
│   │   ├── x86-64 / x86-64 指令集
│   │   ├── ARM / AArch64 / ARM 架构 / 64 位 ARM 指令集
│   │   └── RISC-V / 开放 RISC 指令集
│   ├── Instructions / 指令
│   │   ├── arithmetic / 算术指令
│   │   ├── logical / 逻辑指令
│   │   ├── shift / 移位
│   │   ├── load / store / 加载 / 存储
│   │   ├── branch / jump / call / return / 分支 / 跳转 / 调用 / 返回
│   │   ├── compare / test / 比较 / 测试
│   │   ├── atomic / 原子指令
│   │   └── SIMD / vector / SIMD / 向量
│   ├── Registers / calling convention / 寄存器 / 调用约定
│   │   ├── GPR / 通用寄存器
│   │   ├── stack pointer / 栈指针
│   │   ├── frame pointer / 帧指针
│   │   ├── program counter / 程序计数器
│   │   ├── caller-saved / callee-saved / 调用者保存 / 被调用者保存
│   │   ├── argument passing / 参数传递
│   │   └── prologue / epilogue / 函数序言 / 函数尾声
│   └── Reading assembly / 阅读汇编
│       ├── C to assembly / C 到汇编
│       ├── disassembly / 反汇编
│       ├── objdump / 目标文件反汇编工具
│       ├── gdb / lldb / 调试器 / LLDB 调试器
│       └── symbol / label / relocation / 符号 / 标签 / 重定位
├── R4. Datapath / Control / 数据通路 / 控制
│   ├── CPU components / CPU 组件
│   │   ├── PC / 程序计数器
│   │   ├── instruction memory / 指令存储器
│   │   ├── register file / 寄存器堆
│   │   ├── ALU / 算术逻辑单元
│   │   ├── data memory / 数据存储器
│   │   ├── control unit / 控制单元
│   │   └── branch unit / 分支单元
│   ├── Datapath stages / 数据通路阶段
│   │   ├── fetch / 取指
│   │   ├── decode / 译码
│   │   ├── execute / 执行
│   │   ├── memory / 访存
│   │   └── writeback / 写回
│   ├── Control / 控制
│   │   ├── hardwired control / 硬布线控制
│   │   ├── microcoded control / 微码控制
│   │   ├── control signals / 控制信号
│   │   └── ALU / branch control / 算术逻辑单元 / 分支控制
│   ├── Single-cycle CPU / 单周期 CPU
│   │   ├── one long cycle / 一个长周期
│   │   └── critical path bottleneck / 关键路径瓶颈
│   └── Multi-cycle CPU / 多周期 CPU
│       ├── instruction split into stages / 指令拆分为阶段
│       ├── FSM control / FSM 控制
│       └── hardware reuse / 硬件复用
├── R5. Pipelining / Hazards / 流水线 / 冒险
│   ├── Pipeline idea / 流水线思想
│   │   ├── ILP / 指令级并行
│   │   ├── IF / ID / EX / MEM / WB / 取指阶段 / 译码阶段 / 执行阶段 / 访存阶段 / 写回阶段
│   │   ├── latency vs throughput / 延迟 vs 吞吐量
│   │   └── pipeline register / 流水线寄存器
│   ├── Hazards / 冒险
│   │   ├── structural / 结构冒险
│   │   ├── data: RAW / WAR / WAW / 数据冒险：写后读 / 读后写 / 写后写
│   │   └── control: branch / jump / exception / 控制冒险：分支 / 跳转 / 异常
│   ├── Data hazard solutions / 数据冒险解决方案
│   │   ├── stalling / bubble / 停顿 / 气泡
│   │   ├── forwarding / bypassing / 转发
│   │   ├── hazard detection / 冒险检测
│   │   └── load-use hazard / 加载使用冒险
│   ├── Control hazard solutions / 控制冒险解决方案
│   │   ├── static branch prediction / 静态分支预测
│   │   ├── dynamic branch prediction / 动态分支预测
│   │   ├── BTB / 分支目标缓冲
│   │   ├── RAS / 返回地址栈
│   │   └── speculative execution / 推测执行
│   ├── Exceptions / 异常
│   │   ├── precise exception / 精确异常
│   │   └── pipeline flush / 流水线冲刷
│   └── Advanced ILP / 高级指令级并行
│       ├── superscalar / 超标量
│       ├── out-of-order execution / 乱序执行
│       ├── register renaming / 寄存器重命名
│       ├── ROB / 重排序缓冲
│       ├── reservation station / 保留站
│       └── scoreboarding / 记分牌
├── R6. Memory Hierarchy / Cache / 存储层次 / 缓存
│   ├── Hierarchy / 层次结构
│   │   ├── register / 寄存器
│   │   ├── L1 / L2 / L3 / 一级缓存 / 二级缓存 / 三级缓存
│   │   ├── DRAM / 动态随机访问内存
│   │   ├── SSD / HDD / 固态硬盘 / 机械硬盘
│   │   └── remote storage / 远程存储
│   ├── Locality / 局部性
│   │   ├── temporal / 时间局部性
│   │   ├── spatial / 空间局部性
│   │   ├── working set / 工作集
│   │   └── stride access / 步长访问
│   ├── Cache basics / 缓存基础
│   │   ├── cache line / 缓存行
│   │   ├── tag / index / offset / 标签 / 索引 / 偏移
│   │   ├── direct-mapped / 直接映射
│   │   ├── set-associative / 组相联
│   │   ├── fully-associative / 全相联
│   │   ├── replacement policy / 替换策略
│   │   └── write policy / 写策略
│   ├── Cache performance / 缓存性能
│   │   ├── hit / miss / 命中 / 缺失
│   │   ├── compulsory / capacity / conflict miss / 强制缺失 / 容量缺失 / 冲突缺失
│   │   ├── AMAT / 平均内存访问时间
│   │   ├── pollution / 污染
│   │   └── prefetching / 预取
│   ├── Multi-level cache / 多级缓存
│   │   ├── inclusive / exclusive / non-inclusive / 包含式 / 排他式 / non-inclusive
│   │   ├── victim cache / 受害者缓存
│   │   └── TLB interaction / 与 TLB 的交互
│   └── Cache-friendly programming / 缓存友好编程
│       ├── blocking / tiling / 分块 / 平铺
│       ├── loop interchange / 循环交换
│       ├── AoS vs SoA / 数组套结构体 vs 结构体拆数组
│       └── false sharing / 伪共享
├── R7. Virtual Memory Boundary / 虚拟内存边界
│   ├── Address translation / 地址翻译
│   │   ├── virtual address / 虚拟地址
│   │   ├── physical address / 物理地址
│   │   ├── isolation / 隔离
│   │   └── protection / 保护
│   ├── Paging / 分页
│   │   ├── page / page frame / 页 / 页框
│   │   ├── page table / 页表
│   │   ├── multi-level page table / 多级页表
│   │   └── PTE flags / 页表项标志
│   ├── TLB / 地址翻译缓存
│   │   ├── TLB hit / miss / TLB 命中 / 缺失
│   │   ├── TLB shootdown / TLB 击落
│   │   └── huge page / 大页
│   ├── Faults / 故障 / 缺页
│   │   ├── page fault / 缺页
│   │   ├── demand paging / 按需分页
│   │   ├── COW / 写时复制
│   │   └── mmap / 内存映射
│   └── Cache + VM / 缓存 + 虚拟内存
│       ├── physically indexed / 物理索引
│       ├── virtually indexed / 虚拟索引
│       ├── synonyms / aliasing / 同义地址 / 别名问题
│       └── TLB reach / TLB 覆盖范围
├── R8. Performance Modeling / 性能建模
│   ├── Metrics / 指标
│   │   ├── latency / 延迟
│   │   ├── throughput / 吞吐量
│   │   ├── CPI / IPC / 每指令周期数 / 每周期指令数
│   │   ├── clock rate / 时钟频率
│   │   ├── instruction count / 指令数
│   │   └── utilization / 利用率
│   ├── Formulas / 公式
│   │   ├── CPU time = instruction count * CPI * cycle time / CPU 时间 = 指令数 * 每指令周期数 * 周期时间
│   │   ├── AMAT = hit time + miss rate * miss penalty / 平均访问时间 = 命中时间 + 缺失率 * 缺失代价
│   │   ├── Amdahl's Law / Amdahl 定律
│   │   └── Little's Law intuition / Little 定律直觉
│   ├── Benchmark / profiling / 基准测试 / 性能剖析
│   │   ├── microbenchmark / macrobenchmark / 微基准测试 / 宏基准测试
│   │   ├── perf / time / flamegraph / 性能工具 / time 工具 / 火焰图
│   │   ├── hardware counters / 硬件计数器
│   │   └── warmup / noise / dead-code elimination pitfalls / 预热 / 噪声 / 死代码消除陷阱
│   └── Roofline model / 屋顶线模型
│       ├── arithmetic intensity / 算术强度
│       ├── memory bandwidth bound / 内存带宽受限
│       └── compute bound / 计算受限
├── R9. Parallelism / 并行性
│   ├── Levels / 并行层次
│   │   ├── bit-level / 位级并行
│   │   ├── instruction-level / 指令级并行
│   │   ├── data-level / 数据级并行
│   │   ├── thread-level / 线程级并行
│   │   └── task-level / 任务级并行
│   ├── SIMD / vector / SIMD / 向量
│   │   ├── SSE / AVX / NEON / RISC-V Vector / SSE / AVX / NEON / RISC-V 向量扩展
│   │   ├── lane / 通道
│   │   ├── gather / scatter / 聚集加载 / 分散存储
│   │   └── mask / predicate / 掩码 / 谓词掩码
│   ├── Multicore / 多核
│   │   ├── core / hardware thread / 核心 / 硬件线程
│   │   ├── SMT / 同步多线程
│   │   ├── shared cache / 共享缓存
│   │   ├── MESI intuition / MESI 直觉
│   │   ├── memory consistency / 内存一致性
│   │   └── atomic / fence / lock / 原子指令 / 屏障 / lock
│   ├── NUMA / 非统一内存访问
│   │   ├── local / remote memory / 本地 / 远程内存
│   │   ├── memory affinity / 内存亲和性
│   │   └── false sharing / 伪共享
│   └── GPU / 图形处理器
│       ├── SIMT / 单指令多线程
│       ├── warp / wavefront / 线程束 / 波前
│       ├── thread block / 线程块
│       ├── shared / global memory / shared / 全局内存
│       ├── coalesced access / 合并访问
│       └── divergence / 分支发散
├── R10. Storage / I/O Boundary / 存储 / I/O 边界
│   ├── I/O path / I/O 路径
│   │   ├── CPU / 中央处理器
│   │   ├── memory / 访存
│   │   ├── PCIe / PCIe 总线
│   │   ├── controller / 控制器
│   │   ├── SSD / NVMe / 固态硬盘 / NVMe
│   │   └── NIC / 网卡
│   ├── MMIO / 内存映射 I/O
│   │   ├── device register / 设备寄存器
│   │   └── polling / 轮询
│   ├── Interrupt / DMA / 中断 / DMA
│   │   ├── interrupt controller / 中断控制器
│   │   ├── DMA / 直接内存访问
│   │   ├── descriptor ring / 描述符环
│   │   └── completion queue / 完成队列
│   ├── Storage / 存储
│   │   ├── HDD vs SSD / 机械硬盘 vs 固态硬盘
│   │   ├── block device / 块设备
│   │   ├── sector / page / erase block / 扇区 / 页 / 擦除块
│   │   ├── write amplification / 写放大
│   │   └── queue depth / 队列深度
│   └── I/O performance / I/O 性能
│       ├── sequential vs random / 顺序访问 vs 随机访问
│       ├── batching / 批处理
│       ├── async I/O / 异步 I/O
│       ├── zero-copy / 零拷贝
│       └── page cache boundary / 页缓存边界
└── R11. Security / Microarchitecture / 安全 / 微架构
    ├── Privilege / isolation / 权限 / 隔离
    │   ├── user mode / kernel mode / 用户态 / 内核态
    │   ├── memory protection / 内存保护
    │   ├── NX bit / 不可执行位
    │   ├── ASLR / 地址空间布局随机化
    │   └── W^X / 写和执行互斥
    ├── Microarchitectural state / 微架构状态
    │   ├── cache state / 缓存状态
    │   ├── branch predictor state / 分支预测器状态
    │   ├── TLB state / TLB 状态
    │   ├── speculative state / 推测状态
    │   └── timing side channel / 时间侧信道
    ├── Attacks / 攻击
    │   ├── buffer overflow background / 缓冲区溢出背景
    │   ├── ROP / 返回导向编程
    │   ├── cache timing / 缓存计时攻击
    │   ├── Spectre / Spectre / Spectre 攻击 / Spectre 攻击
    │   ├── Meltdown / Meltdown / Meltdown 攻击 / Meltdown 攻击
    │   └── Rowhammer / Rowhammer 攻击
    └── Defenses / 防御
        ├── constant-time programming / 常数时间编程
        ├── speculation barrier / 推测屏障
        ├── cache partitioning / 缓存分区
        ├── KPTI / 内核页表隔离
        └── memory tagging entrance / 内存标签入口
```

### Architecture Practice Spine

```text
Project A. Assembly Tracer / 汇编跟踪器
├── compile C to assembly / 将 C 编译成汇编
├── trace registers / stack frame / trace registers / 栈帧
└── explain loop / call / array access / explain loop / 调用 / array access

Project B. Tiny CPU Simulator / 迷你 CPU 模拟器
├── RISC-V-like subset / 类 RISC-V 子集
├── interpreter / 解释器
├── single-cycle datapath visualization / 单周期数据通路可视化
└── five-stage pipeline + hazards / 五级流水线 + 冒险

Project C. Cache + TLB Simulator / 缓存 + TLB 模拟器
├── memory trace input / 内存访问轨迹输入
├── cache size / line size / associativity / cache size / line size / 结合性
├── replacement policy / 替换策略
├── TLB entries / page size / TLB 项数 / 页大小
└── miss rate / AMAT / heatmap / miss rate / 平均内存访问时间 / heatmap

Project D. Performance Lab / 性能实验室
├── matrix multiplication / 矩阵乘法
├── array vs linked list / 数组 vs 链表
├── branch prediction / 分支预测
├── SIMD dot product / SIMD 点积
└── perf counters report / perf 计数器报告

Project E. Parallelism Mini Lab / 并行性小实验
├── single-thread / 单线程
├── SIMD / 单指令多数据
├── multithread / 多线程
├── GPU / 图形处理器
└── false sharing / memory bandwidth / 伪共享 / memory bandwidth
```

### Architecture Exit Criteria

- 能从 C 代码一路解释到 assembly、register、memory access、cache behavior。
- 能手画一个简单 CPU datapath，并说明 control signals。
- 能模拟五级流水线并处理基本 data/control hazards。
- 能写 cache/TLB simulator，用它解释真实程序性能差异。
- 能用 perf/hardware counters 验证一个性能假设。
- 能判断瓶颈更可能来自计算、内存、分支、I/O 还是同步。

## 4. Compilers / 编译器

编译器是“让机器理解语言”的系统。它把字符串变成结构，把结构变成语义，把语义变成 IR、字节码、机器码或解释执行。

```text
Compilers / 编译器
├── C0. Layer 0 Prerequisites / Layer 0 前置基础
│   ├── Discrete math / 离散数学
│   │   ├── set / relation / function / 集合 / 关系 / 函数
│   │   ├── recursion / 递归
│   │   ├── structural induction / 结构归纳法
│   │   ├── graph / tree / DAG / 图 / 树 / 有向无环图
│   │   ├── finite automata / 有限自动机
│   │   └── CFG intuition / 上下文无关文法直觉
│   ├── Programming basics / 编程基础
│   │   ├── C/C++/Rust memory model / C/C++/Rust 内存模型
│   │   ├── Python/JS object / closure / interpreter intuition / Python/JS object / 闭包 / interpreter intuition
│   │   ├── array / stack / queue / hash table / tree / graph / 数组 / 栈 / 队列 / 哈希表 / 树 / 图
│   │   └── tokenizer / recursive descent parser toy / 词法切分器 / 递归下降解析器玩具实现
│   └── System basics / 系统基础
│       ├── algorithms: DFS / graph / hash / topo sort / 算法：深度优先搜索 / 图 / hash / topo sort
│       ├── OS: process / VM / syscall / file / dynamic linking / 操作系统：进程 / 虚拟机 / 系统调用 / 文件 / 动态链接
│       └── architecture: ISA / register / ABI / assembly / architecture：指令集架构 / 寄存器 / 应用二进制接口 / 汇编
├── C1. Compiler Overview / 编译器总览
│   ├── Pipeline / 流水线 / 编译流程
│   │   ├── source / 源代码
│   │   ├── tokens / 词法单元
│   │   ├── parse tree / 语法树
│   │   ├── AST / 抽象语法树
│   │   ├── semantic model / 语义模型
│   │   ├── IR / 中间表示
│   │   ├── optimized IR / 优化后的 IR
│   │   └── machine code / bytecode / 机器码 / 字节码
│   ├── Implementation forms / 实现形态
│   │   ├── tree-walking interpreter / 树遍历解释器
│   │   ├── bytecode VM / 字节码虚拟机
│   │   ├── native compiler / 原生编译器
│   │   ├── transpiler / 转译器
│   │   └── JIT / 即时编译
│   └── Toolchain concepts / 工具链概念
│       ├── compiler / 编译器
│       ├── interpreter / 解释器
│       ├── assembler / 汇编器
│       ├── linker / 链接器
│       ├── AOT / 提前编译
│       ├── REPL / 交互式解释循环
│       └── incremental compilation / 增量编译
├── C2. Language Design / 语言设计
│   ├── Semantics / 语义
│   │   ├── expression / statement / declaration / 表达式 / 语句 / 声明
│   │   ├── value / object / 值 / 对象
│   │   ├── variable binding / 变量绑定
│   │   ├── scope / 作用域
│   │   ├── lifetime / 生命周期
│   │   ├── static / dynamic typing / 静态类型 / 动态类型
│   │   ├── value / reference semantics / 值 / 引用语义
│   │   └── ownership entrance / 所有权入口
│   ├── Control flow / 控制流
│   │   ├── if / while / for / 条件分支 / while 循环 / for 循环
│   │   ├── break / continue / return / break / continue / 返回
│   │   ├── function / recursion / 函数 / 递归
│   │   ├── closure / 闭包
│   │   ├── exception / 异常
│   │   └── coroutine / 协程
│   └── Types / abstraction / 类型 / 抽象
│       ├── primitive / 原始类型
│       ├── struct / record / struct / 记录类型
│       ├── enum / sum type / 枚举 / 和类型
│       ├── array / tuple / 数组 / 元组
│       ├── generic / template / 泛型 / 模板
│       ├── trait / interface / typeclass / trait / 接口 / 类型类
│       └── polymorphism / 多态
├── C3. Lexing / Scanning / 词法分析 / 扫描
│   ├── Basics / 基础
│   │   ├── token / token / 词法单元 / 词法单元
│   │   ├── lexeme / 词素
│   │   ├── literal / 字面量
│   │   ├── keyword / 关键字
│   │   ├── identifier / 标识符
│   │   ├── whitespace / comment / 空白符 / 注释
│   │   └── source span / 源码位置
│   ├── Theory / implementation / 理论 / 实现
│   │   ├── regex / 正则表达式
│   │   ├── NFA / 非确定有限自动机
│   │   ├── DFA / 确定有限自动机
│   │   ├── hand-written scanner / 手写扫描器
│   │   ├── flex / lex / flex 生成器 / lex 生成器
│   │   ├── Unicode / 统一字符编码
│   │   ├── escape sequence / 转义序列
│   │   └── numeric literal / 数字字面量
│   └── Errors / 错误
│       ├── illegal character / 非法字符
│       ├── unterminated string / 未闭合字符串
│       ├── invalid escape / 非法转义
│       ├── panic mode / 恐慌模式
│       └── precise location / 精确位置
├── C4. Parsing / 语法分析
│   ├── Grammar / 文法
│   │   ├── CFG / 上下文无关文法
│   │   ├── terminal / non-terminal / 终结符 / 非终结符
│   │   ├── production / 产生式
│   │   ├── ambiguity / 歧义
│   │   ├── precedence / 优先级
│   │   ├── associativity / 结合性
│   │   ├── left recursion / 左递归
│   │   └── FIRST / FOLLOW / FIRST 集 / FOLLOW 集
│   ├── Techniques / 技术
│   │   ├── recursive descent / 递归下降
│   │   ├── Pratt parser / Pratt 解析器
│   │   ├── precedence climbing / 优先级爬升
│   │   ├── LL(k) / k 符号向前看的 LL 解析
│   │   ├── LR / SLR / LALR / LR 解析 / SLR / LALR
│   │   ├── GLR / 广义 LR 解析
│   │   ├── Earley / Earley 解析算法
│   │   └── parser generator / 解析器生成器
│   └── Error recovery / 错误恢复
│       ├── synchronize token / 同步 token
│       ├── expected set / 期望集合
│       ├── token insertion / deletion suggestion / 插入 token / 删除建议
│       └── incremental / partial parse / 增量 / 部分解析
├── C5. AST / Frontend Representation / AST / 前端表示
│   ├── AST design / AST 设计
│   │   ├── Expr / Stmt / Decl / 表达式 / 语句 / 声明
│   │   ├── source span / 源码位置
│   │   ├── node id / 节点 ID
│   │   ├── parent pointer / 父指针
│   │   ├── symbol reference / 符号引用
│   │   ├── CST vs AST / 具体语法树 vs 抽象语法树
│   │   ├── visitor pattern / 访问者模式
│   │   └── arena allocation / arena 分配
│   └── Lowering / normalization / 降级 / 规范化
│       ├── desugaring / 脱糖
│       ├── for to while / for 转 while
│       ├── compound assignment to assignment / 复合赋值转普通赋值
│       ├── name resolution / 名字解析
│       └── typed AST / 带类型 AST
├── C6. Semantic Analysis / 语义分析
│   ├── Names / scopes / 名字 / 作用域
│   │   ├── symbol table / 符号表
│   │   ├── scope stack / 作用域栈
│   │   ├── shadowing / 遮蔽
│   │   ├── hoisting / 提升
│   │   ├── module scope / 模块作用域
│   │   ├── namespace / 命名空间
│   │   ├── forward declaration / 前向声明
│   │   └── mutual recursion / 相互递归
│   ├── Control-flow semantics / 控制流语义
│   │   ├── definite assignment / 确定赋值
│   │   ├── unreachable code / 不可达代码
│   │   ├── return path checking / 返回路径检查
│   │   ├── break / continue legality / break / continue 合法性
│   │   └── closure capture analysis / 闭包捕获分析
│   └── Type pre-analysis / 类型前置分析
│       ├── lvalue / rvalue / 左值 / 右值
│       ├── mutability / 可变性
│       ├── constness / 常量性
│       ├── implicit conversion / 隐式转换
│       └── overload resolution / 重载解析
├── C7. Type Systems / 类型系统
│   ├── Basic type checking / 基础类型检查
│   │   ├── type environment / 类型环境
│   │   ├── typing judgment / 类型判断
│   │   ├── constraint / 约束
│   │   ├── checking vs inference / 检查 vs 推断
│   │   ├── nominal vs structural typing / 名义类型 vs 结构类型
│   │   ├── subtyping / 子类型
│   │   └── variance / 型变
│   ├── Advanced topics / 高级主题
│   │   ├── Hindley-Milner / Hindley-Milner 类型系统
│   │   ├── unification / 合一
│   │   ├── let-polymorphism / let 多态
│   │   ├── monomorphization vs type erasure / 单态化 vs 类型擦除
│   │   ├── traits / interfaces / trait / 接口
│   │   └── ownership / borrow checking intuition / 所有权 / 借用检查直觉
│   └── Error experience / 错误体验
│       ├── expected vs actual / 期望类型 vs 实际类型
│       ├── principal type / 主类型
│       ├── blame assignment / 归责
│       └── suggestions / 建议
├── C8. IR / 中间表示
│   ├── IR levels / IR 层次
│   │   ├── HIR / 高级 IR
│   │   ├── MIR / 中级 IR
│   │   ├── LIR / 低级 IR
│   │   ├── three-address code / 三地址码
│   │   ├── stack IR / 栈式 IR
│   │   ├── register IR / 寄存器 IR
│   │   └── SSA / 静态单赋值
│   ├── Control-flow representation / 控制流表示
│   │   ├── basic block / 基本块
│   │   ├── CFG / 上下文无关文法
│   │   ├── dominator / 支配节点
│   │   ├── post-dominator / 后支配
│   │   ├── loop nesting tree / 循环嵌套树
│   │   ├── phi node / phi 节点
│   │   └── critical edge / 关键边
│   └── Dataflow basics / 数据流基础
│       ├── def-use / 定义到使用链
│       ├── use-def / 使用到定义链
│       ├── liveness / 活跃性
│       ├── reaching definitions / 到达定义
│       └── available expressions / 可用表达式
├── C9. Optimization / 优化
│   ├── Local optimization / 局部优化
│   │   ├── constant folding / 常量折叠
│   │   ├── constant propagation / 常量传播
│   │   ├── algebraic simplification / 代数化简
│   │   ├── copy propagation / 复制传播
│   │   ├── DCE / 死代码删除
│   │   └── CSE / 公共子表达式消除
│   ├── Global optimization / 全局优化
│   │   ├── dataflow framework / 数据流框架
│   │   ├── lattice / 格
│   │   ├── transfer function / 转移函数
│   │   ├── fixed point / 不动点
│   │   ├── global value numbering / 全局值编号
│   │   ├── PRE / 部分冗余消除
│   │   ├── inlining / 内联
│   │   ├── escape analysis / 逃逸分析
│   │   └── devirtualization / 去虚拟化
│   ├── Loop optimization / 循环优化
│   │   ├── LICM / 循环不变量外提
│   │   ├── strength reduction / 强度削弱
│   │   ├── induction variable analysis / 归纳变量分析
│   │   ├── unrolling / 循环展开
│   │   └── vectorization / 向量化
│   └── Tradeoffs / 权衡
│       ├── compile time vs runtime / 编译时间 vs 运行时
│       ├── debuggability / 可调试性
│       ├── undefined behavior / 未定义行为
│       └── PGO / 反馈导向优化
├── C10. Code Generation / 代码生成
│   ├── Target machine model / 目标机器模型
│   │   ├── ISA / 指令集架构
│   │   ├── register / 寄存器
│   │   ├── addressing mode / 寻址模式
│   │   ├── stack frame / 栈帧
│   │   ├── calling convention / 调用约定
│   │   └── ABI / 应用二进制接口
│   ├── Backend stages / 后端阶段
│   │   ├── instruction selection / 指令选择
│   │   ├── tree tiling / 树平铺
│   │   ├── register allocation / 寄存器分配
│   │   ├── linear scan / 线性扫描
│   │   ├── graph coloring / 图着色
│   │   ├── instruction scheduling / 指令调度
│   │   └── peephole optimization / 窥孔优化
│   └── Output formats / 输出格式
│       ├── assembly / 汇编
│       ├── object file / 对象文件
│       ├── ELF / Mach-O / COFF / ELF 格式 / Mach-O 格式 / COFF 格式
│       ├── relocation / 重定位
│       ├── symbol / 符号
│       └── dynamic library / 动态库
├── C11. Runtime Systems / 运行时系统
│   ├── Stack / calls / 栈 / 调用
│   │   ├── call stack / 调用栈
│   │   ├── activation record / 活动记录
│   │   ├── stack frame / 栈帧
│   │   ├── recursion / 递归
│   │   ├── tail call / 尾调用
│   │   ├── closure environment / 闭包环境
│   │   └── exception unwinding / 异常展开
│   ├── Object model / 对象模型
│   │   ├── object layout / 对象布局
│   │   ├── vtable / 虚表
│   │   ├── method dispatch / 方法派发
│   │   ├── boxing / unboxing / 装箱 / 拆箱
│   │   ├── tagged union / 标记联合
│   │   ├── NaN-boxing / NaN 装箱
│   │   ├── string interning / 字符串驻留
│   │   └── array layout / 数组布局
│   └── Modules / linking / 模块 / 链接
│       ├── runtime library / 运行时库
│       ├── startup code / 启动代码
│       ├── FFI / 外部函数接口
│       ├── dynamic loading / 动态加载
│       └── reflection metadata / 反射元数据
├── C12. VM / Bytecode / Interpreter / 虚拟机 / 字节码 / 解释器
│   ├── Bytecode design / 字节码设计
│   │   ├── stack VM / 栈式虚拟机
│   │   ├── register VM / 寄存器虚拟机
│   │   ├── opcode / operand / 操作码 / 操作数
│   │   ├── constant pool / 常量池
│   │   └── chunk / function object / 字节码块 / 函数对象
│   ├── VM execution / 虚拟机执行
│   │   ├── operand stack / 操作数栈
│   │   ├── call frame / 调用帧
│   │   ├── global table / 全局表
│   │   ├── bytecode verifier / 字节码验证器
│   │   ├── disassembler / 反汇编器
│   │   ├── REPL / 交互式解释循环
│   │   └── native function binding / 原生函数绑定
│   └── clox route / clox 路线
│       ├── scanner / 扫描器
│       ├── Pratt parser / Pratt 解析器
│       ├── bytecode compiler / 字节码编译器
│       ├── closures / upvalues / 闭包 / 上值
│       ├── classes / methods / 类 / 方法
│       └── GC / 垃圾回收
├── C13. GC / Memory Management / 垃圾回收 / 内存管理
│   ├── Management styles / 内存管理方式
│   │   ├── ownership / 所有权
│   │   ├── reference counting / 引用计数
│   │   └── tracing GC / 跟踪式 GC
│   ├── Allocation / 分配
│   │   ├── bump pointer / 指针碰撞分配
│   │   ├── free list / 空闲链表
│   │   └── arena / arena 分配
│   ├── Tracing GC / 跟踪式 GC
│   │   ├── mark-sweep / 标记清扫
│   │   ├── tri-color abstraction / 三色抽象
│   │   ├── root set / 根集合
│   │   ├── stack / globals / registers / VM frames / 栈 / globals / registers / VM frames
│   │   ├── moving / copying GC / 移动式 GC / 复制式 GC
│   │   └── generational GC / 分代 GC
│   └── Practical issues / 实践问题
│       ├── finalizer / 终结器
│       ├── weak reference / 弱引用
│       ├── write barrier / 写屏障
│       ├── pause time / 暂停时间
│       └── fragmentation / 碎片化
├── C14. JIT / Dynamic Optimization / JIT / 动态优化
│   ├── JIT forms / JIT 形态
│   │   ├── baseline JIT / 基线 JIT
│   │   ├── method JIT / 方法 JIT
│   │   ├── tracing JIT / 跟踪 JIT
│   │   ├── tiered compilation / 分层编译
│   │   ├── OSR / 栈上替换
│   │   └── deoptimization / 去优化
│   ├── Dynamic language optimization / 动态语言优化
│   │   ├── inline cache / 内联缓存
│   │   ├── hidden class / shape / 隐藏类 / 对象形状
│   │   ├── PIC / 多态内联缓存
│   │   ├── speculative optimization / 推测优化
│   │   ├── guard / 守卫
│   │   └── bailout / 退出优化
│   └── System dependency / 系统依赖
│       ├── executable memory / 可执行内存
│       ├── mmap / mprotect / 内存映射 / mprotect
│       ├── machine code encoding / 机器码编码
│       ├── cache / 缓存
│       └── branch prediction / 分支预测
└── C15. Tooling / Diagnostics / Tests / 工具链 / 诊断 / 测试
    ├── Developer experience / 开发者体验
    │   ├── diagnostic span / 诊断范围
    │   ├── label / note / fix-it / 标签 / note / 修复建议
    │   ├── source map / 源码映射
    │   ├── colored output / 彩色输出
    │   ├── formatter / 格式化器
    │   ├── linter / 静态检查器
    │   └── LSP / 语言服务器协议
    ├── Compiler engineering / 编译器工程
    │   ├── incremental compilation / 增量编译
    │   ├── dependency graph / 依赖图
    │   ├── build cache / 构建缓存
    │   ├── golden tests / golden 测试
    │   ├── snapshot tests / 快照测试
    │   ├── fuzzing / 模糊测试
    │   └── differential testing / 差分测试
    └── Debugging support / 调试支持
        ├── AST dump / AST 转储
        ├── IR dump / IR 转储
        ├── bytecode disassembler / 字节码反汇编器
        ├── trace parser / 解析器跟踪
        ├── trace VM / VM 跟踪
        └── trace GC / GC 跟踪
```

### Compilers Practice Spine

```text
Project A. Expression Interpreter / 表达式解释器
├── lexer / 词法分析器
├── Pratt parser / Pratt 解析器
├── AST interpreter / AST 解释器
├── variables / if / while / functions / 变量 / 条件分支 / while 循环 / 函数
└── Fibonacci + scope + error tests / 斐波那契 + 作用域 + 错误测试

Project B. clox-style Bytecode VM / clox 风格字节码虚拟机
├── bytecode compiler / 字节码编译器
├── stack VM / 栈式虚拟机
├── disassembler / 反汇编器
├── local variables / functions / closures / 局部变量 / 函数 / 闭包
├── class / object / 类 / 对象
└── mark-sweep GC / 标记清扫垃圾回收

Project C. nanoc-style C Subset Compiler / nanoc 风格 C 子集编译器
├── C-like syntax / 类 C 语法
├── AST / 抽象语法树
├── type checking / 类型检查
├── IR / 中间表示
├── optimization / 优化
└── x86-64 / RISC-V / ARM64 assembly / x86-64 / RISC-V / ARM64 汇编

Project D. Compiler Analysis Lab / 编译器分析实验室
├── CFG builder / 控制流图构建器
├── dominator tree / 支配树
├── liveness analysis / 活跃变量分析
├── dataflow fixed point / 数据流不动点
└── register allocation toy / 寄存器分配玩具实现

Project E. Optimization Lab / 优化实验室
├── SSA IR / 静态单赋值中间表示
├── DCE / 死代码删除
├── constant propagation / 常量传播
├── LICM / 循环不变量外提
├── register allocation demo / 寄存器分配演示
└── benchmark before / after / 优化前后基准测试
```

### Compilers Exit Criteria

- 能独立讲清 source -> token -> AST -> semantic analysis -> IR -> backend/VM。
- 能实现 lexer、parser、AST、resolver、type checker、IR、一个后端或 VM。
- 能解释闭包、对象、栈帧、GC、调用约定、基本优化。
- 能用 golden tests、snapshot tests、fuzzing、differential testing 验证语言语义。
- 能阅读 `clox`、`nanoc`、Stanford CS143/LLVM Kaleidoscope，并把概念映射到自己的实现。

## Cross-Trunk Map

```text
Algorithms <-> OS / 算法 <-> 操作系统
├── scheduler: priority queue / fair queueing / online algorithms / 调度器：优先队列 / fair queueing / online algorithms
├── memory: LRU / Clock / buddy allocator / slab allocator / 访存：LRU / 时钟 / 伙伴分配器 / slab 分配器
├── filesystem: B-tree / B+ tree / bitmap / hashing / journal ordering / filesystem：B 树 / B+ 树 / 位图 / hashing / journal ordering
├── networking: queue / timer / congestion control / randomized backoff / networking：队列 / timer / 拥塞控制 / randomized backoff
└── concurrency: lock-free queues / deadlock graph / wait-for graph / 并发：无锁队列 / 死锁图 / 等待图

Algorithms <-> Architecture / 算法 <-> 体系结构
├── Big-O is not enough: cache miss / branch miss / memory bandwidth / Big-O is not enough：缺失 / branch miss / memory bandwidth
├── data layout: array / linked list / hash table / B-tree / data layout：数组 / 链表 / 哈希表 / B 树
├── matrix / FFT / graph / sort depend on memory hierarchy / matrix / FFT / 图 / sort depend on memory hierarchy
└── parallel algorithms need SIMD / cache coherence / GPU memory model / parallel algorithms need SIMD / 缓存一致性 / GPU memory model

Algorithms <-> Compilers / 算法 <-> 编译器
├── lexing: regex / NFA / DFA / string matching / 词法分析：正则表达式 / 非确定有限自动机 / 确定有限自动机 / string matching
├── parsing: stack / recursion / LL / LR / chart parsing / 语法分析：栈 / 递归 / LL 解析 / LR 解析 / chart parsing
├── CFG: DFS / dominator tree / SCC / 上下文无关文法：深度优先搜索 / 支配树 / 强连通分量
├── dataflow: fixed point / lattice / worklist / dataflow：不动点 / 格 / worklist
├── register allocation: graph coloring / interval allocation / 寄存器分配：图着色 / interval allocation
└── GC: graph reachability / worklist / 垃圾回收：graph reachability / worklist

OS <-> Architecture / 操作系统 <-> 体系结构
├── process/thread: register state / PC / stack / page table / process/thread：register state / 程序计数器 / 栈 / 页表
├── syscall/trap/interrupt: ISA privilege mode / 系统调用 / 陷入 / 中断：ISA 权限模式
├── virtual memory: MMU / TLB / page fault / 虚拟内存：MMU / TLB / 缺页
├── synchronization: atomic instruction / memory ordering / cache coherence / synchronization：atomic instruction / memory ordering / 缓存一致性
├── I/O: DMA / interrupt / device controller / I/O：直接内存访问 / 中断 / device controller
└── scheduling: timer interrupt / cache affinity / NUMA / scheduling：timer interrupt / 缓存亲和性 / NUMA

OS <-> Compilers / 操作系统 <-> 编译器
├── process startup: loader / runtime / main / process startup：loader / 运行时 / main
├── syscall ABI: calling convention / registers / 系统调用 ABI：调用约定 / registers
├── dynamic linking: PLT / GOT / shared library / 动态链接：PLT / GOT / shared library
├── debugging: symbol table / frame pointer / DWARF / 调试：符号表 / 帧指针 / DWARF
├── sanitizer: compiler instrumentation + OS memory protection / 消毒器：编译器插桩 + OS 内存保护
└── JIT: mmap / mprotect / executable memory / 即时编译：内存映射 / mprotect / 可执行内存

Architecture <-> Compilers / 体系结构 <-> 编译器
├── backend: ISA / registers / instruction selection / backend：指令集架构 / registers / 指令选择
├── register allocation: physical register pressure / 寄存器分配：physical register pressure
├── calling convention: stack frame / ABI / 调用约定：栈帧 / 应用二进制接口
├── instruction scheduling: pipeline / latency / hazards / 指令调度：流水线 / 延迟 / hazards
├── optimization: cache locality / SIMD / vectorization / 优化问题：缓存局部性 / 单指令多数据 / 向量化
└── security: CFI / bounds checks / speculation mitigation / security：控制流完整性 / bounds checks / speculation mitigation
```

## Minimal Learning Order For This Repo

这不是完整本科顺序，而是适合 `CS4LLM` 当前状态的“先能跑、再能解释、最后能实现”的顺序。

```text
0. Layer 0 still comes first
├── Python reading / Python 代码阅读
├── terminal / git / 终结符 / git
├── list / dict / set / stack / queue / tree / graph / list / dict / 集合 / 栈 / 队列 / 树 / 图
├── complexity / invariant / tests / 复杂度 / 不变量 / 测试
└── small practice bridge / 小型实践桥接

1. Algorithms first, but only the practical core
├── complexity / 复杂度
├── recursion / invariant / 递归 / 不变量
├── array / hash / tree / graph / 数组 / hash / 树 / 图
├── BFS / DFS / Dijkstra / 广度优先搜索 / 深度优先搜索 / Dijkstra 算法
├── sorting / binary search / sorting / 二分搜索
└── testing / benchmark / testing / 基准测试

2. Then choose one systems door
├── OS route: syscall / process / memory / OS route：系统调用 / 进程 / 访存
├── Compiler route: lexer / parser / VM / Compiler route：词法分析器 / parser / 虚拟机
└── Architecture route: data representation / assembly / cache / Architecture route：data representation / 汇编 / 缓存

3. Then integrate
├── B+ tree connects Algorithms + DB + OS I/O + Architecture cache / B+ 树连接算法 + 数据库 + OS I/O + 体系结构缓存
├── syscall connects OS + Architecture + ABI / 系统调用连接 OS + 体系结构 + ABI
├── bytecode VM connects Compilers + OS runtime + Architecture stack/cache / 字节码 VM 连接编译器 + OS 运行时 + 体系结构栈和缓存
└── scheduler connects OS + Algorithms + Architecture timing / 调度器连接 OS + 算法 + 体系结构时间成本
```

## Verification Review

| Area | Coverage Check | Hierarchy Check | Remaining Risk |
| --- | --- | --- | --- |
| Algorithms | Covers analysis, structures, paradigms, graphs, strings, randomized, complexity, approximation, engineering | Deep enough and starts from prerequisites | Too broad for first month; must be sliced into practice labs |
| OS | Covers process, trap/syscall, memory, scheduling, concurrency, FS, I/O, networking boundary, security, containers, observability | Good progression from model to production behavior | Linux-specific depth can overwhelm before xv6 basics |
| Architecture | Covers logic, representation, ISA, datapath, pipeline, cache, VM boundary, performance, parallelism, I/O, security | Clean path from bits to performance diagnosis | Hardware details should stay simulator-based first |
| Compilers | Covers language design, lexing, parsing, AST, semantics, types, IR, optimization, codegen, runtime, VM, GC, JIT, tooling | Strong source-to-runtime sequence | Type systems/JIT/LLVM-level details are later, not first pass |

## Known Omissions

- Networks, databases, distributed systems are Layer 2 and intentionally not expanded here.
- ML/AI math, deep learning, LLM systems are Layer 3 and intentionally not mixed into this tree.
- Cryptography, formal verification, theorem proving, LLVM internals, GPU kernel optimization, FPGA/VLSI, Windows/macOS kernel internals are later specialized branches.
- This file is a map, not a schedule. A schedule should be derived only after choosing the next active branch.
