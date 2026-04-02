// 03_assembly_demo.c
// 这是一个极其简单的 C 语言程序，我们故意不写复杂的逻辑
// 目的只是为了看看它脱掉 C 语言的“外衣”后，底层长什么样。

int add(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int result = add(3, 4);
    return result;
}
