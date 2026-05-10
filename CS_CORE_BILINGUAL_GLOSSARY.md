# CS Core Bilingual Glossary

这份文件配套 [CS_CORE_TREE.md](./CS_CORE_TREE.md)，用来解决一个实际问题：

```text
中文概念 <-> 英文术语 <-> 人话直觉
```

它不是考试词汇表，而是学习时的“翻译层”。看到英文名词先不要慌，先找到它对应的中文和直觉，再回到主树里看它属于哪个分支。

## How To Read This

| Column | Meaning |
| --- | --- |
| 中文 | 你可以先用中文理解的概念 |
| English | 课程、论文、源码、文档里常见的英文术语 |
| 直觉 | 这个东西大概在解决什么问题 |

## Top-Level Map

| 中文 | English | 直觉 |
| --- | --- | --- |
| 预备层 | Prerequisite Layer / Layer 0 | 数学、编程、数据结构、工具肌肉记忆 |
| 四大硬核主干 | Core CS Trunk / Layer 1 | 算法、操作系统、体系结构、编译器 |
| 算法 | Algorithms | 怎么把问题变成可计算步骤 |
| 操作系统 | Operating Systems / OS | 怎么把硬件变成进程、文件、内存、网络等抽象 |
| 计算机体系结构 | Computer Architecture | 代码怎么真的在 CPU、内存、cache、设备上跑 |
| 编译器 | Compilers | 代码文本怎么变成机器能执行的东西 |
| 系统工程主干 | Systems Engineering Trunk / Layer 2 | 网络、数据库、分布式、存储性能 |
| AI/ML 方向 | AI/ML Track / Layer 3 | 机器学习、深度学习、LLM、Agent |
| 工业实践层 | Industrial Practice Layer / Layer 4 | 项目、debug、benchmark、部署、协作 |

## Shared Terms

| 中文 | English | 直觉 |
| --- | --- | --- |
| 数据结构 | Data Structure | 数据在程序里怎么摆放和维护 |
| 算法 | Algorithm | 解决问题的一组步骤 |
| 复杂度 | Complexity | 数据变大时，时间和空间怎么增长 |
| 时间复杂度 | Time Complexity | 输入变大时要跑多久 |
| 空间复杂度 | Space Complexity | 输入变大时要占多少内存 |
| 大 O | Big-O | 增长速度的上界 |
| 不变量 | Invariant | 系统变化中必须一直保持成立的规则 |
| 状态 | State | 某个对象或系统当前保存的信息 |
| 状态机 | State Machine | 用状态和状态转移描述系统行为 |
| 断言 | Assertion | 明确要求某个条件必须为真 |
| 测试 | Test | 用代码验证行为是否符合预期 |
| 基准测试 | Benchmark | 测一个程序在某种输入下跑多快 |
| 性能剖析 | Profiling | 找程序真正慢在哪里 |
| 热点 | Hot Path / Hotspot | 程序最常执行或最耗时的部分 |
| 调试 | Debugging | 找到错误原因并验证修复 |
| 可观测性 | Observability | 系统是否能被日志、指标、trace 看清楚 |
| 抽象 | Abstraction | 把复杂细节包装成可使用的接口 |
| 接口 | Interface | 两个模块之间约定怎么交互 |
| API | Application Programming Interface | 程序给程序用的接口 |
| ABI | Application Binary Interface | 编译后代码之间的二进制调用约定 |
| ISA | Instruction Set Architecture | 软件能看到的 CPU 指令契约 |
| 运行时 | Runtime | 程序运行时依赖的支持系统 |
| 权衡 | Tradeoff | 一个设计好在哪里、代价在哪里 |
| 正确性 | Correctness | 程序是否做了它应该做的事 |
| 可靠性 | Reliability | 系统在故障和边界条件下是否还能工作 |
| 可扩展性 | Scalability | 数据量、请求量、机器数量变大时能否撑住 |

## Algorithms / 算法

### Analysis / 分析基础

| 中文 | English | 直觉 |
| --- | --- | --- |
| 计算模型 | Computation Model | 先约定“什么操作算一步” |
| 随机访问机模型 | RAM Model | 假设数组访问等基本操作是常数时间 |
| 字长随机访问机 | Word RAM Model | 把机器字长和位运算也纳入模型 |
| 比较模型 | Comparison Model | 只能通过比较大小来区分元素 |
| 指针机模型 | Pointer Machine Model | 更贴近链表、树、图等指针结构 |
| 渐进分析 | Asymptotic Analysis | 忽略小常数，关注增长趋势 |
| 上界 | Upper Bound | 最多增长到什么程度 |
| 下界 | Lower Bound | 至少要花多少代价 |
| 紧界 | Tight Bound | 上下界一致，基本就是这个量级 |
| 递推式 | Recurrence | 递归函数的工作量表达式 |
| 递归树 | Recursion Tree | 把递归调用展开成一棵树看总工作 |
| 主定理 | Master Theorem | 快速解常见分治递推 |
| 正确性证明 | Correctness Proof | 证明算法为什么一定对 |
| 循环不变量 | Loop Invariant | 循环每一轮前后都必须保持的规则 |
| 摊还分析 | Amortized Analysis | 多次操作平均下来每次多贵 |
| 最坏情况 | Worst Case | 最倒霉输入下的表现 |
| 平均情况 | Average Case | 按输入分布平均的表现 |
| 期望运行时间 | Expected Runtime | 随机算法平均要跑多久 |

