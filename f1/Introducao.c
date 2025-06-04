#include <stdio.h>
#include "Introducao.h"


int main(){

  ALUNO *A;
  int N;
  A = lerArray(&N);
  mostrarArray(A,N);
  printf("\nARRAY ATUALIZADO\n");
  atualizarArray(A,N);
  mostrarArray(A,N);

  printf("\nMaior Valor de notaFinal - %d\n",maiorNotaFinal_REC(A,N));
  return 0;
}