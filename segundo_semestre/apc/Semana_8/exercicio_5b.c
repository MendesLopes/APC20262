### 🔬 Exercício 5b — for com break e continue

```c
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;
        if (i == 7)     break;
        printf("%d\\n", i);
    }
    return 0;
}
```




#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos.
   Tudo dentro de { } será executado. */

    for (int i = 0; i < 10; i++) {
/* Laço for com três partes:
   - inicialização: declara i = 0 (variável local ao laço);
   - condição: continua enquanto i < 10;
   - incremento: i++ após cada iteração (i = i + 1).
   O bloco será repetido para i = 0, 1, 2, ..., 9 (ou até um break). */

        if (i % 2 == 0) continue;
/* Se o resto da divisão de i por 2 for 0 (i é PAR), executa continue.
   O continue PULA o restante do corpo do laço e vai direto para o
   incremento (i++) e a próxima verificação da condição.
   Ou seja: números pares nunca chegam às linhas seguintes. */

        if (i == 7)     break;
/* Se i == 7, executa break, que ENCERRA o laço imediatamente —
   sai do for por completo, sem executar o incremento nem o restante
   do corpo. Só é alcançado por i ímpar (por causa do continue acima). */

        printf("%d\n", i);
/* Imprime o valor de i seguido de quebra de linha.
   Só é executado para valores ÍMPARES menores que 7. */

    }
/* Fim do corpo do laço. Após cada iteração sem continue/break,
   o incremento i++ é executado e a condição i < 10 é reavaliada. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}