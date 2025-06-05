#include <stdio.h>

int main() {
    int matriz[4][4];
    int soma = 0;

    // Preenchendo a matriz
    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            // Se for elemento da diagonal principal, soma
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    // Exibindo a matriz (opcional)
    printf("\nMatriz:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma da diagonal principal: %d\n", soma);

    return 0;
}
