#include "arvoreb.h"

/*FunÃ§Ã£o principal:*/
int main() {
 
  
  Arvore *a = criar();
 /*=================================== INSERÇÃO DE LETRAS T= 2  ======================================*/
 /*  a = inserir(a, 'F');
    a = inserir(a, 'S');
    a = inserir(a, 'Q');
    a = inserir(a, 'K');
    a = inserir(a, 'C');
    a = inserir(a, 'L');
    a = inserir(a, 'H');
    a = inserir(a, 'T');
    a = inserir(a, 'V');
    a = inserir(a, 'W');
    a = inserir(a, 'M');
    a = inserir(a, 'R');
    a = inserir(a, 'N');
    a = inserir(a, 'P');
    a = inserir(a, 'A');
    a = inserir(a, 'B');
    a = inserir(a, 'X');
    a = inserir(a, 'Y');
    a = inserir(a, 'D');
    a = inserir(a, 'Z');
    a = inserir(a, 'E');


   // CASOS DE REMOÇÕES
   a=remover(a, 'E'); // caso 1
   a=remover(a, 'F'); // caso 2A
   a=remover(a, 'M'); // caso 2B
   a=remover(a, 'N'); // caso 2C
   a=remover(a, 'V'); // caso 3A
   a=remover(a, 'P'); // caso 3B


   /*=========================== INSERÇÃO DE NÚMEROS T= 3 ===================================================*/
    a = inserir(a, 91);
    a = inserir(a, 90);
    a = inserir(a, 80);
    a = inserir(a, 71);
    a = inserir(a, 72);
    a = inserir(a, 50);
    a = inserir(a, 45);
    a = inserir(a, 47);
    a = inserir(a, 10);
    a = inserir(a, 8);
    a = inserir(a, 7);
    a = inserir(a, 5);
    a = inserir(a, 2);
    a = inserir(a, 3);
    a = inserir(a, 22);
    a = inserir(a, 44);
    a = inserir(a, 55);
    a = inserir(a, 66);
    a = inserir(a, 68);
    a = inserir(a, 17);
    a = inserir(a, 6);
    a = inserir(a, 21);
    a = inserir(a, 67);

    //CASOS DE REMOÇÕES
    a= remover(a, 67); //caso 1
    a= remover(a, 10); //caso 2A
    a= remover(a, 8); //caso 2B
    a= remover(a, 80); //caso 2C
    a= remover(a, 68); //caso 3A
    a= remover(a, 22); //caso 3B

    imprimir(a, 0);
   

  return 0;
}