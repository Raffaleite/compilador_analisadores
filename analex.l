%{
#include "sint.h" 
#include <stdio.h>
int line=1;

%}

%%
"+"   { return '+'; } 
"-"   { return '-'; }
"*"   { return '*'; }
"/"   { return '/'; }
")"   { return ')'; }
"("   { return '('; }
";"   { return ';'; }
","   {return ','; }
"{"   {return '{'; }
"}"   {return '}'; }
"="   {return '='; }	
">"   { return '>'; }
"<"   { return '<'; }
">="  { return GE; }
"<="  { return LE; }
"=="  { return EQ; }
"!="  { return NE; }
"||"  { return OR; }
"&&"  { return AND; }
"do"  { return DO; }
"while" { return WHILE; }
"if" { return IF; }
"else" { return ELSE; }
"int" { return INT; }
"char" { return CHAR; }
"void" {return VOID; }
"return" {return RETURN; }

[0-9]+("."[0-9]+)?   { return NUM; }
[a-zA-Z]([a-zA-Z]|[0-9])* { return ID; }
[ ]        { ; }
\n       { line++;}              
\t       { ; }    
.        { printf("token ilegal!!\n"); }

%%
#ifndef yywrap
int yywrap() { return 1; }
#endif


