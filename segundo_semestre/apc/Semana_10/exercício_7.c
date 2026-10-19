#include <stdio.h>
#include <string.h>

int main(void) {
    int v\[5] = {10, 20, 30, 40, 50};
    int soma = 0;
    for (int i = 0; i < 5; i++) soma += v\[i];
    printf("soma = %d\\n", soma);

    /\* cópia de array com memcpy \*/
    int w\[5];
    memcpy(w, v, sizeof(v));
    w\[0] = 99;
    printf("v\[0]=%d  w\[0]=%d\\n", v\[0], w\[0]);   /\* 10 e 99 — independentes \*/

    /\* matriz \*/
    int m\[2]\[3] = {{1, 2, 3}, {4, 5, 6}};
    printf("m\[1]\[2] = %d\\n", m\[1]\[2]);   /\* 6 \*/

    /\* row-major: elementos consecutivos na memória \*/
    int \*p = \&m\[0]\[0];
    for (int i = 0; i < 6; i++) printf("%d ", p\[i]);   /\* 1 2 3 4 5 6 \*/
    printf("\\n");
    return 0;
}

/*confoem solicitado, segue explicação do código*/

#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

#include <string.h>
/* Inclui a biblioteca de manipulação de strings/memória, que fornece
   a função memcpy usada mais adiante. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos.
   Tudo dentro de { } será executado. */

    int v[5] = {10, 20, 30, 40, 50};
/* Declara um ARRAY de 5 inteiros chamado v e o inicializa com os valores
   10, 20, 30, 40, 50. Os índices válidos são 0 a 4 (v[0]=10, v[4]=50).
   Em C, o array ocupa 5 * sizeof(int) bytes contíguos na memória. */

    int soma = 0;
/* Declara a variável inteira soma e a inicializa com 0 (acumulador). */

    for (int i = 0; i < 5; i++) soma += v[i];
/* Laço for que percorre os índices 0 a 4:
   - i = 0 → soma += v[0] → soma = 0 + 10 = 10
   - i = 1 → soma += v[1] → soma = 10 + 20 = 30
   - i = 2 → soma += v[2] → soma = 30 + 30 = 60
   - i = 3 → soma += v[3] → soma = 60 + 40 = 100
   - i = 4 → soma += v[4] → soma = 100 + 50 = 150
   soma += v[i] equivale a soma = soma + v[i]. */

    printf("soma = %d\n", soma);
/* Imprime o valor final do acumulador: soma = 150. */

    /* cópia de array com memcpy */
    int w[5];
/* Declara outro array de 5 inteiros chamado w, SEM inicialização.
   Neste momento, w contém lixo de memória (valores indefinidos). */

    memcpy(w, v, sizeof(v));
/* memcpy(destino, origem, n_bytes) copia n_bytes da origem para o destino.
   - w é o destino;
   - v é a origem;
   - sizeof(v) = 5 * sizeof(int) = 20 bytes (em plataformas com int de 4 bytes).
   Resultado: w passa a conter {10, 20, 30, 40, 50} — uma CÓPIA INDEPENDENTE
   de v. Ou seja, agora há dois arrays distintos com os mesmos valores. */

    w[0] = 99;
/* Altera apenas o primeiro elemento do array w para 99.
   Como w é uma cópia independente, o array v permanece inalterado. */

    printf("v[0]=%d  w[0]=%d\n", v[0], w[0]);   /* 10 e 99 — independentes */
/* Imprime os primeiros elementos dos dois arrays:
   v[0] = 10 (intocado);
   w[0] = 99 (modificado).
   Isso demonstra que memcpy fez uma cópia por valor, e não uma referência. */

    /* matriz */
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
/* Declara uma MATRIZ (array bidimensional) de 2 linhas e 3 colunas.
   - Linha 0: {1, 2, 3}
   - Linha 1: {4, 5, 6}
   Acesso: m[linha][coluna]. Total = 2 * 3 = 6 inteiros. */

    printf("m[1][2] = %d\n", m[1][2]);   /* 6 */
/* Acessa o elemento da linha 1, coluna 2. Índices começam em 0, então:
   - linha 1 = segunda linha = {4, 5, 6}
   - coluna 2 = terceiro elemento = 6.
   Saída: m[1][2] = 6. */

    /* row-major: elementos consecutivos na memória */
    int *p = &m[0][0];
/* Declara um ponteiro p para int e o faz apontar para o endereço do
   PRIMEIRO elemento da matriz (&m[0][0]).
   Como a matriz é armazenada de forma CONTÍGUA na memória (layout
   row-major, linha por linha), p pode percorrer todos os 6 elementos
   sequencialmente apenas incrementando o índice. */

    for (int i = 0; i < 6; i++) printf("%d ", p[i]);   /* 1 2 3 4 5 6 */
/* Percorre 6 posições a partir de p:
   p[0] = m[0][0] = 1
   p[1] = m[0][1] = 2
   p[2] = m[0][2] = 3
   p[3] = m[1][0] = 4   (a memória "salta" para a próxima linha)
   p[4] = m[1][1] = 5
   p[5] = m[1][2] = 6
   Imprime cada valor seguido de espaço. Em C, p[i] é equivalente a
   *(p + i) — aritmética de ponteiros. */

    printf("\n");
/* Imprime uma quebra de linha ao final, apenas para formatar a saída. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}