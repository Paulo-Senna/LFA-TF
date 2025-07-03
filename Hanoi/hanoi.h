#ifndef MULTIPILHA_H
#define MULTIPILHA_H

#define TAM_MAX 100
#define NUM_PILHAS 3

typedef struct {
    int dados[TAM_MAX];
    int topo;
} Pilha;

typedef struct {
    Pilha pilhas[NUM_PILHAS];
} MultiPilha;

void inicializarMultiPilha(MultiPilha *mp);
int estaVazia(MultiPilha *mp, int indice);
int estaCheia(MultiPilha *mp, int indice);
void empilhar(MultiPilha *mp, int indice, int valor);
int desempilhar(MultiPilha *mp, int indice);
int topo(MultiPilha *mp, int indice);
void moverDiscos(int n, MultiPilha *mp, int origem, int auxiliar, int destino);
void imprimirEstado(MultiPilha *mp, int numDiscos);
void reco( char * String, int orig, int dest);

#endif
