#ifndef AUTOMATO_H
#define AUTOMATO_H

#include "pilha.h"

#define MAX_TRANSICOES 12

struct Estado;

typedef struct Transicao {
    char entrada;
    char pop;
    char push;
    struct Estado *destino;
} Transicao;

typedef struct Estado {
    char nome;
    Transicao transicoes[MAX_TRANSICOES];
    int num_transicoes;
} Estado;

// Processa uma transição e imprime passo a passo
int processa(Estado **estado, char entrada, Pilha *pilha, char *palavra, int *pos);

#endif