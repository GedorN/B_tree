#include "arvoreb.h"

/*FunÃ§Ã£o para buscar uma chave em uma Ã¡rvore B:*/
void imprimir(Arvore *a, int nivel) {
  int i;

  /*Imprime recuo para definir o nÃ­vel do nÃ³: */
  for (i = 0; i < nivel; i++) {
    printf("  ");
  }

  /*Imprime as chaves armazenadas no nÃ³: */
  printf("|");
  for (i = 0; i < a->n; i++) {
    printf("%d|", a->chaves[i]);
    // printf("%02d|", a->chaves[i]);
  }
  printf("\n");

  /*Recursivamente imprime as chaves dos filhos: */
  for (i = 0; i <= a->n; i++) {
    if (a->folha == FALSE) {
      imprimir(a->filhos[i], nivel + 1);
    }
  }
}