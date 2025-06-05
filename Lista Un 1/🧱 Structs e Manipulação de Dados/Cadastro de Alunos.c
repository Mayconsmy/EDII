// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [03/05/2025]

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int matricula;
    float media;
} Aluno;

int main() {
    int n, i;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    Aluno* alunos = (Aluno*) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    // Leitura dos dados dos alunos
    for (i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        getchar(); // Limpa o buffer antes de fgets
        fgets(alunos[i].nome, TAM_NOME, stdin);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media: ");
        scanf("%f", &alunos[i].media);
        }