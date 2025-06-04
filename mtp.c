#include <stdio.h>
#include <stdlib.h>

#include "f3/Aleatorio.h"
#include "f3/OperacoesBasicasExC.h"
#include "f3/EADLista.h"
#include "f3/OperacoesExA.h"

/*
// primeiro mtp
// soma dos valores do segundo TE quando NF == n
float igualN(PNodoLista L, int n)
{
  PNodoLista P = L;
  float soma = 0.0f;
  while (P != NULL)
  {
    if (P->Elemento.notaFinal == n)
    {
      printf("elemento a somar -> %f\n", P->Elemento.notasMTP[0]);
      printf("soma_amtes -> %f\n", soma);
      soma += P->Elemento.notasTE[1];
      printf("soma_deçpos -> %f\n", soma);
    }
    P = P->Prox;
  }
  printf("ultinmos saom %f\n", soma);
  return soma;
}

// segundo mtp
// quantidade de elementos de l com NF == 12 e mtpS > x
int f2(PNodoLista L, int x)
{
  PNodoLista P = L;
  int cont = 0;
  while (P != NULL)
  {
    if (P->Elemento.notaFinal == 12 && (P->Elemento.notasMTP[0] + P->Elemento.notasMTP[1] > x))
    {
      cont++;
    }
    P = P->Prox;
  }
  return cont;
}

// site do goat

int site(PNodoLista L, int nota)
{
  PNodoLista P = L;
  int menor = 80000;

  while (P != NULL)
  {
    if (P->Elemento.notaFinal == nota)
    {
      if (P->Elemento.numAluno < menor)
      {
        menor = P->Elemento.numAluno;
      }
    }

    P = P->Prox;
  }

  if (menor == 80000)
  {
    return -1;
  }
  return menor;
}
  */

float sameNIF(PNodoLista L, int N)
{
  PNodoLista P = L;
  float soma = 0;
  while (P != NULL)
  {
    if (P->Elemento.NIF == N)
    {
      soma += P->Elemento.valor;
    }
    P = P->Prox;
  }

  return soma;
}

int contCompras(PNodoLista L, float X)
{
  PNodoLista P = L;
  int cont = 0;
  while (P != NULL)
  {
    if (P->Elemento.mes == 12 && P->Elemento.valor > X)
    {
      cont++;
    }
    P = P->Prox;
  }
  return cont;
}

int maiorCompra(PNodoLista L, int A)
{
  PNodoLista P = L;
  float valor = 0.0;
  int numero = -1;

  while (P != NULL)
  {
    if (P->Elemento.ano == A && P->Elemento.valor > valor)
    {
      valor = P->Elemento.valor;
      numero = P->Elemento.numero;
    }
    P = P->Prox;
  }
  return numero;
}

int main()
{

  PNodoLista L;

  L = criarListaAleatoria(2, 15);

  printf("elementos de L\n");
  mostrarListaInicio(L);

  printf("\n");
  PNodoLista P;
  P = L;
  P = P->Prox;
  L = libertarNodoLista(L);
  mostrarListaInicio(P);
  


/*   int N = L->Elemento.NIF;
  printf("NIF -> %d\n", N);

  float ex1 = sameNIF(L, N);
  printf("ex1 -> %f\n", ex1);

  float X = L->Elemento.valor;
  printf("X -> %f\n", X);

  int ex2 = contCompras(L, X);
  printf("ex2 -> %d\n", ex2);

  int A = L->Elemento.ano;
  printf("A -> %d\n", A);

  int ex3 = maiorCompra(L, 14);
  printf("ex3 -> %d\n", ex3);
 */
  /*
    // int n = L->Elemento.NIF;
    int n = L->Elemento.notaFinal;

    printf("n -> %d\n", n);

    float soma = igualN(L, n);
    printf("fun ->  %.2f\n", soma);

    float n2 = 2.0f;
    int cont = f2(L, n2);
    printf("fun2 -> %d\n", cont);

    // site cenas
    //printf("aqui -> %d\n", tamanhoLista(L));
    if (tamanhoLista(L) > 1)
    {
      INFOLista x = L->Prox->Elemento;
      printf("mtp + te -> %f - %f - %f - %f\n", x.notasMTP[0], x.notasMTP[1], x.notasTE[0], x.notasTE[1]);
    }
    else
    {
      printf("CONDICAO .> tam < 2\n");
    }

    printf("fun3 -> %d\n", site(L, 10));

    printf("\n----TESTE----\n");

    printf("2ºL -> %d\n", L->Prox->Elemento.numAluno);

    */
}