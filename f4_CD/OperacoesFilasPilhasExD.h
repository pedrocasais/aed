
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

void mostrarPilha(PNodoPilha S)
{
  PNodoPilha P = S;
  while (P != NULL)
  {
    mostrarElementoPilha(P->Elemento);
    P = P->Ant;
  }
}

PNodoPilha criarPilhaAleatoria(int a, int b)
{
  int n = 1, k;

  INFOPilha X;
  PNodoPilha P;
  P = criarPilha();

  k = gerarNumeroInteiro(a, b);
  while (n <= k)
  {
    X = criarElementoPilha();
    P = push(X, P);
    n++;
  }

  return P;
}

PNodoPilha inverterPilha(PNodoPilha P)
{

  // why not this ->
  /*
  PNodoPilha S;
  S = criarPilha();
  while (pilhaVazia(P) == 0)
  {
    S = push(topo(P),S);
    P = pop(P);
  }

  return S;
 */

  PNodoFila F;
  F = criarFila();
  while (pilhaVazia(P) == 0)
  {
    F = juntar(topo(P), F);
    P = pop(P);
  }

  while (filaVazia(F) == 0)
  {
    P = push(frente(F), P);
    F = remover(F);
  }

  return P;
}

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
  INFOFila X;
  PNodoFila F;
  F = criarFila();
  k = gerarNumeroInteiro(a, b);
  while (n <= k)
  {
    X = criarElementoFila();
    F = juntar(X, F);
    n++;
  }
  return F;
}

PNodoFila inverterFila(PNodoFila F)
{
  PNodoPilha S;
  S = criarPilha();

  while (filaVazia(F) == 0)
  {
    S = push(frente(F), S);
    F = remover(F);
  }

  while (pilhaVazia(S) == 0)
  {
    F = juntar(topo(S), F);
    S = pop(S);
  }

  return F;
}