#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_PALAVRA 20
#define MAX_TENTATIVAS 6

int main() {
    char palavraSecreta[TAMANHO_PALAVRA] = "computador";  // palavra a ser adivinhada
    int tamanho = strlen(palavraSecreta);
    char letrasDescobertas[TAMANHO_PALAVRA];
    int tentativasRestantes = MAX_TENTATIVAS;
    char letra;
    int acertouTudo = 0;

    // Inicializa letrasDescobertas com '_'
    for (int i = 0; i < tamanho; i++) {
        letrasDescobertas[i] = '_';
    }

    printf("==== Jogo da Forca ====\n");

    while (tentativasRestantes > 0 && !acertouTudo) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", letrasDescobertas[i]);
        }

        printf("\nTentativas restantes: %d", tentativasRestantes);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);  // converte para minúscula

        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra && letrasDescobertas[i] == '_') {
                letrasDescobertas[i] = letra;
                acertou = 1;
            }
        }

        if (!acertou) {
            printf("Letra incorreta!\n");
            tentativasRestantes--;
        } else {
            printf("Boa! Você acertou uma letra.\n");
        }

        // Verifica se todas as letras foram descobertas
        acertouTudo = 1;
        for (int i = 0; i < tamanho; i++) {
            if (letrasDescobertas[i] == '_') {
                acertouTudo = 0;
                break;
            }
        }
    }

    if (acertouTudo) {
        printf("\nParabéns! Você venceu! A palavra era: %s\n", palavraSecreta);
    } else {
        printf("\nGame Over! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
