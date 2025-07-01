#include "arquiv.h"

int leitura_fita (int Q[],int tamest, char E[],int qntsimb, char str[],int **delta);
int main (){
    
    int qntsimb, qntest;
    char *E;
    int choice = 1;
    while(choice != 0 ){
    printf("\n --------- AUTOMATA  MENU -----------");
    printf("\n");
    printf("\n (1) Criar 5-tupla:");
    printf("\n (2) Verificar simbolo:");
    printf("\n Sair do programa");
    scanf ("%d", &choice);
    
    switch(choice){
        case 1:
            
            
            printf("\nQuantos simbolos?");
            scanf("%d", &qntsimb);
            printf("\nAlfabeto:");
            E = malloc (qntsimb *(sizeof(char)));
            for (int i = 0; i < qntsimb; i++){
            scanf(" %c",&E[i]);
            }
            
            printf("\nQuantidade de estados:");
            scanf("%d", &qntest);
            int * Q = malloc (qntest*(sizeof(int)));
            for (int i = 0; i < qntest; i++){
                Q[i] = i;
            }
            
            printf("\nEstados finais:");
            int parfinais = 0;
            int finais = 0;
            int j = 0;
            int num;
            int i = 0;
            int *F = NULL;
            while(parfinais == 0){
                
                scanf("%d", &num );
                if (num == -1){
                    parfinais = 1;
                }else{
                   int loop = 0;
                   while(loop == 0){
                      
                      for (int k = 0; k < qntest;k++){ 
                         
                         if (num == Q[k]){
                         
                            finais++;
                            F = realloc(F,finais * (sizeof(int)));
                            F[finais-1] = num;
                            
                            
                         }
                      }
                      loop = 1;
                      
                          
                      
                   }
                
                }
                
            }
            
           
             printf("Você digitou:\n");
             for (int k = 0; k < finais; k++) {
                printf("F[%d] = %d\n", k, F[k]);
             }
               
               
               
               int ** delta = malloc (qntest *sizeof(int));
               for (int i = 0; i <qntest;i++){
                   delta[i] = malloc (qntsimb * sizeof(int));
               }
               
               printf("\nTransicoes de cada estado com os simbolos:");
               for (int i = 0; i < qntest; i++){
                   for(int k = 0; k < qntsimb; k++){
                       printf("\ndelta[%d][%c]: ",i , E[k]);
                       scanf("%d", &delta[i][k]);
                   }
               }
               for (int i = 0; i < qntest; i++){
                   for(int k = 0; k < qntsimb; k++){
                       printf("\ndelta[%d][%c]:  %d ",i , E[k], delta[i][k]);
                   }
               }
               
            free(F);
            
            break;
    
        case 2:
            int key = 0;
            char str[100];
            printf("\nPalavra a verificar-se pertencimento: ");
            scanf("%s", str);
            
            leitura_fita (Q,qntest, E,qntsimb, str, delta);
            
            break;
    }
    
    
    
}
return 0;
}






int leitura_fita (int Q[],int tamest, char E[],int qntsimb, char str[], int **delta){
    int fita = strlen(str);
    int cont = 0;
    int current = 0;
    int i = 0;
    int past = 0;
    while (cont < fita){
        int warning = 0;
        for( i = 0; i < qntsimb; i++){
          
           if (str[cont] == E[i]){
              printf("\nWIN");
              warning = 1;
              current = delta[current][i];
              cont++;
           }
               
           
           
        }
        
        if(warning == 0 && i == qntsimb){
           printf("\nPalavra nao aceita");
           return -1;
        
    }
    
    
        
    }    
    
    
    
    
    
    printf("\nPalavra aceita");
    
    return 0;
}
