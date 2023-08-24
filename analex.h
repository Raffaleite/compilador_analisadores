#include <stdio.h>
#include <ctype.h>
#define NUM 256

int analex();
int tokenval;
int linhas = 1;

int analex()
{
    int ch;
    tokenval = -1;
    ch = getchar();


    while(ch == ' ' || ch == '\n' || ch == '\t')
    {
        ch = getchar();
    }

    if (ch== '+')
    {
        linhas++;
        return '+';
    }

    if (ch== '-')
    {
        linhas++;
        return '-';
    }

    if (ch== '*')
    {
        linhas++;
        return '*';
    }

    if (ch== '/')
    {
        linhas++;
        return '/';
    }

    if (ch== '(')
    {
        linhas++;
        return '(';
    }

    if (ch== ')')
    {
        linhas++;
        return ')';
    }

    if (ch== ';')
    {

        return ';';
    }



    if (isdigit(ch)){
        tokenval = ch - '0';
        ch = getchar();
        while(isdigit(ch)) {
            tokenval = tokenval * 10 + ch - '0';
            ch = getchar();
        }
        ungetc(ch, stdin);
        linhas++;

        return NUM;
    }

}
