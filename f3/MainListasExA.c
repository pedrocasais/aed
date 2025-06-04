
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasExA.h"
#include "EADLista.h"
#include "OperacoesExA.h"

// void criarListaGenero(PNodoLista L, PNodoLista *L1, PNodoLista *L2)
// {
//   PNodoLista P = L;
//   *L1 = criarLista(); // l1 = NULL;
//   *L2 = criarLista();
//   while (P != NULL)
//   {
//     if (P->Elemento.genero == 0)
//     {
//       *L1 = inserirListaInicio(P->Elemento, *L1);
//     }
//     else
//     {
//       *L2 = inserirListaInicio(P->Elemento, *L2);
//     }
//     P = P->Prox;
//   }
// }


int maiorR(PNodoLista L){

  int maior = -1;
  if(L == NULL) return maior;

  
  maior = maiorR(L->Prox);

  if (L->Elemento.numAluno > maior) 
    return L->Elemento.numAluno;
  else
    return maior;

}

PNodoLista remover(PNodoLista L){
  PNodoLista P = L,Paux;

  int cont = 0;
  if(L == NULL) return L;

  if(P->Elemento.notaFinal >= 10) cont++;

  Paux = P->Prox;
  while (Paux != NULL)
  {
    if (Paux->Elemento.notaFinal >= 10){
      cont++;
      if (cont == 2)
      {
        P->Prox = Paux->Prox;
        Paux = libertarNodoLista(Paux);
        break;
      }
      
    }

    P = Paux;
    Paux = Paux->Prox;
    
    
  }

  return P;
  
}

PNodoLista removerX(PNodoLista L,int x){
  PNodoLista P, P2;

  if (L == NULL)
  {
    return L;
  }

  if (L->Elemento.notaFinal > x)
  {
    P = L;
    L = L->Prox;
    P = libertarNodoLista(P);
    return L;
  }
  
  P2 = L;
  P = L->Prox;
  while (P != NULL)
  {
    if (P->Elemento.notaFinal > x)
    {
      P2->Prox = P->Prox;
      P = libertarNodoLista(P);
      break;
    }
    
    P2 = P;
    P = P->Prox;
  }
  return L;
}


int main()
{
  /*
  PNodoLista Lista;

  Lista = criarListaAleatoria(0, 15);
  mostrarListaInicio(Lista);
  printf("\n");
  mostrarListaFimRec(Lista);
  printf("\ntamanho da Lista -> %d\n",tamanhoLista(Lista));
  printf("tamanho da Lista REC -> %d\n",tamanhoListaRec(Lista));
  printf("conta NF igual a N REC -> %d\n",contaIgualNF(Lista,10));
  printf("conta NF maior ou igual a N -> %d\n", contaMaiorNF(Lista,10));
  printf("maior NF -> %d\n",maiorNF(Lista));
  printf("maior NF REC -> %d\n",maiorNFREC(Lista));
  printf("maior TE -> %d\n",maiorTE(Lista));
  printf("maior TE REC -> %d\n",maiorTEREC(Lista).numAluno);
  printf("menor MTP   -> %d\n", menorMTP(Lista));
  printf("menor MTP REC  // erro  -> %d\n",menorMTPREC(Lista));
//falta o ex 9
  printf("numero de n elementos de L, em que k1 < L->elementos.notaFinal < k2 -> %d\n",entreK1eK2(Lista,10,15));
  printf("numero de n elementos de L, em que k1 < L->elementos.notaFinal < k2 REC -> %d\n",entreK1eK2REC(Lista,10,15));
  removerIgualNum(Lista,71000);
  removerMenorK(Lista,10);
  printf("\n");
  mostrarListaInicio(Lista);
  printf("\n");
  //removerIgualNota(Lista,10);
  printf("\n");
  mostrarListaInicio(Lista);
  printf("14 -> \n");
  removerN(Lista,tamanhoLista(Lista));
  mostrarListaInicio(Lista);
  printf("\n");

  */

  // PNodoLista Lista, L1, L2;

  // Lista = criarListaAleatoria(0, 15);
  // mostrarListaInicio(Lista);
  // printf("\n");
  // mostrarListaFimRec(Lista);
  // //  printf("\ntamanho da Lista -> %d\n",tamanhoLista(Lista));

  // criarListaGenero(Lista, &L1, &L2);
  // printf("lista masculina\n");
  // mostrarListaInicio(L1);
  // printf("lista feminina\n");
  // mostrarListaInicio(L2);

  PNodoLista Lista;

  Lista = criarListaAleatoria(0, 15);
  mostrarListaInicio(Lista);
  printf("\n");
  //int a = maiorR(Lista);
  //printf("%d\n",a);

  printf("\n");
  Lista = removerX(Lista,10);
  mostrarListaInicio(Lista);


}
