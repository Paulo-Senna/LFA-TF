#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hanoi.h"

void inicializarMultiPilha(MultiPilha *mp) {
    for (int i = 0; i < NUM_PILHAS; i++) {
        mp->pilhas[i].topo = -1;
    }
}

int estaVazia(MultiPilha *mp, int indice) {
    return mp->pilhas[indice].topo == -1;
}

int estaCheia(MultiPilha *mp, int indice) {
    return mp->pilhas[indice].topo == TAM_MAX - 1;
}

void empilhar(MultiPilha *mp, int indice, int valor) {
    if (!estaCheia(mp, indice)) {
        mp->pilhas[indice].dados[++mp->pilhas[indice].topo] = valor;
    }
}

int desempilhar(MultiPilha *mp, int indice) {
    if (!estaVazia(mp, indice)) {
        return mp->pilhas[indice].dados[mp->pilhas[indice].topo--];
    }
    return -1;
}

int topo(MultiPilha *mp, int indice) {
    if (!estaVazia(mp, indice)) {
        return mp->pilhas[indice].dados[mp->pilhas[indice].topo];
    }
    return -1;
}

void moverDiscos(int n, MultiPilha *mp, int origem, int auxiliar, int destino, char * str) {
    if (n == 1) {
        int valor = desempilhar(mp, origem);
        printf("D%d(%c) -> (%c)\n", valor, 'A' + origem, 'A' + destino );
        empilhar(mp, destino, valor);
        reco(str, origem, destino);
        imprimirEstado(mp, n);
        return;
    }

    moverDiscos(n - 1, mp, origem, destino, auxiliar, str);

    int valor = desempilhar(mp, origem);
    printf("D%d(%c) -> (%c)\n", valor, 'A' + origem, 'A' + destino);
    empilhar(mp, destino, valor);
    reco(str, origem, destino);
    imprimirEstado(mp, n);

    moverDiscos(n - 1, mp, auxiliar, origem, destino, str);

}

void reco (char * String, int orig, int dest){
   if (orig == 0 && dest == 1){
      strcat(String,"1");
   }else if(orig == 0 && dest == 2){
      strcat(String,"2");
   }else if(orig == 1 && dest == 0){
      strcat(String,"3");
   }else if(orig == 1 && dest == 2){
      strcat(String,"4");
   }else if(orig == 2 && dest == 0){
      strcat(String,"5");
   }else if(orig == 2 && dest == 1){
      strcat(String,"6");
   }
}

void imprimirEstado(MultiPilha *mp, int numDiscos) {

    int alturaMax = 0;
    for(int i = 0; i < NUM_PILHAS; i++){
        if(mp->pilhas[i].topo + 1 > alturaMax){
            alturaMax = mp->pilhas[i].topo + 1;
        }
    }
    printf("\nEstado atual:\n");

    for (int nivel = alturaMax - 1; nivel >= 0; nivel--) {
        for (int j = 0; j < NUM_PILHAS; j++) {
            if (mp->pilhas[j].topo >= nivel) {
                int valor = mp->pilhas[j].dados[nivel];
                printf(" D%d ", valor);
            } else {
                printf(" -- ");
            }
        }
        printf("\n");
    }
    printf(" A   B   C \n");
}
