#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esquerdo;
    struct no *direito;    
} no;

no* criar_no(int valor) {
    no* novo_no = (no*)malloc(sizeof(no));
    if (novo_no == NULL){
        printf("erro de alocação de memoria");
        exit(1);
    }
    novo_no->dado = valor;
    novo_no->esquerdo = NULL;
    novo_no->direito = NULL;
    return novo_no;
}

no* inserir(no* raiz, int valor) {
     if (raiz == NULL) {
        return criar_no(valor);
     }
     if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
     }
     else if (valor > raiz->dado) {
        raiz->direito = inserir(raiz->direito, valor);
     }

     return raiz;
}

void imprimir_em_ordem(no* raiz){
    if(raiz != NULL){
        imprimir_em_ordem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        imprimir_em_ordem(raiz->direito);
    }
}

int main(){
    no* raiz = NULL;

    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("arvore em ordem: ");
    imprimir_em_ordem(raiz);
    printf("\n");   

    return 0;
}