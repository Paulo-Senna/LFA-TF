#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

int main() {
    Pilha p;
    MultiPilha mp;
    int numDiscos;
    char palavra[1000] = "";

    printf("Digite a quantidade de discos: ");
    scanf("%d", &numDiscos);

    inicializa_pilha(&p);
    inicializarPilha(&mp);

    for (int i = 1; i <= numDiscos; i++) {
        emp(&p, 'N');
        printf("est. E");
        desemp(&p);
        printf("est. V");
        emp(&p, 'T');
    }

    for (int i = numDiscos; i >= 1; i--) {
        empilhar(&mp, 0, i);
    }

    printf("\nEstado Inicial: \n");
    imprimirEstado(&mp, numDiscos);

    moverDiscos(numDiscos, &p, &mp, 0, 1, 2, palavra);

    imprime_pilha(&p);

    if (p.topo == -1) {
        printf("\nPilha auxiliar est\u00e1 vazia!");
    }

    printf("\nMovimentos: %s\n", palavra);

    return 0;
}
