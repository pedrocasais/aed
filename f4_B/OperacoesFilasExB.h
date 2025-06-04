
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo:
//   - n�o faz parte da EAD Fila
//   - mostra a Fila da frente para a cauda
void mostrarFila(PNodoFila);

/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo:
//   - n�o faz parte da EAD Fila
//   - mostra a Fila da frente para a cauda
void mostrarFila(PNodoFila Q)
{
  PNodoFila P = Q;
  while (P != NULL)
  {
    mostrarElementoFila(P->Elemento);
    P = P->Seg;
  }
}

PNodoFila criarFilaAleatoria(int a, int b)
{
  int n = 1, k;
  INFOFila x;
  PNodoFila F;
  F = criarFila();

  k = gerarNumeroInteiro(a, b);

  while (n <= k)
  {
    x = criarElementoFila();
    F = juntar(x, F);
    n++;
  }

  return F;
}

// ex2

int segundoElemento(PNodoFila *F, INFOFila *x)
{
  if (filaVazia(*F) == 1)
  {
    return 0;
  }

  *F = remover(*F);
  if (filaVazia(*F) == 1)
  {
    return 0;
  }
  *x = frente(*F);

  return 1;
}
