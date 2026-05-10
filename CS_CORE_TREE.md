# Layer 1 Core CS Tree

这份文件展开 `CS / AI 工业研究型本科地图` 的第 1 层。术语中英文对应关系见 [CS_CORE_BILINGUAL_GLOSSARY.md](./CS_CORE_BILINGUAL_GLOSSARY.md)：

```text
1. 四大硬核主干：真正的 CS 骨架
Algorithms / Operating Systems / Computer Architecture / Compilers
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
Layer 1. Core CS Trunk
├── Algorithms
│   ├── Algorithm analysis
│   ├── Data structures
│   ├── Paradigms
│   ├── Sorting / searching / selection
│   ├── Graph algorithms
│   ├── String algorithms
│   ├── Randomized / probabilistic algorithms
│   ├── Complexity / NP
│   ├── Approximation / online / streaming
│   ├── Numeric / geometric / algebraic algorithms
│   ├── Parallel / external-memory / distributed algorithms
│   └── Algorithm engineering
├── Operating Systems
│   ├── OS model
│   ├── Process / thread / execution context
│   ├── Syscall / trap / interrupt
│   ├── Memory / virtual memory
│   ├── Scheduling
│   ├── Synchronization / concurrency
│   ├── Filesystems
│   ├── I/O / devices / drivers
│   ├── Networking at OS boundary
│   ├── Security / isolation
│   ├── Virtualization / containers
│   ├── Observability / debugging / performance
│   └── Reliability / production behavior
├── Computer Architecture
│   ├── Digital logic
│   ├── Data representation
│   ├── ISA / assembly
│   ├── Datapath / control
│   ├── Pipelining / hazards
│   ├── Memory hierarchy / cache
│   ├── Virtual memory boundary
│   ├── Performance modeling
│   ├── SIMD / multicore / GPU
│   ├── Storage / I/O boundary
│   └── Security / microarchitecture
└── Compilers
    ├── Language implementation overview
    ├── Language design
    ├── Lexing
    ├── Parsing
    ├── AST / frontend representation
    ├── Semantic analysis
    ├── Type systems
    ├── IR
    ├── Optimization
    ├── Code generation
    ├── Runtime systems
    ├── VM / bytecode / interpreter
    ├── GC / memory management
    ├── JIT / dynamic optimization
    └── Tooling / diagnostics / tests
```

## 1. Algorithms

算法不是“刷题技巧”，而是把问题变成可计算结构的语言。它给 OS、体系结构、编译器、数据库、分布式系统提供共同的建模方式。

