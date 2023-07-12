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
stmt : exp NEWLINE { printf("Value = %d\n",$1); exit(0);} 
 ; 

exp : exp '+' exp { $$=$1+$3; } 
 | exp '-' exp { $$=$1-$3; } 
 | exp '*' exp { $$=$1*$3; } 
 | exp '/' exp { if($3==0) {  printf("Cannot divide by 0\n");  exit(0); } 
 		  else { $$=$1/$3; }
 	       } 
 | '(' exp ')' { $$=$2; } 
 | ID { $$=$1; } 
 | NUMBER { $$=$1; } 
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
