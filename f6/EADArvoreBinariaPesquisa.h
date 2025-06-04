
struct NodoABP {
	INFOABP  Elemento;
	struct NodoABP *Esquerda;
	struct NodoABP *Direita;
};

typedef struct NodoABP *PNodoABP;

/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// Opera��es sobre o Nodo

PNodoABP criarNodoABP (INFOABP);

PNodoABP libertarNodoABP (PNodoABP);

// Opera��es sobre a EAD �rvore Bin�ria de Pesquisa

PNodoABP criarABP ();

PNodoABP destruirABP (PNodoABP);

int ABPVazia(PNodoABP);

void mostrarEmOrdemABP (PNodoABP);
void mostrarPreOrdemABP (PNodoABP);
void mostrarPosOrdemABP (PNodoABP);

int alturaABP (PNodoABP);

PNodoABP pesquisarABP (INFOABP, PNodoABP);

void atualizarElementoABP (INFOABP, INFOABP, PNodoABP);

PNodoABP inserirABP (INFOABP, PNodoABP);

// remover um elemento de uma ABP: X est� na ABP
PNodoABP removerABP (INFOABP, PNodoABP);

/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// Opera��es sobre o Nodo

PNodoABP criarNodoABP (INFOABP X)
{
  PNodoABP P;
  P = (PNodoABP) malloc(sizeof(struct NodoABP));
  if (P == NULL)
    return  NULL;
  P->Elemento = X;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}

PNodoABP libertarNodoABP (PNodoABP P)
{
  P->Esquerda = NULL;
  P->Direita = NULL;
  free(P);
  P = NULL;
  return P;
}

// Opera��es sobre a EAD �rvore Bin�ria de Pesquisa

PNodoABP criarABP ()
{
  PNodoABP T;
  T = NULL;
  return T;
}

PNodoABP destruirABP (PNodoABP T)
{
  if (T == NULL) 
    return NULL;
  T->Esquerda = destruirABP(T->Esquerda);
  T->Direita = destruirABP(T->Direita);
  T = libertarNodoABP(T);
  return T;
}

int ABPVazia (PNodoABP T)
{
  if (T == NULL)
    return 1;
  else
    return 0;
}

void mostrarEmOrdemABP (PNodoABP T)
{
  if (T != NULL){
    mostrarEmOrdemABP(T->Esquerda);
    mostrarElementoABP(T->Elemento);
    mostrarEmOrdemABP(T->Direita);
  }
}

void mostrarPreOrdemABP (PNodoABP T)
{
  if (T != NULL){
    mostrarElementoABP(T->Elemento);
    mostrarPreOrdemABP(T->Esquerda);
    mostrarPreOrdemABP(T->Direita);
  }
}

void mostrarPosOrdemABP (PNodoABP T)
{
  if (T != NULL){
    mostrarPosOrdemABP(T->Esquerda);
    mostrarPosOrdemABP(T->Direita);
    mostrarElementoABP(T->Elemento);
  }
}

int alturaABP (PNodoABP T)
{
  int altEsq, altDir;
  if (T == NULL)
    return -1;
  altEsq = alturaABP(T->Esquerda);
  altDir = alturaABP(T->Direita);
  if (altEsq > altDir)
    return altEsq + 1;	// altura da esquerda + raiz
  else
    return altDir + 1;	// altura da direita + raiz
}

// Opera��es sobre a EAD �rvore Bin�ria de Pesquisa

PNodoABP pesquisarABP (INFOABP X, PNodoABP T)
{
  if (T == NULL)
    return NULL;
  if (compararElementosABP(X, T->Elemento) == 0)  // X == T->Elemento
    return T;
  if (compararElementosABP(X, T->Elemento) == -1)   // X < T->Elemento
    return pesquisarABP(X, T->Esquerda);
  else
    return pesquisarABP(X, T->Direita);
}

void atualizarElementoABP (INFOABP X, INFOABP Y, PNodoABP T)
{
  PNodoABP P;
  P = pesquisarABP(X, T);
  if (P != NULL){
    T = removerABP(X, T);
    T = inserirABP(Y, T);
  }
}

// inserir de forma que fique o mais poss�vel equilibrada

PNodoABP inserirABP (INFOABP X, PNodoABP T)
{
  if (T == NULL){
    T = criarNodoABP(X);
    return T;
  }
  if (compararElementosABP(X, T->Elemento) == -1)   // X < T->Elemento
    T->Esquerda = inserirABP(X, T->Esquerda);
  else
    T->Direita = inserirABP(X, T->Direita);
  return T;
}
 
// opera��es associadas � opera��o removerABP

PNodoABP substituirNodoDireita (PNodoABP T, INFOABP *X)
{
  PNodoABP PAux;
  if (T->Esquerda == NULL){
    *X = T->Elemento;
    PAux = T;
    T = T->Direita;
    PAux = libertarNodoABP(PAux);
    return T;
  }
  T->Esquerda = substituirNodoDireita(T->Esquerda, X);
  return T;
}

PNodoABP substituirNodoEsquerda (PNodoABP T, INFOABP *X)
{
  PNodoABP PAux;
  if (T->Direita == NULL){
    *X = T->Elemento;
    PAux = T;
    T = T->Esquerda;
    PAux = libertarNodoABP(PAux);
    return T;
  }
  T->Direita = substituirNodoEsquerda(T->Direita, X);
  return T;
}

PNodoABP removerNodoABP (PNodoABP T)
{
  PNodoABP P;
  INFOABP X;
  if (T->Esquerda == NULL && T->Direita == NULL){   // T � uma folha
    T = libertarNodoABP(T);
    return T;
  }
  if (T->Esquerda == NULL){   //  s� um filho, o direito 
    P = T;
    T = T->Direita;
    P = libertarNodoABP(P);
    return T;
  }
  if (T->Direita == NULL){     // s� um filho, o esquerdo
    P = T;
    T = T->Esquerda;
    P = libertarNodoABP(P);
    return T;
  }
  // 2 filhos (1� caso): remover o nodo sucessor (nodo mais � esquerda da sub�rvore direita) e copiar a sua informa��o
  T->Direita = substituirNodoDireita(T->Direita, &X);
  // 2 filhos (2� caso): remover o nodo antecessor (nodo mais � direita da sub�rvore esquerda) e copiar a sua informa��o
//  T->Esquerda = substituirNodoEsquerda(T->Esquerda, &X);  // 2� caso
  T->Elemento = X;
  return T;
}

PNodoABP removerABP (INFOABP X, PNodoABP T) 
{
  if (compararElementosABP(X, T->Elemento) == 0){
    T = removerNodoABP(T);
    return T;
  }    
  if (compararElementosABP(X, T->Elemento) == -1)
    T->Esquerda = removerABP(X, T->Esquerda);
  else
    T->Direita = removerABP(X, T->Direita);
  return T;
}