```text
Algorithms
├── A0. Layer 0 Prerequisites
│   ├── Discrete math
│   │   ├── set / relation / function / mapping
│   │   ├── logic / predicate / proof
│   │   ├── induction / strong induction
│   │   ├── invariant
│   │   ├── recurrence
│   │   └── graph / tree / DAG
│   ├── Probability basics
│   │   ├── random variable
│   │   ├── expectation / variance
│   │   ├── conditional probability
│   │   └── Bayes / Markov / Chebyshev / Chernoff intuition
│   ├── Programming basics
│   │   ├── Python for experiment / visualization
│   │   ├── C/C++/Rust for memory and data structure reality
│   │   ├── Java/Go for engineering interfaces
│   │   └── tests / logs / debugging / profiling
│   └── Basic structures
│       ├── array / linked list
│       ├── stack / queue / deque
│       ├── hash table
│       ├── binary tree / heap
│       └── graph representation
├── A1. Algorithm Analysis
│   ├── Computation models
│   │   ├── RAM model
│   │   ├── Word RAM model
│   │   ├── comparison model
│   │   └── pointer machine model
│   ├── Asymptotic complexity
│   │   ├── O / Omega / Theta
│   │   ├── little-o / little-omega
│   │   ├── O(1), O(log n), O(n), O(n log n), O(n^2), O(2^n)
│   │   └── multi-variable complexity: O(V + E), O(n + m)
│   ├── Recurrences
│   │   ├── expansion
│   │   ├── recursion tree
│   │   ├── Master Theorem
│   │   └── common recurrence patterns
│   ├── Correctness
│   │   ├── loop invariant
│   │   ├── recursive invariant
│   │   ├── greedy-choice property
│   │   ├── optimal substructure
│   │   ├── exchange argument
│   │   └── cut property
│   ├── Amortized analysis
│   │   ├── aggregate method
│   │   ├── accounting method
│   │   └── potential method
│   └── Lower bounds
│       ├── comparison sorting lower bound
│       ├── information-theoretic intuition
│       └── reduction-based lower bound
├── A2. Data Structures
│   ├── Linear structures
│   │   ├── array / dynamic array
│   │   ├── linked list / intrusive list
│   │   ├── stack
│   │   ├── queue
│   │   └── deque / monotonic queue
│   ├── Hashing
│   │   ├── hash function
│   │   ├── chaining
│   │   ├── open addressing
│   │   ├── load factor / rehashing
│   │   ├── Bloom filter
│   │   ├── Count-Min Sketch
│   │   └── consistent hashing
│   ├── Trees
│   │   ├── binary tree
│   │   ├── BST
│   │   ├── AVL / Red-Black / Treap / Splay
│   │   ├── B-tree / B+ tree
│   │   ├── segment tree
│   │   ├── Fenwick tree
│   │   ├── interval tree
│   │   ├── order statistic tree
│   │   ├── trie / radix tree / Patricia trie
│   │   └── suffix tree as advanced entrance
│   ├── Heap / priority queue
│   │   ├── binary heap
│   │   ├── d-ary heap
│   │   ├── binomial / Fibonacci / pairing heap
│   │   └── indexed priority queue
│   ├── Disjoint Set Union
│   │   ├── make-set / find / union
│   │   ├── path compression
│   │   └── union by rank / size
│   ├── Persistent structures
│   │   ├── path copying
│   │   ├── structural sharing
│   │   └── immutable map / versioned state
│   └── Cache-friendly structures
│       ├── AoS vs SoA
│       ├── bitset / roaring bitmap
│       ├── compact representation
│       ├── arena allocator
│       └── compressed sparse row
├── A3. Algorithmic Paradigms
│   ├── Brute force / enumeration
│   │   ├── subset enumeration
│   │   ├── permutation enumeration
│   │   ├── pruning
│   │   └── brute force as oracle
│   ├── Divide and conquer
│   │   ├── merge sort
│   │   ├── quicksort / quickselect
│   │   ├── binary search
│   │   ├── closest pair
│   │   ├── Karatsuba
│   │   └── FFT entrance
│   ├── Greedy
│   │   ├── interval scheduling
│   │   ├── Huffman coding
│   │   ├── MST
│   │   ├── Dijkstra condition
│   │   ├── matroid intuition
│   │   └── failed greedy examples
│   ├── Dynamic programming
│   │   ├── memoization / tabulation
│   │   ├── state / transition / base case
│   │   ├── path reconstruction
│   │   ├── LIS / LCS / edit distance
│   │   ├── knapsack
│   │   ├── interval DP / tree DP / bitmask DP
│   │   ├── DP on DAG
│   │   └── optimization: monotonic queue / CHT / divide-and-conquer / Knuth
│   ├── Backtracking / constraint solving
│   │   ├── DFS search tree
│   │   ├── constraint propagation
│   │   ├── exact cover / Dancing Links
│   │   ├── SAT / CSP entrance
│   │   └── branch and bound
│   ├── Reduction / transformation
│   │   ├── problem reduction
│   │   ├── graph modeling
│   │   ├── flow modeling
│   │   ├── shortest path modeling
│   │   ├── SAT / ILP modeling
│   │   └── NP-completeness entrance
│   └── Randomization
│       ├── Las Vegas vs Monte Carlo
│       ├── randomized quicksort / select
│       ├── skip list / treap
│       ├── random sampling
│       └── probabilistic verification
├── A4. Sorting / Selection / Searching
│   ├── Comparison sorting
│   │   ├── insertion / selection / bubble
│   │   ├── merge sort / quicksort / heapsort
│   │   ├── introsort
│   │   └── timsort
│   ├── Non-comparison sorting
│   │   ├── counting sort
│   │   ├── radix sort
│   │   └── bucket sort
│   ├── Sorting properties
│   │   ├── stable vs unstable
│   │   ├── in-place vs out-of-place
│   │   ├── external sorting
│   │   ├── parallel sorting
│   │   └── cache-aware sorting
│   ├── Selection
│   │   ├── min / max
│   │   ├── kth element
│   │   ├── quickselect
│   │   ├── median of medians
│   │   └── top-k / streaming top-k
│   └── Searching
│       ├── linear search
│       ├── binary search
│       ├── binary search on answer
│       ├── exponential / interpolation / ternary search
│       └── parametric search entrance
├── A5. Graph Algorithms
│   ├── Representation
│   │   ├── adjacency matrix
│   │   ├── adjacency list
│   │   ├── edge list
│   │   ├── CSR
│   │   └── implicit / dynamic graph
│   ├── Traversal
│   │   ├── BFS
│   │   ├── DFS
│   │   ├── connected components
│   │   ├── bipartite checking
│   │   ├── topological sort
│   │   └── cycle detection
│   ├── Shortest paths
│   │   ├── BFS
│   │   ├── Dijkstra
│   │   ├── Bellman-Ford
│   │   ├── Floyd-Warshall
│   │   ├── Johnson
│   │   ├── A*
│   │   └── bidirectional search
│   ├── MST
│   │   ├── Kruskal
│   │   ├── Prim
│   │   ├── Boruvka
│   │   ├── cut property
│   │   └── cycle property
│   ├── Connectivity
│   │   ├── Tarjan SCC
│   │   ├── Kosaraju
│   │   ├── articulation points
│   │   ├── bridges
│   │   └── condensation graph
│   ├── Flow / matching
│   │   ├── max flow
│   │   ├── min cut
│   │   ├── Dinic
│   │   ├── push-relabel
│   │   ├── min-cost max-flow
│   │   ├── bipartite matching
│   │   ├── Hopcroft-Karp
│   │   └── Hungarian algorithm
│   └── Advanced graph ideas
│       ├── graph coloring
│       ├── dominator tree
│       ├── dataflow fixed point
│       ├── PageRank / random walk
│       ├── tree decomposition entrance
│       └── dynamic graph entrance
├── A6. String Algorithms
│   ├── String basics
│   │   ├── ASCII / UTF-8 / Unicode
│   │   ├── byte array vs string
│   │   ├── prefix / suffix / substring / subsequence
│   │   └── lexicographic order
│   ├── Pattern matching
│   │   ├── naive matching
│   │   ├── KMP
│   │   ├── Z algorithm
│   │   ├── Rabin-Karp
│   │   ├── Boyer-Moore
│   │   └── Aho-Corasick
│   ├── Suffix structures
│   │   ├── suffix array
│   │   ├── LCP array
│   │   ├── suffix tree
│   │   ├── suffix automaton
│   │   ├── FM-index
│   │   └── Burrows-Wheeler Transform
│   ├── Diff / sequence alignment
│   │   ├── Levenshtein distance
│   │   ├── edit distance DP
│   │   ├── LCS
│   │   └── Myers diff
│   └── Compiler connection
│       ├── regex engine
│       ├── NFA / DFA
│       ├── lexer
│       ├── CYK / Earley
│       └── LL / LR parsing entrance
├── A7. Randomized / Probabilistic Algorithms
│   ├── Randomization basics
│   │   ├── expected runtime
│   │   ├── high-probability bound
│   │   ├── independence
│   │   └── probability amplification
│   ├── Randomized algorithms
│   │   ├── randomized quicksort / select
│   │   ├── skip list / treap
│   │   ├── Miller-Rabin
│   │   ├── randomized min cut
│   │   └── randomized load balancing
│   ├── Sampling / estimation
│   │   ├── reservoir sampling
│   │   ├── Monte Carlo simulation
│   │   ├── HyperLogLog
│   │   ├── MinHash
│   │   └── locality-sensitive hashing
│   └── Probabilistic data structures
│       ├── Bloom filter
│       ├── Counting Bloom filter
│       ├── Cuckoo filter
│       ├── Count-Min Sketch
│       └── quotient filter entrance
├── A8. Complexity / NP
│   ├── Problem types
│   │   ├── decision
│   │   ├── search
│   │   ├── optimization
│   │   └── language recognition
│   ├── Complexity classes
│   │   ├── P / NP / co-NP
│   │   ├── EXP / PSPACE entrance
│   │   ├── RP / BPP
│   │   └── parameterized complexity
│   ├── Reductions
│   │   ├── many-one reduction
│   │   ├── polynomial-time reduction
│   │   └── reduction chain
│   ├── NP-completeness
│   │   ├── SAT / 3-SAT
│   │   ├── CLIQUE / VERTEX-COVER / INDEPENDENT-SET
│   │   ├── HAMILTONIAN-CYCLE
│   │   ├── TSP
│   │   ├── SUBSET-SUM / PARTITION / KNAPSACK
│   │   └── SET-COVER / graph coloring / exact cover
│   └── Engineering response
│       ├── exact exponential
│       ├── branch and bound
│       ├── SAT / SMT / ILP
│       ├── approximation
│       ├── heuristics
│       ├── local search
│       └── parameterized algorithms
├── A9. Approximation / Online / Streaming
│   ├── Approximation
│   │   ├── approximation ratio
│   │   ├── PTAS / FPTAS
│   │   ├── LP relaxation / rounding
│   │   ├── set cover
│   │   ├── vertex cover
│   │   └── knapsack FPTAS
│   ├── Online algorithms
│   │   ├── competitive analysis
│   │   ├── caching / paging
│   │   ├── ski rental
│   │   ├── online scheduling
│   │   └── load balancing
│   ├── Streaming
│   │   ├── one-pass constraints
│   │   ├── sublinear memory
│   │   ├── heavy hitters
│   │   ├── approximate quantiles
│   │   ├── distinct count
│   │   └── sliding window
│   └── System uses
│       ├── telemetry aggregation
│       ├── observability metrics
│       ├── rate limiting
│       ├── abuse detection
│       └── cache admission
├── A10. Numeric / Geometric / Algebraic Algorithms
│   ├── Numeric
│   │   ├── floating point
│   │   ├── numerical stability
│   │   ├── root finding
│   │   ├── Gaussian elimination
│   │   ├── matrix multiplication
│   │   └── sparse matrix
│   ├── Computational geometry
│   │   ├── orientation test
│   │   ├── line segment intersection
│   │   ├── convex hull
│   │   ├── sweep line
│   │   ├── closest pair
│   │   └── kd-tree / quad tree / R-tree
│   └── Algebraic
│       ├── fast exponentiation
│       ├── modular arithmetic
│       ├── Euclidean algorithm
│       ├── primality testing
│       ├── FFT / NTT
│       └── polynomial multiplication
├── A11. Parallel / External-Memory / Distributed Algorithms
│   ├── Parallel
│   │   ├── work / span
│   │   ├── fork-join
│   │   ├── parallel prefix sum
│   │   ├── map-reduce
│   │   └── parallel sort / BFS
│   ├── External memory
│   │   ├── I/O model
│   │   ├── block transfer
│   │   ├── external merge sort
│   │   ├── B-tree
│   │   └── cache-oblivious algorithms
│   ├── Distributed algorithm entrance
│   │   ├── leader election
│   │   ├── consistent hashing
│   │   ├── sharding
│   │   ├── gossip
│   │   └── fault model
│   └── GPU / vector algorithms
│       ├── data parallelism
│       ├── reduction
│       ├── matrix multiplication
│       └── memory coalescing
└── A12. Algorithm Engineering
    ├── From pseudocode to reliable code
    │   ├── edge cases
    │   ├── overflow
    │   ├── deterministic output
    │   ├── memory ownership
    │   └── stable API
    ├── Testing / verification
    │   ├── unit tests
    │   ├── property-based tests
    │   ├── fuzzing
    │   ├── brute-force oracle
    │   ├── differential testing
    │   └── invariant checks
    ├── Performance
    │   ├── benchmark
    │   ├── profiler
    │   ├── constant factor
    │   ├── allocation cost
    │   ├── branch prediction
    │   ├── cache locality
    │   └── vectorization / parallel overhead
    └── AI-assisted workflow
        ├── ask AI for multiple solutions
        ├── ask AI for counterexamples
        ├── generate oracle / random tests
        ├── generate benchmark harness
        └── human must explain sample, failure, invariant, rewrite
```

