#include <stdio.h>

// Função recursiva x(n)
int x(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return x(n - 1) + x(n - 2);
    }
}

int main() {
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int resultado = x(n);
    printf("Resultado: %d\n", resultado);

    return 0;
}