### Data Structures / 数据结构

| 中文 | English | 直觉 |
| --- | --- | --- |
| 数组 | Array | 连续格子，按下标快速访问 |
| 动态数组 | Dynamic Array | 会自动扩容的数组 |
| 链表 | Linked List | 每个节点指向下一个节点 |
| 侵入式链表 | Intrusive List | 节点自己带链表指针，OS 常见 |
| 栈 | Stack | 后进先出 |
| 队列 | Queue | 先进先出 |
| 双端队列 | Deque | 两头都能进出 |
| 哈希表 | Hash Table | key -> value 的快速查找表 |
| 哈希函数 | Hash Function | 把 key 映射成位置 |
| 碰撞 | Collision | 两个 key 映射到同一位置 |
| 开放寻址 | Open Addressing | 碰撞后在表里继续找空位 |
| 拉链法 | Chaining | 碰撞后挂到同一个桶的链表里 |
| 负载因子 | Load Factor | 哈希表装得多满 |
| 布隆过滤器 | Bloom Filter | 很省空间地判断“可能存在/一定不存在” |
| 计数最小草图 | Count-Min Sketch | 用近似方式统计频率 |
| 一致性哈希 | Consistent Hashing | 分片变动时尽量少移动数据 |
| 二叉树 | Binary Tree | 每个节点最多两个孩子 |
| 二叉搜索树 | Binary Search Tree / BST | 左小右大的查找树 |
| 平衡树 | Balanced Tree | 控制树高度，避免退化成链表 |
| 红黑树 | Red-Black Tree | 工程常见的平衡 BST |
| B 树 | B-tree | 适合磁盘页访问的多叉搜索树 |
| B+ 树 | B+ Tree | 数据库常用索引，数据主要在叶子层 |
| 线段树 | Segment Tree | 维护区间查询和区间更新 |
| 树状数组 | Fenwick Tree / Binary Indexed Tree | 轻量维护前缀和 |
| 前缀树 | Trie / Prefix Tree | 按字符前缀组织字符串 |
| 基数树 | Radix Tree | 压缩过的 Trie，路由表常见 |
| 堆 | Heap | 总能快速取最小或最大 |
| 优先队列 | Priority Queue | 按优先级取任务 |
| 并查集 | Disjoint Set Union / Union-Find | 维护“谁和谁在同一组” |
| 持久化数据结构 | Persistent Data Structure | 保留旧版本的数据结构 |
| 位图 | Bitmap / Bitset | 用 bit 表示集合或状态 |
| 稀疏表示 | Sparse Representation | 只存非零或有效部分 |

### Paradigms / 算法范式

| 中文 | English | 直觉 |
| --- | --- | --- |
| 暴力枚举 | Brute Force / Exhaustive Search | 把可能性都试一遍 |
| 剪枝 | Pruning | 提前砍掉不可能成功的分支 |
| 分治 | Divide and Conquer | 拆成小问题，分别解决再合并 |
| 贪心 | Greedy | 每一步做当前看起来最好的选择 |
| 动态规划 | Dynamic Programming / DP | 复用子问题结果，避免重复计算 |
| 记忆化搜索 | Memoization | 递归算过的结果缓存起来 |
| 表格法 | Tabulation | 按顺序填 DP 表 |
| 状态转移 | State Transition | 从一个状态怎么走到另一个状态 |
| 回溯 | Backtracking | 试一条路，不行就退回来换路 |
| 约束求解 | Constraint Solving | 用约束缩小搜索空间 |
| 归约 | Reduction | 把一个问题转换成另一个已知问题 |
| 随机化算法 | Randomized Algorithm | 用随机性换平均性能或简单性 |
| 拉斯维加斯算法 | Las Vegas Algorithm | 结果一定对，运行时间随机 |
| 蒙特卡洛算法 | Monte Carlo Algorithm | 运行时间可控，结果可能有小概率错 |

### Graph / 图

| 中文 | English | 直觉 |
| --- | --- | --- |
| 图 | Graph | 点和边组成的关系网络 |
| 顶点 | Vertex / Node | 图里的点 |
| 边 | Edge | 点之间的连接 |
| 有向图 | Directed Graph | 边有方向 |
| 无向图 | Undirected Graph | 边没有方向 |
| 加权图 | Weighted Graph | 边带成本 |
| 邻接表 | Adjacency List | 每个点存它连向谁 |
| 邻接矩阵 | Adjacency Matrix | 用矩阵表示点和点是否相连 |
| BFS | Breadth-First Search | 一层一层扩散 |
| DFS | Depth-First Search | 一条路走到底再退回 |
| 连通分量 | Connected Component | 互相能到达的一组点 |
| 拓扑排序 | Topological Sort | 对依赖关系排先后顺序 |
| 最短路 | Shortest Path | 找成本最低的路径 |
| Dijkstra 算法 | Dijkstra's Algorithm | 非负边权最短路 |
| Bellman-Ford | Bellman-Ford Algorithm | 可处理负边的最短路 |
| A 星搜索 | A* Search | 带启发式的路径搜索 |
| 最小生成树 | Minimum Spanning Tree / MST | 用最小成本连通所有点 |
| 强连通分量 | Strongly Connected Component / SCC | 有向图里互相可达的一组点 |
| 网络流 | Network Flow | 在容量限制下最多能流多少 |
| 最大流 | Max Flow | 源点到汇点的最大流量 |
| 最小割 | Min Cut | 切断网络的最小代价 |
| 匹配 | Matching | 给两边对象配对 |
| 支配树 | Dominator Tree | 编译器 CFG 里“必经节点”的结构 |

