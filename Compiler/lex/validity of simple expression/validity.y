%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token NUMBER ID NEWLINE 
%left '+' '-'
%left '*' '/' 

%% 
stmt : exp NEWLINE { printf("Valid Expression"); exit(0);} 
 ; 

exp : exp '+' exp 
 | exp '-' exp 
 | exp '*' exp 
 | exp '/' exp 
 | '(' exp ')' 
 | ID 
 | NUMBER 
 ; 
%% 

int yyerror(char *message) 
{ 
 printf("This is an Invalid Expression\n"); 
 exit(0); 
} 

int main () 
{ 
 printf("Enter the expression: "); 
 yyparse(); 
 return 0;
}
