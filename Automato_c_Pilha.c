#include "arquiv.h"

int main()
{
    //\/\/\/\/ ALFABETO DE SAÍDA \/\/\/\/\/// 
    int nEs;
    printf("\nQuantidade de alfabetos de saída:");
    scanf("%d", &nEs);
    char alfSaida[nEs];
    for (int i = 0; i < nEs; i++){
        printf("\nAlf. Saida [%d] : ", i+1);
        scanf(" %c", &alfSaida[i]);
    }
    /*      Verificação dos valores 
    for (int i = 0; i < nEs; i++){
        printf("\nAlf. Saida [%d] : ", i+1);
        printf("%c", alfSaida[i]);
    }
    */
    
    
    





    return 0;
}