### Strings / 字符串

| 中文 | English | 直觉 |
| --- | --- | --- |
| 字符编码 | Character Encoding | 字符怎么变成字节 |
| ASCII | ASCII | 早期英文字符编码 |
| UTF-8 | UTF-8 | 现代常用 Unicode 字节编码 |
| 前缀 | Prefix | 字符串开头部分 |
| 后缀 | Suffix | 字符串结尾部分 |
| 子串 | Substring | 连续的一段 |
| 子序列 | Subsequence | 不一定连续但保持顺序 |
| 模式匹配 | Pattern Matching | 找字符串里有没有某个模式 |
| KMP | Knuth-Morris-Pratt | 利用失败函数避免重复匹配 |
| 滚动哈希 | Rolling Hash | 滑动窗口中快速更新 hash |
| Aho-Corasick | Aho-Corasick Automaton | 多模式字符串匹配 |
| 后缀数组 | Suffix Array | 把所有后缀排序后的索引 |
| 编辑距离 | Edit Distance | 一个字符串改成另一个要几步 |
| 最长公共子序列 | Longest Common Subsequence / LCS | 两个序列共同保留顺序的最长部分 |

### Hard Problems / 困难问题

| 中文 | English | 直觉 |
| --- | --- | --- |
| 决策问题 | Decision Problem | 答案是 yes/no 的问题 |
| 搜索问题 | Search Problem | 找一个满足条件的解 |
| 优化问题 | Optimization Problem | 找成本最低或收益最高的解 |
| 复杂度类 | Complexity Class | 按难度给问题分类 |
| P 类 | P | 多项式时间能解的问题 |
| NP 类 | NP | 给答案后能快速验证的问题 |
| NP-hard | NP-hard | 至少和 NP 中最难问题一样难 |
| NP-complete | NP-complete | 既在 NP 里，又 NP-hard |
| 归约证明 | Reduction Proof | 证明一个问题不比另一个简单 |
| SAT | Boolean Satisfiability | 布尔公式是否有满足赋值 |
| 近似算法 | Approximation Algorithm | 不求最优，但保证离最优不太远 |
| 在线算法 | Online Algorithm | 不知道未来输入，只能边来边决策 |
| 流式算法 | Streaming Algorithm | 数据只扫一遍或少数几遍，内存很小 |

## Operating Systems / 操作系统

### OS Model / 总体模型

| 中文 | English | 直觉 |
| --- | --- | --- |
| 内核 | Kernel | OS 最核心、最高权限的部分 |
| 用户态 | User Mode | 普通程序运行的低权限模式 |
| 内核态 | Kernel Mode | 内核运行的高权限模式 |
| 单体内核 | Monolithic Kernel | 大部分服务都在内核里 |
| 微内核 | Microkernel | 内核只留最小核心服务 |
| 资源复用 | Resource Multiplexing | 多个程序共享 CPU、内存、磁盘等 |
| 隔离 | Isolation | 程序之间互不乱碰 |
| 进程 | Process | 正在运行的程序实例和资源容器 |
| 文件 | File | 持久化数据的抽象 |
| 虚拟内存 | Virtual Memory | 每个进程都像独占一片内存 |
| 套接字 | Socket | 网络连接也被抽象成类似文件的对象 |

### Process / Thread / Context

| 中文 | English | 直觉 |
| --- | --- | --- |
| 地址空间 | Address Space | 进程能看到的内存范围 |
| 文件描述符 | File Descriptor / FD | 进程里代表文件、socket、pipe 的整数句柄 |
| 父进程 | Parent Process | 创建当前进程的进程 |
| 子进程 | Child Process | 当前进程创建出来的进程 |
| 僵尸进程 | Zombie Process | 已退出但父进程还没回收状态的进程 |
| 孤儿进程 | Orphan Process | 父进程没了的进程 |
| fork | fork | 复制出一个子进程 |
| exec | exec | 用新程序替换当前进程内容 |
| wait | wait | 父进程等待并回收子进程 |
| exit | exit | 进程退出 |
| 线程 | Thread | 进程内部的一条执行流 |
| 内核线程 | Kernel Thread | 内核能调度的线程 |
| 用户线程 | User Thread | 用户态 runtime 自己管理的线程 |
| 线程局部存储 | Thread-Local Storage / TLS | 每个线程自己的一份变量 |
| 上下文切换 | Context Switch | CPU 从运行一个执行流切到另一个 |
| 寄存器保存恢复 | Register Save / Restore | 切换时保存/恢复 CPU 当前状态 |
| 内核栈 | Kernel Stack | 进程进入内核时使用的栈 |
| 陷入帧 | Trap Frame | 保存用户态进入内核时的寄存器现场 |
| 信号 | Signal | Unix 给进程发的异步通知 |

### Syscall / Trap / Interrupt

