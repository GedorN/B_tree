#include "arvoreb.h"

/*===========================================Função Buscar=================================================================*\
|*  *Argumentos:                                                                                                           *|
|*    - Arvore* a: recebe um ponteiro para a Árvore criada na função main().                                               *|
|*    - TIPO chave: corresponde à chave que esta sendo buscada.                                                            *|
|*                                                                                                                         *|
|*  *return:                                                                                                               *| 
|*    - i: retorna o índice da posição no vetor em que chave buscada se encontra.                                          *|
|*   - NOT FOUND: retorno quando a chave não é encontrada.                                                                 *| 
\==========================================================================================================================*/
int buscar (Arvore *a, TIPO chave) {

   int i = 0;

   /*Procurando a chave no vetor de chaves: */
   while ((i < a->n) && (chave > a->chaves[i])) {
     i = i + 1; 
   }
   
   if (chave == a->chaves[i]) {
      /*Achou a chave!*/
      return i;
   }  
   else if (a->folha) {
      /*Não achou a chave!*/
      return NOT_FOUND;
   }
   else {
      /*Buscando a chave no filho: */
      if (a->folha == FALSE) {
         return buscar (a->filhos[i], chave);
      }
   }
}
