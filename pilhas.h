#include <stdio.h>
#include <stdlib.h>

int totalNosPilha = 0;

struct no
{
    int        dado; // offset 0 (zero)
    struct no *prox; // offset 2 (dois)
};

typedef struct
{
    struct no *topo;
    int       totalNosPilha;
} pilha;

void cria(pilha *s);
int  empilha(pilha *s, int d);
int  desempilha(pilha *s);
int  estaVazia(pilha s);
void mostra(pilha s);
int  topo(pilha s);
int  contaNos(pilha s);
pilha p;

void cria(pilha *s)
{
    s->topo = NULL;
    totalNosPilha = 0;
}
int  empilha(pilha *s, int d)
{
    struct no *aux;
    aux = (struct no*) malloc(sizeof(struct no));
    if (aux == NULL)
        return 0;
    aux->dado = d;// deixa o dado no espaço de dados no bloco de memoria alocada
    aux->prox = s->topo;// faz o prox do no receber o endereço de memoria do no em baixo dele, que era o antigo topo
    s->topo = aux; // faz o ponteiro de topo apontar para o novo topo
    totalNosPilha++;
    return 1;
}
void mostra(pilha s)
{
    struct no *aux;
    aux = s.topo;
    if (aux == NULL)
        printf("\nPilha vazia...\n\n");
    else
    {
        while (aux != NULL)
        {
            printf(" = %d\n", aux->dado);
            aux = aux->prox;
        }
    }
}

int desempilha(pilha *s)
{
    struct no *aux;
    int dadoDesempilhado;
    if (s->topo == NULL)
    {
        printf("\nPilha vazia! Remocao nao efetuada!\n\n");
        return -1;
    }
    aux = s->topo;
    dadoDesempilhado = aux->dado;
    s->topo = s->topo->prox;
    aux->dado = 0;    // Garbagge Collection
    aux->prox = NULL; // Garbagge Collection
    free(aux);
    totalNosPilha--;
    return dadoDesempilhado;
}

int  estaVazia(pilha s)
{
    if (s.topo == NULL)
        return 1;
    return 0;
}
int topo(pilha s)
{
    return s.topo->dado;
}
int contaNos(pilha s)
{
    struct no *aux;
    int contador = 0;
    aux = s.topo;
    if (aux == NULL)
        return 0;
    else
    {
        while (aux != NULL)
        {
            contador++;
            aux = aux->prox;
        }
    }
    return contador;
}