| 中文 | English | 直觉 |
| --- | --- | --- |
| 系统调用 | System Call / Syscall | 用户程序请求内核帮忙 |
| 陷入 | Trap | CPU 从用户态切到内核态处理事件 |
| 中断 | Interrupt | 设备或计时器打断 CPU，请求处理 |
| 异常 | Exception | CPU 执行指令时发现异常情况 |
| 页错误 | Page Fault | 访问虚拟内存时发现页不在或权限不对 |
| 断点 | Breakpoint | 调试器故意触发的暂停点 |
| 系统调用号 | Syscall Number | 标识请求哪个内核服务 |
| errno | errno | Unix 风格错误码 |
| copyin / copyout | copyin / copyout | 内核和用户空间之间安全拷贝数据 |
| 用户指针校验 | User Pointer Validation | 防止内核乱信用户传来的地址 |
| TOCTOU | Time-of-Check to Time-of-Use | 检查时和使用时状态变了导致漏洞 |
| seccomp | seccomp | 限制进程能调用哪些 syscall |

### Memory / VM

| 中文 | English | 直觉 |
| --- | --- | --- |
| 物理内存 | Physical Memory | 真实 RAM |
| 虚拟地址 | Virtual Address | 程序看到的地址 |
| 物理地址 | Physical Address | 硬件 RAM 的真实地址 |
| 页 | Page | 虚拟内存管理的固定大小块 |
| 页框 | Page Frame | 物理内存里的页大小块 |
| 页表 | Page Table | 虚拟地址到物理地址的映射表 |
| 页表项 | Page Table Entry / PTE | 页表里的一条映射记录 |
| MMU | Memory Management Unit | CPU 里负责地址翻译的硬件 |
| TLB | Translation Lookaside Buffer | 地址翻译结果的硬件缓存 |
| 缺页 | Page Fault | 访问的页暂时无法直接使用 |
| 按需分页 | Demand Paging | 用到某页时才真正分配或加载 |
| 写时复制 | Copy-on-Write / COW | 先共享，写的时候再复制 |
| mmap | Memory-Mapped File | 把文件映射进内存地址空间 |
| swap | Swap | 内存不够时把页换到磁盘 |
| 工作集 | Working Set | 程序近期频繁访问的内存集合 |
| 抖动 | Thrashing | 内存不够导致疯狂换页 |
| 伙伴分配器 | Buddy Allocator | 按 2 的幂管理物理页 |
| slab 分配器 | Slab Allocator | 高效分配固定大小对象 |

### Scheduling / Concurrency

| 中文 | English | 直觉 |
| --- | --- | --- |
| 调度器 | Scheduler | 决定下一个让谁运行 |
| 运行队列 | Run Queue | 等待 CPU 的任务队列 |
| 时间片轮转 | Round Robin | 每个任务轮流跑一小段 |
| 优先级调度 | Priority Scheduling | 优先级高的先跑 |
| 多级反馈队列 | Multilevel Feedback Queue / MLFQ | 用多级队列兼顾响应和公平 |
| 完全公平调度器 | Completely Fair Scheduler / CFS | Linux 的普通任务调度模型 |
| 虚拟运行时间 | Virtual Runtime | CFS 用来衡量“公平”的时间 |
| 饥饿 | Starvation | 某任务一直拿不到资源 |
| 优先级反转 | Priority Inversion | 低优先级任务挡住高优先级任务 |
| 竞态条件 | Race Condition | 并发执行顺序不同导致结果错 |
| 临界区 | Critical Section | 不能被多个线程同时乱进的代码段 |
| 原子性 | Atomicity | 操作不可被中间打断 |
| 可见性 | Visibility | 一个线程的修改另一个线程何时看见 |
| 内存屏障 | Memory Barrier / Fence | 限制 CPU/编译器重排内存操作 |
| 互斥锁 | Mutex | 一次只允许一个线程进入 |
| 自旋锁 | Spinlock | 拿不到锁就一直循环等 |
| 读写锁 | Reader-Writer Lock | 多读可并发，写要独占 |
| 信号量 | Semaphore | 控制同时可进入的数量 |
| 条件变量 | Condition Variable | 等待某个条件发生 |
| futex | Fast Userspace Mutex | Linux 用户态锁和内核等待结合机制 |
| 死锁 | Deadlock | 多方互相等，谁也走不动 |
| 活锁 | Livelock | 一直动但没有进展 |
| 无锁 | Lock-Free | 至少有线程能持续推进 |
| 等待自由 | Wait-Free | 每个线程都能在有限步内完成 |

### Files / I/O / Network / Containers

| 中文 | English | 直觉 |
| --- | --- | --- |
| inode | inode | 文件元数据对象 |
| 目录项 | Directory Entry / Dentry | 名字到 inode 的映射 |
| 硬链接 | Hard Link | 多个名字指向同一个 inode |
| 符号链接 | Symbolic Link / Symlink | 指向路径的特殊文件 |
| 页缓存 | Page Cache | OS 缓存文件内容的内存 |
| 写回 | Writeback | 把缓存中的脏数据写回磁盘 |
| fsync | fsync | 要求数据真正落盘 |
| 原子重命名 | Atomic Rename | rename 要么完成要么没发生 |
| 日志文件系统 | Journaling Filesystem | 先记日志，崩溃后可恢复 |
| 虚拟文件系统 | Virtual Filesystem / VFS | 统一不同文件系统接口 |
| 设备驱动 | Device Driver | OS 和硬件设备之间的适配层 |
| 块设备 | Block Device | 按块读写的设备，比如磁盘 |
| 字符设备 | Character Device | 按字节流交互的设备 |
| DMA | Direct Memory Access | 设备直接读写内存，减少 CPU 搬运 |
| MMIO | Memory-Mapped I/O | 通过内存地址访问设备寄存器 |
| epoll | epoll | Linux 高并发事件通知机制 |
| io_uring | io_uring | Linux 新式异步 I/O 接口 |
| 容器 | Container | 共享内核但隔离进程视图和资源 |
| 命名空间 | Namespace | 隔离进程看到的 pid、网络、挂载等视图 |
| cgroups | Control Groups / cgroups | 限制和统计资源使用 |
| 虚拟机 | Virtual Machine / VM | 模拟一台完整机器 |
| 虚拟化 | Virtualization | 让一个物理机跑多个隔离机器环境 |

