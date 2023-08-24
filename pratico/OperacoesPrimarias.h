
typedef struct
{
    int numAluno;      // chave, com valores entre 4000 e 4100
    float notaFreq;    // soma das notas das frequências ([0..16])
    float notaPratica; // soma das notas dos testes práticos ([0..4])
    int aprovado;      // 0 (reprovado) e 1 (aprovado)
} INFOAB;

void mostrarElementoAB(INFOAB);

INFOAB criarElementoAB();

// comparação de 2 elementos do tipo INFOAB,
// segundo o campo numAluno (chave);
// devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB(INFOAB, INFOAB);

#include "OperacoesPrimarias.c"
