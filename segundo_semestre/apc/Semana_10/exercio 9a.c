#include <stdio.h>

int main(void) {
    int x = 10;
    int \*p = \&x;

    printf("x    = %d\\n",  x);
    printf("\&x   = %p\\n",  (void\*)\&x);
    printf("p    = %p\\n",  (void\*)p);
    printf("\*p   = %d\\n",  \*p);

    \*p = 99;
    printf("x apos \*p=99: %d\\n", x);
    return 0;
}

/*conforme solicitado segue explicação linha por linha*/

#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    int x = 10;
/* Declara a variável inteira x e a inicializa com 10.
   Em memória, o compilador reserva sizeof(int) bytes (geralmente 4) para
   armazenar o valor 10 em algum endereço, por exemplo 0x7ffd1234. */

    int *p = &x;
/* Declara p como um PONTEIRO PARA INT (int *) e o inicializa com o ENDEREÇO
   de x (operador & = "endereço de").
   Agora p "aponta para" x: o valor armazenado em p é o endereço de x,
   não o número 10. */

    printf("x    = %d\n",  x);
/* Imprime o VALOR armazenado em x usando %d (inteiro decimal).
   Saída: x    = 10. */

    printf("&x   = %p\n",  (void*)&x);
/* - &x é o ENDEREÇO de x;
   - %p é o formato para imprimir PONTEIROS (endereços), usualmente em
     hexadecimal;
   - (void*)&x converte o ponteiro de int* para void*.
     Isso é necessário porque %p espera um void* — passar outro tipo de
     ponteiro é tecnicamente comportamento indefinido em C (na prática
     funciona, mas o cast é a forma correta).
   Saída: algo como &x   = 0x7ffd1234 (endereço varia a cada execução). */

    printf("p    = %p\n",  (void*)p);
/* - p contém o endereço de x, então imprimir p mostra esse endereço;
   - (void*)p faz o mesmo cast que na linha anterior, pelo mesmo motivo.
   Como p = &x, a saída desta linha é IDÊNTICA à da linha anterior:
   p e &x guardam o mesmo valor (o endereço de x).
   Saída: p    = 0x7ffd1234 (mesmo endereço mostrado acima). */

    printf("*p   = %d\n",  *p);
/* O operador * (desreferência) acessa o VALOR ARMAZENADO NO ENDEREÇO
   apontado por p. Como p aponta para x, *p é o próprio x = 10.
   Usa %d porque *p é um int.
   Saída: *p   = 10. */

    *p = 99;
/* Atribuição através do ponteiro: o lado esquerdo *p é um "lvalue" —
   significa "o local apontado por p". Atribuir 99 a *p é equivalente a
   atribuir 99 a x, pois p aponta para x.
   Após esta linha, x vale 99. */

    printf("x apos *p=99: %d\n", x);
/* Imprime x novamente para provar que a alteração via ponteiro afetou a
   variável original. Como p aponta para x, *p = 99 modificou x.
   Saída: x apos *p=99: 99. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}
