#include "arvoreb.h"

/*=======================================Função Remover de uma Folha=========================================================*\
|*    *Argumentos:                                                                                                           *|
|*        -Arvore* a: recebe um ponteiro para a folha em que a chave será eliminada.                                         *|
|*        -int index: corresponde ao índice da posição no vetor em que  a chave eliminada se encontra.                       *|
|*                                                                                                                           *|                      
|*    *return:                                                                                                               *|
|*        -A função retorna o ponteiro Arvore* a , ou seja, um ponteiro para a própria onde a chave foi removida.            *|
\*===========================================================================================================================*/

Arvore *remover_de_folha(Arvore *a, int index)
{
    
    for (int i = index; i < (2 * T) - 1; i++)
    {

        a->chaves[i] = a->chaves[i + 1];
    }

    a->n--;
    
    return a;
}

/*=====================================Função Remover de um Nó não Folha=================================================*\
|*    *Argumentos:                                                                                                       *|
|*        -Arvore* a: recebe um ponteiro para o nó, que não é folha, em que se deseja remover uma chave.                 *|
|*        -int index: contém o indice correspondente à posição no vetor  da chave que será removida.                     *|
|*                                                                                                                       *|
|*    *return:                                                                                                           *|
|*        -A função retorna o ponteiro Árvore* a, ou seja, um ponteiro para o nó em que a chave foi eliminada.           *|
\*=======================================================================================================================*/

Arvore *remover_de_nao_folha(Arvore *a, int index)
{
    TIPO k = a->chaves[index];
    TIPO predecessor, sucessor;

    /*=============================================CASO 2A======================================================================================
      Caso o nó tenha o  filho da posição com índice index com pelo menos T chaves. A chave no ińdice index do nó será eliminada e a última chave
      do filho correspondente será puxada.*/

    if (a->filhos[index]->n >= T)
    {
        a->chaves[index] = a->filhos[index]->chaves[a->filhos[index]->n - 1];
        a->filhos[index] = remover(a->filhos[index], a->filhos[index]->chaves[a->filhos[index]->n - 1]);

    }
    /*==============================================CASO 2B====================================================================================
      Caso o nó tenha um filho na posição (index + 1) com pelo menos T chaves. A chave na posição index será removida e substituída
      pela chave na posição 0 do filho na posição (index + 1).*/
    else if (a->filhos[index + 1]->n >= T)
    {
        
        a->chaves[index] = a->filhos[index + 1]->chaves[0];
        a->filhos[index + 1] = remover(a->filhos[index + 1], a->filhos[index + 1]->chaves[0]);

    }
    /*================================================CASO 2C==============================================================================
      Caso a chave esteja em um nó interno cujos filhos nas posições (index) e (index +1) possuam (T - 1) chaves. A chave é rmeovida
      e as chaves dos filhos citados são unidos em um só nó.*/
    else
    {

        /*Juntando os filhos.*/
        for (int i = 0; i < a->filhos[index + 1]->n; i++)
        {

            a->filhos[index]->chaves[a->filhos[index]->n] = a->filhos[index + 1]->chaves[i];
            a->filhos[index]->n++;
        }
        a->filhos[index + 1]->n = 0;

        /*Puxando elementos.*/
        for (int i = index; i + 1 < a->n; i++)
        {
            a->chaves[i] = a->chaves[i + 1];
        }

        a->n--;

        /*Puxando os filhos.*/

        for (int j = index; (j + 2) < (2 * T) && (a->filhos[j + 2] != NULL); j++)
        {

            for (int i = 0; i < a->filhos[j + 2]->n; i++)
            {
                a->filhos[j + 1]->chaves[i] = a->filhos[j + 2]->chaves[i];
            }

            a->filhos[j + 1]->n = a->filhos[j + 2]->n;
            a->filhos[j + 2]->n = 0;
        }
        if (a->n == 0)
        {
            return a->filhos[index];
        }

    }

    return a;
}

/*============================================ Função verificar raiz vazia ===============================*\
|*    *Argumentos:                                                                                        *|
|*        -Ponteiro para raiz de árvore previamente criada                                                *|
|*                                                                                                        *|
|*    *retorno:                                                                                           *|
|*        -Ponteiro para nó filho abaixo não vazio, se houver                                             *|
|*        - NULL se não houver                                                                            *|
\*========================================================================================================*/
Arvore *verificar_raiz_vazia(Arvore *raiz)
{
    int i;

    if(!raiz->folha)
    {
        if(raiz->n == 0)
        {
            for(i = 0; i < 2 * T; i++)
            {
                if(raiz->filhos[i] != NULL && raiz->filhos[i]->n > 0)
                {
                    Arvore *aux= raiz;
                    raiz= raiz->filhos[i];
                    free(aux);
                    return raiz;
                }
            }

            if( i == 2* T)
            {
                free(raiz);
                return NULL;
            }
        }
    }

    return raiz;
}

