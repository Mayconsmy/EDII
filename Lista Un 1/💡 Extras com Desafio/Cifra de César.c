#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cifraDeCesar(char *mensagem, int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        char c = mensagem[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            mensagem[i] = (c - base + deslocamento) % 26 + base;
        }
        // Caracteres não alfabéticos permanecem inalterados
    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    printf("Digite a mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remover newline, se presente
    size_t len = strlen(mensagem);
    if (mensagem[len - 1] == '\n') {
        mensagem[len - 1] = '\0';
    }

    printf("Digite o deslocamento (ex: 3): ");
    scanf("%d", &deslocamento);

    cifraDeCesar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}
