
#include <stdio.h>

#include "token.h"

/* Flex */
// extern FILE *yyin;
// extern int yylex();
// extern char* yytext;

/* Bison */
extern int yyparse();

int main() 
{
    if (yyparse()) {
        printf("Parse successful!\n");
    } else {
        printf("Parse failed!\n");
    }

   //  yyin = fopen("program.c", "r");
   //  if (!yyin) {
   //      printf("Could not open source file!\n");
   //      return 1;
   //  }

   // while (1) {
   //     enum yytokentype t = yylex();
   //     if (t == YYEOF) break;
   //     printf("token: %d text: %s\n", t, yytext);
   // }
}


