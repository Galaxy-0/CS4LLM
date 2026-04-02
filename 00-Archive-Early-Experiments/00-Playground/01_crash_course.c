#include <stdio.h>

int main() {
    printf("===== 欢迎来到小白的新手村 =====\n");
    printf(">> 1. 正常操作：我们在栈上放了一个变量...\n");
    
    int age = 1; // 代表我们刚出生（第一天学习）
    int* ptr = &age; // 指针 ptr 指向了 age 所在的内存地址
    printf("      我们刚满 %d 岁，当前这个岁数存放在内存地址： %p\n", *ptr, (void*)ptr);
    
    printf("\n>> 2. 开始作死 (主动犯错)：\n");
    printf("      既然有了指针，那就相当于有了一把能随便去别人家串门的万能钥匙。\n");
    printf("      如果我强行去系统的 0x0 地址（黑洞）写东西会怎样？...\n");
    printf("      准备执行：*bad_ptr = 100; \n");
    
    int* bad_ptr = NULL; 
    *bad_ptr = 100; // 这行绝对会引起大名鼎鼎的 Segmentation fault (段错误)
    
    // 下面这行永远不会被执行到，因为程序在上一行就被操作系统强行“击毙”了
    printf("\n>> 3. 如果你能看到这行字，说明计算机底层逻辑出问题了！\n");
    
    return 0;
}
