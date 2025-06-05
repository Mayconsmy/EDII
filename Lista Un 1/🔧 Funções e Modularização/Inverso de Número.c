// Codigo em C para inverter um número
// Autor: [Maycon Soares Maia]
// Doscente: [Dr. Kennedy Reurison Lopes]
// Data: [01/05/2025]
/* Observação:
Certifique-se de estar no diretório correto ao executar o comando 
no terminal. Use o comando cd para navegar até o diretório do arquivo antes de compilar:*/
// Compilação: gcc -o inverso "Inverso de Número.c"
// Execução: ./inverso
// Observação: O programa inverte uma string representando um número, mantendo os zeros à esquerda.
// O número é lido como uma string para preservar os zeros à esquerda e, em seguida, a string é invertida.

#include <stdio.h>
#include <string.h>

// Função para inverter uma string (in-place)
void inverterString(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char numero[100];

    printf("Digite um número (pode conter zeros à esquerda): ");
    scanf("%s", numero); // Lê como string

    inverterString(numero);

    printf("Número invertido (com zeros à esquerda): %s\n", numero);

    return 0;
}
