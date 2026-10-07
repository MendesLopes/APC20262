#include <stdio.h>

int main(void) {
    printf("char:      %zu byte(s)\n", sizeof(char));
    printf("short:     %zu byte(s)\n", sizeof(short));
    printf("int:       %zu byte(s)\n", sizeof(int));
    printf("long:      %zu byte(s)\n", sizeof(long));
    printf("long long: %zu byte(s)\n", sizeof(long long));
    printf("float:     %zu byte(s)\n", sizeof(float));
    printf("double:    %zu byte(s)\n", sizeof(double));

    /* Promoção e truncamento */
    printf("\n7 / 2   = %d\n",   7 / 2);       /* 3  */
    printf("7.0 / 2 = %.1f\n",  7.0 / 2);      /* 3.5 */
    printf("(int)3.9= %d\n",    (int)3.9);      /* 3  */

    unsigned int u = 0;
    u--;  /* wrap-around: vira UINT_MAX */
    printf("0u - 1  = %u\n", u);
    return 0;
}
/* Descrevendo o que está ocorrendo
 * O programa imprime o tamanho em bytes de diferentes tipos de dados.
 * Em seguida, demonstra a promoção e truncamento de tipos em operações aritméticas.
 * Por fim, mostra o comportamento de wrap-around ao decrementar um valor unsigned int.
 */
