
// bibliotecas exclusivas desta biblioteca

typedef PNodoABP INFOFila;   // INFOFila = PNodoABP

#include "EADFila.h"


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarPorNiveisABP (PNodoABP);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

void mostrarPorNiveisABP (PNodoABP T)
{
  PNodoFila Q;
  PNodoABP  P;
  int niveis, k = 0;
  
  if (ABPVazia(T))
    return;
  niveis = alturaABP(T) + 1;
  printf("Legenda: nodo[pai]\n");
  Q = criarFila();
  Q = juntar(T, Q);
  Q = juntar(NULL, Q);
  printf("Nivel %1d: %2d\n", k, T->Elemento);
  k++;
  printf("Nivel %1d: ", k);
  while (!filaVazia(Q)){
    P = frente(Q);
    Q = remover(Q);
    if (P == NULL){
      k++;
      if (k == niveis)
      {
        printf("\n");
        return;
      }
      printf("\nNivel %1d: ", k);
      if (!filaVazia(Q))
        Q = juntar(NULL, Q);
    }
    else{
      if (P->Esquerda != NULL)
        printf("%2d[%2d] # ", P->Esquerda->Elemento, P->Elemento);
      else
        printf("  [%2d] # ", P->Elemento);
      if (P->Direita != NULL)
        printf("%2d[%2d] # ", P->Direita->Elemento, P->Elemento);
      else
        printf("  [%2d] # ", P->Elemento);
      if (P->Esquerda != NULL)
        Q = juntar(P->Esquerda, Q);
      if (P->Direita != NULL)
        Q = juntar(P->Direita, Q);
    } // else
  } // while
  printf("\n");
}


