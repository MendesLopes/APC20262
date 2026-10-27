#include <stdio.h>
/* Inclui a biblioteca padrão de entrada/saída, que fornece a função printf. */

union Dado { int i; float f; char c; };
/* Declara uma UNION chamada Dado com três membros: int i, float f, char c.
   Uma union é como uma struct — agrupa campos nomeados — MAS com uma
   diferença crucial: TODOS os campos COMPARTILHAM O MESMO ESPAÇO DE MEMÓRIA.
   O tamanho da union é o tamanho do MAIOR membro (aqui, int e float
   costumam ter 4 bytes, char tem 1; logo sizeof(union Dado) = 4 bytes).
   Só UM campo pode ser lido com valor significativo por vez — o último
   que foi escrito. Escrever em um campo "sobrescreve" os bytes dos outros,
   pois todos ocupam os mesmos bytes físicos. */

int main(void) {
/* Declara a função principal main. void indica que ela não recebe argumentos. */

    union Dado d;
/* Declara uma variável d do tipo union Dado.
   Aloca sizeof(union Dado) = 4 bytes (o tamanho do maior membro).
   O conteúdo é LIXO até que alguém escreva em algum campo. */

    d.i = 65;
/* Escreve o inteiro 65 no campo d.i.
   Em memória, supondo little-endian com int de 4 bytes, os bytes ficam:
   endereço+0: 0x41   (65 em hexadecimal = 0x41)
   endereço+1: 0x00
   endereço+2: 0x00
   endereço+3: 0x00
   ATENÇÃO: ao escrever em d.i, os campos d.f e d.c são "sobrescritos" no
   sentido de que os bytes deles foram alterados — pois todos compartilham
   os mesmos 4 bytes. Só d.i é o campo "ativo" agora. */

    printf("d.i='%d'  d.c='%c'\n", d.i, d.c);   /* 65 e 'A' — mesmos bytes */
/* Aqui já entra em terreno delicado:
   - %d com d.i → imprime 65 (o valor que escrevemos, tipo correto);
   - %c com d.c → d.c é o PRIMEIRO BYTE da union, que contém 0x41 = 65.
     Como 65 é o código ASCII de 'A', o %c imprime 'A'.
   Este é o uso CLÁSSICO de union: "TYPE PUNNING" — reinterpretar os mesmos
   bytes como tipos diferentes. Funciona aqui porque 65 cabe em 1 byte e o
   layout little-endian coloca o byte menos significativo primeiro.
   Saída: d.i='65'  d.c='A'.
   ATENÇÃO: tecnicamente, ler um membro de union diferente do último escrito
   é COMPORTAMENTO DEFINIDO em C (é permitido pela norma), mas o valor
   resultante depende da representação interna — não é portável entre
   arquiteturas (big-endian daria resultado diferente). */

    d.f = 3.14f;
/* Escreve o float 3.14 no campo d.f.
   Agora a union está "ativa" como float. Os 4 bytes que antes continham
   o inteiro 65 são SOBRESCRITOS pelos 4 bytes da representação IEEE-754
   de 3.14 (0x4048F5C3). Com isso, d.i e d.c passam a ter valores
   indefinidos do ponto de vista semântico — os BYTES são válidos, mas
   lidos como int ou char não representam o 3.14. */

    printf("d.f=%.2f\n", d.f);   /* d.i agora tem valor indefinido */
/* Lê o campo d.f (o último escrito) e imprime com 2 casas decimais.
   Saída: d.f=3.14.
   O comentário avisa: d.i agora está "indefinido" — não no sentido de
   UB da linguagem (ler d.i seria permitido), mas no sentido de que o
   valor 65 se perdeu; qualquer valor que se leia é a interpretação dos
   bytes IEEE-754 de 3.14 como inteiro, que é 1078523331 (0x4048F5C3). */

    return 0;
/* Retorna 0 para o sistema operacional, indicando que o programa terminou
   com sucesso. */
}