#include "OperacoesPrimarias.c"
typedef struct
{
  int numAluno;
  float notaFreq;
  float notaPratica;
  int aprovado;
} INFO;

void mostrarElemento(INFO);

INFO criarElemento();

// compara��o de 2 elementos do tipo INFO, segundo o campo numAluno (chave)
// devolve -1 se primeiro < segundo, 0 se iguais, 1 se primeiro > segundo
int compararElementos(INFO, INFO);

#include "OperacoesPrimarias.c"
