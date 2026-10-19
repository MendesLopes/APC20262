### 🔬 Exercício 5a — if / else if / else

```c
#include <stdio.h>

int main(void) {
    int nota = 72;
    if      (nota >= 90) printf("A\\n");
    else if (nota >= 80) printf("B\\n");
    else if (nota >= 70) printf("C\\n");
    else                 printf("Reprovado\\n");
    return 0;
}
```

#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos.
   Tudo dentro de { } será executado. */

    int nota = 72;
/* Declara a variável inteira nota e a inicializa com o valor 72. */

    if      (nota >= 90) printf("A\n");
/* Primeira condição: verifica se nota >= 90 (72 >= 90 → falso).
   Como é falso, o printf("A\n") NÃO é executado; o fluxo passa para o próximo else if. */

    else if (nota >= 80) printf("B\n");
/* Segunda condição, só é avaliada porque a anterior foi falsa:
   nota >= 80 (72 >= 80 → falso). O printf("B\n") NÃO é executado;
   o fluxo passa para o próximo else if. */

    else if (nota >= 70) printf("C\n");
/* Terceira condição, avaliada porque as anteriores foram falsas:
   nota >= 70 (72 >= 70 → verdadeiro). O printf("C\n") É executado,
   imprimindo "C" seguido de quebra de linha. */

    else                 printf("Reprovado\n");
/* O else só seria executado se TODAS as condições anteriores fossem falsas.
   Como a condição anterior (nota >= 70) foi verdadeira, este bloco é ignorado. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}