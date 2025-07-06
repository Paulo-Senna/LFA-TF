#ifndef PILHA_H
#define PILHA_H

#define MAX_PILHA 100

typedef struct {
    char itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializa_pilha(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void push(Pilha *p, char elemento);
char pop(Pilha *p);
char topo(Pilha *p);
void imprime_pilha(Pilha *p);

#endif
