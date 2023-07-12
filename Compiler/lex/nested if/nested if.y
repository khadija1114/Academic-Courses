%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);

int level = 0;
%}

%token IF THEN ELSE ENDIF RELOP S NUMBER ID END

%% 
program : statement END {exit(0);}
        ;

statement :IF '(' condition ')' THEN '{' statement '}' ELSE '{' statement '}' ENDIF { printf("Level: %d\n", ++level);}
        | IF '(' condition ')' THEN '{' statement '}' ENDIF{  printf("Level: %d\n", ++level);}
	| S
        ;

condition : x RELOP x
	| x
 ; 
x : ID 
 | NUMBER 
 ; 
%%


int yyerror(char *message) 
{ 
  printf("Error: %s\n", message);
  exit(0); 
} 

int main () 
{ 
 printf("Enter the statement: "); 
 yyparse(); 
 return 0;
}
