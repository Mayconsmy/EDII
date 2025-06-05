// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [03/05/2025]

#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_NOME 100
#define TAM_TELEFONE 20

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
} Contato;

void adicionarContato(Contato contatos[], int *n) {
    if (*n >= MAX_CONTATOS) {
        printf("Limite de contatos atingido.\n");
        return;
    }

    printf("\n=== Adicionar Contato ===\n");
    printf("Nome: ");
    getchar(); // Limpa o buffer antes de fgets
    fgets(contatos[*n].nome, TAM_NOME, stdin);
    contatos[*n].nome[strcspn(contatos[*n].nome, "\n")] = '\0'; // Remove o \n

    printf("Telefone: ");
    fgets(contatos[*n].telefone, TAM_TELEFONE, stdin);
    contatos[*n].telefone[strcspn(contatos[*n].telefone, "\n")] = '\0';

    (*n)++;
    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(Contato contatos[], int n) {
    char nomeBusca[TAM_NOME];
    int encontrado = 0;

    printf("\n=== Buscar Contato ===\n");
    printf("Digite o nome: ");
    getchar(); // Limpa o buffer
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcasecmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

void listarContatos(Contato contatos[], int n) {
    printf("\n=== Lista de Contatos ===\n");
    if (n == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n\n", contatos[i].telefone);
    }
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int numContatos = 0;
    int opcao;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar contato\n");
        printf("2. Buscar contato por nome\n");
        printf("3. Listar todos os contatos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &numContatos);
                break;
            case 2:
                buscarContato(contatos, numContatos);
                break;
            case 3:
                listarContatos(contatos, numContatos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
