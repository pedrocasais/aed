
typedef struct
{
  int numero; // n�mero de aluno ({ 70000, �, 75000 })
  int NIF;    // notas dos mini-testes pr�ticos ([0.0, 2.0])
  int dia;    // notas dos testes escritos ([0.0, 8.0])
  int mes;
  int ano;
  float valor; // nota final ({ 0, �, 20 }): valor arredondado da soma das notas
} INFOLista;

/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoLista(INFOLista);

INFOLista criarElementoLista();

// compara��o de 2 elementos do tipo INFOLista, segundo o campo numAluno (chave)
// devolve -1 se primeiro < segundo, 0 se iguais, 1 se primeiro > segundo
int compararElementosLista(INFOLista, INFOLista);

/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

void mostrarElementoLista(INFOLista X)
{
  printf("%d - ", X.numero);
  printf("%d - ", X.NIF);
  printf("%d - ", X.dia);
  printf("%d - ", X.mes);
  printf("%d - ", X.ano);
  printf("%.2f\n", X.valor);
}

INFOLista criarElementoLista()
{
  INFOLista X;
  float soma;
  X.numero = gerarNumeroInteiro(1000, 2000);
  X.NIF = gerarNumeroInteiro(123450, 123460);
  X.dia = gerarNumeroInteiro(1, 31);
  X.mes = gerarNumeroInteiro(1, 12);
  X.ano = gerarNumeroInteiro(2020, 2024);
  X.valor = gerarNumeroReal(1.0, 500.0);
  return X;
}

// compara��o de 2 elementos do tipo INFOLista, segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosLista(INFOLista X, INFOLista Y)
{
  if (X.numero > Y.numero)
    return 1;
  if (X.numero < Y.numero)
    return -1;
  return 0;
}
