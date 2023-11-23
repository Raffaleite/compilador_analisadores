%{ 
#include "analex.c" 
#include "sint.h"
void yyerror(char *s) {
  printf("erro sintatico na linha %d\n",line);
}
%}
  

%token ID
%token NUM 
%token INT
%token CHAR
%token VOID
%token RETURN
%token AND
%token OR
%token EQ
%token LE
%token GE
%token NE
%token IF
%token WHILE
%token ELSE
%token DO
%left '='
%left ','
%left AND OR
%left '>' '<' NE EQ GE LE
%left '+' '-' 
%left '*' '/' 
%start Prog  
%%  
Prog : Statement_Seq  				 	 
     ;

Statement_Seq :
	Statement Statement_Seq
	|
	;
	

Func_Statement :
	Tipo ID '(' Args_Func ')' Func_Statement_Compound
	;

Func_Statement_Compound :
	'{' Func_Statement_Seq RETURN Exp ';' '}'
	;

Func_Statement_Seq :
	Statement Func_Statement_Seq
	|
	;
	
	
Func_Call :
	ID '(' Args ')'
	;
     

Args_Func: 
	Args_Func ',' Tipo ID
	| Tipo ID
	|
	;


Args:
	  Args ',' Exp
	| Exp
	|
	;
		
Statement: 
		Atribuicao
	|	If_Statement
	| 	While_Statement
	|   Do_While_Statement
	|   ID '(' Args ')' ';'
	|   Func_Call
	|   Func_Statement
	|   Var_Statement
	;
	
Var_Statement :
	Tipo ID ';'
	| Tipo ID '=' Exp ';'
	| Tipo ID ',' Var_Statement_Next ';'
	| Tipo ID '=' Exp ',' Var_Statement_Next ';'
	;

Var_Statement_Next :
	ID Var_Statement_Final
	| ID ',' Var_Statement_Final
	| ID '=' Exp ',' Var_Statement_Final
	| ID '=' Exp Var_Statement_Final
	;

Var_Statement_Final :
	ID Var_Statement_Final
	| ID ',' Var_Statement_Final
	| ID '=' Exp ',' Var_Statement_Final
	| ID '=' Exp Var_Statement_Final
	|
	; 

Tipo:
	INT
	| CHAR
	;
	
	
Atribuicao : ID '=' Exp ';' 
	;

Compound_Statement :
	  Statement
	| '{' Statement_Seq '}'
	;
     
     
If_Statement:
	  IF '(' Exp ')' Compound_Statement Else_Part 
	;
		
Else_Part:
	  ELSE Compound_Statement
	|
	;

While_Statement:
	  WHILE '(' Exp ')' Compound_Statement  
	;

Do_While_Statement:
	  DO Compound_Statement WHILE '(' Exp ')' ';'   
	;    


			 
Exp : Exp '+' Exp  
	| Exp '-' Exp  
	| Exp '*' Exp  
	| Exp '/' Exp  
	| Exp '>' Exp  
	| Exp '<' Exp 
	| Exp GE Exp  
	| Exp LE Exp   
	| Exp EQ Exp   
	| Exp NE Exp   
	| Exp AND Exp  
	| Exp OR Exp   
	| '(' Exp ')'  
	| NUM		   
	| ID
	| Func_Call       
	;  
  
  
    

%%  


int main(int argc, char **argv) {     
  yyin = fopen(argv[1],"r");
  yyparse();      
} 

