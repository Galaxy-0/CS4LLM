#include <stdio.h>
#include <stdlib.h> // 需要用到这个库里的 malloc 和 free 来向操作系统借/还内存

// 第一步：我们来定义一节“火车车厢”长什么样
struct TrainCar {
    int passenger_count;       // 1. 这节车厢装了多少人 (我们要存的真实数据)
    struct TrainCar* next_car; // 2. 连接下一节车厢的挂钩 (这是一个指向别的火车的指针/内存地址)
};

int main() {
    printf("===== 小白的内存组装工厂：手搓单向链表 =====\n");
    
    // 第二步：向系统伸手要内存 (动态内存分配)
    // malloc 的意思就是 "Memory Allocation"，我们求操作系统施舍一块刚好能装下一节车厢的内存地皮。
    // 返回回来的是这块地皮在计算机里的起始地址。
    struct TrainCar* engine = (struct TrainCar*)malloc(sizeof(struct TrainCar));
    engine->passenger_count = 100; // 火车头坐了 100 人
    engine->next_car = NULL;       // 刚出厂，车尾还没挂接任何车厢（千万记住：一定要设为NULL，不然它会瞎指）
    
    printf("1. 火车头造好了！装了 %d 人，停靠在地址：%p\n", engine->passenger_count, (void*)engine);
    
    // 第三步：再向系统要一块内存造第二节车厢
    struct TrainCar* car_1 = (struct TrainCar*)malloc(sizeof(struct TrainCar));
    car_1->passenger_count = 50;   // 这节车厢坐了 50 人
    car_1->next_car = NULL;
    printf("2. 1号普通车厢造好了！装了 %d 人，停靠在地址：%p\n", car_1->passenger_count, (void*)car_1);
    
    // 第四步：这是整个单向链表的核心——把车厢挂到火车头后面！
    engine->next_car = car_1;
    printf("3. 咔哒！挂接成功。火车头挂着的第一节车厢停靠在：%p\n", (void*)engine->next_car);
    
    // 第五步：乘务员开始检票 (循环遍历链表)
    // 只要我抓住车头，我就能顺藤摸瓜找到所有车厢，哪怕它们在内存里是东一块西一块乱放的！
    printf("\n>> 开始顺藤摸瓜检票：\n");
    struct TrainCar* current_car = engine; // 乘务员站在火车头上
    int rank = 0;
    
    // 只要有当前车厢 (不是空地址 NULL)，乘务员就继续走
    while(current_car != NULL) {
        printf("   第 %d 节车厢停靠在 %p 处，检票人数：%d\n", rank, (void*)current_car, current_car->passenger_count);
        // 关键动作：乘务员顺着地上的挂钩，走到下一节车厢去
        current_car = current_car->next_car; 
        rank++;
    }
    
    // 第六步：有借有还，再借不难！
    // 刚刚用 malloc 借来的地皮，用完了必须用 free 主动还给操作系统。
    // 假设你是一个永远不关机的服务后台，你借了不还，内存越吃越多，这叫【内存泄漏 Memory Leak】，最终死机。
    printf("\n>> 列车解体，把地皮退还给操作系统：\n");
    free(car_1);  // 记得：哪块被申请了，那块的地址就必须得被 free()
    free(engine);
    
    printf("完美杀青！没有发生内存泄漏。\n");
    return 0;
}
