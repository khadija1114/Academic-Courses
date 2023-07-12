%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yylex();
int yyerror(char *s);
%}

%token NUMBER SIN COS TAN PI
%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc UMINUS

%union {
    double num;
}

%type <num> factor term exp NUMBER

%%

program : exp '\n' { printf("Result: %lf\n", $1); exit(0); }
        ;

exp : exp '+' term { $$ = $1 + $3; }
     | exp '-' term { $$ = $1 - $3; }
     | exp '^' term { $$ = pow($1, $3);}
     | '-' exp %prec UMINUS { $$ = -$2; }
     | term { $$ = $1; }
     ;

term : term '*' factor { $$ = $1 * $3; }
     | term '/' factor { 
		if ($3 == 0) {
              	      yyerror("Error: Division by zero\n");
            	}
		$$ = $1 / $3; 
     }
     | factor { $$ = $1; }

     ;

factor : NUMBER { $$ = $1; }
       | PI { $$ = 3.14159; }
       | '(' exp ')' { $$ = $2; }
       | SIN '(' exp ')' {  $$ = sin($3);  }
       | COS '(' exp ')' {  $$ = cos($3);  }
       | TAN '(' exp ')' {  $$ = tan($3);  }
       ;

%%


int yyerror(char *message) 
{ 
  printf("Error: %s\n", message);
  exit(0); 
} 

int main () 
{ 
  printf("Enter an arithmetic expression: "); 
  yyparse(); 
  return 0;
}