### Algorithms Practice Spine

```text
Phase A. 可证明的基础算法
├── Big-O / recurrence / correctness
├── sorting / binary search / basic structures
├── BFS / DFS / Dijkstra / MST
└── output: 20 core implementations with tests

Phase B. 范式迁移
├── greedy
├── dynamic programming
├── divide and conquer
├── backtracking
└── reductions

Phase C. 系统可用算法
├── hash table
├── B-tree
├── LRU cache
├── external sort
├── string matching
└── priority scheduler

Phase D. 困难问题与工程策略
├── NP-completeness
├── approximation
├── online
├── randomized
└── streaming

Phase E. 跨主干融合
├── OS scheduler + online algorithms
├── compiler CFG + graph algorithms
├── architecture cache + data layout
└── database/search index + trees/string algorithms
```

### Algorithms Exit Criteria

- 能对常见算法写出正确性证明和复杂度分析。
- 能区分 worst-case、average-case、expected、amortized。
- 能从零实现核心数据结构与算法，并配测试、oracle、benchmark。
- 能把实际问题抽象为图、序列、集合、状态空间、流网络或约束系统。
- 能识别可能 NP-hard 的需求，并提出可运行的工程替代方案。

## 2. Operating Systems

OS 是把裸硬件变成可用抽象的系统：进程、文件、虚拟内存、socket、权限、调度、持久化、隔离。

