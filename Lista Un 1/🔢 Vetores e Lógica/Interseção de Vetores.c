// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [03/05/2025]
// /* Observação:
// Certifique-se de estar no diretório correto ao executar o comando   
// no terminal. Use o comando cd para navegar até o diretório do arquivo antes de compilar:*/
// Compilação: gcc -o intersecao "Interseção de Vetores.c"

#include <stdio.h>

int main() {
    int vetor1[5], vetor2[5];
    int i, j, k;
    int comuns[5]; // Supondo no máximo 5 elementos comuns
    int count = 0;
    int jaInserido;

    printf("Digite 5 numeros para o primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Digite 5 numeros para o segundo vetor:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &vetor2[i]);
    }

    // Verifica elementos comuns
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (vetor1[i] == vetor2[j]) {
                // Verifica se já foi adicionado
                jaInserido = 0;
                for (k = 0; k < count; k++) {
                    if (comuns[k] == vetor1[i]) {
                        jaInserido = 1;
                        break;
                    }
                }
                if (!jaInserido) {
                    comuns[count] = vetor1[i];
                    count++;
                }
            }
        }
    }

    // Mostra elementos comuns
    if (count == 0) {
        printf("Nao ha elementos comuns.\n");
    } else {
        printf("Elementos comuns:\n");
        for (i = 0; i < count; i++) {
            printf("%d ", comuns[i]);
        }
        printf("\n");
    }

    return 0;
}
