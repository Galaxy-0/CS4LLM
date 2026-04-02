#include <stdio.h>
#include <stdlib.h>

// 还是刚才的“火车厢”（节点）
struct Node {
    int val;
    struct Node* next;
};

// 这是一个极其经典的【高级扫地僧】操作：原地反转链表
// 也就是在不申请新内存的前提下，把 1->2->3->4->5 的火车，瞬间掉头变成 5->4->3->2->1。
// 它是检验你是否真正掌控了内存地址的终极考题。
struct Node* reverseList(struct Node* head) {
    // 我们需要三个变量来玩“丢沙包”游戏，否则线索一断，后面的车厢就全弄丢了（内存泄漏警告！）
    struct Node* prev = NULL;    // 前一节车厢（初始是空，因为反转后，原本第一节的车尾要指向 NULL）
    struct Node* curr = head;    // 当前正在操作的车厢
    struct Node* next_temp = NULL; // 这是一个临时锚点，用来记住下一节车厢在哪

    while (curr != NULL) {
        // 第一步：先用小本本(临时指针)记下下一节车厢的地址，不然一会儿挂钩断了就真找不到了！
        next_temp = curr->next; 
        
        // 第二步：核心动作！把当前车厢的挂钩，暴力扯断，直接反过头来挂在前面的车厢上
        curr->next = prev;
        
        // 第三步：指针集体往前走一步，开始处理下一节车厢
        prev = curr;       // prev 往前挪
        curr = next_temp;  // curr 往前挪（多亏了第一步记下了地址！）
    }
    
    // 循环结束后，curr 变成了 NULL（走到头了），那这个时候 prev 刚好停在了原先最后一节车厢上。
    // 这节车厢，就是我们新火车的“火车头”！
    return prev;
}

// 辅助函数：快速打印整列火车
void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("[%d|%p] -> ", curr->val, (void*)curr->next);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    printf("===== 高级挑战：脑力体操之『反转链表』 =====\n\n");
    
    // 1. 造一列长为 5 的火车 (1->2->3->4->5) 
    // 这里为了快，暴力手动分配，大厂里这通常是用循环做的。
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));
    
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 3; n3->next = n4;
    n4->val = 4; n4->next = n5;
    n5->val = 5; n5->next = NULL;
    
    printf(">> 发车前，原始列车的挂靠状态 (车头是1)：\n");
    printList(n1);
    
    // 2. 施展魔法：原地反转！
    printf("\n>> 开始施展内存魔法，不借用任何新地皮...\n");
    struct Node* new_head = reverseList(n1);
    
    // 3. 打印反转后的奇迹
    printf("\n>> 魔法完成！现在的挂靠状态 (车头变成了5)：\n");
    printList(new_head);
    
    // 4. 打扫战场 (释放内存)
    free(n1); free(n2); free(n3); free(n4); free(n5);
    return 0;
}
