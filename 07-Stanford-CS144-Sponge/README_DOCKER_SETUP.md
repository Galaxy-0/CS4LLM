# Stanford CS144 (Sponge/Minnow) 终极物理连网测试环境破壁指南

> “没测试学个蛋” —— 谨记，没有自动化评测脚本的代码，只能配叫玩具。

由于咱们用的是 Mac (物理机)，而斯坦福的打分脚本（测试 TCP 协议栈）强行依赖了 Linux 独占的最底层 **TUN/TAP 虚拟网卡接口** 和 **环境隔离 (Network Namespaces)**。如果直接在 Mac 上 `make test`，不仅跑不起来，还可能把本机的网络内存搞崩。

所以，我们需要用 Docker 特权挂载破壁！

## 🚀 极其暴力的 Docker 挂载评测大法 (0 成本搭建)

无需忍受臃肿的 VMware/VirtualBox 虚拟机，直接让 Mac 充当编辑器，后台跑 Linux 实战沙盒：

1. 打开你 Mac 终端上的 Docker Desktop（确保后台启动）。
2. 在这个 `07-Stanford-CS144-Sponge` 目录下打开终端，敲入这行启动虫洞：
```bash
# --privileged 给权限，强行击穿容器沙盒，获取创建底层虚拟网卡 /dev/net/tun 的神权
docker run -it --privileged \
  -v $(pwd):/workspace \
  ubuntu:22.04 /bin/bash
```

## ⚔️ 进沙盒后，环境一键装载
进入这个属于你的专属 Linux 黑盒后，敲下这行命令，让斯坦福的全套依赖全部归位：
```bash
apt-get update && apt-get install -y \
  build-essential cmake g++ gdb pcaputils \
  libpcap-dev libssl-dev iptables iproute2 tcpdump
```

## 🔥 终极快感：享受大浪淘沙的报错瀑布
准备就绪后，直接进入代码构建池，启动那个包含了几万种极端并发测试的恶魔脚本：
```bash
cd /workspace
mkdir -p build && cd build
cmake ..
make -j4
# 一锤定音：
make check
```

如果在这满屏的红灯里，你能在一周内把它刷到全绿（PASS），你写出来的这个 TCP 协议栈，就是**真正能够连接上中国电信/联通的物理宽带，并在全世界互联网上进行文件收发的硬核代码！**
