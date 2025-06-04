
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

PNodoLista criarListaAleatoria(int A, int B)
{
  PNodoLista L;
  int N, K;
  INFOLista X;

  L = criarLista();
  N = gerarNumeroInteiro(A, B);
  K = 1;
  while (K <= N)
  {
    X = criarElementoLista();
    if (pesquisarLista(X, L) == 0)
    {
      L = inserirListaInicio(X, L);
      K++;
    }
  }
  return L;
}

int tamanhoLista(PNodoLista L)
{
  int count = 0;
  PNodoLista P;
  P = L;
  while (P != NULL)
  {
    count = count + 1;
    P = P->Prox;
  }
  return count;
}

int tamanhoListaRec(PNodoLista L)
{
  if (L == NULL)
    return 0;
  return 1 + tamanhoListaRec(L->Prox);
}
/*
// ex4

int contaIgualNF(PNodoLista L, int N)
{
  int count = 0;

  if (L == NULL)
    return count;

  count = contaIgualNF(L->Prox, N);

  if (L->Elemento.notaFinal == N)
  {
    count++;
  }
  return count;
}

// ex5

int contaMaiorNF(PNodoLista L, int N)
{
  int count = 0;
  PNodoLista P = L;
  while (P != NULL)
  {
    if (P->Elemento.notaFinal >= N)
    {
      count++;
    }
    P = P->Prox;
  }
  return count;
}

// ex6

int maiorNF(PNodoLista L)
{
  int maior = 0;
  PNodoLista P = L;
  while (P != NULL)
  {
    if (P->Elemento.notaFinal > maior)
    {
      maior = P->Elemento.notaFinal;
    }
    P = P->Prox;
  }

  return maior;
}

int maiorNFREC(PNodoLista L)
{
  int maior = 0;

  if (L == NULL)
  {
    return 0;
  }

  maior = maiorNFREC(L->Prox);
  if (L->Elemento.notaFinal > maior)
  {
    maior = L->Elemento.notaFinal;
  }

  return maior;
}

// ex7

int maiorTE(PNodoLista L)
{
  float maior = 0.0f;
  // float maior= L->Elemento.notasTE[0] + L->Elemento.notasTE[1];
  int n = 0;
  PNodoLista P = L; // L->Prox;
  while (P != NULL)
  {
    if ((P->Elemento.notasTE[0] + P->Elemento.notasTE[1]) > maior)
    {
      maior = (P->Elemento.notasTE[0] + P->Elemento.notasTE[1]);
      // printf("\n\n|| maior --> %f \n\n||",maior);
      n = P->Elemento.numAluno;
    }
    P = P->Prox;
  }
  return n;
}

INFOLista maiorTEREC(PNodoLista L)
{
  float soma1, soma2;
  INFOLista n;
  if (L == NULL)
  {
    return n;
  }

  if (L->Prox == NULL)
    return L->Elemento;

  n = maiorTEREC(L->Prox);

  soma1 = L->Elemento.notasTE[0] + L->Elemento.notasTE[1];
  soma2 = n.notasTE[0] + n.notasTE[1];
  if (soma1 > soma2)
  {
    return L->Elemento;
  }
  else
    return n;
}

// ex8

int menorMTP(PNodoLista L)
{
  float menor = L->Elemento.notasMTP[0];
  int n = 0;
  PNodoLista P = L;
  while (P != NULL)
  {

    if (P->Elemento.notasMTP[0] < menor)
    {
      menor = P->Elemento.notasMTP[0];
      n = P->Elemento.numAluno;
    }

    if (P->Elemento.notasMTP[1] < menor)
    {
      menor = P->Elemento.notasMTP[1];
      n = P->Elemento.numAluno;
    }

    P = P->Prox;
  }

  return n;
}

int menorMTPREC(PNodoLista L)
{
  if (L == NULL)
  {
    return 0;
  }
  float menor = (L->Elemento.notasMTP)[0];
  int n = 0;

  n = menorMTPREC(L->Prox);
  if (L->Elemento.notasMTP[0] < menor)
  {
    menor = L->Elemento.notasMTP[0];
    n = L->Elemento.numAluno;
  }

  if (L->Elemento.notasMTP[1] < menor)
  {
    menor = L->Elemento.notasMTP[1];
    n = L->Elemento.numAluno;
  }
  return n;
}

// ex 9

// ex 10

int entreK1eK2(PNodoLista L, int k1, int k2)
{

  int count = 0;
  PNodoLista P = L;

  while (P != NULL)
  {
    if (P->Elemento.notaFinal >= k1 && P->Elemento.notaFinal <= k2)
    {
      count++;
    }
    P = P->Prox;
  }

  return count;
}

int entreK1eK2REC(PNodoLista L, int k1, int k2)
{

  int count = 0;

  if (L == NULL)
  {
    return 0;
  }

  if (L->Elemento.notaFinal >= k1 && L->Elemento.notaFinal <= k2)
  {
    count++;
  }

  return count + entreK1eK2REC(L->Prox, k1, k2);
}

// ex 11

PNodoLista removerIgualNum(PNodoLista L, int num)
{
  INFOLista x;

  x.numAluno = num;

  if (pesquisarLista(x, L) == 1)
  {
    L = removerLista(x, L);
  }
  return L;
}

// ex 12

PNodoLista removerMenorK(PNodoLista L, int k)
{
  PNodoLista P, Ant;

  if (L != NULL && L->Elemento.notaFinal < k)
  {
    P = L;
    L = L->Prox;
    P = libertarLista(P);
    // return L;
  }

  Ant = L;
  while (Ant != NULL && Ant->Prox != NULL)
  {
    if (Ant->Prox->Elemento.notaFinal < k)
    {
      P = Ant->Prox;
      Ant->Prox = Ant->Prox->Prox;
      P = libertarNodoLista(P);
    }
    else
    {
      Ant = Ant->Prox;
    }
  }

  return L;
}

// ex 13

PNodoLista removerIgualNota(PNodoLista L, int nota)
{

  PNodoLista P, Ant;

  if (L != NULL && L->Elemento.notaFinal == nota)
  {
    P = L;
    L = L->Prox;
    P = libertarNodoLista(P);
    // return L;
  }

  Ant = L;
  while (Ant != NULL && Ant->Prox != NULL)
  {
    if (Ant->Prox->Elemento.notaFinal == nota)
    {
      P = Ant->Prox;
      Ant->Prox = Ant->Prox->Prox;
      P = libertarNodoLista(P);
    }
    else
    {
      Ant = Ant->Prox;
    }
  }

  return L;
}

// ex 14

PNodoLista removerN(PNodoLista L, int n)
{
  PNodoLista P, Ant;
  int count = 0;
  if (tamanhoLista(L) > n)
  {
    L = libertarLista(L);
    return L;

    /* if (L == NULL)
      L = libertarLista(L);

    while (L != NULL)
    {
      P = L;
      L = L->Prox;
      P = libertarNodoLista(P);
    } */
/**
  }

  Ant = L;
  while (count <= n)
  {
    P = Ant;
    Ant = Ant->Prox;
    P = libertarNodoLista(P);
    count++;

    if (count == n)
    {
      L = libertarLista(L);
    }
    
  }
  return L;
  
}
*/