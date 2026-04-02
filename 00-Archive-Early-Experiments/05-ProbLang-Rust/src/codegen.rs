use crate::ast::{Program, Stmt, Expr};
use std::fs::File;
use std::io::Write;
use std::process::Command;

// 这就是最神秘的“编译器最后一道防线”：代码生成器 (Code Generator / Backend)
// 它是一个极其冷酷的翻译官，负责爬上那棵完美组合好的 AST 树。
// 把它死板、不打折扣地翻译成底层强悍的 C 语言与系统调用，最后压成机器码！
pub struct CodeGenerator {
    output: String,
}

impl CodeGenerator {
    pub fn new() -> Self {
        // 第一步：强行在生成的物理文件中，嵌入操作系统的底层头文件与随机引擎
        let boilerplate = r#"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// 【绝密黑盒】当用户的 ProbLang 代码出现 predictive_if 时，编译器会自动插入这段汇编级伪随机代码
int evaluate_predictive_if(double probability) {
    static int seeded = 0;
    if (!seeded) { 
        // 疯狂截取底层硬件主板上极高精度的微秒级震荡，作为乱序熵核心
        struct timeval time; 
        gettimeofday(&time,NULL);
        srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
        seeded = 1; 
    }
    double roll = (double)rand() / (double)RAND_MAX;
    return roll < probability;
}

int main() {
    printf("==========================================\n");
    printf(">> [这是孤立无援的硅基机器] ProbLang 物理目标程序已在此硬件成功启动...\n");
    printf("==========================================\n\n");
"#;
        CodeGenerator {
            output: boilerplate.to_string(),
        }
    }

    // 这是一条在生命之树上游弋的毒蛇，爬遍每一个节点
    pub fn generate(&mut self, program: &Program) -> String {
        for stmt in &program.statements {
            self.generate_statement(stmt, 1);
        }
        self.output.push_str("\n    return 0;\n}\n");
        self.output.clone()
    }

    fn generate_statement(&mut self, stmt: &Stmt, indent: usize) {
        let prefix = "    ".repeat(indent);
        match stmt {
            // 当翻译官看到你创造的 Let 树枝时，它翻译成了底层的 C 语言内存分配指令 `double xxx = xxx;`
            Stmt::Let { name, value } => {
                let expr_c_code = self.generate_expression(value);
                self.output.push_str(&format!("{}double {} = {};\n", prefix, name, expr_c_code));
                
                // 为了让你直观看到它跑了，编译器再送你一句底层的打印
                self.output.push_str(&format!("{}printf(\">> [内存分配探针] 硬盘变量名 \\\"{}\\\" 成功在硅片上分配内存，值为: %f\\n\", {});\n", prefix, name, name));
            },
            
            // 当编译器看到你的伟大神迹 PredictiveIf 树干时：
            Stmt::PredictiveIf { probability, consequence } => {
                self.output.push_str(&format!("{}if (evaluate_predictive_if({})) {{\n", prefix, probability));
                self.output.push_str(&format!("{}    printf(\"   🚨 [核爆预警探针] 极小概率物理支线发生了坍缩！世界线发生了跳跃！大括号内部逻辑解锁执行！\\n\");\n", prefix));
                
                // 疯狂递归下潜：看看大括号里面还有什么逻辑，继续降维翻译
                for cons_stmt in consequence {
                    self.generate_statement(cons_stmt, indent + 1);
                }
                self.output.push_str(&format!("{}}}\n", prefix));
            },
            
            Stmt::Expression(expr) => {
                if let Expr::Identifier(name) = expr {
                     self.output.push_str(&format!("{}printf(\"   💥 [致命进程调用] 执行最终物理动作：%s\\n\", \"{}\");\n", prefix, name));
                } else {
                     self.output.push_str(&format!("{};\n", self.generate_expression(expr)));
                }
            }
        }
    }

    // 严苛保证加减乘除结合律（完美转换出带着精确括号的 C 语言）
    fn generate_expression(&self, expr: &Expr) -> String {
        match expr {
            Expr::Number(val) => val.to_string(),
            Expr::Identifier(name) => name.clone(),
            Expr::Infix { left, operator, right } => {
                format!("({} {} {})", self.generate_expression(left), operator, self.generate_expression(right))
            }
        }
    }

    // 终极绝杀制导：召唤操作系统的黑暗骑士 GCC，强行进行不可逆转的机器码打桩融合
    pub fn compile_to_binary(&self, output_filename: &str) {
        let c_file = format!("{}.c", output_filename);
        let mut file = File::create(&c_file).expect("🚨【宕机】无法在硬盘创建 C 语言中间图纸");
        file.write_all(self.output.as_bytes()).expect("🚨【宕机】硬盘写入惨败");

        println!(">> 正在唤醒 Mac 底层恶龙 GCC/Clang，强行融合生成不可逆的绝对机器码...");
        
        // 我们在 Rust 里操控了操作系统的底层终端
        let status = Command::new("gcc")
            .arg(&c_file)
            .arg("-o")
            .arg(output_filename)
            .status()
            .expect("🚨【宕机】找不到系统的 GCC 编译器模块！");

        if status.success() {
            println!(">> 🌟 融合碾压成功！无坚不摧的物理执行程序 {} 已经诞生。", output_filename);
            // 阅后即焚，不留翻译过的痕迹，只留下最纯粹的二进制文件
            std::fs::remove_file(&c_file).unwrap();
        } else {
            panic!("底层汇编链接彻底失败！");
        }
    }
}
