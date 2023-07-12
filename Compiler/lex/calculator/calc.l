%{
#include "y.tab.h"
%}

%%

[ \t]+          /* Ignore whitespace */
\n              return '\n';
[0-9]+          yylval = atoi(yytext); return NUMBER;
.               return yytext[0];

%%

int yywrap() {
    return 1;
}

