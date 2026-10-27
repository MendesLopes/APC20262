#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    int   x  = 42;
/* Declara a variável inteira x e a inicializa com 42.
   Em memória, x ocupa sizeof(int) bytes (geralmente 4) em algum endereço,
   por exemplo 0x1000. */

    int  *p  = &x;
/* Declara p como PONTEIRO PARA INT (int *) e o inicializa com o endereço
   de x (&x). Agora p aponta para x:
   - p guarda o endereço 0x1000;
   - *p acessa o valor 42 em x. */

    int **pp = &p;
/* Declara pp como PONTEIRO PARA PONTEIRO PARA INT (int **) e o inicializa
   com o endereço de p (&p).
   Agora pp aponta para p, e p aponta para x. Temos uma INDIRETAÇÃO DUPLA:
   - pp guarda o endereço de p (ex.: 0x2000);
   - *pp acessa p (que vale 0x1000);
   - **pp acessa x (que vale 42). */

    printf("x   = %d\n",   x);
/* Imprime o valor direto de x usando %d.
   Saída: x   = 42. */

    printf("*p  = %d\n",  *p);
/* Uma indireção: *p acessa o valor no endereço que p guarda — que é x.
   Saída: *p  = 42. */

    printf("**pp= %d\n", **pp);
/* Duas indireções:
   - *pp  → desreferencia pp → obtém p (endereço de x);
   - **pp → desreferencia *pp → obtém o valor em x → 42.
   Equivalência: **pp ≡ *(*pp) ≡ *p ≡ x.
   Saída: **pp= 42. */

    **pp = 100;
/* ATRIBUIÇÃO ATRAVÉS DE DUAS INDIRETAÇÕES.
   O lado esquerdo **pp é um lvalue — significa "o local no fim da cadeia
   de ponteiros", ou seja, x.
   Como **pp ≡ x, atribuir 100 a **pp é equivalente a fazer x = 100.
   Nenhum ponteiro muda; apenas o VALOR FINAL apontado é alterado. */

    printf("x apos **pp=100: %d\n", x);
/* Imprime x para provar que a alteração via dupla indireção afetou a
   variável original. Agora x vale 100.
   Saída: x apos **pp=100: 100. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}