```text
Operating Systems
├── O0. Layer 0 Prerequisites
│   ├── Systems C
│   │   ├── pointer / array / struct / function pointer
│   │   ├── stack / heap / memory layout
│   │   ├── malloc / free
│   │   ├── undefined behavior
│   │   └── compile / link / object file / library
│   ├── Data structures
│   │   ├── linked list
│   │   ├── queue
│   │   ├── heap
│   │   ├── tree
│   │   ├── hash table
│   │   └── bitmap
│   ├── Architecture
│   │   ├── privilege level
│   │   ├── interrupt
│   │   ├── cache / TLB / MMU
│   │   ├── DMA
│   │   ├── atomic instruction
│   │   └── memory barrier
│   └── Compiler/runtime basics
│       ├── ABI
│       ├── calling convention
│       ├── stack frame
│       ├── ELF / Mach-O
│       ├── loader
│       └── dynamic linking
├── O1. OS Overall Model
│   ├── Core responsibilities
│   │   ├── abstraction: process / file / virtual memory / socket
│   │   ├── multiplexing: CPU / memory / disk / network
│   │   ├── isolation: address space / privilege / capability
│   │   ├── persistence: filesystem / journal / cache
│   │   ├── concurrency: interrupt / thread / lock / scheduler
│   │   └── reliability: crash recovery / observability
│   ├── Kernel architecture
│   │   ├── monolithic kernel
│   │   ├── microkernel
│   │   ├── hybrid kernel
│   │   ├── exokernel / library OS
│   │   ├── unikernel
│   │   └── Linux / xv6 / BSD / seL4 comparison
│   └── Resource lifecycle
│       ├── process
│       ├── page
│       ├── file descriptor
│       ├── inode
│       └── socket
├── O2. Process / Thread / Execution Context
│   ├── Process model
│   │   ├── address space
│   │   ├── file descriptor table
│   │   ├── signal handlers
│   │   ├── credentials
│   │   ├── cwd / environment
│   │   ├── parent-child relationship
│   │   └── zombie / orphan process
│   ├── Process lifecycle
│   │   ├── fork
│   │   ├── exec
│   │   ├── wait
│   │   ├── exit
│   │   ├── clone
│   │   └── copy-on-write fork
│   ├── Threads
│   │   ├── kernel thread vs user thread
│   │   ├── 1:1 / M:N threading
│   │   ├── pthreads
│   │   ├── thread-local storage
│   │   └── stack per thread
│   ├── Context switch
│   │   ├── register save / restore
│   │   ├── kernel stack
│   │   ├── trap frame
│   │   ├── address space switch
│   │   ├── TLB flush / ASID / PCID
│   │   └── lazy FPU state
│   └── Signals
│       ├── signal delivery
│       ├── signal mask
│       ├── async-signal-safe
│       └── signal vs interrupt vs exception
├── O3. Syscall / Trap / Interrupt
│   ├── User mode / kernel mode
│   │   ├── privilege rings
│   │   ├── syscall ABI
│   │   ├── syscall number / arguments
│   │   └── return value / errno
│   ├── Trap types
│   │   ├── syscall
│   │   ├── page fault
│   │   ├── divide-by-zero
│   │   ├── illegal instruction
│   │   ├── breakpoint
│   │   ├── timer interrupt
│   │   └── device interrupt
│   ├── Trap path
│   │   ├── CPU saves minimal state
│   │   ├── switch to kernel stack
│   │   ├── build trap frame
│   │   ├── dispatch handler
│   │   ├── validate user pointer
│   │   ├── copyin / copyout
│   │   └── return to user mode
│   ├── Interrupts
│   │   ├── interrupt controller
│   │   ├── top half / bottom half
│   │   ├── softirq / workqueue
│   │   ├── interrupt latency
│   │   └── preemption boundary
│   └── Security boundary
│       ├── parameter validation
│       ├── TOCTOU
│       ├── seccomp
│       └── capability checks
├── O4. Memory / Virtual Memory
│   ├── Physical memory
│   │   ├── page frame
│   │   ├── free list
│   │   ├── buddy allocator
│   │   ├── slab / slub allocator
│   │   ├── per-CPU cache
│   │   └── NUMA basics
│   ├── Virtual address space
│   │   ├── user/kernel split
│   │   ├── text / data / bss / heap / stack / mmap
│   │   ├── guard page
│   │   ├── ASLR
│   │   └── VMA
│   ├── Page table
│   │   ├── multi-level page table
│   │   ├── PTE flags
│   │   ├── huge pages
│   │   ├── TLB
│   │   ├── page walk
│   │   └── page fault handling
│   ├── Demand paging
│   │   ├── lazy allocation
│   │   ├── zero page
│   │   ├── copy-on-write
│   │   ├── memory-mapped file
│   │   ├── swap
│   │   ├── page replacement
│   │   └── working set / thrashing
│   ├── Kernel memory
│   │   ├── direct mapping
│   │   ├── kernel heap
│   │   ├── vmalloc
│   │   ├── memory pinning
│   │   └── DMA-safe memory
│   └── Memory safety
│       ├── use-after-free
│       ├── double free
│       ├── buffer overflow
│       ├── stack overflow
│       ├── ASAN / KASAN
│       └── guard pages
├── O5. Scheduling
│   ├── Goals
│   │   ├── throughput
│   │   ├── latency
│   │   ├── fairness
│   │   ├── responsiveness
│   │   ├── deadline
│   │   ├── energy efficiency
│   │   └── cache affinity
│   ├── Algorithms
│   │   ├── FCFS
│   │   ├── SJF / SRTF
│   │   ├── Round Robin
│   │   ├── Priority Scheduling
│   │   ├── MLFQ
│   │   ├── Lottery / Stride
│   │   ├── EDF
│   │   └── RMS
│   ├── Linux-style scheduling
│   │   ├── CFS
│   │   ├── virtual runtime
│   │   ├── red-black tree runqueue
│   │   ├── nice value
│   │   ├── scheduler class
│   │   ├── realtime scheduling
│   │   ├── CPU affinity
│   │   └── cgroups CPU controller
│   ├── Multiprocessor scheduling
│   │   ├── per-CPU run queues
│   │   ├── work stealing
│   │   ├── cache locality
│   │   ├── NUMA awareness
│   │   └── preemption
│   └── Priority pathologies
│       ├── starvation
│       ├── priority inversion
│       ├── priority inheritance
│       └── convoy effect
├── O6. Synchronization / Concurrency
│   ├── Problems
│   │   ├── race condition
│   │   ├── critical section
│   │   ├── atomicity / visibility / ordering
│   │   ├── deadlock
│   │   ├── livelock
│   │   └── starvation
│   ├── Atomic / memory model
│   │   ├── CAS
│   │   ├── test-and-set
│   │   ├── fetch-add
│   │   ├── acquire / release
│   │   ├── memory barrier
│   │   └── cache coherence
│   ├── Locks
│   │   ├── spinlock
│   │   ├── mutex
│   │   ├── reader-writer lock
│   │   ├── seqlock
│   │   ├── RCU
│   │   ├── futex
│   │   └── lock-free vs wait-free
│   ├── Condition synchronization
│   │   ├── semaphore
│   │   ├── condition variable
│   │   ├── monitor
│   │   ├── wait queue
│   │   └── completion
│   └── Kernel concurrency
│       ├── interrupt disable
│       ├── preemption disable
│       ├── per-CPU data
│       ├── workqueue
│       ├── reference counting
│       └── lifetime management
├── O7. Filesystems
│   ├── File abstraction
│   │   ├── file descriptor
│   │   ├── open file table
│   │   ├── inode
│   │   ├── dentry
│   │   ├── path lookup
│   │   ├── hard link / symbolic link
│   │   └── sparse file
│   ├── Disk layout
│   │   ├── superblock
│   │   ├── inode table
│   │   ├── data blocks
│   │   ├── bitmap
│   │   ├── extents
│   │   └── indirect blocks
│   ├── File operation path
│   │   ├── open
│   │   ├── read / write
│   │   ├── lseek
│   │   ├── fsync
│   │   ├── rename
│   │   ├── unlink
│   │   ├── page cache
│   │   └── writeback
│   ├── Crash consistency
│   │   ├── journaling
│   │   ├── WAL
│   │   ├── copy-on-write FS
│   │   ├── ordered writes
│   │   └── fsck
│   └── VFS
│       ├── mount namespace
│       ├── procfs / sysfs / tmpfs
│       ├── device files
│       └── FUSE
├── O8. I/O / Devices / Drivers
│   ├── I/O models
│   │   ├── programmed I/O
│   │   ├── interrupt-driven I/O
│   │   ├── DMA
│   │   ├── MMIO
│   │   ├── polling
│   │   ├── blocking / non-blocking
│   │   └── async I/O
│   ├── Driver model
│   │   ├── device discovery
│   │   ├── probe / remove
│   │   ├── character device
│   │   ├── block device
│   │   ├── network device
│   │   ├── ioctl
│   │   └── sysfs
│   ├── Block I/O
│   │   ├── request queue
│   │   ├── elevator scheduling
│   │   ├── merge / split requests
│   │   ├── NVMe queues
│   │   └── completion path
│   └── Event I/O
│       ├── select
│       ├── poll
│       ├── epoll
│       ├── kqueue
│       ├── io_uring
│       └── readiness vs completion
├── O9. Networking at OS Boundary
│   ├── Socket abstraction
│   │   ├── socket / bind / listen / accept / connect
│   │   ├── send / recv
│   │   ├── blocking / non-blocking socket
│   │   ├── socket options
│   │   └── backlog
│   ├── Network stack
│   │   ├── NIC driver
│   │   ├── Ethernet / ARP / IP / ICMP
│   │   ├── UDP / TCP
│   │   ├── routing table
│   │   └── firewall hooks
│   ├── TCP in OS
│   │   ├── connection state machine
│   │   ├── retransmission
│   │   ├── congestion control
│   │   ├── flow control
│   │   ├── socket buffers
│   │   ├── TIME_WAIT
│   │   └── SYN backlog
│   └── Packet path
│       ├── interrupt / NAPI
│       ├── skb
│       ├── protocol dispatch
│       ├── socket buffer
│       ├── wakeup application
│       └── zero-copy
├── O10. Security / Isolation
│   ├── Permissions
│   │   ├── UID / GID
│   │   ├── file permissions
│   │   ├── setuid
│   │   ├── capabilities
│   │   ├── ACL
│   │   └── LSM
│   ├── Process isolation
│   │   ├── virtual address space
│   │   ├── kernel/user boundary
│   │   ├── credentials
│   │   ├── namespaces
│   │   └── cgroups
│   ├── Syscall attack surface
│   │   ├── validation
│   │   ├── seccomp-bpf
│   │   ├── sandboxing
│   │   ├── TOCTOU
│   │   └── privilege escalation
│   └── Hardening
│       ├── ASLR
│       ├── NX / DEP
│       ├── stack canary
│       ├── W^X
│       ├── SMEP / SMAP
│       └── CFI
├── O11. Virtualization / Containers
│   ├── Virtualization
│   │   ├── trap-and-emulate
│   │   ├── hardware virtualization
│   │   ├── hypervisor
│   │   ├── VM exit
│   │   ├── shadow page table
│   │   ├── nested page table
│   │   └── virtio
│   ├── Containers
│   │   ├── namespaces: pid / mount / network / ipc / uts / user
│   │   ├── cgroups: cpu / memory / io / pids
│   │   ├── union filesystem
│   │   ├── rootfs
│   │   ├── runtime
│   │   └── OCI
│   └── Resource accounting
│       ├── CPU quota
│       ├── memory limit
│       ├── OOM killer
│       ├── PSI
│       └── blkio throttling
├── O12. Observability / Debugging / Performance
│   ├── Tools
│   │   ├── strace / ltrace
│   │   ├── gdb
│   │   ├── perf
│   │   ├── ps / top / htop
│   │   ├── vmstat / iostat / pidstat
│   │   ├── ss / tcpdump
│   │   ├── procfs
│   │   └── sysfs
│   ├── Kernel debugging
│   │   ├── printk
│   │   ├── panic / oops
│   │   ├── stack trace
│   │   ├── ftrace
│   │   ├── kprobes / uprobes
│   │   └── eBPF
│   ├── Performance method
│   │   ├── CPU-bound vs IO-bound
│   │   ├── latency vs throughput
│   │   ├── flame graph
│   │   ├── off-CPU analysis
│   │   ├── lock contention
│   │   ├── page fault analysis
│   │   ├── syscall overhead
│   │   └── tail latency
│   └── OS bug types
│       ├── race / deadlock
│       ├── memory leak / UAF
│       ├── fd leak
│       ├── stuck process
│       ├── high syscall rate
│       ├── IO wait
│       └── packet loss
└── O13. Reliability / Production Behavior
    ├── Crash consistency
    │   ├── write ordering
    │   ├── journaling
    │   ├── WAL
    │   ├── atomic commit
    │   ├── replay
    │   └── fsync discipline
    ├── Fault containment
    │   ├── process isolation
    │   ├── supervisor / restart
    │   ├── watchdog
    │   ├── health check
    │   └── resource limits
    ├── Resource exhaustion
    │   ├── memory pressure
    │   ├── OOM killer
    │   ├── fd exhaustion
    │   ├── process limit
    │   ├── disk full
    │   ├── inode exhaustion
    │   └── port exhaustion
    └── Service lifecycle
        ├── boot process
        ├── init / systemd
        ├── logs
        ├── crash loop
        └── graceful shutdown
```

