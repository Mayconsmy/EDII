// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [03/05/2025]

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    printf("\n=== Cadastro de Produto ===\n");
    printf("Nome: ");
    getchar(); // Limpa o buffer
    fgets(p.nome, TAM_NOME, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o '\n' do final

    printf("Codigo: ");
    scanf("%d", &p.codigo);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Preco: ");
    scanf("%f", &p.preco);

    produtos[*numProdutos] = p;
    (*numProdutos)++;
    printf("Produto cadastrado com sucesso!\n");
}

void buscarProduto(Produto produtos[], int numProdutos) {
    int codigo, i;
    printf("\n=== Buscar Produto ===\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    for (i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("\nProduto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: %.2f\n", produtos[i].preco);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void listarProdutos(Produto produtos[], int numProdutos) {
    int i;
    printf("\n=== Lista de Produtos ===\n");
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (i = 0; i < numProdutos; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: %.2f\n", produtos[i].preco);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Buscar produto\n");
        printf("3. Listar produtos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &numProdutos);
                break;
            case 2:
                buscarProduto(produtos, numProdutos);
                break;
            case 3:
                listarProdutos(produtos, numProdutos);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
