`c
#include <stdio.h>

int main(void) {
    int a = 17, b = 5;
    printf("%d / %d = %d\\n",  a, b, a / b);   /\* 3 — truncamento \*/
    printf("%d %% %d = %d\\n", a, b, a % b);   /\* 2 — resto \*/

    int x = 3;
    int pre = ++x;   /\* x=4, pre=4 \*/
    int pos = x++;   /\* pos=4, x=5 \*/
    printf("pre=%d  pos=%d  x=%d\\n", pre, pos, x);

    int max = (a > b) ? a : b;
    printf("max = %d\\n", max);

    /\* Bit a bit \*/
    unsigned char flags = 0;
    flags |= (1 << 2);   /\* liga bit 2: 0b00000100 = 4 \*/
    flags |= (1 << 5);   /\* liga bit 5: 0b00100100 = 36 \*/
    printf("flags = %u  (0x%02X)\\n", flags, flags);

    flags \&= \~(1 << 2);  /\* desliga bit 2: 0b00100000 = 32 \*/
    printf("flags sem bit2 = %u\\n", flags);
    return 0;
}





#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos.
   Tudo dentro de { } será executado. */

    int a = 17, b = 5;
/* Declara duas variáveis inteiras: a vale 17 e b vale 5. */

    printf("%d / %d = %d\n",  a, b, a / b);   /* 3 — truncamento */
/* a / b = 17 / 5. Como ambos são int, a divisão é inteira: o resultado é 3
   (a parte decimal .4 é descartada — daí o "truncamento").
   Imprime: 17 / 5 = 3. */

    printf("%d %% %d = %d\n", a, b, a % b);   /* 2 — resto */
/* %% no printf imprime um caractere % literal.
   a % b = 17 % 5 = 2 (resto da divisão inteira: 17 = 5·3 + 2).
   Imprime: 17 % 5 = 2. */

    int x = 3;
/* Declara x com valor 3. */

    int pre = ++x;   /* x=4, pre=4 */
/* ++x é o pré-incremento: primeiro incrementa x (3 → 4) e depois usa o valor
   na atribuição. Logo pre = 4 e x = 4. */

    int pos = x++;   /* pos=4, x=5 */
/* x++ é o pós-incremento: primeiro usa o valor atual de x (4) na atribuição
   e depois incrementa. Logo pos = 4 e x passa a 5. */

    printf("pre=%d  pos=%d  x=%d\n", pre, pos, x);
/* Imprime: pre=4  pos=4  x=5. */

    int max = (a > b) ? a : b;
/* Operador ternário condição ? valor_se_verdadeiro : valor_se_falso.
   a > b → 17 > 5 é verdadeiro, então max recebe a = 17. */

    printf("max = %d\n", max);
/* Imprime: max = 17. */

    /* Bit a bit */
    unsigned char flags = 0;
/* Declara flags como inteiro sem sinal de 8 bits, iniciando em 0 (0b00000000). */

    flags |= (1 << 2);   /* liga bit 2: 0b00000100 = 4 */
/* 1 << 2 desloca o bit 1 duas posições à esquerda → 0b00000100 = 4.
   |= é OR bit a bit com atribuição. Como flags = 0, o resultado é 4
   (liga o bit de índice 2). */

    flags |= (1 << 5);   /* liga bit 5: 0b00100100 = 36 */
/* 1 << 5 = 0b00100000 = 32.
   flags |= 32 → 0b00000100 | 0b00100000 = 0b00100100 = 36
   (liga também o bit 5). */

    printf("flags = %u  (0x%02X)\n", flags, flags);
/* %u imprime o unsigned char promovido a inteiro → 36.
   %02X imprime em hexadecimal maiúsculo com pelo menos 2 dígitos → 24.
   Saída: flags = 36  (0x24). */

    flags &= ~(1 << 2);  /* desliga bit 2: 0b00100000 = 32 */
/* 1 << 2 = 0b00000100.
   ~ inverte todos os bits: ~0b00000100 = 0b11111011 (máscara que tem 0 na
   posição 2 e 1 nas demais).
   flags &= ... faz AND bit a bit: 0b00100100 & 0b11111011 = 0b00100000 = 32
   (desliga o bit 2, mantém o bit 5). */

    printf("flags sem bit2 = %u\n", flags);
/* Imprime: flags sem bit2 = 32. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}