## Computer Architecture / 计算机体系结构

### Logic / Representation

| 中文 | English | 直觉 |
| --- | --- | --- |
| 布尔代数 | Boolean Algebra | 用 true/false 做逻辑运算 |
| 真值表 | Truth Table | 列出所有输入下的输出 |
| 组合逻辑 | Combinational Logic | 输出只由当前输入决定 |
| 时序逻辑 | Sequential Logic | 输出还依赖历史状态 |
| 门电路 | Logic Gate | AND/OR/NOT 等基础硬件 |
| 多路选择器 | Multiplexer / MUX | 从多个输入中选一个 |
| 加法器 | Adder | 做二进制加法的电路 |
| 锁存器 | Latch | 存一位状态的电路 |
| 触发器 | Flip-Flop | 按时钟边沿更新状态 |
| 寄存器 | Register | CPU 内部超快小存储 |
| 有限状态机 | Finite State Machine / FSM | 状态和转移组成的机器 |
| 补码 | Two's Complement | 计算机常用有符号整数表示 |
| 溢出 | Overflow | 数值超过能表示的范围 |
| 字节序 | Endianness | 多字节数字在内存中的排列顺序 |
| 小端 | Little-Endian | 低位字节放低地址 |
| 大端 | Big-Endian | 高位字节放低地址 |
| 浮点数 | Floating Point | 近似表示实数 |
| IEEE 754 | IEEE 754 | 浮点数工业标准 |
| 对齐 | Alignment | 数据地址按某个边界摆放 |
| 填充 | Padding | 为对齐插入的空洞 |

### ISA / CPU

| 中文 | English | 直觉 |
| --- | --- | --- |
| 指令集架构 | Instruction Set Architecture / ISA | 软件可见的 CPU 指令契约 |
| 微架构 | Microarchitecture | CPU 内部怎么实现 ISA |
| 汇编 | Assembly | 机器指令的人类可读形式 |
| 机器码 | Machine Code | CPU 直接执行的二进制指令 |
| RISC | Reduced Instruction Set Computer | 指令较简单规整 |
| CISC | Complex Instruction Set Computer | 指令复杂、历史包袱多 |
| x86-64 | x86-64 | 桌面/服务器常见 ISA |
| ARM / AArch64 | ARM / AArch64 | 移动端和新服务器常见 ISA |
| RISC-V | RISC-V | 开放、教学友好的 ISA |
| 程序计数器 | Program Counter / PC | 下一条指令地址 |
| 栈指针 | Stack Pointer / SP | 当前栈顶位置 |
| 帧指针 | Frame Pointer / FP | 当前函数栈帧基准 |
| 调用约定 | Calling Convention | 函数参数、返回值、寄存器怎么约定 |
| 栈帧 | Stack Frame | 一次函数调用占用的栈区域 |
| 调用者保存 | Caller-Saved | 调用函数前由调用者自己保存的寄存器 |
| 被调用者保存 | Callee-Saved | 被调用函数负责恢复的寄存器 |
| 数据通路 | Datapath | 数据在 CPU 组件间怎么流动 |
| 控制单元 | Control Unit | 根据指令产生控制信号 |
| ALU | Arithmetic Logic Unit | 做算术和逻辑运算的单元 |
| 取指 | Fetch | 取下一条指令 |
| 译码 | Decode | 看懂指令要干什么 |
| 执行 | Execute | 真正做运算或地址计算 |
| 写回 | Writeback | 把结果写回寄存器 |

### Pipeline / Cache / Performance

| 中文 | English | 直觉 |
| --- | --- | --- |
| 流水线 | Pipeline | 多条指令分阶段重叠执行 |
| 指令级并行 | Instruction-Level Parallelism / ILP | 同时推进多条指令 |
| 吞吐量 | Throughput | 单位时间完成多少工作 |
| 延迟 | Latency | 单个任务从开始到结束多久 |
| 结构冒险 | Structural Hazard | 硬件资源冲突 |
| 数据冒险 | Data Hazard | 后一条指令依赖前一条结果 |
| 控制冒险 | Control Hazard | 分支导致不知道下一条取哪 |
| 气泡 | Bubble | 流水线里空转的一拍 |
| 转发 | Forwarding / Bypassing | 结果没写回前先直接拿来用 |
| 分支预测 | Branch Prediction | CPU 猜 if/跳转会走哪边 |
| 推测执行 | Speculative Execution | 先按猜测执行，错了再回滚 |
| 乱序执行 | Out-of-Order Execution | CPU 不完全按代码顺序执行指令 |
| 重排序缓冲 | Reorder Buffer / ROB | 保证乱序执行后还能按序提交 |
| 缓存 | Cache | 靠近 CPU 的小而快存储 |
| 缓存行 | Cache Line | cache 每次搬运的固定大小块 |
| 命中 | Cache Hit | 要的数据在 cache 里 |
| 缺失 | Cache Miss | 要的数据不在 cache 里 |
| 时间局部性 | Temporal Locality | 最近用过的东西可能还会用 |
| 空间局部性 | Spatial Locality | 附近的数据可能也会用 |
| 直接映射缓存 | Direct-Mapped Cache | 每个地址只能去一个 cache 位置 |
| 组相联缓存 | Set-Associative Cache | 每个地址可去一组位置 |
| 替换策略 | Replacement Policy | cache 满了踢谁出去 |
| AMAT | Average Memory Access Time | 平均内存访问时间 |
| TLB | Translation Lookaside Buffer | 虚拟地址翻译缓存 |
| CPI | Cycles Per Instruction | 每条指令平均多少周期 |
| IPC | Instructions Per Cycle | 每个周期平均完成多少指令 |
| Amdahl 定律 | Amdahl's Law | 优化一部分程序的总体收益有限 |
| 屋顶线模型 | Roofline Model | 判断程序受算力还是内存带宽限制 |

