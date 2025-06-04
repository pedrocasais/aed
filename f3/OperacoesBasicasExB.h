
typedef struct{
  int  numCC;   // número de cartão de cidadão (chave): valores entre 100000 e 200000
  int  dataNasc[3]; // data de nascimento (dia/mes/ano), com ano entre 1920 e 2025
  float  altura;   // em metros (ex: 1.86)
  int  genero;  // 1 = feminino e 0 = masculino
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
  printf("%d - ", X.numCC);
  printf("%2d / %2d / %2d ", X.dataNasc[0], X.dataNasc[1], X.dataNasc[2]);
  printf("%.2f - ", X.altura);
  if (X.genero == 0)
  {
    printf("Masculino\n");
    /* code */
  }else 
  printf("Feminino\n");
  
}

INFOLista criarElementoLista()
{
  INFOLista X;
  float soma;
  X.numCC = gerarNumeroInteiro(100000, 200000);
  X.dataNasc[0] = gerarNumeroInteiro(1,31);
  X.dataNasc[1] = gerarNumeroInteiro(1,12);
  X.dataNasc[2] = gerarNumeroInteiro(1930,2010);
  X.genero = gerarNumeroInteiro(0,1);
  return X;
}

// compara��o de 2 elementos do tipo INFOLista, segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosLista(INFOLista X, INFOLista Y)
{
  if (X.numCC > Y.numCC)
    return 1;
  if (X.numCC < Y.numCC)
    return -1;
  return 0;
}


