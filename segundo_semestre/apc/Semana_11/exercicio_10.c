#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece printf e perror. */

#include <stdlib.h>
/* Inclui a biblioteca utilitária padrão, que fornece calloc, realloc e free. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    int n = 4;
/* Declara a variável inteira n e a inicializa com 4.
   Representa a QUANTIDADE de elementos que o array dinâmico terá. */

    int *v = calloc(n, sizeof(int));   /* heap, inicializado com 0 */
/* calloc(nmemb, size) aloca memória no HEAP para nmemb elementos de size bytes
   cada, e ZERA todos os bytes alocados (diferente de malloc, que deixa lixo).
   - n = 4, sizeof(int) = 4 → aloca 4 * 4 = 16 bytes;
   - Retorna um ponteiro para o início do bloco, ou NULL se falhar.
   A variável v (na stack) guarda esse ponteiro para o heap. */

    if (!v) { perror("calloc"); return 1; }
/* - !v é o mesmo que v == NULL — testa se a alocação falhou;
   - perror("calloc") imprime uma mensagem de erro do sistema precedida
     pela string "calloc", como "calloc: Cannot allocate memory";
   - return 1 encerra o programa com código de erro (não-zero).
   Esta é a forma CORRETA de tratar falha de alocação — nunca usar o
   ponteiro sem verificar. */

    for (int i = 0; i < n; i++) v[i] = (i + 1) * 10;
/* Preenche o array: v[0]=10, v[1]=20, v[2]=30, v[3]=40.
   Acessa cada posição com a sintaxe de array (v[i] ≡ *(v + i)).
   Como calloc zerou tudo, mesmo que pulássemos esta linha, os valores
   iniciais seriam 0. */

    for (int i = 0; i < n; i++) printf("v[%d]=%d\n", i, v[i]);
/* Imprime os 4 elementos atuais.
   Saída:
   v[0]=10
   v[1]=20
   v[2]=30
   v[3]=40 */

    /* expandir para 6 elementos */
    n = 6;
/* Atualiza n para 6 — novo tamanho desejado do array. */

    int *tmp = realloc(v, n * sizeof(int));
/* realloc(ptr, novo_tamanho) REDIMENSIONA o bloco apontado por ptr:
   - Se houver espaço adjacente suficiente, pode estender no mesmo local;
   - Caso contrário, aloca um NOVO bloco, copia os dados antigos e
     libera o antigo automaticamente;
   - Retorna o ponteiro para o novo bloco, ou NULL em falha.
   IMPORTANTE: realloc NÃO zera os bytes novos (v[4] e v[5] terão lixo);
   e o ponteiro antigo NÃO deve mais ser usado — daí o padrão de usar
   uma variável temporária (tmp). */

    if (!tmp) { free(v); perror("realloc"); return 1; }
/* Tratamento de erro CRÍTICO:
   - Se realloc falhar, ele retorna NULL mas NÃO libera o bloco antigo;
   - Por isso precisamos liberar v manualmente com free(v) para evitar
     VAZAMENTO DE MEMÓRIA;
   - Depois imprime erro e encerra com código 1.
   Se tivéssemos feito v = realloc(v, ...) diretamente e realloc falhasse,
   v passaria a ser NULL e o bloco antigo ficaria inacessível = leak. */

    v = tmp;
/* Só agora atualizamos v: realloc teve sucesso, então tmp aponta para o
   novo bloco (possivelmente o mesmo endereço, possivelmente diferente).
   A partir daqui, v é o ponteiro válido para o array de 6 elementos. */

    v[4] = 50; v[5] = 60;
/* Preenche os dois NOVOS elementos (índices 4 e 5).
   Como realloc não inicializa os bytes adicionados, é nossa
   responsabilidade atribuir valores antes de lê-los.
   Os elementos antigos (v[0]..v[3]) foram preservados por realloc. */

    for (int i = 0; i < n; i++) printf("v[%d]=%d\n", i, v[i]);
/* Imprime todos os 6 elementos do array expandido.
   Saída:
   v[0]=10
   v[1]=20
   v[2]=30
   v[3]=40
   v[4]=50
   v[5]=60 */

    free(v);
/* free(ptr) devolve ao sistema operacional o bloco de memória alocado.
   É OBRIGATÓRIO liberar toda memória dinâmica — caso contrário há
   VAZAMENTO DE MEMÓRIA (memory leak) até o fim do processo.
   Após free(v), o valor de v é inválido (ponteiro pendurado / dangling). */

    v = NULL;
/* Boa prática: após free, atribuir NULL ao ponteiro.
   Isso evita uso acidental de ponteiro liberado (use-after-free) e
   torna um eventual segundo free(v) seguro (free(NULL) é no-op). */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}