### Parallel / I/O / Security

| 中文 | English | 直觉 |
| --- | --- | --- |
| SIMD | Single Instruction, Multiple Data | 一条指令处理多份数据 |
| 向量寄存器 | Vector Register | 存多 lane 数据的寄存器 |
| 多核 | Multicore | 一个芯片里多个 CPU 核心 |
| 硬件线程 | Hardware Thread | CPU 硬件支持的并发执行上下文 |
| SMT / 超线程 | Simultaneous Multithreading / Hyper-Threading | 一个核心跑多个硬件线程 |
| 缓存一致性 | Cache Coherence | 多核 cache 对同一内存看法保持一致 |
| MESI | MESI Protocol | 常见缓存一致性协议直觉 |
| 内存一致性模型 | Memory Consistency Model | 多核下内存操作顺序的规则 |
| NUMA | Non-Uniform Memory Access | 不同 CPU 访问不同内存距离不同 |
| GPU | Graphics Processing Unit | 大规模数据并行处理器 |
| SIMT | Single Instruction, Multiple Threads | GPU 的线程执行模型 |
| warp | Warp | GPU 上一组一起调度的线程 |
| 合并访问 | Coalesced Access | GPU 线程访问连续内存以提高效率 |
| 分支发散 | Divergence | GPU 同一组线程走不同分支导致慢 |
| PCIe | PCI Express | CPU 和设备之间的高速总线 |
| NVMe | Non-Volatile Memory Express | 现代 SSD 协议 |
| 描述符环 | Descriptor Ring | 设备和 CPU 交换请求的环形队列 |
| 零拷贝 | Zero-Copy | 减少数据在内核/用户/设备之间复制 |
| 侧信道 | Side Channel | 通过时间、cache 等间接泄露信息 |
| Spectre | Spectre | 利用推测执行泄露信息的一类攻击 |
| Meltdown | Meltdown | 利用乱序/权限检查时序泄露内核信息的一类攻击 |
| 常数时间编程 | Constant-Time Programming | 让耗时不依赖秘密数据 |

## Compilers / 编译器

### Pipeline / Language Design

| 中文 | English | 直觉 |
| --- | --- | --- |
| 源代码 | Source Code | 人写的代码文本 |
| 词法分析 | Lexing / Scanning | 把字符流切成 token |
| 语法分析 | Parsing | 把 token 组织成语法结构 |
| 语法树 | Parse Tree | 按文法完整展开的树 |
| 抽象语法树 | Abstract Syntax Tree / AST | 去掉语法噪声后的代码结构 |
| 语义分析 | Semantic Analysis | 检查名字、作用域、类型、控制流是否合法 |
| 中间表示 | Intermediate Representation / IR | 更适合优化和生成代码的内部表示 |
| 优化 | Optimization | 在保持语义的前提下让代码更好 |
| 代码生成 | Code Generation | 把 IR 变成汇编、机器码或字节码 |
| 字节码 | Bytecode | VM 执行的中间指令 |
| 机器码 | Machine Code | CPU 直接执行的指令 |
| 解释器 | Interpreter | 直接执行源代码/AST/字节码 |
| 编译器 | Compiler | 把一种程序表示翻译成另一种 |
| 转译器 | Transpiler | 把一种高级语言翻译成另一种高级语言 |
| 汇编器 | Assembler | 把汇编变成机器码对象文件 |
| 链接器 | Linker | 把目标文件和库拼成可执行文件 |
| AOT 编译 | Ahead-of-Time Compilation | 运行前编译好 |
| JIT 编译 | Just-in-Time Compilation | 运行时边跑边编译 |
| REPL | Read-Eval-Print Loop | 交互式读入、执行、打印 |

### Lexing / Parsing / AST

