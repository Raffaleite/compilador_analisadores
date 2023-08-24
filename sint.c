#include <stdio.h>
#include <stdlib.h>
#include "analex.h"
#include "pilhas.h"

int token;

void E();
void T();
void E_linha();
void T_linha();
void F();
void erro();
void reconhecer(int tok);

int a;
int b;

void erro()
{
    printf("Erro sintatico na linha: %d\n", linhas);
    exit(1);
}

void reconhecer(int tok)
{
    if (tok == token)
        token = analex();
    else
        erro();
}

void E()
{
    T();
    E_linha();
}

void E_linha()
{
    if(token == '+')
    {
        reconhecer('+');
        T();

        a = desempilha(&p);
        b = desempilha(&p);
        empilha(&p, a+b);
        E_linha();

    }
    else if (token == '-')
    {
        reconhecer('-');
        T();

        a = desempilha(&p);
        b = desempilha(&p);
        empilha(&p, b-a);

        E_linha();
    }
}

void T()
{
    F();
    T_linha();
}

void T_linha()
{
    if(token == '*')
    {
        reconhecer('*');
        F();

        a = desempilha(&p);
        b = desempilha(&p);
        empilha(&p, a*b);
        T_linha();

    }
    else if(token == '/')
    {
        reconhecer('/');
        F();

        a = desempilha(&p);
        b = desempilha(&p);
        empilha(&p, b/a);
        T_linha();

    }
}

void F()
{
    if(token == NUM)
    {
        empilha(&p, tokenval);
        reconhecer(NUM);

    }
    else if (token == '(')
    {
        reconhecer('(');
        E();
        reconhecer(')');
    }
}

int main()
{
    cria(&p);
    token = analex();
    E();
    if (token != ';')
        erro();
    else
    {
        printf("Resultado da expressao: ");
        mostra(p);
    }
}