// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [03/05/2025]
// /* Observação:
// Certifique-se de estar no diretório correto ao executar o comando
// no terminal. Use o comando cd para navegar até o diretório do arquivo antes de compilar:*/
// Compilação: gcc -o frequencia "Frequência de Números.c"


#include <stdio.h>

int main() {
    int numeros[10];
    int contagem[10] = {0}; // Armazena quantas vezes cada número foi contado
    int i, j;
    int jaContado;

    // Leitura dos 10 números
    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    // Contagem das ocorrências
    for (i = 0; i < 10; i++) {
        jaContado = 0;
        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                jaContado = 1;
                break;
            }
        }
        if (!jaContado) {
            int contador = 1;
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    contador++;
                }
            }
            printf("O numero %d aparece %d vez(es).\n", numeros[i], contador);
        }
    }

    return 0;
}
