#include "Aleatorio.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int numaluno;
  float notaMTP[2];
  float notaTE[2];
  int notaFinal;
} ALUNO;

ALUNO *lerArray(int *N);
void mostrarArray(ALUNO *A, int N);
void atualizarArray(ALUNO *A, int N);
int maiorNotaFinal_REC(ALUNO *A, int N);
ALUNO *lerArray(int *N)
{
  ALUNO *A;
  *N = gerarNumeroInteiro(1, 30);
  A = (ALUNO *)malloc(*N * sizeof(ALUNO));
  int K = 0;
  int aux, j, existe;
  while (K < *N)
  {
    aux = gerarNumeroInteiro(70000, 75000);
    j = 0;
    existe = 0;

    while (j < K && existe == 0)
    {

      if (aux == A[K].numaluno)
      {
        existe = 1;
      }
      j++;

    }
    if (existe == 0)
    {
      A[K].numaluno = aux;
      A[K].notaMTP[0] = gerarNumeroReal(0, 2);
      A[K].notaMTP[1] = gerarNumeroReal(0, 2);
      A[K].notaTE[0] = gerarNumeroReal(0, 8);
      A[K].notaTE[1] = gerarNumeroReal(0, 8);
    }

    K++;
  }
  return A;
};

void mostrarArray(ALUNO *A, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("NAluno = %d\tMTP1 = %2f\tMTP2 = %2f\tTE1 = %2f\tTE2 = %2f\tTF = %d\n", A[i].numaluno, A[i].notaMTP[0], A[i].notaMTP[1], A[i].notaTE[0], A[i].notaTE[1],A[i].notaFinal);
  }
}

void atualizarArray(ALUNO *A, int N)
{
  for (int i = 0; i < N; i++)
  {
    A[i].notaFinal = (int)A[i].notaMTP[0] + A[i].notaMTP[1] + A[i].notaTE[0] + A[i].notaTE[1];
  }
}

int maiorNotaFinal_REC(ALUNO *A, int N)
{
  if(N == 1) return A[0].notaFinal;

  int maior = maiorNotaFinal_REC(A,N-1);
  if(maior > A[N-1].notaFinal) return maior;
  else return A[N-1].notaFinal;
}