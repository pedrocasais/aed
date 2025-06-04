
// tipo de dados

typedef int INFOABP;


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoABP (INFOABP);

INFOABP criarElementoABP ();

// compara��o de 2 elementos do tipo INFOABP:
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP, INFOABP);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
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

// compara��o de 2 elementos do tipo INFO:
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP X, INFOABP Y)
{
  if (X > Y)
    return 1;
  if (X < Y)
    return -1;
  return 0;
}



