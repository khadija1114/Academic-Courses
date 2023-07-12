%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token NUMBER

%%

program : exp '\n' { printf("Result: %d\n", $1); }
        ;

exp : exp '+' term { $$ = $1 + $3; }
     | exp '-' term { $$ = $1 - $3; }
     | term { $$ = $1; }
     ;

term : term '*' factor { $$ = $1 * $3; }
     | term '/' factor { $$ = $1 / $3; }
     | factor { $$ = $1; }
     ;

factor : NUMBER { $$ = $1; }
       | '(' exp ')' { $$ = $2; }
       ;

%%

int main() {
    printf("Enter the expression: ");
    yyparse();
    return 0;
}

int yyerror(char* message) {
    printf("Invalid Expression\n");
    return 1;
}

