#include <stdio.h>
#include <time.h>

long long fibonacci_iterativo(int n) {
    if (n <= 1) return 1;

    long long a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    int N_Max = 1000;
    double total_time = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        fibonacci_iterativo(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / N_Max);
    return 0;
}
/*
| n  | Tempo Médio (segundos)  |
|----|-------------------------| 
| 100 |    0.000001            |
| 200 |    0.000001            |
| 300 |    0.000001            |
| 400 |    0.000001            |
| 500 |    0.000001            |
| 600 |    0.000002            |
| 700 |    0.000001            |
-------------------------------
*/