#include <stdio.h>

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return meio; // valor encontrado na posição 'meio'
        } else if (vetor[meio] < valor) {
            inicio = meio + 1; // busca na metade direita
        } else {
            fim = meio - 1; // busca na metade esquerda
        }
    }

    return -1; // valor não encontrado
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    int posicao = buscaBinaria(vetor, tamanho, valor);

    if (posicao != -1)
        printf("Valor encontrado na posição %d.\n", posicao);
    else
        printf("Valor não encontrado no vetor.\n");

    return 0;
}
