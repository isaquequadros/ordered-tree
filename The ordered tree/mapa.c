/*
    NOME: Isaque Quadros Amaral
    CURSO: Engenharia de Software
    RA:200291965
    DISCIPLINA: ESTRUTURA DE Dados II - 52/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct DADO_ARVORE{
       int valor;
       struct DADO_ARVORE *esquerda, *direita, *pai;
};
typedef struct DADO_ARVORE ARVORE;
ARVORE *INICIALIZAR_NULL(){
    return NULL;
}
ARVORE *BIN(ARVORE *arvore, int v);
int VERIFICA_ARVORE_VAZIA(ARVORE *a);
void IMPRIMIR_PreOrdem(ARVORE *a);
void imprimir_arvore(ARVORE *a);
main(){
    ARVORE *a = INICIALIZAR_NULL();
    int opcao, valor;
    
   setlocale(LC_ALL, "");   
    
   a = BIN(a, 2);
   a = BIN(a, 0);   
   a = BIN(a, 0);
   a = BIN(a, 2);
   a = BIN(a, 9);
   a = BIN(a, 1);
   a = BIN(a, 9);
   a = BIN(a, 6);   
   a = BIN(a, 5);
   printf("Arvore Binaria");
   imprimir_arvore(a);
   printf("\n\n\n");
   printf("\nRA:200291965");
   printf(" - Visitação pré-ordem: ");
   IMPRIMIR_PreOrdem(a);
    
    
    return 0;                 
        
        
}
ARVORE *BIN(ARVORE *arvore, int v){
    ARVORE *auxiliar;
    
    if(arvore == NULL){
       auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
       auxiliar->valor = v;
       auxiliar->esquerda = INICIALIZAR_NULL();
       auxiliar->direita = INICIALIZAR_NULL();
       return auxiliar;
       }
    else{
         int dir;
         auxiliar = arvore;
         ARVORE *pai = NULL, *raiz = arvore;
         while(auxiliar != NULL){
           pai = auxiliar;
           if(v <= auxiliar->valor){
              dir = 0;
              auxiliar = auxiliar->esquerda;
              }
           else{
              dir = 1;
              auxiliar = auxiliar->direita;
              }
           }
    auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
    auxiliar->valor = v;
    auxiliar->esquerda = INICIALIZAR_NULL();
    auxiliar->direita = INICIALIZAR_NULL();
    
    if(dir)
      pai->direita = auxiliar;
    else
      pai->esquerda = auxiliar;
      return raiz;
    }
}
int VERIFICA_ARVORE_VAZIA(ARVORE *a){
    return a == NULL;
}
void IMPRIMIR_PreOrdem(ARVORE *a){
    if(a != NULL){
        printf("%d ", a->valor);
        IMPRIMIR_PreOrdem(a->esquerda);
        
        IMPRIMIR_PreOrdem(a->direita);
        
        
    }
}
void imprimir_arvore(ARVORE *a){
     printf("\n\n\t Pai %d \n",a->valor);
     if(a->esquerda != NULL){
        printf("Esquerdo: %d\t",a->esquerda->valor);    
     }       
     else{
        printf("Esquerdo: NULL\t");
     }
       
     if(a->direita != NULL){
        printf("\tDireito: %d\t",a->direita->valor);
     }       
     else{
        printf("Direito: NULL\t");
     }
       
     if(a->esquerda != NULL){
        imprimir_arvore(a->esquerda);
     }
      
     if(a->direita != NULL){
        imprimir_arvore(a->direita);
     }
       
}
