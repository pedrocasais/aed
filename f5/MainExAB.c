
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasExAB.h"
#include "EADArvoreBinaria.h"
#include "ABPorNiveis.h"
#include "OperacoesExAB.h"



int maiorNegativa(PNodoAB T){

  if (T == NULL)
    return -1;

  if (T->Elemento.notaFinal >= 10 )
    return T->Esquerda;

  int maior = maiorNegativa(T->Esquerda);

  if ( maior == -1)
    return T->Elemento.notaFinal;
  
  if (maior > T->Elemento.notaFinal)
    return maior;
  else
    return T->Elemento.notaFinal;
}


int maior(PNodoAB T, int A){
  int max = -1;

  if (T == NULL) return  -1;

  int esq = maior(T->Esquerda,A);
  int dir = maior(T-> Direita,A);

  if (esq > max) max = esq;
  if (dir > max) max = dir;
  if (T->Elemento.notaFinal > A && T->Elemento.notaFinal > max) max = T->Elemento.numAluno;
  return max;

}


int quantCompras(PNodoAB T, int A,int X){
	int cont = 0;
  if(T == NULL) return 0;

  if (T->Elemento.numAluno >= A && T->Elemento.notaFinal > X)
  {
    cont = 1;
  }
  
	int esq = quantCompras(T->Esquerda,A,X);
	int dir = quantCompras(T->Direita,A,X);

	return cont + esq + dir;
	
}


int soma(PNodoAB T, int A,int N){
	if (T == NULL) return 0;
	
	int esq = soma(T->Esquerda,A,N);
	int dir = soma(T->Direita,A,N);

	if(T->Elemento.notaFinal >= A &&T->Elemento.numAluno >= N)
		return T->Elemento.notaFinal + esq + dir;
	else 
    return esq +dir;
}

int main()
{
  PNodoAB T;
  T = criarABAleatoria(0,20);
  mostrarEmOrdemAB(T);
  printf("\npor niveis\n");
  /*mostrarPorNiveisAB(T);
  printf("%d\n",T->Elemento.numAluno);
  int a = 10;
  if(T->Esquerda != NULL) a = T->Elemento.notaFinal;
  printf("\n1 -> %d\n",maior(T,a));


  int b = 70000;
  int x = 200;
  if(T->Direita != NULL) {
	  b = T->Direita->Elemento.numAluno;
	  x = T->Direita->Elemento.notaFinal;
  }

  printf("2 -> %d\n",quantCompras(T,b,x));

  printf("3 -> %d\n",soma(T,12,T->Elemento.numAluno));

  */

  printf("-> -> %d\n",maiorNegativa(T));

}
