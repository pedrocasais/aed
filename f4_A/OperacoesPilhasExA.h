
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo
//   - n�o faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha(PNodoPilha);

// criar pilha entre A e B
PNodoPilha criarPilhaAleatoria(int A, int B);

/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo
//   - n�o faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha(PNodoPilha S)
{
  PNodoPilha P = S;
  while (P != NULL)
  {
    mostrarElementoPilha(P->Elemento);
    P = P->Ant;
  }
}

PNodoPilha criarPilhaAleatoria(int A, int B)
{
  int N, K;
  PNodoPilha P;
  INFOPilha X;
  N = gerarNumeroInteiro(A, B);

  P = criarPilha(P);
  K = 1;
  while (K <= N)
  {
    X = criarElementoPilha();
    P = push(X, P);
    K++;
  }
  return P;
}

int segundoElemento(PNodoPilha *p, INFOPilha *x)
{
  if (pilhaVazia(*p) == 1)
  {
    return 0;
  }

  *p = pop(*p);
  if (pilhaVazia(*p) == 1)
  {
    return 0;
  }

  *x = topo(*p);
  return 1;
}

// ex3
int segundo(PNodoPilha *p, INFOPilha *x)
{
  INFOPilha y;
  if (pilhaVazia(*p) == 1)
  {
    return 0;
  }

  y = topo(*p);
  *p = pop(*p);
  if (pilhaVazia(*p) == 1)
  {
    *p = push(y, *p);
    return 0;
  }
  *x = topo(*p);
  *p = push(y, *p);
  return 1;
}

// ex 4

INFOPilha n_Esimo(PNodoPilha P, int N)
{
  INFOPilha X;

  PNodoPilha P2;
  P2 = criarPilha();

  int cont = 1;
  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
    if (cont == N)
    {
      X = topo(P2);
    }
    cont++;
  }

  return X;
}

// ex 5

INFOPilha n_Esimo2(PNodoPilha P, int N)
{

  INFOPilha X;
  if (pilhaVazia(P) == 1)
  {
    X.numAluno = -1;
    X.notasMTP[0] = -1.0;
    X.notasMTP[1] = -1.0;
    X.notasTE[0] = -1.0;
    X.notasTE[1] = -1.0;
    X.notaFinal = -1;
    return X;
  }

  PNodoPilha P2;
  P2 = criarPilha();

  int cont = 1;
  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
    if (cont == N)
    {
      X = topo(P2);
    }
    cont++;
  }

  while (pilhaVazia(P2) == 0)
  {
    P = push(topo(P2), P);
    P2 = pop(P2);
  }

  return X;
}

/*
int n_Esimo2(PNodoPilha *P, int N, INFOPilha *X)
{

  if (pilhaVazia(*P) == 1)
  {
    return 0;
  }

  PNodoPilha P2;
  P2 = criarPilha();

  int cont = 1;
  while (pilhaVazia(*P) == 0)
  {

    P2 = push(topo(*P), P2);
    *P = pop(*P);
    if (cont == N)
    {
      *X = topo(P2);
    }
    cont++;
  }

  while (pilhaVazia(P2) == 0)
  {
    *P = push(topo(P2), *P);
    P2 = pop(P2);
  }

  return 1;
}

 */
// ex 6

INFOPilha fundoPilha(PNodoPilha P)
{
  INFOPilha X;

  PNodoPilha P2;
  P2 = criarPilha();
  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
  }

  X = topo(P2);

  return X;
}

// ex7

INFOPilha fundoPilha2(PNodoPilha P)
{
  INFOPilha X;

  PNodoPilha P2;
  P2 = criarPilha();
  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
  }

  X = topo(P2);

  while (pilhaVazia(P2) == 0)
  {
    P = push(topo(P2), P);
    P2 = pop(P2);
  }

  return X;
}

// ex 8

INFOPilha antePenultimo(PNodoPilha P)
{
  PNodoPilha P2;
  P2 = criarPilha();
  INFOPilha x;

  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
  }

  int cont = 1;

  while (pilhaVazia(P2) == 0)
  {
    if (cont == 3){
      x = topo(P2);
      cont++;
    }
    P = push(topo(P2), P);
    P2 = pop(P2);
    cont++;
    
  }

  return x;
}

// ex 9

PNodoPilha trocar(PNodoPilha P)
{
  PNodoPilha P2;
  INFOPilha x, y;
  P2 = criarPilha();
  x = topo(P);
  while (pilhaVazia(P) == 0)
  {
    P2 = push(topo(P), P2);
    P = pop(P);
  }

  y = topo(P2);

  P = push(x, P);
  P2 = pop(P2);
  while (pilhaVazia(P2) == 0)
  {
    P = push(topo(P2), P);
    P2 = pop(P2);
  }
  P = pop(P);
  P = push(y, P);

  return P;
}

// ex 10

PNodoPilha separarNF(PNodoPilha P)
{
  PNodoPilha P2, P3;
  P2 = criarPilha();
  P3 = criarPilha();

  while (pilhaVazia(P) == 0)
  {
    if (P->Elemento.notaFinal < 10)
    {
      P2 = push(topo(P), P2);
      P = pop(P);
    }
    else
    {
      P3 = push(topo(P), P3);
      P = pop(P);
    }
  }

  while (pilhaVazia(P2) == 0)
  {
    P = push(topo(P2), P);
    P2 = pop(P2);
  }

  while (pilhaVazia(P3) == 0)
  {
    P = push(topo(P3), P);
    P3 = pop(P3);
  }

  return P;
}