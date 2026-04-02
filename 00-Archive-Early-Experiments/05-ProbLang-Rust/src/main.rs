mod lexer;
mod ast;
mod parser;
mod codegen;

use lexer::Lexer;
use parser::Parser;
use codegen::CodeGenerator;
use std::env;
use std::fs;

fn main() {
    println!("============================================================");
    println!("🦅 觉醒时刻：ProbLang 正式进化为真实的命令行编译工具！");
    println!("============================================================");

    // 【质变时刻】：不再使用程序内部写死的字符串，而是像纯正的 GCC/Javac 一样去通过终端指令读取外部文件！
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("🔥 致命错误：你怎么没给编译器传代码？");
        eprintln!("用法举例: problang <你的源文件.prob>");
        std::process::exit(1);
    }

    let source_file_path = &args[1];
    println!(">> 收到指令：准备剥离并载入物理文件 [{}]", source_file_path);

    // 严酷的文件读取（直接从硬盘里生抽源码文本）
    let raw_source_code = fs::read_to_string(source_file_path)
        .expect("🔥 致命错误：文件读取惨痛失败（有可能文件不存在）！");

    println!("------------------ [文件源码载入成功] ----------------------");
    println!("{}", raw_source_code);
    println!("------------------------------------------------------------");

    // 老规矩，送上手术台进行流水线加工
    let scan_engine = Lexer::new(&raw_source_code);
    let mut ast_builder = Parser::new(scan_engine);
    let the_ast_tree = ast_builder.parse_program();

    // 根据文件名动动手脚，比如输入 "game_logic.prob" ，我们就输出可执行文件 "game_logic"
    let output_binary_name = source_file_path.replace(".prob", "");
    
    let mut backend_generator = CodeGenerator::new();
    backend_generator.generate(&the_ast_tree);
    backend_generator.compile_to_binary(&output_binary_name);
    
    println!("------------------------------------------------------------");
    println!(">>> 【编译器退场】物理硬件级的独立机器程序 `{}` 现已生成！", output_binary_name);
}
