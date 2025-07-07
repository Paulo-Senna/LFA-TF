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

void imprime_pilha(Pilha *p);
void emp(Pilha *p, char elemento);
char desemp(Pilha *p);
void inicializa_pilha(Pilha *p);
void inicializarPilha(MultiPilha *p);
int estaVazia(MultiPilha *mp, int indice);
int estaCheia(MultiPilha *mp, int indice);
void empilhar(MultiPilha *mp, int indice, int valor);
int desempilhar(MultiPilha *mp, int indice);
int topo(MultiPilha *mp, int indice);
void moverDiscos(int n, Pilha *p, MultiPilha *mp, int origem, int auxiliar, int destino, char *str);
void imprimirEstado(MultiPilha *mp, int numDiscos);
void reco(char *String, int orig, int dest);

#endif