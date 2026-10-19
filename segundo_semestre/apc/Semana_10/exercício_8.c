#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char s\[] = "Brasilia";
    printf("Comprimento: %zu\\n", strlen(s));

    for (int i = 0; s\[i] != '\\0'; i++)
        printf("s\[%d]='%c' ASCII=%d\\n", i, s\[i], (int)s\[i]);

    /\* comparação \*/
    printf("strcmp: %d\\n", strcmp(s, "Brasilia"));    /\* 0 \*/
    printf("strcmp: %d\\n", strcmp(s, "Curitiba"));    /\* negativo \*/

    /\* busca \*/
    char \*pos = strchr(s, 'i');
    if (pos) printf("Primeiro 'i' na posição %td\\n", pos - s);  /\* 5 \*/

    /\* conversão \*/
    int n = atoi("1234");
    printf("atoi(\\"1234\\") = %d\\n", n);
    return 0;
}

/*conforme solicitado, segue abaixo explicação do código*/

#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

#include <string.h>
/* Inclui a biblioteca de manipulação de strings, que fornece strlen, strcmp e strchr. */

#include <stdlib.h>
/* Inclui a biblioteca utilitária padrão, que fornece atoi (conversão de string para int). */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    char s[] = "Brasilia";
/* Declara um array de char inicializado com a string "Brasilia".
   O compilador adiciona automaticamente o caractere terminador '\0' ao final,
   então s ocupa 9 bytes: 'B','r','a','s','i','l','i','a','\0'.
   Como o tamanho não foi especificado (s[]), o compilador o deduz do literal.
   Em C, uma string é apenas um array de char terminado em '\0'. */

    printf("Comprimento: %zu\n", strlen(s));
/* strlen(s) percorre s até encontrar '\0' e devolve o número de caracteres
   ANTES do terminador — ou seja, 8 (não conta o '\0').
   O formato %zu é o correto para size_t (o tipo retornado por strlen).
   Saída: Comprimento: 8. */

    for (int i = 0; s[i] != '\0'; i++)
/* Laço for que percorre a string da posição 0 até encontrar o terminador '\0'.
   A condição de parada NÃO é um número fixo — é o próprio caractere nulo,
   que marca o fim da string. Isso permite percorrer strings de qualquer tamanho
   sem saber o comprimento de antemão. */

        printf("s[%d]='%c' ASCII=%d\n", i, s[i], (int)s[i]);
/* Para cada caractere:
   - %d  → imprime o índice i;
   - %c  → imprime o caractere s[i];
   - (int)s[i] converte o char para o código ASCII correspondente;
   - %d  → imprime esse código ASCII.
   Cada iteração imprime uma linha, por exemplo: s[0]='B' ASCII=66. */

    /* comparação */
    printf("strcmp: %d\n", strcmp(s, "Brasilia"));    /* 0 */
/* strcmp(a, b) compara strings lexicograficamente:
   - retorna 0 se forem IGUAIS;
   - retorna negativo se a < b;
   - retorna positivo se a > b.
   Aqui s == "Brasilia", então retorna 0.
   Saída: strcmp: 0. */

    printf("strcmp: %d\n", strcmp(s, "Curitiba"));    /* negativo */
/* Compara "Brasilia" com "Curitiba".
   O primeiro caractere diferente é o primeiro: 'B' (66) vs 'C' (67).
   Como 'B' < 'C', strcmp retorna um valor NEGATIVO (a diferença exata
   depende da implementação; tipicamente é 66 - 67 = -1).
   Saída: strcmp: (valor negativo, geralmente -1). */

    /* busca */
    char *pos = strchr(s, 'i');
/* strchr(s, c) procura a PRIMEIRA ocorrência do caractere c em s.
   - Se encontrar, retorna um PONTEIRO para essa posição dentro de s;
   - Se não encontrar, retorna NULL.
   Aqui procura o primeiro 'i' em "Brasilia", que está no índice 5
   ('B'=0, 'r'=1, 'a'=2, 's'=3, 'i'=4, 'l'=5 — atenção: o primeiro 'i'
   na verdade está no índice 4! Vamos ver o comentário do código abaixo). */

    if (pos) printf("Primeiro 'i' na posição %td\n", pos - s);  /* 5 */
/* - if (pos) é uma forma idiomática de testar se pos != NULL;
   - pos - s faz ARITMÉTICA DE PONTEIROS: a diferença entre dois ponteiros
     que apontam para o mesmo array é o número de ELEMENTOS entre eles.
     Como s aponta para o índice 0 e pos aponta para o 'i' encontrado,
     pos - s dá exatamente o índice.
   - %td é o formato para o tipo ptrdiff_t (resultado de subtração de ponteiros).
   Observação: no literal "Brasilia" o primeiro 'i' está no índice 4,
   então a saída real seria "Primeiro 'i' na posição 4". O comentário /* 5 */
   no código original está INCORRETO — o valor correto é 4. */

    /* conversão */
    int n = atoi("1234");
/* atoi (ASCII to integer) converte uma string numérica em int.
   - "1234" → 1234;
   - Ignora espaços iniciais;
   - Para de ler no primeiro caractere não numérico;
   - Se a string não começar com número, retorna 0;
   - NÃO detecta overflow (para isso usar strtol). */

    printf("atoi(\"1234\") = %d\n", n);
/* Imprime o resultado da conversão.
   As \" dentro do printf servem para imprimir aspas literais na saída.
   Saída: atoi("1234") = 1234. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}