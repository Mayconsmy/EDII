/*O algoritmo 1 tem como objetivo calcular o tempo médio de execução da função recursiva x(n) para um valor fixo n₀, 
repetindo a execução N_Max vezes. Ele utiliza a soma dos tempos de execução individuais e, ao final, retorna a média aritmética desses tempos. 
Esse procedimento é útil na análise empírica de complexidade temporal de algoritmos*/
/*
Algorithm 1: Calculo da função ao recursiva x(n)
input: Algoritmo para x(n) avaliado para n = n₀
Output: Tempo medio do algoritmo x(n) para n = n₀, N_Max
N = 0;
T = 0;
if N ≤ N_Max then
    return T / N_Max
end
else
    N = N + 1;
    T = T + tempo_execucao(x(n₀));
    Execute Algoritmo para calcular x(n₀);
end
*/