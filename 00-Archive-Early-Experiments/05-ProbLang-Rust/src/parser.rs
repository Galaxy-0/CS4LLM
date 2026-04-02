use crate::lexer::{Lexer, Token};
use crate::ast::{Program, Stmt, Expr};

pub struct Parser {
    lexer: Lexer,
    current_token: Token,
    peek_token: Token,
}

impl Parser {
    pub fn new(mut lexer: Lexer) -> Self {
        let current_token = lexer.next_token();
        let peek_token = lexer.next_token();
        Parser { lexer, current_token, peek_token }
    }

    fn next_token(&mut self) {
        self.current_token = self.peek_token.clone();
        self.peek_token = self.lexer.next_token();
    }

    fn get_precedence(&self, token: &Token) -> u8 {
        match token {
            Token::Plus | Token::Minus => 10,
            Token::Asterisk | Token::Slash => 20,
            _ => 0,
        }
    }

    pub fn parse_program(&mut self) -> Program {
        let mut program = Program { statements: Vec::new() };
        while self.current_token != Token::EOF {
            if let Some(stmt) = self.parse_statement() {
                program.statements.push(stmt);
            }
        }
        program
    }

    fn parse_statement(&mut self) -> Option<Stmt> {
        match self.current_token {
            Token::Let => self.parse_let_statement(),       
            Token::PredictIf => self.parse_predictive_if(), 
            _ => self.parse_expression_statement(),         
        }
    }

    fn parse_let_statement(&mut self) -> Option<Stmt> {
        self.next_token(); 
        
        let name = match &self.current_token {
            Token::Identifier(n) => n.clone(),
            _ => panic!("语法炸裂：let 后面没跟变量名"),
        };
        self.next_token();
        
        if self.current_token != Token::Assign { panic!("语法炸裂：期望一个 = 号！"); }
        self.next_token(); 
        
        let value = self.parse_expression(0);
        
        if self.current_token == Token::Semicolon {
            self.next_token(); 
        }
        Some(Stmt::Let { name, value })
    }

    fn parse_expression(&mut self, precedence: u8) -> Expr {
        let mut left = match &self.current_token {
            Token::Identifier(name) => {
                let expr = Expr::Identifier(name.clone());
                self.next_token();
                expr
            },
            Token::Number(val) => {
                let expr = Expr::Number(*val);
                self.next_token();
                expr
            },
            _ => panic!("算术系统炸裂，无效表达式起始：{:?}", self.current_token),
        };

        while self.current_token != Token::EOF && self.current_token != Token::Semicolon && precedence < self.get_precedence(&self.current_token) {
            let operator = match self.current_token {
                Token::Plus => "+",
                Token::Minus => "-",
                Token::Asterisk => "*",
                Token::Slash => "/",
                _ => break,
            }.to_string();
            
            let cur_prec = self.get_precedence(&self.current_token);
            self.next_token(); 
            
            let right = self.parse_expression(cur_prec);
            
            left = Expr::Infix {
                left: Box::new(left),
                operator,
                right: Box::new(right)
            };
        }
        left
    }

    fn parse_predictive_if(&mut self) -> Option<Stmt> {
        self.next_token(); 
        if self.current_token != Token::LParen { panic!("语法报错：期望 '(' {:?}", self.current_token); }
        self.next_token(); 
        let prob = match &self.current_token {
            Token::Number(n) => *n,
            _ => panic!("语法报错：期望概率数字"),
        };
        self.next_token(); 
        if self.current_token != Token::RParen { panic!("语法报错：期望 ')'"); }
        self.next_token(); 
        if self.current_token != Token::LBrace { panic!("语法报错：期望 '{{'"); }
        self.next_token(); 
        
        let mut consequence = Vec::new();
        while self.current_token != Token::RBrace && self.current_token != Token::EOF {
            if let Some(stmt) = self.parse_statement() {
                consequence.push(stmt);
            }
        }
        if self.current_token == Token::RBrace {
            self.next_token(); // 吃掉 '}'
        }
        
        Some(Stmt::PredictiveIf { probability: prob, consequence })
    }

    fn parse_expression_statement(&mut self) -> Option<Stmt> {
        let expr = self.parse_expression(0);
        if self.current_token == Token::Semicolon { self.next_token(); }
        Some(Stmt::Expression(expr))
    }
}
