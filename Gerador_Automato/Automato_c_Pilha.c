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
    
  
// CRIA FUNÇÃO                  
pilha * cria (){
    
    pilha *p = NULL;
    p = (pilha *) malloc (sizeof(pilha));
    if (p){
        p->topo = NULL;
        p->tamPilha = 0;
    }
    return p;
}

                   
int empilha (dado *novo, pilha *p){
    celP * helper = NULL;
    helper =(celP*) malloc (sizeof(celP));
    if(helper != NULL){
        memcpy(&(helper->info),novo,sizeof(dado));
        helper->abaixo = p->topo;
        p->topo = helper;
        (p->tamPilha)++;
        return 0;
    }
    return 1;
}

int desempilha (){
    
    
}
    





    return 0;
}
