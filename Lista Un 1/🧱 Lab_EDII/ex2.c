#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do nó da árvore binária para alunos
typedef struct aluno {
    char nome[50];
    int matricula;
    float nota;
    struct aluno *esquerda;
    struct aluno *direita;
} aluno;

// Função para criar um novo nó de aluno
aluno* criarAluno(const char* nome, int matricula, float nota) {
    aluno* novo = (aluno*)malloc(sizeof(aluno));
    if (novo) {
        strncpy(novo->nome, nome, 49);
        novo->nome[49] = '\0';
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

// Função para inserir um novo aluno na árvore (ordenando por matrícula)
aluno* inserir(aluno* raiz, const char* nome, int matricula, float nota) {
    if (raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    if (matricula < raiz->matricula) {
        raiz->esquerda = inserir(raiz->esquerda, nome, matricula, nota);
    } else {
        raiz->direita = inserir(raiz->direita, nome, matricula, nota);
    }
    return raiz;
}

// Impressão em ordem (matrícula crescente)
void inOrdem(aluno* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda);
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        inOrdem(raiz->direita);
    }
}

// Impressão pré-ordem
void preOrdem(aluno* raiz) {
    if (raiz != NULL) {
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Impressão pós-ordem
void posOrdem(aluno* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
    }
}

int main() {
    aluno* raiz = NULL;
    // Exemplo de inserção de alunos
    raiz = inserir(raiz, "Pedro Henrique", 10, 8.5);
    raiz = inserir(raiz, "caio", 5, 7.2);
    raiz = inserir(raiz, "savio", 15, 4.0);
    raiz = inserir(raiz, "joao carlos", 12, 6.8);
    raiz = inserir(raiz, "Giovani", 20, 7.9);

    printf("Alunos em ordem (matrícula crescente):\n");
    inOrdem(raiz);

    printf("\nAlunos em pré-ordem:\n");
    preOrdem(raiz);

    printf("\nAlunos em pós-ordem:\n");
    posOrdem(raiz);

    return 0;
}