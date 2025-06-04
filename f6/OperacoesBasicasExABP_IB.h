
// tipo de dados

typedef int INFOABP;


/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoABP (INFOABP);

INFOABP criarElementoABP ();

// comparação de 2 elementos do tipo INFOABP:
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP, INFOABP);


/* ------------------------------------------------------- */
/* -------------- implementação das funções -------------- */
/* ------------------------------------------------------- */

void mostrarElementoABP (INFOABP X)
{
  printf("%d\n", X);
}

INFOABP criarElementoABP ()
{
  INFOABP X;
  do{
    printf("Insira um inteiro entre 10 e 99: ");  // por exemplo
    scanf("%d", &X);
  }while(X < 10 || X > 99);
  return X;
}

// comparação de 2 elementos do tipo INFO:
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP X, INFOABP Y)
{
  if (X > Y)
    return 1;
  if (X < Y)
    return -1;
  return 0;
}



