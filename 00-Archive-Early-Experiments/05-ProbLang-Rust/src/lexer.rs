#[derive(Debug, PartialEq, Clone)]
pub enum Token {
    PredictIf,            
    Let,                  
    Identifier(String),
    Number(f64),
    Assign,               
    Plus,                 
    Minus,                
    Asterisk,             
    Slash,                
    Semicolon,            
    LBrace, RBrace, LParen, RParen, EOF,
}

pub struct Lexer {
    input: Vec<char>,
    position: usize,
}

impl Lexer {
    pub fn new(input: &str) -> Self {
        Lexer { input: input.chars().collect(), position: 0 }
    }

    // 智能升级：不仅仅是跳过空格，还能识别并跳过双斜杠 `//` 行注释！
    fn skip_whitespace(&mut self) {
        loop {
            // 跳过普通的空格、回车
            while self.position < self.input.len() && self.input[self.position].is_whitespace() {
                self.position += 1;
            }
            
            // 预测式向下偷瞄：如果连续遇到两个 '/'，这就是注释
            if self.position + 1 < self.input.len() && self.input[self.position] == '/' && self.input[self.position+1] == '/' {
                // 疯狂吃掉这一排的字符，直到碰见回车换行符
                while self.position < self.input.len() && self.input[self.position] != '\n' {
                    self.position += 1;
                }
                // 然后重头再来（防止好几行连着的注释）
                continue;
            }
            break; // 如果既没有空格也没有注释，安全退出
        }
    }

    fn read_identifier(&mut self) -> Token {
        let start_pos = self.position;
        while self.position < self.input.len() && (self.input[self.position].is_alphanumeric() || self.input[self.position] == '_') {
            self.position += 1;
        }
        let text: String = self.input[start_pos..self.position].iter().collect();
        match text.as_str() {
            "predictive_if" => Token::PredictIf,
            "let" => Token::Let,
            _ => Token::Identifier(text),
        }
    }

    fn read_number(&mut self) -> Token {
        let start_pos = self.position;
        while self.position < self.input.len() && (self.input[self.position].is_numeric() || self.input[self.position] == '.') {
            self.position += 1;
        }
        let num_str: String = self.input[start_pos..self.position].iter().collect();
        Token::Number(num_str.parse::<f64>().unwrap_or(0.0)) 
    }

    pub fn next_token(&mut self) -> Token {
        self.skip_whitespace();
        if self.position >= self.input.len() { return Token::EOF; }

        let current_char = self.input[self.position];
        if current_char.is_alphabetic() { return self.read_identifier(); } 
        if current_char.is_numeric() { return self.read_number(); }

        self.position += 1;
        match current_char {
            '=' => Token::Assign,
            '+' => Token::Plus,
            '-' => Token::Minus,
            '*' => Token::Asterisk,
            '/' => Token::Slash,
            ';' => Token::Semicolon,
            '{' => Token::LBrace, '}' => Token::RBrace,
            '(' => Token::LParen, ')' => Token::RParen,
            _ => panic!("🚨 外星文: {}", current_char),
        }
    }
}
