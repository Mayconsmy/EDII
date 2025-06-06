#include <stdio.h>
#include <time.h>

int x(int n) {
    if (n <= 1) return 1;
    return x(n - 1) + x(n - 2);
}

int main() {
    int n;              
    int N_Max = 1000;    
    double total_time = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / N_Max);
    return 0;
}
/*
b) Tabela de resultados:
| n  | Tempo Médio (segundos) |
|----|------------------------| 
| 10 | 0.000000               |
| 15 | 0.000006               | 
| 20 | 0.000032               |
| 25 | 0.000343               |
| 30 | 0.003879               |
| 35 | 0.041994               |
| 40 | 0.100123               |
-------------------------------

c) A versão recursiva simples de Fibonacci faz muitas chamadas redundantes. Sua complexidade é:
                T(n) = O(2^n)
    isso ocorre porque a função chama a si mesma duas vezes para cada n > 1, resultando em uma árvore de chamadas exponencialmente grande.
*/