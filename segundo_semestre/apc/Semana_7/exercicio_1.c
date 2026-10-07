#include <stdio.h>

int mult(int a, int b) {
    return a * b;
}

int soma_mult(int a, int b, int c) {
    return a + mult(b, c);
}

int main(void) {
    int resultado = soma_mult(1, 5, 3);
    printf("%d\n", resultado);   /* 16 */
    return 0;
}

/*Descrevendo o que está ocorrendo
 * A função soma_mult recebe três parâmetros: a, b e c.
 * Ela chama a função mult com os parâmetros b e c, e depois soma o resultado com a.
 * No main, soma_mult(1, 5, 3) é chamada.
 * mult(5, 3) retorna 15.
 * 1 + 15 = 16.
 */