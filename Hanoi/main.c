#include <stdio.h>
#include "hanoi.h"

int main() {
    MultiPilha mp;
    int numDiscos;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &numDiscos);

    inicializarMultiPilha(&mp);

    for (int i = numDiscos; i >= 1; i--) {
        empilhar(&mp, 0, i); 
    }

    printf("\nEstado Inicial: \n");
    imprimirEstado(&mp, numDiscos);

    moverDiscos(numDiscos, &mp, 0, 1, 2);  

    return 0;
}
