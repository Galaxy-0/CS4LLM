#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[2048] = {0}; // 用来装浏览器发来的 HTTP 报文
    
    // 我们亲自伪造一段极简的、符合 HTTP 1.1 协议退层规范的响应报文
    // 只有严格按照这个格式（包含俩换行 \r\n\r\n），浏览器才会认你！
    char *http_response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Server: CS4LLM-BareMetal-C-Server\r\n"
        "\r\n"
        "<html>"
        "<body style='background-color:#1e1e1e; color:#00ff00; font-family:monospace; text-align:center; padding-top:100px;'>"
        "<h1>🚀 Hello from CS4LLM Custom C Server!</h1>"
        "<p>这是你亲手用 C 语言 Socket 从操作系统网卡里捞出来的数据！</p>"
        "<p>脱离了 Tomcat / Nginx 等高级组件，体会降维打击的快乐。</p>"
        "</body>"
        "</html>";
    
    // 1. 系统调用：向操作系统要一个 Socket (插座/套接字) 句柄。
    // AF_INET 代表 IPv4, SOCK_STREAM 代表 TCP 协议的可靠传输。
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket 申请失败"); exit(EXIT_FAILURE);
    }
    
    // 强制复用端口（防止你刚才重启程序时，操作系统说 8080 端口还没释放被占用）
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // 2. 配置我们到底要监听哪台机器的哪个端口
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // 监听所有网卡上的请求
    address.sin_port = htons(PORT);       // 端口我们要用 htons 转成底层的网络字节序 (大端序)
    
    // 3. 系统调用：将刚才的 Socket 铁插座，死死绑定在电脑的 8080 端口上
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("端口绑定失败"); exit(EXIT_FAILURE);
    }
    
    // 4. 监听：开启大门，允许同时最多 3 个人在门口排队
    if (listen(server_fd, 3) < 0) {
        perror("监听失败"); exit(EXIT_FAILURE);
    }
    
    printf("🟢 [底层 C 语言 TCP 服务器] 启动成功！正在监听端口 %d...\n", PORT);
    printf("   (现在它卡住了，正在死死盯着操作系统的网卡，等待任何经过 8080 端口的流量)\n\n");
    
    // 5. 阻塞等待：accept() 会卡住整个程序，直到有一个客户端(比如浏览器)真的连上来了！
    // 连上后，操作系统会返回一个【全新的专属插座 new_socket】来专门跟这一个人通讯。
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("接收连接失败"); exit(EXIT_FAILURE);
    }
    
    // 6. 只要程序走到这里，说明有人连进来了！立马读取他发了什么？
    read(new_socket, buffer, 2048);
    printf("=========================================\n");
    printf("🚨 绝密截获！我们抓到了浏览器发来的原生 HTTP 请求报文：\n\n");
    printf("%s", buffer);
    printf("=========================================\n\n");
    
    // 7. 发送我们拼接好的报文给那个客户端
    send(new_socket, http_response, strlen(http_response), 0);
    printf("✅ 我们已经成功把伪造的网页数据塞进了网卡，发送出去了！\n");
    
    // 8. 渣男行为：发完就断开连接（严格的 HTTP/1.0 短连接标准）
    close(new_socket);
    close(server_fd);
    printf("🔌 拔掉网线插座，服务器安全退出。\n");
    
    return 0;
}
