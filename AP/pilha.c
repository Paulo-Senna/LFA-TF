#include <stdio.h>
#include "pilha.h"

void inicializa_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

void push(Pilha *p, char elemento) {
    if (!pilha_cheia(p)) {
        p->itens[++(p->topo)] = elemento;
    } else {
        printf("Erro: pilha cheia\n");
    }
}

char pop(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: pilha vazia\n");
        return '\0';
    }
}

char topo(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->itens[p->topo];
    } else {
        return '\0';
    }
}

void imprime_pilha(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("[vazia]");
        return;
    }

    printf("[");
    for (int i = 0; i <= p->topo; i++) {
        printf("%c", p->itens[i]);
        if (i < p->topo) printf(", ");
    }
    printf("]");
}
