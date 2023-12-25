
#include "expr.h"
#include <stdlib.h>

struct decl* decl_create(
        char* name, 
        struct type* type, 
        struct expr* value,
        struct stmt* code,
        struct decl* next) 
{
    
    struct decl* d = malloc(sizeof(*d));
    d->name = name;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

struct stmt* stmt_create(
        stmt_t kind,
        struct decl* decl, struct expr* init_expr,
        struct expr* expr, struct expr* next_expr,
        struct stmt* body, struct stmt* else_body,
        struct stmt* next)
{

    struct stmt* s = malloc(sizeof(*s));
    s->decl = decl;
    s->expr = expr;
    s->next = next;
    s->body = body;
    s->else_body = else_body;
    s->init_expr = init_expr;
    s->next_expr = next_expr;
    s->kind = kind;
    return s;
}

struct expr* expr_create(expr_t kind, struct expr* left, struct expr* right)
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

struct expr* expr_create_name(const char* name) 
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = EXPR_NAME;
    e->name = name;
    return e;
}

struct expr* expr_create_integer_literal(int i) 
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = EXPR_INTEGER_LITERAL;
    e->integer_value = i;
    return e;
}

struct expr* expr_create_boolean_literal(int b) 
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = EXPR_BOOLEAN_LITERAL;
    // FIXME: Check if it is 0 or 1?
    e->integer_value = b;
    return e;
}


struct expr* expr_create_char_literal(char c)
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = EXPR_CHAR_LITERAL;
    e->integer_value = c; // this limits us to ASCII?
    return e;
}

struct expr* expr_create_string_literal(const char* s)
{
    struct expr* e = malloc(sizeof(*e));
    e->kind = EXPR_STRING_LITERAL;
    e->string_literal = s;
    return e;
}

struct type* create_type(type_t kind, struct type* subtybe, struct param_list* param_list) 
{
    struct type* t = malloc(sizeof(*t));
    t->kind = kind;
    t->subtype = subtybe;
    t->params = param_list;
    return t;
}

