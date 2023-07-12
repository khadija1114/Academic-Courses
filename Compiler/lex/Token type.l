%{
#include <stdio.h>
%}

digit       [0-9]
letter      [a-zA-Z]
identifier  {letter}({letter}|{digit})*
integer     {digit}+
whitespace  [ \t\n]
semicolon   ;
plus        [+]
minus       -
equal       =
lt          <
gt          >
le          <=
ge          >=


%%

{whitespace}    /* Ignore whitespace */
{integer}       { printf("INTEGER: %s\n", yytext); }
{identifier}    { printf("IDENTIFIER: %s\n", yytext); }
{plus}          { printf("plus: %s\n", yytext); }
{minus}         { printf("minus: %s\n", yytext); }
{semicolon}     { printf("semicolon: %s\n", yytext); }
{equal}         { printf("equal: %s\n", yytext); }
{lt}            { printf("less then: %s\n", yytext); }
{gt}            { printf("greater then: %s\n", yytext); }
{le}            { printf("less then equal: %s\n", yytext); }
{ge}            { printf("greater then equal: %s\n", yytext); }
.               { printf("UNKNOWN: %s\n", yytext); }

%%

int yywrap(){}

int main()
{
    yylex();
    return 0;
}
