#include <stdio.h>
#include <string.h>
#include <ctype.h> // para tolower (caso queira ignorar maiúsculas/minúsculas)

// Função para verificar se uma string é um palíndromo
int ehPalindromo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; // não é palíndromo
        }
        inicio++;
        fim--;
    }
    return 1; // é palíndromo
}

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (ehPalindromo(palavra))
        printf("É um palíndromo.\n");
    else
        printf("Não é um palíndromo.\n");

    return 0;
}
