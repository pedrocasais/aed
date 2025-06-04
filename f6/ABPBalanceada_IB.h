
/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */

int numeroNodosABP (PNodoABP);

PNodoABP criarABPBalanceadaIB (PNodoABP);

// 1 = ABP equilibrada; 0 = ABP não equilibrada
int ABPBalanceada (PNodoABP);

/* ------------------------------------------------------- */
/* -------------- implementação das funções -------------- */
/* ------------------------------------------------------- */

int numeroNodosABP (PNodoABP T)
{
  if(T == NULL)
    return 0;
  return 1 + numeroNodosABP(T->Esquerda) + numeroNodosABP(T->Direita);
}

void ABPInsercaoBinaria (PNodoABP *TE, INFOABP L[], int inicio, int fim) 
{
  int  meio;
  if (inicio > fim)
    return ;
  if (inicio == fim){
    *TE = inserirABP(L[inicio], *TE);
    return;
  }
  meio = (inicio + fim) / 2;
  *TE = inserirABP(L[meio], *TE);
  ABPInsercaoBinaria(TE, L, inicio, meio-1);
  ABPInsercaoBinaria(TE, L, meio+1, fim);
}

void criarSequenciaEmOrdem (PNodoABP T, INFOABP L[], int *N)
{
  if (T != NULL){
    criarSequenciaEmOrdem(T->Esquerda, L, N);
    L[*N] = T->Elemento;
    *N = (*N) + 1;
    criarSequenciaEmOrdem(T->Direita, L, N);
  }
}

PNodoABP criarABPBalanceadaIB (PNodoABP T)
{
  INFOABP *Lista;
  PNodoABP TE;
  int  N = 0, num;
  TE = criarABP();
  num = numeroNodosABP(T);
  if (T == NULL)
    return NULL;
  Lista = (INFOABP *) malloc(num * sizeof(INFOABP));
  if (Lista == NULL)
    return NULL;
  criarSequenciaEmOrdem(T, Lista, &N);
  ABPInsercaoBinaria(&TE, Lista, 0, N-1);
  return TE;
}


// 1 = equilibrada; 0 = não equilibrada
int ABPBalanceada (PNodoABP T)
{
  int altEsq, altDir;
  if (T == NULL)
    return 1;
  altEsq = alturaABP(T->Esquerda);
  altDir = alturaABP(T->Direita);
  if (abs(altEsq - altDir) > 1)
    return 0;
  if (T->Esquerda != NULL && ABPBalanceada(T->Esquerda) == 0)
    return 0;
  if (T->Direita != NULL && ABPBalanceada(T->Direita) == 0)
    return 0;
  return 1;
}


