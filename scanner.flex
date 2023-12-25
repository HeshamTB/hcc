%{

#include "token.h"

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
(" "|\t|\n) /* skip whitespce */
\+ { return TOKEN_PLUS; }
\- { return TOKEN_MINUS; }
\* { return TOKEN_MUL; }
\/ { return TOKEN_DIV; }
if { return TOKEN_IF; }
\( { return TOKEN_LPAREN; }
\) { return TOKEN_RPAREN; }
\{ { return TOKEN_LBRACE; }
\} { return TOKEN_RBRACE; }
void { return TOKEN_VOID; }
int { return TOKEN_INT; }
while { return TOKEN_WHILE; }
{LETTER}+ { return TOKEN_IDENT; }
{DIGIT}+ { return TOKEN_NUMBER; }
. { return TOKEN_ERROR; } 

%%
int yywrap() { return 1; }

