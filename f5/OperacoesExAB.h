
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */



/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */


PNodoAB criarABAleatoria(int a, int b){
  int n=1,k;
  PNodoAB AB;
  AB = criarAB();
  INFOAB x;

  k = gerarNumeroInteiro(a,b);
  while (n <= k)
  {
    x = criarElementoAB();

    if (pesquisarAB(x,AB) == NULL)
    {
      AB = inserirPorAlturaAB(x,AB);
      n++;
    }
    
  }
  
  return AB;
}