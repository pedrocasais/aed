
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasExA.h"
#include "EADLista.h"
#include "OperacoesExA.h"

INFOLista menorNum(PNodoLista L, int nota)
{
  PNodoLista P = L;
  INFOLista n, menor;
  menor.numAluno = 80000;
  
  while (P != NULL)
  {
    if(nota == P->Elemento.notaFinal){
      if (P->Elemento.numAluno < menor.numAluno)
      {
        menor.numAluno = P->Elemento.numAluno;
        n.numAluno = P->Elemento.numAluno;  
      }
    }
    
    P = P->Prox;
  }
  if (menor.numAluno != 80000)
  {
    return n;
    
  }
  menor.numAluno = -1;
  return menor;
}

int menorNum2(PNodoLista L,int nota)
{
PNodoLista P = L;
int menor2 = 80000;

while (P != NULL)
{
  if (P->Elemento.notaFinal  == nota )
  {
    if (P->Elemento.numAluno < menor2)
    {
      menor2 = P->Elemento.numAluno;
    }
    
  }
  P =P->Prox;
}


if (menor2 != 80000)
{
  /* code */
  return menor2;
}
return -1;

}

int main()
{
  PNodoLista Lista;
  Lista = criarListaAleatoria(0, 15);

  printf("Listra:\n");
  mostrarListaInicio(Lista);

  printf("\n(C)\n");
  INFOLista a;
  a= Lista->Prox->Elemento;
  printf("%.2f \t%.2f \t%.2f \t%.2f \t",a.notasMTP[0],a.notasMTP[1],a.notasTE[0],a.notasTE[1]);

  printf("\n(D)\n");
  int NOTA = Lista->Elemento.notaFinal;
  printf("%d",NOTA);
  
  INFOLista b = menorNum(Lista, 10);
  printf("\n%d\n", b.numAluno);
}
