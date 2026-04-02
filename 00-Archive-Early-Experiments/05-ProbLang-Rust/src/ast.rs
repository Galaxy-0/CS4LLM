#[derive(Debug, Clone)]
pub enum Expr {
    Identifier(String),
    Number(f64),
    // 伟大的诞生：双向挂靠的二叉算术树杈 (Infix)
    // 比如 2 * 3，left 挂着 2，operator 是 *，right 挂着 3。
    // 为了防止无限嵌套撑爆 Rust 的内存，我们在枝干处加了高级的 Box（堆内存智能指针）
    Infix {
        left: Box<Expr>,
        operator: String,  
        right: Box<Expr>,
    }
}

#[derive(Debug, Clone)]
pub enum Stmt {
    // 全新的变量声明语句节点：统管诸如 `let x = 1 + 2 * 3;` 
    Let {
        name: String,      // 变量名叫啥 (x)
        value: Expr,       // 等号右边挂着的极其庞大的算术运算树
    },
    
    PredictiveIf {
        probability: f64,
        consequence: Vec<Stmt>,
    },
    
    Expression(Expr),
}

#[derive(Debug, Clone)]
pub struct Program {
    pub statements: Vec<Stmt>,
}
