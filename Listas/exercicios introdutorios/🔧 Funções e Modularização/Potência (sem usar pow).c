// codigo em c para potenciação de um número
// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [01/05/2025]
/* Observação:
Certifique-se de estar no diretório correto ao executar o comando 
no terminal. Use o comando cd para navegar até o diretório do arquivo antes de compilar:*/
// Compilação: gcc -o potencia potencia.c
// Execução: ./potencia
// Observação: O programa calcula a potência de um número inteiro não negativo usando apenas multiplicações.

#include <stdio.h>

// Função para calcular potência usando apenas multiplicações
int potencia(int base, int expoente) {
    int resultado = 1;
    int i;
    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente (inteiro >= 0): ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Expoente negativo não é suportado.\n");
    } else {
        int resultado = potencia(base, expoente);
        printf("%d^%d = %d\n", base, expoente, resultado);
    }

    return 0;
}
