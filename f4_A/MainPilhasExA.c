
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasPilhasExA.h"
#include "EADPilha.h"
#include "OperacoesPilhasExA.h"

int pp(PNodoPilha *P){
  PNodoPilha S;
  int res = -1;
  S = criarPilha();
  int cont = 1;
  while (pilhaVazia(*P)==0)
  {
    if (topo(*P).notaFinal == 10 && cont == 1)
    {
      res = topo(*P).numAluno;
      cont++;
    }
    S = push(topo(*P),S);
    *P = pop(*P);
    
  }

  while (pilhaVazia(S) == 0)
  {
    *P = push(topo(S),*P);
    S = pop(S);
  }
  
  return res;

}

int main()
{
  PNodoPilha Pilha;
  INFOPilha x, y;
  Pilha = criarPilhaAleatoria(0, 15);
  printf("Pilha\n");
  mostrarPilha(Pilha);
  printf("\n");


  int a = pp(&Pilha);
  printf("\n%d\n",a);
  // /*
  //   int existe;
  //   existe = segundoElemento(&Pilha,&x);
  //   if (existe == 1)
  //   {
  //     printf("2 º elemento: ");
  //     mostrarElementoPilha(x);
  //   }

  // */

  // int existe = segundo(&Pilha, &x);
  // if (existe == 1)
  // {
  //   printf("2 º elemento: ");
  //   mostrarElementoPilha(x);
  // }
  // printf("\n");

  // printf("n-Esimo2\n");
  // // mostrarElementoPilha(n_Esimo(Pilha,2));
  // // int existe2 = n_Esimo2(&Pilha,2,&y);
  // // mostrarElementoPilha(y);
  // mostrarElementoPilha(n_Esimo2(Pilha, 2));

  // printf("Ultimo da Pilha\n");
  // mostrarElementoPilha(fundoPilha2(Pilha));
  // printf("\nPilha\n");

  // mostrarPilha(Pilha);
  // printf("\n antePenultime el\n");
  // mostrarElementoPilha(antePenultimo(Pilha));
  // printf("\nPilha\n");
  // mostrarPilha(Pilha);

  // printf("\nPilha trocada 1st <-> last\n");
  // trocar(Pilha);
  // mostrarPilha(Pilha);


  // printf("\nsep nf \n");
  // separarNF(Pilha);
  // mostrarPilha(Pilha);
}
