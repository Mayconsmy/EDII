#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// a) Criar um novo nó
No* criarNo(int dado) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

// b) Inserir
No* inserir(No* raiz, int dado) {
    if (raiz == NULL)
        return criarNo(dado);
    if (dado < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, dado);
    else if (dado > raiz->dado)
        raiz->direito = inserir(raiz->direito, dado);
    return raiz;
}

// b) Buscar
No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado)
        return raiz;
    if (dado < raiz->dado)
        return buscar(raiz->esquerdo, dado);
    else
        return buscar(raiz->direito, dado);
}

// b) Remover todos os nós
void remover(No* raiz) {
    if (raiz != NULL) {
        remover(raiz->esquerdo);
        remover(raiz->direito);
        free(raiz);
    }
}

// d) In-ordem (esquerda, raiz, direita)
void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        inOrdem(raiz->direito);
    }
}

// e) Pré-ordem (raiz, esquerda, direita)
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

// f) Pós-ordem (esquerda, direita, raiz)
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

// g) Altura da árvore
int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int altEsq = altura(raiz->esquerdo);
    int altDir = altura(raiz->direito);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

// h) Profundidade de um nó
int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, nivel + 1);
    else
        return profundidade(raiz->direito, valor, nivel + 1);
}

// i) Soma dos valores
int somaValores(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + somaValores(raiz->esquerdo) + somaValores(raiz->direito);
}

// j) Nível de um nó (igual profundidade)
int nivel(No* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}

// k) Número de nós
int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}

// l) Número de folhas
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}

// Teste principal
int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("In-ordem: "); inOrdem(raiz); printf("\n");
    printf("Pre-ordem: "); preOrdem(raiz); printf("\n");
    printf("Pos-ordem: "); posOrdem(raiz); printf("\n");

    printf("Altura: %d\n", altura(raiz));
    printf("Profundidade do 60: %d\n", profundidade(raiz, 60, 0));
    printf("Nivel do 60: %d\n", nivel(raiz, 60));
    printf("Soma dos valores: %d\n", somaValores(raiz));
    printf("Numero de nos: %d\n", contarNos(raiz));
    printf("Numero de folhas: %d\n", contarFolhas(raiz));

    remover(raiz);
    return 0;
}