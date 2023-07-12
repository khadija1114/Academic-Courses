%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s);
%}

%token DIGIT LETTER NEWLINE UND 

%% 
stmt : variable NEWLINE { printf("Valid Identifiers\n"); exit(0);} 
 ; 
 
variable : LETTER alphanumeric 
 ; 
alphanumeric: LETTER alphanumeric 
 | DIGIT alphanumeric 
 | UND alphanumeric 
 | LETTER 
 | DIGIT 
 | UND 
 ; 
%% 

int yyerror(char *message) 
{ 
 printf("Invalid Identifiers\n"); 
 exit(0); 
} 


int main () 
{ 
 printf("Enter the variable name: "); 
 yyparse(); 
 return 0;
}
