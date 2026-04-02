# Stanford CS143 (COOL Compiler) 上古底层测试环境复活指南

> 编译出 AST 和指令只是大一水平，只有让它在 MIPS 底层模拟器上能跑出正确结果，才是大厂级编译器！

斯坦福由于防作弊，要求所有的汇编指令必须放到几十年前极其骨灰级的 **SPIM (MIPS 物理架构指令模拟器)** 上跑。你的 Mac （M芯片的 ARM64 架构）根本无法向下兼容运行他们的打分系统。

## 🚀 Docker 傻瓜级一键唤醒大法

全球的顶级黑客早就不惯着官方的傲慢了，他们直接把包含了 SPIM 引擎的 Linux 镜像封装打包。你只需要在你的 `10-Stanford-CS143-Compiler` 目录下敲这一句：

```bash
docker run -it -v $(pwd):/app angusshire/cs143-env /bin/bash
```

## ⚔️ 开始接受最残忍的 Semantic Check (语义报错)
进了上面那个容器后，这就像是你的 Mac 上多了一个异次元的空间：
1. 你在原生的 VS Code 或者 Cursor 里舒服地修改你的 `.cpp` 编译器代码。
2. 切回终端里的 Docker 会话，直接输入：
```bash
cd /app/assignments/PA1
make test
```
此时，镜像里的 SPIM 模拟引擎、Flex/Bison 神级词法解析器会全部启动，拿到你的代码骨架，并试图拿几百个包含了恶意继承、极其变态死循环的 `bad.cl` 源码文件，去轰炸你的编译器内核！

每一次红屏（Error），就是一次在编译原理地缝中找底层 Bug 的历劫！当你刷满绿灯，这份汇编生成器的含金量，不可估量。
