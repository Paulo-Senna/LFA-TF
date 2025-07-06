#include <stdio.h>
#include "automato.h"

Estado E = {'E'}, V = {'V'}, A = {'A'}, B = {'B'}, C = {'C'}, F = {'F'};

void adiciona(Estado *origem, char entrada, char pop, char push, Estado *destino) {
    origem->transicoes[origem->num_transicoes++] = (Transicao){entrada, pop, push, destino};
}

void construir_automato() {
    adiciona(&E, 'e', 'e', 'N', &V);
    adiciona(&V, 'e', 'N', 'T', &V);
    adiciona(&V, 'e', 'N', 'T', &A);

    adiciona(&A, '1', 'e', 'e', &B);
    adiciona(&B, '2', 'T', 'e', &A);
    adiciona(&B, '3', 'T', 'e', &C);
    adiciona(&C, '5', 'e', 'T', &B);
    adiciona(&C, '6', 'e', 'T', &A);
    adiciona(&A, '4', 'e', 'e', &A);

    adiciona(&A, '?', '?', 'e', &F);
    adiciona(&B, '?', '?', 'e', &F);
    adiciona(&C, '?', '?', 'e', &F);
}

void simular(int discos) {
    Pilha pilha;
    inicializa_pilha(&pilha);
    Estado *atual = &E;
    char palavra[100] = "";
    int pos = 0;

    // Inicialização (epsilon transições)
    processa(&atual, 'e', &pilha, palavra, &pos);
    for (int i = 1; i < discos; i++) {
        processa(&atual, 'e', &pilha, palavra, &pos);
    }
    processa(&atual, 'e', &pilha, palavra, &pos);

    char entrada[] = {'1', '2', '3', '5', '4', '6', '?'};
    int tam = sizeof(entrada) / sizeof(char);

    for (int i = 0; i < tam; i++) {
        if (!processa(&atual, entrada[i], &pilha, palavra, &pos)) {
            printf("Erro na transicao com entrada '%c'\n", entrada[i]);
            return;
        }
    }

    printf("\nPalavra formada: %s\n", palavra);
    printf("Estado final: %c\n", atual->nome);
    printf("Pilha final: ");
    imprime_pilha(&pilha);
}

int main() {
    construir_automato();
    int discos;
    printf("Digite o numero de discos: ");
    scanf("%d", &discos);
    printf("\n--- Simulando Autômato da Torre de Hanoi ---\n\n");
    simular(discos);
    return 0;
}
