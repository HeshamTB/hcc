%{

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "token.h"

struct decl* parser_result = 0;

extern int yylex(); 
extern char* yytext;


%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_RBRACE
%token TOKEN_LBRACE
%token TOKEN_IF
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_COLON
%token TOKEN_ASSIGN
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_IDENT
%token TOKEN_NUMBER

%union {

    struct decl* decl;
    struct stmt* stmt;
    struct expr* expr;
    struct type* type;

    char* name;
}

%type <decl> program decl_list decl
%type <stmt> stmt_list stmt
%type <expr> expr factor term
%type <type> type
%type <name> name

%%

program : decl_list { parser_result = $1; }
    ;

decl : name TOKEN_COLON type TOKEN_SEMI 
        { $$ = decl_create($1,$3,0,0,0); }
    | name TOKEN_COLON type TOKEN_ASSIGN expr TOKEN_SEMI 
        { $$ = decl_create($1,$3,$5,0,0); }
    ;

decl_list : decl decl_list { $$ = $1; $1->next = $2; }
    | { $$ = 0; }
    ;

stmt : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
        { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$5,0,0); } 
    | TOKEN_LBRACE stmt_list TOKEN_RBRACE
        { $$ = stmt_create(STMT_BLOCK,0,0,0,0,$2,0,0); }
    ;

stmt_list : stmt stmt_list { $$ = $1; $1->next = $2; }
    | { $$ = 0; }
    ;

expr : expr TOKEN_PLUS term { $$ = expr_create(EXPR_ADD,$1,$3); } 
    | expr TOKEN_MINUS term { $$ = expr_create(EXPR_SUB,$1,$3); }
    | term { $$ = $1; }
    ;

term : term TOKEN_MUL factor { $$ = expr_create(EXPR_MUL,$1,$3); }
    |  term TOKEN_DIV factor { $$ = expr_create(EXPR_DIV,$1,$3); }
    | factor { $$ = $1; }
    ;

factor : TOKEN_MINUS factor 
            { $$ = expr_create(EXPR_SUB, expr_create_integer_literal(0), $2); }
    | TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
    | TOKEN_NUMBER { $$ = expr_create_integer_literal(atoi(yytext)); }
    ;

type : TOKEN_INT { $$ = create_type(TYPE_INTEGER,0,0); }
    | TOKEN_VOID { $$ = create_type(TYPE_VOID,0,0); }
    ;

name : TOKEN_IDENT { $$ = yytext; }
    ;

%%

int yyerror(char* s) 
{
    printf("parse error: %s\n", s);
    return 1;
}
