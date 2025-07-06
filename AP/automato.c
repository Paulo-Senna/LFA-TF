#include <stdio.h>
#include <string.h>
#include "automato.h"

int processa(Estado **estado, char entrada, Pilha *pilha, char *palavra, int *pos) {
    for (int i = 0; i < (*estado)->num_transicoes; i++) {
        Transicao t = (*estado)->transicoes[i];

        int cond_entrada = (t.entrada == entrada) || (t.entrada == 'e' && entrada == 'e');
        int cond_pilha = (t.pop == 'e') || (t.pop == topo(pilha));
        int cond_final = (entrada == '?' && t.entrada == '?' && pilha_vazia(pilha));

        if (cond_entrada && (cond_pilha || cond_final)) {
            if (t.pop != 'e' && t.pop != '?') pop(pilha);
            if (t.push != 'e') push(pilha, t.push);

            if (entrada != 'e' && entrada != '?') {
                palavra[(*pos)++] = entrada;
                palavra[*pos] = '\0';
            }

            printf("Transicao: %c -> %c  | entrada: %c, pop: %c, push: %c\n",
                   (*estado)->nome,
                   t.destino->nome,
                   entrada,
                   t.pop == 'e' ? '-' : t.pop,
                   t.push == 'e' ? '-' : t.push);

            printf("Pilha: ");
            imprime_pilha(pilha);
            printf("\n\n");

            *estado = t.destino;
            return 1;
        }
    }

    return 0;
}
