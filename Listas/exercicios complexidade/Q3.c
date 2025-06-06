/*
Aréa de teste do código:

(gdb) start
Temporary breakpoint 1 at 0x4014a8: file c:\Users\1mayc\OneDrive\Desktop\AEII\projeto_1u\Estruturas-de-dados-II\EDII\Listas\exercicios complexidade\Q2.c, line 15.
Starting program: C:\Users\1mayc\OneDrive\Desktop\AEII\projeto_1u\Estruturas-de-dados-II\EDII\Listas\exercicios complexidade\output/Q2.exe
[New Thread 17228.0xa64]
[New Thread 17228.0x3ed8]

Temporary breakpoint 1, main ()
    at c:\Users\1mayc\OneDrive\Desktop\AEII\projeto_1u\Estruturas-de-dados-II\EDII\Listas\exercicios complexidade\Q2.c:15  
15          printf("Digite o valor de n: ");
(gdb) n
Digite o valor de n: 16     scanf("%d", &n);
(gdb) n
n
18          int resultado = x(n);
(gdb) n
19          printf("Resultado: %d\n", resultado);
(gdb) print resultado
$1 = 1
(gdb) print n
$2 = 0
(gdb) quit
A debugging session is active.

        Inferior 1 [process 17228] will be killed.

*/