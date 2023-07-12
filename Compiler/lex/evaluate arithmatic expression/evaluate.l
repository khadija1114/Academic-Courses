%{ 
 #include "y.tab.h"
 extern int yylval; 
%} 

%% 
[ \t]+          /* Ignore whitespace */
[0-9]+ 		{ yylval=atoi(yytext); return NUMBER; } 
\n 		{ return NEWLINE ;} 
. 		{ return yytext[0]; } 
%% 


int yywrap() {
    return 1;
}