### OS Practice Spine

```text
Phase A. Unix Process Lab
├── mini shell
├── pipeline / redirection / job control
└── strace report

Phase B. xv6 Kernel Lab
├── syscall tracing
├── scheduler modification
├── lazy allocation
├── COW fork
└── filesystem extension

Phase C. Memory + Concurrency Runtime
├── toy malloc
├── coroutine / thread scheduler
├── mutex / condvar / futex simulator
└── race / deadlock tests

Phase D. Filesystem + Crash Lab
├── toy block device
├── inode filesystem
├── journal / recovery simulator
└── crash-safe file update

Phase E. Linux Observability Lab
├── profile CPU-bound program
├── debug fd leak
├── debug memory pressure
├── trace syscall latency
└── observe network packet path

Phase F. Container Lab
├── namespaces
├── cgroups
├── rootfs
├── seccomp
└── veth networking
```

### OS Exit Criteria

- 能区分 syscall、trap、interrupt、context switch、page fault。
- 能解释进程、线程、文件、socket、虚拟内存的生命周期。
- 能在 xv6 中添加 syscall、改 scheduler、实现 lazy/COW memory。
- 能实现 toy shell、toy malloc、toy scheduler、toy filesystem、mini container。
- 能用 Linux 工具定位 CPU、memory、IO、network、lock 问题。

## 3. Computer Architecture

体系结构是“代码如何在机器上真实运行”的地图。它把算法的复杂度、OS 的抽象、编译器的后端全部拉回到寄存器、指令、cache、TLB、流水线和 I/O。

