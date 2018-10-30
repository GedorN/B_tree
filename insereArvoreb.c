#include "arvoreb.h"

/*=========================Função Dividir Nó====================================================================================*\
|* *Argumentos:                                                                                                                 *|
|*    -Arvore* x : recebe um ponteiro para a ávore criada na Função Inserir quando algum nó estiver cheio e precisar dividí-lo. *|
|*    -Arvore* y: recebe um ponteiro para a raiz da árvore criada inicialmente na função main().                                *|
|*    -int i: inteiro que contém o índice da posição em que haverá a divisão.                                                   *|
|*                                                                                                                              *|                   
|* *return:                                                                                                                     *|                    
|*    -A função retorna o ponteiro x, que corresponde a raiz com a árvore dividida.                                             *|
\*==============================================================================================================================*/

Arvore *dividir_no(Arvore *x, int i, Arvore *y)
{
    Arvore *z = criar();
    z->folha = y->folha;
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
    {
        z->chaves[j] = y->chaves[j + T];
    }
    if (y->folha == 0)
    {
        for (int j = 0; j < T; j++)
        {
            z->filhos[j] = y->filhos[j + T];
        }
    }
    y->n = T - 1;
    for (int j = x->n ; j >= i + 1; j--)
    {
        x->filhos[j + 1] = x->filhos[j];
    }
    x->filhos[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--)
    {
        x->chaves[j + 1] = x->chaves[j];
    }
    x->chaves[i] = y->chaves[T - 1];
    x->n = x->n + 1;

    return x;
}
\
/*==========================================Função Inserir em Árvore não Cheia=============================================*\
|* *Argumentos:                                                                                                            *|       
|*    -Arvore* x: recebe um ponteiro para a raiz da Árvore em que se deseja inserir uma chave.                             *|  
|*    -TIPO k: é a chave que será inserida.                                                                                *| 
|*                                                                                                                         *|
|* *return                                                                                                                 *|     
|*    -A função retorna um ponteiro para a raiz após ocorrer a inserção.                                                   *|
\*=========================================================================================================================*/
Arvore *inserir_arvore_nao_cheia(Arvore *x, TIPO k)
{
    
    int i = x->n - 1;
    if (x->folha)
    {
        while (i >= 0 && k < x->chaves[i])
        {
            x->chaves[i + 1] = x->chaves[i];
            i--;
        }
        x->chaves[i + 1] = k;
        x->n = x->n + 1;
    }
    else
    {
        while (i >= 0 && k < x->chaves[i])
        {
            i--;
        }
        i++;
        if (x->filhos[i]->n == (2 * T) - 1)
        {
            dividir_no(x, i, x->filhos[i]);
            if (k > x->chaves[i])
            {
                i++;
            }
        }
       x->filhos[i]= inserir_arvore_nao_cheia(x->filhos[i], k);
    }
    return x;
}

/*================================= Função para inserir uma chave em uma árvore B ===============================================*\
|* *Argumentos:                                                                                                                  *|
|*    -Arvore* raiz: recebe um ponteiro para a raiz da Árvore a criada na função main().                                         *|
|*    -TIPO chave: corresponde a chave que será inserida na árvore                                                               *|
|*                                                                                                                               *|
|* *return:                                                                                                                      *|
|*    -A função retorna um ponteiro Arvore* s para a raiz da Árvore passada inicialmente.                                        *|
|*                                                                                                                               *|
\*================================================================================================================================*/

Arvore *inserir(Arvore *raiz, TIPO chave)
{
    Arvore *r = raiz;
    if (r->n == (2 * T - 1))
    {
        Arvore *s = criar();
        s->folha = FALSE;
        s->filhos[0] = r;
        s = dividir_no(s, 0, r);
        s = inserir_arvore_nao_cheia(s, chave);
        return s;
    }
    else
    {
        return inserir_arvore_nao_cheia(r, chave);
    }
}
