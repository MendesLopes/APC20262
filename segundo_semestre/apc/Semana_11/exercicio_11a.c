#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

#include <string.h>
/* Inclui a biblioteca de strings — neste código não é estritamente usada,
   mas costuma ser incluída quando se trabalha com o campo char[] da struct. */

typedef struct {
/* Define uma nova ESTRUTURA (struct) ANÔNIMA e, com typedef, dá a ela o
   nome Ponto. Sem o typedef, teríamos que escrever "struct Ponto" toda vez;
   com ele, basta escrever "Ponto" como se fosse um tipo primitivo. */

    char nome[30];
/* Campo 1: array de 30 chars para armazenar o nome do ponto.
   Cabe até 29 caracteres + o terminador '\0'. */

    int  x, y;
/* Campos 2 e 3: dois inteiros x e y representando as coordenadas.
   Dois campos declarados na mesma linha, ambos int. */
} Ponto;
/* Fecha a struct e cria o ALIAS Ponto via typedef.
   Agora Ponto é um tipo de dado completo: podemos declarar variáveis
   como "Ponto a;" — a memória reservada terá 30 + 4 + 4 = 38 bytes
   (com possível padding para alinhamento, tipicamente 40 bytes). */

float dist2(const Ponto *a, const Ponto *b) {
/* Declara a função dist2 que:
   - recebe DOIS PONTEIROS constantes para Ponto (const Ponto *);
     "const" indica que a função promete NÃO modificar as structs apontadas;
   - retorna float (a distância ao quadrado, sem extrair a raiz).
   Passar structs por ponteiro é mais eficiente que por valor — evita
   copiar ~40 bytes a cada chamada. */

    int dx = a->x - b->x, dy = a->y - b->y;
/* O operador -> acessa um campo de struct ATRAVÉS DE UM PONTEIRO.
   Equivalência: a->x ≡ (*a).x  (o -> é apenas açúcar sintático).
   - dx = diferença das coordenadas X dos dois pontos;
   - dy = diferença das coordenadas Y.
   Declaração múltipla: dois ints na mesma linha. */

    return (float)(dx*dx + dy*dy);
/* Calcula o QUADRADO da distância euclidiana:
   dist² = dx² + dy²   (teorema de Pitágoras, sem a raiz).
   O cast (float) converte o resultado int para float antes do return,
   garantindo que o valor de retorno (tipo float) não perca informação.
   Se dx*dx + dy*dy for grande, poderia haver overflow em int antes do cast. */
}

int main(void) {
/* Declara a função principal main. */

    Ponto origem = {"origem", 0, 0};
/* Inicializa uma variável Ponto chamada origem com INICIALIZAÇÃO POR
   LISTA, na ordem dos campos:
   - nome = "origem" (copiado para o array char[30]);
   - x = 0;
   - y = 0.
   Os campos não especificados seriam zerados automaticamente. */

    Ponto p      = {"p",      3, 4};
/* Inicializa outra struct Ponto chamada p:
   - nome = "p";
   - x = 3;
   - y = 4. */

    printf("%s: (%d,%d)\n", p.nome, p.x, p.y);
/* O operador . (ponto) acessa campos de uma struct POR VALOR (variável direta).
   - %s → imprime a string p.nome ("p");
   - %d → p.x (3);
   - %d → p.y (4).
   Saída: p: (3,4). */

    Ponto *ptr = &p;
/* Declara ptr como PONTEIRO para Ponto e o inicializa com o endereço de p.
   Agora ptr aponta para a struct p, permitindo acesso INDIRETO aos campos. */

    ptr->x = 10;
/* Acessa o campo x da struct apontada por ptr usando -> e atribui 10.
   Como ptr aponta para p, isso modifica p.x diretamente: p.x passa de 3 para 10.
   Equivalência: ptr->x ≡ (*ptr).x. */

    printf("apos ptr->x=10: p.x=%d\n", p.x);
/* Confirma que p.x foi modificado indiretamente via ponteiro.
   Saída: apos ptr->x=10: p.x=10. */

    printf("dist2(origem,p)=%.0f\n", dist2(&origem, &p));
/* Chama dist2 passando os ENDEREÇOS das duas structs (&origem e &p).
   Dentro da função:
   - dx = origem.x - p.x = 0 - 10 = -10;
   - dy = origem.y - p.y = 0 - 4  = -4;
   - dist² = (-10)² + (-4)² = 100 + 16 = 116.
   O %.0f imprime float com ZERO casas decimais (arredonda 116.0 para 116).
   Saída: dist2(origem,p)=116. */

    /* struct como valor — cópia independente */
    Ponto q = p;
/* Atribui uma struct a outra. Em C, isso é uma CÓPIA PROFUNDA (byte a byte)
   de TODOS os campos — inclusive o array char nome[30].
   Agora q é uma cópia independente de p. Alterar q NÃO afeta p. */

    q.x = 99;
/* Modifica apenas o campo x da cópia q. O p.x permanece 10.
   Isso prova que a atribuição de struct fez uma cópia por VALOR. */

    printf("p.x=%d  q.x=%d\n", p.x, q.x);   /* 10 e 99 */
/* Saída: p.x=10  q.x=99 — confirmando independência entre as duas structs. */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}