
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasFilasExD.h"
#include "EADFila.h"
#include "OperacoesBasicasPilhasExD.h"
#include "EADPilha.h"

#include "OperacoesFilasPilhasExD.h"

int main()
{
  // Grupo C

  PNodoPilha Pilha;
  Pilha = criarPilhaAleatoria(0,15);

  printf("Pilha \n");
  mostrarPilha(Pilha);

  Pilha = inverterPilha(Pilha);
  printf("\nPilha invertida\n");
  mostrarPilha(Pilha);


  printf("\n");
  // Grupo D

  PNodoFila Fila;
  Fila = criarFilaAleatoria(0,15);

  printf("Fila\n");
  mostrarFila(Fila);


  Fila = inverterFila(Fila);
  printf("\nFila invertida\n");
  mostrarFila(Fila);
}