```text
Computer Architecture
├── R0. Layer 0 Prerequisites
│   ├── Binary / hex / two's complement
│   ├── bit operations
│   ├── Boolean algebra
│   ├── state machine
│   ├── C pointer / array / struct / layout
│   ├── Python simulator
│   └── API / ABI / ISA / microarchitecture distinction
├── R1. Digital Logic
│   ├── Boolean algebra
│   │   ├── AND / OR / NOT / XOR / NAND / NOR
│   │   ├── truth table
│   │   └── De Morgan
│   ├── Combinational logic
│   │   ├── logic gates
│   │   ├── MUX
│   │   ├── decoder / encoder
│   │   ├── adder
│   │   ├── comparator
│   │   └── shifter
│   ├── Sequential logic
│   │   ├── latch
│   │   ├── flip-flop
│   │   ├── clock
│   │   ├── register
│   │   ├── counter
│   │   └── FSM
│   ├── HDL boundary
│   │   ├── Verilog / VHDL idea
│   │   ├── simulation vs synthesis
│   │   └── wire / reg / always / assign
│   └── Pitfalls
│       ├── combinational loop
│       ├── latch inference
│       ├── setup / hold
│       └── critical path
├── R2. Data Representation
│   ├── Integer
│   │   ├── unsigned / signed
│   │   ├── two's complement
│   │   ├── overflow
│   │   ├── sign / zero extension
│   │   └── endianness
│   ├── Floating point
│   │   ├── IEEE 754
│   │   ├── sign / exponent / fraction
│   │   ├── normalized / denormalized
│   │   ├── NaN / Infinity
│   │   ├── rounding
│   │   └── non-associativity
│   ├── Character / encoding
│   │   ├── ASCII
│   │   ├── UTF-8
│   │   └── code point vs bytes
│   ├── Data layout
│   │   ├── alignment
│   │   ├── padding
│   │   ├── struct layout
│   │   ├── AoS vs SoA
│   │   └── pointer / address / object representation
│   └── Bit-level techniques
│       ├── mask / shift
│       ├── packing / unpacking
│       ├── bitmap
│       ├── popcount
│       └── clz / ctz
├── R3. ISA / Assembly
│   ├── ISA role
│   │   ├── software-hardware contract
│   │   ├── instruction / register / memory model
│   │   ├── exception / privilege level
│   │   └── ISA vs microarchitecture
│   ├── Representative ISA
│   │   ├── x86-64
│   │   ├── ARM / AArch64
│   │   └── RISC-V
│   ├── Instructions
│   │   ├── arithmetic
│   │   ├── logical
│   │   ├── shift
│   │   ├── load / store
│   │   ├── branch / jump / call / return
│   │   ├── compare / test
│   │   ├── atomic
│   │   └── SIMD / vector
│   ├── Registers / calling convention
│   │   ├── GPR
│   │   ├── stack pointer
│   │   ├── frame pointer
│   │   ├── program counter
│   │   ├── caller-saved / callee-saved
│   │   ├── argument passing
│   │   └── prologue / epilogue
│   └── Reading assembly
│       ├── C to assembly
│       ├── disassembly
│       ├── objdump
│       ├── gdb / lldb
│       └── symbol / label / relocation
├── R4. Datapath / Control
│   ├── CPU components
│   │   ├── PC
│   │   ├── instruction memory
│   │   ├── register file
│   │   ├── ALU
│   │   ├── data memory
│   │   ├── control unit
│   │   └── branch unit
│   ├── Datapath stages
│   │   ├── fetch
│   │   ├── decode
│   │   ├── execute
│   │   ├── memory
│   │   └── writeback
│   ├── Control
│   │   ├── hardwired control
│   │   ├── microcoded control
│   │   ├── control signals
│   │   └── ALU / branch control
│   ├── Single-cycle CPU
│   │   ├── one long cycle
│   │   └── critical path bottleneck
│   └── Multi-cycle CPU
│       ├── instruction split into stages
│       ├── FSM control
│       └── hardware reuse
├── R5. Pipelining / Hazards
│   ├── Pipeline idea
│   │   ├── ILP
│   │   ├── IF / ID / EX / MEM / WB
│   │   ├── latency vs throughput
│   │   └── pipeline register
│   ├── Hazards
│   │   ├── structural
│   │   ├── data: RAW / WAR / WAW
│   │   └── control: branch / jump / exception
│   ├── Data hazard solutions
│   │   ├── stalling / bubble
│   │   ├── forwarding / bypassing
│   │   ├── hazard detection
│   │   └── load-use hazard
│   ├── Control hazard solutions
│   │   ├── static branch prediction
│   │   ├── dynamic branch prediction
│   │   ├── BTB
│   │   ├── RAS
│   │   └── speculative execution
│   ├── Exceptions
│   │   ├── precise exception
│   │   └── pipeline flush
│   └── Advanced ILP
│       ├── superscalar
│       ├── out-of-order execution
│       ├── register renaming
│       ├── ROB
│       ├── reservation station
│       └── scoreboarding
├── R6. Memory Hierarchy / Cache
│   ├── Hierarchy
│   │   ├── register
│   │   ├── L1 / L2 / L3
│   │   ├── DRAM
│   │   ├── SSD / HDD
│   │   └── remote storage
│   ├── Locality
│   │   ├── temporal
│   │   ├── spatial
│   │   ├── working set
│   │   └── stride access
│   ├── Cache basics
│   │   ├── cache line
│   │   ├── tag / index / offset
│   │   ├── direct-mapped
│   │   ├── set-associative
│   │   ├── fully-associative
│   │   ├── replacement policy
│   │   └── write policy
│   ├── Cache performance
│   │   ├── hit / miss
│   │   ├── compulsory / capacity / conflict miss
│   │   ├── AMAT
│   │   ├── pollution
│   │   └── prefetching
│   ├── Multi-level cache
│   │   ├── inclusive / exclusive / non-inclusive
│   │   ├── victim cache
│   │   └── TLB interaction
│   └── Cache-friendly programming
│       ├── blocking / tiling
│       ├── loop interchange
│       ├── AoS vs SoA
│       └── false sharing
├── R7. Virtual Memory Boundary
│   ├── Address translation
│   │   ├── virtual address
│   │   ├── physical address
│   │   ├── isolation
│   │   └── protection
│   ├── Paging
│   │   ├── page / page frame
│   │   ├── page table
│   │   ├── multi-level page table
│   │   └── PTE flags
│   ├── TLB
│   │   ├── TLB hit / miss
│   │   ├── TLB shootdown
│   │   └── huge page
│   ├── Faults
│   │   ├── page fault
│   │   ├── demand paging
│   │   ├── COW
│   │   └── mmap
│   └── Cache + VM
│       ├── physically indexed
│       ├── virtually indexed
│       ├── synonyms / aliasing
│       └── TLB reach
├── R8. Performance Modeling
│   ├── Metrics
│   │   ├── latency
│   │   ├── throughput
│   │   ├── CPI / IPC
│   │   ├── clock rate
│   │   ├── instruction count
│   │   └── utilization
│   ├── Formulas
│   │   ├── CPU time = instruction count * CPI * cycle time
│   │   ├── AMAT = hit time + miss rate * miss penalty
│   │   ├── Amdahl's Law
│   │   └── Little's Law intuition
│   ├── Benchmark / profiling
│   │   ├── microbenchmark / macrobenchmark
│   │   ├── perf / time / flamegraph
│   │   ├── hardware counters
│   │   └── warmup / noise / dead-code elimination pitfalls
│   └── Roofline model
│       ├── arithmetic intensity
│       ├── memory bandwidth bound
│       └── compute bound
├── R9. Parallelism
│   ├── Levels
│   │   ├── bit-level
│   │   ├── instruction-level
│   │   ├── data-level
│   │   ├── thread-level
│   │   └── task-level
│   ├── SIMD / vector
│   │   ├── SSE / AVX / NEON / RISC-V Vector
│   │   ├── lane
│   │   ├── gather / scatter
│   │   └── mask / predicate
│   ├── Multicore
│   │   ├── core / hardware thread
│   │   ├── SMT
│   │   ├── shared cache
│   │   ├── MESI intuition
│   │   ├── memory consistency
│   │   └── atomic / fence / lock
│   ├── NUMA
│   │   ├── local / remote memory
│   │   ├── memory affinity
│   │   └── false sharing
│   └── GPU
│       ├── SIMT
│       ├── warp / wavefront
│       ├── thread block
│       ├── shared / global memory
│       ├── coalesced access
│       └── divergence
├── R10. Storage / I/O Boundary
│   ├── I/O path
│   │   ├── CPU
│   │   ├── memory
│   │   ├── PCIe
│   │   ├── controller
│   │   ├── SSD / NVMe
│   │   └── NIC
│   ├── MMIO
│   │   ├── device register
│   │   └── polling
│   ├── Interrupt / DMA
│   │   ├── interrupt controller
│   │   ├── DMA
│   │   ├── descriptor ring
│   │   └── completion queue
│   ├── Storage
│   │   ├── HDD vs SSD
│   │   ├── block device
│   │   ├── sector / page / erase block
│   │   ├── write amplification
│   │   └── queue depth
│   └── I/O performance
│       ├── sequential vs random
│       ├── batching
│       ├── async I/O
│       ├── zero-copy
│       └── page cache boundary
└── R11. Security / Microarchitecture
    ├── Privilege / isolation
    │   ├── user mode / kernel mode
    │   ├── memory protection
    │   ├── NX bit
    │   ├── ASLR
    │   └── W^X
    ├── Microarchitectural state
    │   ├── cache state
    │   ├── branch predictor state
    │   ├── TLB state
    │   ├── speculative state
    │   └── timing side channel
    ├── Attacks
    │   ├── buffer overflow background
    │   ├── ROP
    │   ├── cache timing
    │   ├── Spectre
    │   ├── Meltdown
    │   └── Rowhammer
    └── Defenses
        ├── constant-time programming
        ├── speculation barrier
        ├── cache partitioning
        ├── KPTI
        └── memory tagging entrance
```

### Architecture Practice Spine

```text
Project A. Assembly Tracer
├── compile C to assembly
├── trace registers / stack frame
└── explain loop / call / array access

Project B. Tiny CPU Simulator
├── RISC-V-like subset
├── interpreter
├── single-cycle datapath visualization
└── five-stage pipeline + hazards

Project C. Cache + TLB Simulator
├── memory trace input
├── cache size / line size / associativity
├── replacement policy
├── TLB entries / page size
└── miss rate / AMAT / heatmap

Project D. Performance Lab
├── matrix multiplication
├── array vs linked list
├── branch prediction
├── SIMD dot product
└── perf counters report

Project E. Parallelism Mini Lab
├── single-thread
├── SIMD
├── multithread
├── GPU
└── false sharing / memory bandwidth
```

### Architecture Exit Criteria

- 能从 C 代码一路解释到 assembly、register、memory access、cache behavior。
- 能手画一个简单 CPU datapath，并说明 control signals。
- 能模拟五级流水线并处理基本 data/control hazards。
- 能写 cache/TLB simulator，用它解释真实程序性能差异。
- 能用 perf/hardware counters 验证一个性能假设。
- 能判断瓶颈更可能来自计算、内存、分支、I/O 还是同步。

## 4. Compilers

编译器是“让机器理解语言”的系统。它把字符串变成结构，把结构变成语义，把语义变成 IR、字节码、机器码或解释执行。

