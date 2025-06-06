#include <stdio.h>
#include <time.h>

#define MAX 1000  
long long memo[MAX];  

long long x(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n]; 
    memo[n] = x(n - 1) + x(n - 2);     
    return memo[n];
}

int main() {
    int n;
    int N_Max = 1000;
    double total_time = 0;

    printf("Digite o valor de n (até %d): ", MAX - 1);
    scanf("%d", &n);

  
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    for (int i = 0; i < N_Max; i++) {
      
        for (int j = 0; j < MAX; j++) {
            memo[j] = -1;
        }

        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / N_Max);
    return 0;
}
/*
| n  | Tempo Médio (segundos) |
|----|------------------------| 
| 10 |    0.000000            |
| 20 |    0.000000            |
| 30 |    0.000000            |
| 40 |    0.000000            |
| 50 |    0.000001            |
| 60 |    0.000000            |
| 70 |    0.000001            |
-------------------------------
*/