| 中文 | English | 直觉 |
| --- | --- | --- |
| token | Token | 词法单元，比如数字、标识符、关键字 |
| 词素 | Lexeme | token 在源码里的原始文本 |
| 字面量 | Literal | 代码中直接写出的值 |
| 关键字 | Keyword | 语言保留词 |
| 标识符 | Identifier | 变量名、函数名等名字 |
| 源码位置 | Source Span / Location | 错误定位用的行列范围 |
| 正则表达式 | Regular Expression / Regex | 描述字符串模式 |
| NFA | Nondeterministic Finite Automaton | 非确定有限自动机 |
| DFA | Deterministic Finite Automaton | 确定有限自动机 |
| 上下文无关文法 | Context-Free Grammar / CFG | 描述递归语法结构的规则 |
| 终结符 | Terminal | 文法里的最终 token |
| 非终结符 | Non-terminal | 文法里的抽象语法类别 |
| 产生式 | Production | 文法规则 |
| 歧义 | Ambiguity | 同一串代码有多种解析方式 |
| 优先级 | Precedence | 运算符先算谁 |
| 结合性 | Associativity | 同级运算符从左还是从右结合 |
| 递归下降解析 | Recursive Descent Parsing | 用函数递归写 parser |
| Pratt 解析器 | Pratt Parser | 很适合表达式优先级的 parser |
| LL 解析 | LL Parsing | 从左到右、自顶向下解析 |
| LR 解析 | LR Parsing | 从左到右、自底向上解析 |
| 错误恢复 | Error Recovery | 解析出错后尽量继续分析 |
| 访问者模式 | Visitor Pattern | 遍历 AST 节点的一种组织方式 |
| 脱糖 | Desugaring | 把语法糖变成更核心的语法 |
| 降级 | Lowering | 把高层表示转换到更低层表示 |

### Semantics / Types / IR

| 中文 | English | 直觉 |
| --- | --- | --- |
| 作用域 | Scope | 名字在哪里可见 |
| 符号表 | Symbol Table | 名字到声明信息的映射 |
| 遮蔽 | Shadowing | 内层名字覆盖外层同名名字 |
| 名字解析 | Name Resolution | 把变量使用绑定到声明 |
| 闭包捕获 | Closure Capture | 函数记住外部变量 |
| 左值 | Lvalue | 能被赋值的位置 |
| 右值 | Rvalue | 被计算出来的值 |
| 静态类型 | Static Typing | 运行前检查类型 |
| 动态类型 | Dynamic Typing | 运行时检查类型 |
| 类型检查 | Type Checking | 判断表达式类型是否符合规则 |
| 类型推断 | Type Inference | 编译器自动推导类型 |
| 名义类型 | Nominal Typing | 按名字判断类型关系 |
| 结构类型 | Structural Typing | 按结构判断类型关系 |
| 子类型 | Subtyping | 一个类型可当作另一个类型用 |
| 多态 | Polymorphism | 同一接口适配多种类型 |
| 泛型 | Generics | 类型参数化 |
| 单态化 | Monomorphization | 泛型为具体类型生成专门代码 |
| 类型擦除 | Type Erasure | 运行时抹掉部分泛型类型信息 |
| SSA | Static Single Assignment | 每个变量只赋值一次的 IR 形式 |
| 基本块 | Basic Block | 无分支进入中间、无分支离开中间的一段指令 |
| 控制流图 | Control-Flow Graph / CFG | 基本块之间的跳转图 |
| phi 节点 | Phi Node | SSA 中合并不同路径变量值 |
| 支配关系 | Dominance | 到某节点是否必须经过另一个节点 |
| 活跃变量分析 | Liveness Analysis | 判断变量之后还会不会被用 |
| 数据流分析 | Dataflow Analysis | 在 CFG 上传播信息直到稳定 |
| 不动点 | Fixed Point | 继续迭代也不再变化的状态 |

### Optimization / Backend / Runtime

| 中文 | English | 直觉 |
| --- | --- | --- |
| 常量折叠 | Constant Folding | 编译期算出常量表达式 |
| 常量传播 | Constant Propagation | 把已知常量传播到使用处 |
| 死代码删除 | Dead Code Elimination / DCE | 删除不会影响结果的代码 |
| 公共子表达式消除 | Common Subexpression Elimination / CSE | 重复计算只算一次 |
| 循环不变量外提 | Loop-Invariant Code Motion / LICM | 循环里不变的计算移到循环外 |
| 内联 | Inlining | 把函数调用展开到调用处 |
| 逃逸分析 | Escape Analysis | 判断对象是否会逃出当前作用域 |
| 去虚拟化 | Devirtualization | 把动态派发变成直接调用 |
| 指令选择 | Instruction Selection | 选择目标机器指令 |
| 寄存器分配 | Register Allocation | 决定变量放哪些物理寄存器 |
| 线性扫描分配 | Linear Scan Allocation | 快速寄存器分配算法 |
| 图着色分配 | Graph Coloring Allocation | 把寄存器分配建模成图着色 |
| 指令调度 | Instruction Scheduling | 调整指令顺序以适配流水线 |
| 窥孔优化 | Peephole Optimization | 局部小窗口替换更好指令 |
| 对象文件 | Object File | 编译后的中间二进制文件 |
| 重定位 | Relocation | 链接时修正地址 |
| 符号 | Symbol | 函数或变量在目标文件中的名字记录 |
| 动态链接 | Dynamic Linking | 程序运行时加载共享库 |
| 调用栈 | Call Stack | 函数调用层层叠起来的运行结构 |
| 活动记录 | Activation Record | 一次函数调用的运行记录 |
| 对象布局 | Object Layout | 对象字段和元数据在内存中怎么摆 |
| 虚表 | Vtable | 动态派发方法查找表 |
| 装箱 | Boxing | 把原始值包装成对象 |
| 拆箱 | Unboxing | 从对象取回原始值 |
| 标记联合 | Tagged Union | 用标签记录当前值是哪种类型 |
| 字符串驻留 | String Interning | 相同字符串共享一份对象 |

### VM / GC / JIT / Tooling

