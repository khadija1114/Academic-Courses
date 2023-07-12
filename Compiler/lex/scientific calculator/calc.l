%{
#include "y.tab.h"
%} 

%%

[0-9]+(\.[0-9]+)?    { yylval.num = atof(yytext); return NUMBER; }
"sin"                  { return SIN; }
"cos"                { return COS; }
"tan"                { return TAN; }
"pi"		     { return PI; }
[ \t]                {  ; }
[\n]		     { return '\n'; } 
.                    { return yytext[0]; }

%% 

int yywrap() {
    return 1;
}