```text
Compilers
├── C0. Layer 0 Prerequisites
│   ├── Discrete math
│   │   ├── set / relation / function
│   │   ├── recursion
│   │   ├── structural induction
│   │   ├── graph / tree / DAG
│   │   ├── finite automata
│   │   └── CFG intuition
│   ├── Programming basics
│   │   ├── C/C++/Rust memory model
│   │   ├── Python/JS object / closure / interpreter intuition
│   │   ├── array / stack / queue / hash table / tree / graph
│   │   └── tokenizer / recursive descent parser toy
│   └── System basics
│       ├── algorithms: DFS / graph / hash / topo sort
│       ├── OS: process / VM / syscall / file / dynamic linking
│       └── architecture: ISA / register / ABI / assembly
├── C1. Compiler Overview
│   ├── Pipeline
│   │   ├── source
│   │   ├── tokens
│   │   ├── parse tree
│   │   ├── AST
│   │   ├── semantic model
│   │   ├── IR
│   │   ├── optimized IR
│   │   └── machine code / bytecode
│   ├── Implementation forms
│   │   ├── tree-walking interpreter
│   │   ├── bytecode VM
│   │   ├── native compiler
│   │   ├── transpiler
│   │   └── JIT
│   └── Toolchain concepts
│       ├── compiler
│       ├── interpreter
│       ├── assembler
│       ├── linker
│       ├── AOT
│       ├── REPL
│       └── incremental compilation
├── C2. Language Design
│   ├── Semantics
│   │   ├── expression / statement / declaration
│   │   ├── value / object
│   │   ├── variable binding
│   │   ├── scope
│   │   ├── lifetime
│   │   ├── static / dynamic typing
│   │   ├── value / reference semantics
│   │   └── ownership entrance
│   ├── Control flow
│   │   ├── if / while / for
│   │   ├── break / continue / return
│   │   ├── function / recursion
│   │   ├── closure
│   │   ├── exception
│   │   └── coroutine
│   └── Types / abstraction
│       ├── primitive
│       ├── struct / record
│       ├── enum / sum type
│       ├── array / tuple
│       ├── generic / template
│       ├── trait / interface / typeclass
│       └── polymorphism
├── C3. Lexing / Scanning
│   ├── Basics
│   │   ├── token
│   │   ├── lexeme
│   │   ├── literal
│   │   ├── keyword
│   │   ├── identifier
│   │   ├── whitespace / comment
│   │   └── source span
│   ├── Theory / implementation
│   │   ├── regex
│   │   ├── NFA
│   │   ├── DFA
│   │   ├── hand-written scanner
│   │   ├── flex / lex
│   │   ├── Unicode
│   │   ├── escape sequence
│   │   └── numeric literal
│   └── Errors
│       ├── illegal character
│       ├── unterminated string
│       ├── invalid escape
│       ├── panic mode
│       └── precise location
├── C4. Parsing
│   ├── Grammar
│   │   ├── CFG
│   │   ├── terminal / non-terminal
│   │   ├── production
│   │   ├── ambiguity
│   │   ├── precedence
│   │   ├── associativity
│   │   ├── left recursion
│   │   └── FIRST / FOLLOW
│   ├── Techniques
│   │   ├── recursive descent
│   │   ├── Pratt parser
│   │   ├── precedence climbing
│   │   ├── LL(k)
│   │   ├── LR / SLR / LALR
│   │   ├── GLR
│   │   ├── Earley
│   │   └── parser generator
│   └── Error recovery
│       ├── synchronize token
│       ├── expected set
│       ├── token insertion / deletion suggestion
│       └── incremental / partial parse
├── C5. AST / Frontend Representation
│   ├── AST design
│   │   ├── Expr / Stmt / Decl
│   │   ├── source span
│   │   ├── node id
│   │   ├── parent pointer
│   │   ├── symbol reference
│   │   ├── CST vs AST
│   │   ├── visitor pattern
│   │   └── arena allocation
│   └── Lowering / normalization
│       ├── desugaring
│       ├── for to while
│       ├── compound assignment to assignment
│       ├── name resolution
│       └── typed AST
├── C6. Semantic Analysis
│   ├── Names / scopes
│   │   ├── symbol table
│   │   ├── scope stack
│   │   ├── shadowing
│   │   ├── hoisting
│   │   ├── module scope
│   │   ├── namespace
│   │   ├── forward declaration
│   │   └── mutual recursion
│   ├── Control-flow semantics
│   │   ├── definite assignment
│   │   ├── unreachable code
│   │   ├── return path checking
│   │   ├── break / continue legality
│   │   └── closure capture analysis
│   └── Type pre-analysis
│       ├── lvalue / rvalue
│       ├── mutability
│       ├── constness
│       ├── implicit conversion
│       └── overload resolution
├── C7. Type Systems
│   ├── Basic type checking
│   │   ├── type environment
│   │   ├── typing judgment
│   │   ├── constraint
│   │   ├── checking vs inference
│   │   ├── nominal vs structural typing
│   │   ├── subtyping
│   │   └── variance
│   ├── Advanced topics
│   │   ├── Hindley-Milner
│   │   ├── unification
│   │   ├── let-polymorphism
│   │   ├── monomorphization vs type erasure
│   │   ├── traits / interfaces
│   │   └── ownership / borrow checking intuition
│   └── Error experience
│       ├── expected vs actual
│       ├── principal type
│       ├── blame assignment
│       └── suggestions
├── C8. IR
│   ├── IR levels
│   │   ├── HIR
│   │   ├── MIR
│   │   ├── LIR
│   │   ├── three-address code
│   │   ├── stack IR
│   │   ├── register IR
│   │   └── SSA
│   ├── Control-flow representation
│   │   ├── basic block
│   │   ├── CFG
│   │   ├── dominator
│   │   ├── post-dominator
│   │   ├── loop nesting tree
│   │   ├── phi node
│   │   └── critical edge
│   └── Dataflow basics
│       ├── def-use
│       ├── use-def
│       ├── liveness
│       ├── reaching definitions
│       └── available expressions
├── C9. Optimization
│   ├── Local optimization
│   │   ├── constant folding
│   │   ├── constant propagation
│   │   ├── algebraic simplification
│   │   ├── copy propagation
│   │   ├── DCE
│   │   └── CSE
│   ├── Global optimization
│   │   ├── dataflow framework
│   │   ├── lattice
│   │   ├── transfer function
│   │   ├── fixed point
│   │   ├── global value numbering
│   │   ├── PRE
│   │   ├── inlining
│   │   ├── escape analysis
│   │   └── devirtualization
│   ├── Loop optimization
│   │   ├── LICM
│   │   ├── strength reduction
│   │   ├── induction variable analysis
│   │   ├── unrolling
│   │   └── vectorization
│   └── Tradeoffs
│       ├── compile time vs runtime
│       ├── debuggability
│       ├── undefined behavior
│       └── PGO
├── C10. Code Generation
│   ├── Target machine model
│   │   ├── ISA
│   │   ├── register
│   │   ├── addressing mode
│   │   ├── stack frame
│   │   ├── calling convention
│   │   └── ABI
│   ├── Backend stages
│   │   ├── instruction selection
│   │   ├── tree tiling
│   │   ├── register allocation
│   │   ├── linear scan
│   │   ├── graph coloring
│   │   ├── instruction scheduling
│   │   └── peephole optimization
│   └── Output formats
│       ├── assembly
│       ├── object file
│       ├── ELF / Mach-O / COFF
│       ├── relocation
│       ├── symbol
│       └── dynamic library
├── C11. Runtime Systems
│   ├── Stack / calls
│   │   ├── call stack
│   │   ├── activation record
│   │   ├── stack frame
│   │   ├── recursion
│   │   ├── tail call
│   │   ├── closure environment
│   │   └── exception unwinding
│   ├── Object model
│   │   ├── object layout
│   │   ├── vtable
│   │   ├── method dispatch
│   │   ├── boxing / unboxing
│   │   ├── tagged union
│   │   ├── NaN-boxing
│   │   ├── string interning
│   │   └── array layout
│   └── Modules / linking
│       ├── runtime library
│       ├── startup code
│       ├── FFI
│       ├── dynamic loading
│       └── reflection metadata
├── C12. VM / Bytecode / Interpreter
│   ├── Bytecode design
│   │   ├── stack VM
│   │   ├── register VM
│   │   ├── opcode / operand
│   │   ├── constant pool
│   │   └── chunk / function object
│   ├── VM execution
│   │   ├── operand stack
│   │   ├── call frame
│   │   ├── global table
│   │   ├── bytecode verifier
│   │   ├── disassembler
│   │   ├── REPL
│   │   └── native function binding
│   └── clox route
│       ├── scanner
│       ├── Pratt parser
│       ├── bytecode compiler
│       ├── closures / upvalues
│       ├── classes / methods
│       └── GC
├── C13. GC / Memory Management
│   ├── Management styles
│   │   ├── ownership
│   │   ├── reference counting
│   │   └── tracing GC
│   ├── Allocation
│   │   ├── bump pointer
│   │   ├── free list
│   │   └── arena
│   ├── Tracing GC
│   │   ├── mark-sweep
│   │   ├── tri-color abstraction
│   │   ├── root set
│   │   ├── stack / globals / registers / VM frames
│   │   ├── moving / copying GC
│   │   └── generational GC
│   └── Practical issues
│       ├── finalizer
│       ├── weak reference
│       ├── write barrier
│       ├── pause time
│       └── fragmentation
├── C14. JIT / Dynamic Optimization
│   ├── JIT forms
│   │   ├── baseline JIT
│   │   ├── method JIT
│   │   ├── tracing JIT
│   │   ├── tiered compilation
│   │   ├── OSR
│   │   └── deoptimization
│   ├── Dynamic language optimization
│   │   ├── inline cache
│   │   ├── hidden class / shape
│   │   ├── PIC
│   │   ├── speculative optimization
│   │   ├── guard
│   │   └── bailout
│   └── System dependency
│       ├── executable memory
│       ├── mmap / mprotect
│       ├── machine code encoding
│       ├── cache
│       └── branch prediction
└── C15. Tooling / Diagnostics / Tests
    ├── Developer experience
    │   ├── diagnostic span
    │   ├── label / note / fix-it
    │   ├── source map
    │   ├── colored output
    │   ├── formatter
    │   ├── linter
    │   └── LSP
    ├── Compiler engineering
    │   ├── incremental compilation
    │   ├── dependency graph
    │   ├── build cache
    │   ├── golden tests
    │   ├── snapshot tests
    │   ├── fuzzing
    │   └── differential testing
    └── Debugging support
        ├── AST dump
        ├── IR dump
        ├── bytecode disassembler
        ├── trace parser
        ├── trace VM
        └── trace GC
```

