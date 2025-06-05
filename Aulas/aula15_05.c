#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Renomeado o array para evitar conflito com a função
int fibonacci_cache[1600] = {0};

// Função Fibonacci com memoização
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    if (fibonacci_cache[n] != 0) {
        return fibonacci_cache[n];
    }
    fibonacci_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibonacci_cache[n];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <n> <n_max>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    clock_t start, end;
    double tempo = 0.0;
    int resultado;

    for (int i = 0; i < n_max; i++) {
        start = clock();
        resultado = fibonacci(n);
        end = clock();
        tempo += (double)(end - start) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluido\n", ((i + 1) / (double)n_max) * 100);
    }

    printf("Fibonacci na posição %d eh %d\n", n, resultado);
    printf("Tempo médio: %f segundos\n", tempo / n_max);

    return 0;
}