/*==========================================Função  Buscar Index Remoçã ==================================*\
|*    *Argumentos:                                                                                        *|
|*        -Ponteiro para nó de árvore                                                                     *|
|*        -Chave a ser procurada                                                                          *|
|*    *retorno:                                                                                           *|
|*        -índice da posição do elemento 'chave'                                                          *|
\*========================================================================================================*/
int buscar_index_remocao(Arvore *a, TIPO chave)
{

    int i = 0;

    /*Procurando a chave no vetor de chaves */
    while ((i < a->n) && (chave > a->chaves[i]))
    {
        i = i + 1;
    }

    return i;
}

/*====================================================Função Remover==================================*\
|*    *Argumentos:                                                                                    *|
|*        -Ponteiro para nó da árvore                                                                 *|
|*        -Elemento 'k' a ser retirado                                                                *|
|*    *retorno:                                                                                       *|
|*        -Ponteiro para raiz da árvore com o ponteiro removido                                       *|
\*====================================================================================================*/
Arvore *remover(Arvore *a, TIPO k)
{
    int index;

   
    if (a == NULL)
    {
        
        printf("Árvore, já está vazia\n");
        exit(1);
    }

    index = buscar_index_remocao(a, k);

    //A chave a ser removida está presente neste nó
    if (index >= 0 && a->chaves[index] == k)
    {
        if (a->folha)
        {
            a = remover_de_folha(a, index);
        }
        else
        {
            a = remover_de_nao_folha(a, index);
        }
    }
    else
    {
        //Se este nó é um nó folha, então a chave não está na árvore
        if (a->folha)
        {
            printf("\nA chave %c não está na árvore.\n", k);
           
            return a;
        }
        else
        { 
            a->filhos[index] = remover(a->filhos[index], k);
        }
    }
    if (!a->folha)
    {
       
        
        /*============== CASO 3B  =============*/
        if (index > 0 && a->filhos[index]->n < T - 1 && a->filhos[index - 1]->n <= T - 1)
        {
          

            a->filhos[index - 1] = inserir(a->filhos[index - 1], a->chaves[index - 1]);
            for (int i = a->filhos[index]->n - 1; i >= 0; i--)
            {
                a->filhos[index - 1] = inserir(a->filhos[index - 1], a->filhos[index]->chaves[i]);
                a->filhos[index] = remover(a->filhos[index], a->filhos[index]->chaves[i]);
            }
            for (int i = index; i + 1 < a->n; i++)
            {
                a->chaves[i] = a->chaves[i + 1];
            }
            a->n--;

            if (a->n == 0)
            {

                return a->filhos[index - 1];
            }
        }
        
        /*=================== CASO 3B =========================*/
        else if (index == 0 && a->filhos[index]->n <= T - 1 && a->filhos[index + 1]->n <= T - 1)
        {
            

            a->filhos[index] = inserir(a->filhos[index], a->chaves[index]);

            for (int j = 0; j + 1 <= a->n; j++) 
            {
                for (int i = a->filhos[j + 1]->n - 1; i >= 0; i--)
                {
                    a->filhos[j] = inserir(a->filhos[j], a->filhos[j + 1]->chaves[i]);
                    a->filhos[j + 1] = remover(a->filhos[j + 1], a->filhos[j + 1]->chaves[i]);
                   
                }
            }
            for (int i = index; i + 1 < a->n; i++)
            {
                a->chaves[i] = a->chaves[i + 1];
            }
            a->n--;

            if (a->n == 0)
            {

                return a->filhos[index];
            }
        }
        else if (index > 0 && a->filhos[index]->n < T - 1)
        {
            /*========CASO 3A==============*/
          
            a->filhos[index] = inserir(a->filhos[index], a->chaves[index - 1]);
            a->chaves[index - 1] = a->filhos[index - 1]->chaves[a->filhos[index - 1]->n - 1];
            a->filhos[index - 1] = remover(a->filhos[index - 1], a->filhos[index - 1]->chaves[a->filhos[index - 1]->n - 1]);
        }
        else if (index == 0 && a->filhos[index]->n < T - 1)
        {
            /*========= CASO 3A======*/
            a->filhos[index] = inserir(a->filhos[index], a->chaves[index]);
            a->chaves[index] = a->filhos[index + 1]->chaves[0];
            a->filhos[index + 1] = remover(a->filhos[index + 1], a->filhos[index + 1]->chaves[0]);
        }
    }

    a = verificar_raiz_vazia(a);

    return a;
}
