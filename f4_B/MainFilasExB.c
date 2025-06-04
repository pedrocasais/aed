

#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasFilasExB.h"
#include "EADFila.h"
#include "OperacoesFilasExB.h"

int main()
{
  PNodoFila Fila;
  Fila = criarFilaAleatoria(0, 15);

  printf("Fila \n");
  mostrarFila(Fila);

  printf("\n");
  INFOFila x;
  printf("Segundo Elemento -> ");

  int a = segundoElemento(&Fila, &x);
  if (a == 1)
  {
    mostrarElementoFila(x);
  }else{
    printf("0");
  }
  printf("\n");
}
