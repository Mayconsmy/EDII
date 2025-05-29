//invertexto.com/rzak36
#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária

typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node* criarNo(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

Node* inserir(Node*raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(raiz->valor > valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
        return raiz;
    }
    else{
        raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    }
}

void preOrdem(Node* raiz){
    if(raiz!= NULL)   {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
 
void posOrdem(Node* raiz){
    if(raiz!= NULL)   {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void inOrdem(Node* raiz){
    if(raiz!= NULL)   {
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        inOrdem(raiz->direita);
    }
}

int main(){
    Node *raiz = NULL;
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 19);
    raiz = inserir(raiz, 17);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 41);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 31);
    posOrdem(raiz);
}