

#ifndef PARSER_H
#define PARSER_H

typedef enum {
    STMT_DECL,
    STMT_EXPR,
    STMT_IF_ELSE,
    STMT_FOR,
    STMT_PRINT,
    STMT_RETURN,
    STMT_BLOCK
} stmt_t;

typedef enum {
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_GT,
    EXPR_LT,
    EXPR_EQ,
    EXPR_NOT,
    EXPR_NAME,
    EXPR_INTEGER_LITERAL,
    EXPR_STRING_LITERAL,
    EXPR_BOOLEAN_LITERAL,
    EXPR_CHAR_LITERAL,
    EXPR_CALL,
    EXPR_ARG,
    EXPR_SUBSCRIPT
} expr_t;

typedef enum {
    TYPE_VOID,
    TYPE_BOOLEAN,
    TYPE_CHARACTER,
    TYPE_INTEGER,
    TYPE_STRING,
    TYPE_ARRAY,
    TYPE_FUNCTION
} type_t;

struct type {
    type_t kind;
    struct type* subtype;
    struct param_list* params;
};

struct param_list {
    char* name;
    struct type* type;
    struct param_list* next;
};

struct expr {
    expr_t kind;
    struct expr* left;
    struct expr* right;

    const char* name;
    int integer_value;
    const char* string_literal;
};

struct stmt {
    stmt_t kind;
    struct decl* decl;
    struct expr* init_expr;
    struct expr* expr;
    struct expr* next_expr;
    struct stmt* body;
    struct stmt* else_body;
    struct stmt* next;
};

struct decl {
    char* name;
    struct type* type;
    struct expr* value;
    struct stmt* code;
    struct decl* next;
};

struct expr* expr_create(expr_t kind, struct expr* left, struct expr* right);


#endif // PARSER_H
