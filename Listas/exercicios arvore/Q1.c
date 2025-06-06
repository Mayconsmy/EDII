#include <stdio.h>
#include <stdlib.h>

// a) Estrutura de um nó da árvore binária de busca
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Função auxiliar para criar um novo nó
No* criarNo(int c) { // b) Criação
    No* novo = (No*) malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = c;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// b) Inserção
No* insert(No* raiz, int c) {
    if (raiz == NULL)
        return criarNo(c);
    if (c < raiz->dado)
        raiz->esquerdo = insert(raiz->esquerdo, c);
    else if (c > raiz->dado)
        raiz->direito = insert(raiz->direito, c);
    return raiz;
}

// b) Busca
No* search(No* raiz, int c) {
    if (raiz == NULL || raiz->dado == c)
        return raiz;
    if (c < raiz->dado)
        return search(raiz->esquerdo, c);
    else
        return search(raiz->direito, c);
}

// b) Remoção
void remove(No* raiz) {
    if (raiz != NULL) {
        remove(raiz->esquerdo);
        remove(raiz->direito);
        free(raiz);
    }
}

// c) Função de teste
void testfunctions() {
    No* raiz = NULL;
    raiz = insert(raiz, 50);
    insert(raiz, 30);
    insert(raiz, 70);
    insert(raiz, 20);
    insert(raiz, 40);
    insert(raiz, 60);
    insert(raiz, 80);
    
    printf("Teste de busca: %s\n", search(raiz, 60) ? "Encontrado" : "Não encontrado");
}

// d) Percurso in-ordem (em ordem)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direito);
    }
}

// e) Percurso pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

// f) Percurso pós-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

// g) Altura da árvore
int height(No* raiz) {
    if (raiz == NULL)
        return -1;
    int esq = height(raiz->esquerdo);
    int dir = height(raiz->direito);
    return (esq > dir ? esq : dir) + 1;
}

// h) Profundidade de um nó (assumindo raiz com depth 0)
int depth(No* raiz, int valor, int level) {
    if (raiz == NULL)
        return -1;
    if (raiz->dado == valor)
        return level;
    if (valor < raiz->dado)
        return depth(raiz->esquerdo, valor, level + 1);
    else
        return depth(raiz->direito, valor, level + 1);
}

// i) Soma dos valores
int sum(No* raiz) {
    if (raiz == NULL)
        return 0;
    return raiz->dado + sum(raiz->esquerdo) + sum(raiz->direito);
}

// j) Nível de um nó (mesmo que depth)
int level(No* raiz, int valor) {
    return depth(raiz, valor, 0);
}

// k) Número de nós
int countnos(No* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + countnos(raiz->esquerdo) + countnos(raiz->direito);
}

// l) Número de folhas
int countsheets(No* raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL)
        return 1;
    return countsheets(raiz->esquerdo) + countsheets(raiz->direito);
}

// Função principal para testar as funções
// e exibir os resultados
int main() {
    No* raiz = NULL;
    raiz = insert(raiz, 50);
    insert(raiz, 30);
    insert(raiz, 70);
    insert(raiz, 20);
    insert(raiz, 40);
    insert(raiz, 60);
    insert(raiz, 80);

    printf("In-ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da árvore: %d\n", height(raiz));
    printf("Profundidade do nó 60: %d\n", depth(raiz, 60, 0));
    printf("Soma dos valores: %d\n", sum(raiz));
    printf("Nível do nó 40: %d\n", level(raiz, 40));
    printf("Número de nós: %d\n", countnos(raiz));
    printf("Número de folhas: %d\n", countsheets(raiz));

    remove(raiz); // libera toda a memória alocada

    return 0;
}
