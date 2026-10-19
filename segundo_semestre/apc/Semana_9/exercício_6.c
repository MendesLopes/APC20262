#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) return 1;
    return n \* fatorial(n - 1);
}

void dobra(int \*x) { \*x \*= 2; }

int main(void) {
    printf("5! = %d\\n", fatorial(5));

    int v = 7;
    dobra(\&v);
    printf("dobro de 7 = %d\\n", v);

    /\* ponteiro para função \*/
    int (\*fn)(int) = fatorial;
    printf("fn(4) = %d\\n", fn(4));   /\* 24 \*/
    return 0;
}

#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int fatorial(int n) {
/* Declara a função fatorial, que recebe um inteiro n e devolve um inteiro.
   Esta é uma função RECURSIVA: ela chama a si mesma. */

    if (n <= 1) return 1;
/* Caso-base da recursão: se n for 0 ou 1 (ou menor), retorna 1.
   É o ponto que interrompe a recursão — sem ele, a função se chamaria para
   sempre. Lembre que 0! = 1! = 1 por definição. */

    return n * fatorial(n - 1);
/* Caso recursivo: retorna n multiplicado pelo fatorial de (n - 1).
   Ou seja, fatorial(n) = n · fatorial(n-1). A chamada fatorial(n-1) reduz
   o problema até chegar ao caso-base (n <= 1). */
}

void dobra(int *x) { *x *= 2; }
/* Declara a função dobra, que NÃO devolve valor (void) e recebe um PONTEIRO
   para int (int *x). O parâmetro x guarda o ENDEREÇO de uma variável.
   Dentro do corpo:
   - *x significa "o valor apontado por x";
   - *x *= 2 equivale a *x = *x * 2, ou seja, dobra o valor que está no
     endereço recebido. Como trabalhamos com o endereço, a alteração afeta
     a variável ORIGINAL do chamador (passagem por referência). */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    printf("5! = %d\n", fatorial(5));
/* Chama fatorial(5). A recursão se desenrola assim:
   fatorial(5) = 5 · fatorial(4)
              = 5 · 4 · fatorial(3)
              = 5 · 4 · 3 · fatorial(2)
              = 5 · 4 · 3 · 2 · fatorial(1)
              = 5 · 4 · 3 · 2 · 1 = 120.
   O valor 120 é passado ao printf, que imprime: 5! = 120. */

    int v = 7;
/* Declara a variável inteira v e a inicializa com 7. */

    dobra(&v);
/* Chama dobra passando o ENDEREÇO de v (operador & = "endereço de").
   Dentro de dobra, *x *= 2 dobra o valor apontado — que é o próprio v.
   Portanto v passa de 7 para 14. */

    printf("dobro de 7 = %d\n", v);
/* Imprime o valor atual de v, que já foi modificado pela função dobra.
   Saída: dobro de 7 = 14. */

    /* ponteiro para função */
    int (*fn)(int) = fatorial;
/* Declara fn como um PONTEIRO PARA FUNÇÃO que recebe um int e devolve um int.
   A sintaxe int (*fn)(int) lê-se: "fn é um ponteiro para função(int) que
   retorna int". A inicialização fn = fatorial faz fn apontar para o endereço
   da função fatorial (o nome da função, sem parênteses, representa seu
   endereço). Agora fn pode ser chamada como se fosse a própria fatorial. */

    printf("fn(4) = %d\n", fn(4));   /* 24 */
/* Chama a função apontada por fn — isto é, fatorial(4).
   fatorial(4) = 4 · 3 · 2 · 1 = 24.
   Saída: fn(4) = 24. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}