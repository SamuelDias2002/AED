/*****************************************************/
// Número de estudante:
// Nome de estudante:
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "EADArvoreBinariaPesquisa.h"

// Devolve uma ABP com N elementos
// do tipo INFOAB gerados aleatoriamente
PNodoAB criarABPAleatoria(int N)
{
    int k;
    INFOAB X;
    PNodoAB T;
    T = criarAB();
    k = 1;
    while (k <= N)
    {
        X = criarElementoAB();
        if (pesquisarABP(X, T) == 0)
        {
            T = inserirABP(X, T);
            k = k + 1;
        }
    }
    return T;
}

int ex1(PNodoAB T, int num)
{
    int dir, esq;

    if (ABVazia(T))
    {
        return 0;
    }
    dir = ex1(T->Direita, num);
    esq = ex1(T->Esquerda, num);

    if (T->Elemento.numAluno >= num)
    {
        if (T->Elemento.aprovado == 1)
        {
            return 1 + esq + dir;
        }
        else
        {
            return esq + dir;
        }
    }
}
int main()
{
    PNodoAB T;
    int num;

    // 2.a)
    criarABPAleatoria(25);

    // 2.b)
    printf("Arvore Pesquisa T:\n", )

        // 2.c)
        if (ABVazia(T))
    {
        return NULL;
    }
    else
    {
        int esqV = (T->Esquerda.Elemento);
        int dirV = T->Direita.Elemento;
    }

    // 2.d)
    int Q;
    Q = ex1(T, 4050);

    // 2.e)
    printf("%d\n", Q);
}
