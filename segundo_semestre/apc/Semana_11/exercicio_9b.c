#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

#include <stddef.h>
/* Inclui definições de tipos auxiliares, em particular ptrdiff_t, que é o
   tipo retornado pela subtração de dois ponteiros. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    int v[4] = {10, 20, 30, 40};
/* Declara um ARRAY de 4 inteiros chamado v e o inicializa com os valores
   10, 20, 30, 40. Os índices válidos são 0 a 3:
   v[0]=10, v[1]=20, v[2]=30, v[3]=40.
   Na memória, os 4 ints ficam em posições CONTÍGUAS, por exemplo:
   endereço base+0 → 10
   endereço base+4 → 20   (assumindo sizeof(int)=4)
   endereço base+8 → 30
   endereço base+12 → 40 */

    int *p = v;
/* Declara p como ponteiro para int e o inicializa com v.
   Em C, o NOME de um array (sem índice) DECAI para um ponteiro para seu
   primeiro elemento. Portanto "int *p = v;" equivale a "int *p = &v[0];".
   Agora p aponta para v[0] (valor 10). */

    printf("*p     = %d\n", *p);
/* *p desreferencia p — acessa o valor no endereço apontado.
   Como p aponta para v[0], *p = 10.
   Saída: *p     = 10. */

    printf("*(p+1) = %d\n", *(p+1));
/* ARITMÉTICA DE PONTEIROS: p+1 não avança 1 BYTE, avança 1 ELEMENTO
   (ou seja, sizeof(int) bytes = 4 bytes na maioria das plataformas).
   Portanto p+1 aponta para v[1], e *(p+1) = 20.
   Equivalência fundamental: *(p + i) ≡ p[i].
   Saída: *(p+1) = 20. */

    printf("*(p+2) = %d\n", *(p+2));
/* p+2 aponta para v[2] (2 elementos à frente de v[0]).
   *(p+2) = v[2] = 30.
   Saída: *(p+2) = 30. */

    int *q = v + 3;
/* v+3 aplica aritmética de ponteiros ao nome do array: aponta para v[3].
   Portanto q aponta para o último elemento, cujo valor é 40.
   Equivalência: v + 3 ≡ &v[3]. */

    ptrdiff_t diff = q - p;
/* SUBTRAÇÃO DE PONTEIROS: quando ambos apontam para o MESMO array, a
   diferença é o número de ELEMENTOS entre eles (não bytes!).
   q aponta para v[3], p aponta para v[0]. A diferença é 3 elementos.
   O tipo do resultado é ptrdiff_t (inteiro com sinal, definido em stddef.h),
   por isso o formato correto para imprimir é %td. */

    printf("q - p  = %td\n", diff);   /* 3 */
/* %td é o especificador para ptrdiff_t (o "t" indica "tamanho de ponteiro").
   Saída: q - p  = 3.
   Note: o valor é 3 (elementos), NÃO 12 (bytes). Se fosse 12 bytes, seria
   porque sizeof(int)=4 — mas a subtração de ponteiros sempre retorna a
   diferença em ELEMENTOS, não em bytes. */

    p++;
/* Pós-incremento de ponteiro: p passa a apontar para o PRÓXIMO elemento.
   Como p apontava para v[0], agora aponta para v[1].
   O incremento avança sizeof(int) bytes (4 bytes), não 1 byte.
   Equivalência: p++ ≡ p = p + 1. */

    printf("apos p++: *p = %d\n", *p);   /* 20 */
/* Após o incremento, p aponta para v[1], cujo valor é 20.
   Saída: apos p++: *p = 20.
   Observação: o array v NÃO foi modificado — apenas o PONTEIRO p mudou
   de posição. v[0] continua valendo 10. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}