### Compilers Practice Spine

```text
Project A. Expression Interpreter
├── lexer
├── Pratt parser
├── AST interpreter
├── variables / if / while / functions
└── Fibonacci + scope + error tests

Project B. clox-style Bytecode VM
├── bytecode compiler
├── stack VM
├── disassembler
├── local variables / functions / closures
├── class / object
└── mark-sweep GC

Project C. nanoc-style C Subset Compiler
├── C-like syntax
├── AST
├── type checking
├── IR
├── optimization
└── x86-64 / RISC-V / ARM64 assembly

Project D. Compiler Analysis Lab
├── CFG builder
├── dominator tree
├── liveness analysis
├── dataflow fixed point
└── register allocation toy

Project E. Optimization Lab
├── SSA IR
├── DCE
├── constant propagation
├── LICM
├── register allocation demo
└── benchmark before / after
```

### Compilers Exit Criteria

- 能独立讲清 source -> token -> AST -> semantic analysis -> IR -> backend/VM。
- 能实现 lexer、parser、AST、resolver、type checker、IR、一个后端或 VM。
- 能解释闭包、对象、栈帧、GC、调用约定、基本优化。
- 能用 golden tests、snapshot tests、fuzzing、differential testing 验证语言语义。
- 能阅读 `clox`、`nanoc`、Stanford CS143/LLVM Kaleidoscope，并把概念映射到自己的实现。

## Cross-Trunk Map

```text
Algorithms <-> OS
├── scheduler: priority queue / fair queueing / online algorithms
├── memory: LRU / Clock / buddy allocator / slab allocator
├── filesystem: B-tree / B+ tree / bitmap / hashing / journal ordering
├── networking: queue / timer / congestion control / randomized backoff
└── concurrency: lock-free queues / deadlock graph / wait-for graph

Algorithms <-> Architecture
├── Big-O is not enough: cache miss / branch miss / memory bandwidth
├── data layout: array / linked list / hash table / B-tree
├── matrix / FFT / graph / sort depend on memory hierarchy
└── parallel algorithms need SIMD / cache coherence / GPU memory model

Algorithms <-> Compilers
├── lexing: regex / NFA / DFA / string matching
├── parsing: stack / recursion / LL / LR / chart parsing
├── CFG: DFS / dominator tree / SCC
├── dataflow: fixed point / lattice / worklist
├── register allocation: graph coloring / interval allocation
└── GC: graph reachability / worklist

OS <-> Architecture
├── process/thread: register state / PC / stack / page table
├── syscall/trap/interrupt: ISA privilege mode
├── virtual memory: MMU / TLB / page fault
├── synchronization: atomic instruction / memory ordering / cache coherence
├── I/O: DMA / interrupt / device controller
└── scheduling: timer interrupt / cache affinity / NUMA

OS <-> Compilers
├── process startup: loader / runtime / main
├── syscall ABI: calling convention / registers
├── dynamic linking: PLT / GOT / shared library
├── debugging: symbol table / frame pointer / DWARF
├── sanitizer: compiler instrumentation + OS memory protection
└── JIT: mmap / mprotect / executable memory

Architecture <-> Compilers
├── backend: ISA / registers / instruction selection
├── register allocation: physical register pressure
├── calling convention: stack frame / ABI
├── instruction scheduling: pipeline / latency / hazards
├── optimization: cache locality / SIMD / vectorization
└── security: CFI / bounds checks / speculation mitigation
```

## Minimal Learning Order For This Repo

这不是完整本科顺序，而是适合 `CS4LLM` 当前状态的“先能跑、再能解释、最后能实现”的顺序。

```text
0. Layer 0 still comes first
├── Python reading
├── terminal / git
├── list / dict / set / stack / queue / tree / graph
├── complexity / invariant / tests
└── small practice bridge

1. Algorithms first, but only the practical core
├── complexity
├── recursion / invariant
├── array / hash / tree / graph
├── BFS / DFS / Dijkstra
├── sorting / binary search
└── testing / benchmark

2. Then choose one systems door
├── OS route: syscall / process / memory
├── Compiler route: lexer / parser / VM
└── Architecture route: data representation / assembly / cache

3. Then integrate
├── B+ tree connects Algorithms + DB + OS I/O + Architecture cache
├── syscall connects OS + Architecture + ABI
├── bytecode VM connects Compilers + OS runtime + Architecture stack/cache
└── scheduler connects OS + Algorithms + Architecture timing
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