| 中文 | English | 直觉 |
| --- | --- | --- |
| 栈式虚拟机 | Stack VM | 指令主要操作栈顶数据 |
| 寄存器虚拟机 | Register VM | 指令操作虚拟寄存器 |
| 操作码 | Opcode | 字节码指令类型 |
| 操作数 | Operand | 指令携带的参数 |
| 常量池 | Constant Pool | 字节码里集中存常量的区域 |
| 反汇编器 | Disassembler | 把字节码或机器码转成人可读形式 |
| 原生函数绑定 | Native Function Binding | VM 调用宿主语言函数 |
| 垃圾回收 | Garbage Collection / GC | 自动回收不再使用的对象 |
| 引用计数 | Reference Counting | 记录对象被引用次数 |
| 跟踪式 GC | Tracing GC | 从根对象出发找可达对象 |
| 标记清扫 | Mark-Sweep | 先标记活对象，再清理死对象 |
| 三色标记 | Tri-Color Marking | GC 标记过程的三类对象模型 |
| 根集合 | Root Set | GC 遍历的起点 |
| 移动式 GC | Moving GC | 回收时移动对象以整理内存 |
| 分代 GC | Generational GC | 按对象年龄分区回收 |
| 写屏障 | Write Barrier | 赋值时通知 GC 的机制 |
| 基线 JIT | Baseline JIT | 快速生成还不太优化的机器码 |
| 跟踪 JIT | Tracing JIT | 优化热路径 trace |
| 分层编译 | Tiered Compilation | 解释器、基线 JIT、优化 JIT 逐级升级 |
| 栈上替换 | On-Stack Replacement / OSR | 正在运行的函数切换到优化代码 |
| 去优化 | Deoptimization | 假设失效时退回安全版本 |
| 内联缓存 | Inline Cache | 缓存动态派发/属性查找结果 |
| 隐藏类 | Hidden Class / Shape | 动态语言对象结构的内部表示 |
| 诊断信息 | Diagnostics | 编译器给用户的错误/警告反馈 |
| golden test | Golden Test | 输出和标准答案文件对比 |
| 快照测试 | Snapshot Test | 对结构化输出保存快照后对比 |
| 差分测试 | Differential Testing | 和另一个实现对比结果 |
| 模糊测试 | Fuzzing | 随机生成输入找 bug |

## Frequently Confused Pairs

| 中文对照 | English Pair | 差异 |
| --- | --- | --- |
| 函数调用 vs 系统调用 | Function Call vs Syscall | 函数调用还在用户态；syscall 要进入内核态 |
| 陷入 vs 中断 vs 异常 | Trap vs Interrupt vs Exception | trap 是进入内核的统称；interrupt 常来自外部设备；exception 常来自当前指令 |
| 进程 vs 线程 | Process vs Thread | 进程是资源容器；线程是执行流 |
| 并发 vs 并行 | Concurrency vs Parallelism | 并发是处理多个任务的结构；并行是真的同时执行 |
| 虚拟地址 vs 物理地址 | Virtual Address vs Physical Address | 程序看到虚拟地址；硬件内存用物理地址 |
| cache miss vs page fault | Cache Miss vs Page Fault | cache miss 是硬件缓存没命中；page fault 是虚拟内存映射/权限/驻留问题 |
| 栈 vs 堆 | Stack vs Heap | 栈跟函数调用走；堆用于动态分配对象 |
| API vs ABI vs ISA | API vs ABI vs ISA | API 是源码层接口；ABI 是二进制调用约定；ISA 是 CPU 指令契约 |
| 解释器 vs 编译器 | Interpreter vs Compiler | 解释器直接执行表示；编译器把表示翻译成另一种表示 |
| AST vs IR vs 字节码 | AST vs IR vs Bytecode | AST 像源码结构；IR 适合分析优化；字节码适合 VM 执行 |
| 机器码 vs 汇编 | Machine Code vs Assembly | 机器码是二进制；汇编是人类可读文本形式 |
| 复杂度 vs benchmark vs profiling | Complexity vs Benchmark vs Profiling | 复杂度看增长趋势；benchmark 测实际耗时；profiling 找热点 |
| mutex vs semaphore | Mutex vs Semaphore | mutex 管互斥；semaphore 管资源数量 |
| condition variable vs event | Condition Variable vs Event | 条件变量等待共享状态变化；event 更像一次通知信号 |
| B-tree vs B+ tree | B-tree vs B+ Tree | B-tree 内部节点也可存数据；B+ tree 数据主要在叶子，范围查询更友好 |
| static typing vs dynamic typing | Static Typing vs Dynamic Typing | 静态类型运行前查；动态类型运行时查 |
| codegen vs runtime | Code Generation vs Runtime | codegen 生成可执行表示；runtime 支撑程序运行行为 |

## Minimal Term Learning Order

如果名词太多，先只记这一条线：

```text
Data Structure / Algorithm / Complexity / Invariant / Test
-> Process / Syscall / Virtual Memory / File Descriptor / Thread
-> ISA / Assembly / Register / Cache / Pipeline
-> Token / AST / IR / Bytecode / Runtime
```

对应中文：

```text
数据结构 / 算法 / 复杂度 / 不变量 / 测试
-> 进程 / 系统调用 / 虚拟内存 / 文件描述符 / 线程
-> 指令集 / 汇编 / 寄存器 / 缓存 / 流水线
-> 词法单元 / 抽象语法树 / 中间表示 / 字节码 / 运行时
```
