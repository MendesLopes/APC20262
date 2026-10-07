#include <stdio.h>

int global = 0;   /* variáveis globais são inicializadas com 0 automaticamente */

int main(void) {
    int a = 42;
    int b;          /* valor lixo — NUNCA use antes de atribuir */
    b = a + 8;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("global = %d\n", global);

    const int N = 100;
    /* N = 200; */   /* erro de compilação: assignment of read-only variable */
    printf("N = %d\n", N);
    return 0;
}
/* Descrevendo o que está ocorrendo
 * O programa demonstra o uso de variáveis globais e locais.
 * A variável global 'global' é inicializada automaticamente com 0.
 * A variável local 'a' é inicializada com 42, e 'b' recebe o valor de 'a + 8'.
 * O programa imprime os valores de 'a', 'b' e 'global'.
 * Também mostra o uso de uma constante 'N', que não pode ser modificada após a inicialização.
 */