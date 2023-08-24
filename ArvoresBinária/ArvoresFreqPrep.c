#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"

#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

// A.1
PNodoAB criarABAleatoria(int N)
{
    INFOAB cont;
    PNodoAB arvore;
    int k = 1;
    arvore = criarAB();

    while (k <= N)
    {
        cont = criarElementoAB();
        if (pesquisarAB(cont, arvore) == NULL)
        {
            arvore = inserirPorAlturaAB(cont, arvore);
            k = k + 1;
        }
    }
    return arvore;

    // A.2
    numeroNodosAB(arvore);
}

// A.3
void numNodosEsqDir(PNodoAB arvore, int *esq, int *dir)
{
    if (arvore == NULL)
    {
        *esq = 0;
        *dir = 0;
    }
    else
    {
        *dir = numeroNodosAB(arvore->Direita);
        *esq = numeroNodosAB(arvore->Esquerda);
    }
}

// ex4

int ex4(PNodoAB T, int nif)
{
    if (ABVazia(T))
    {
        return 0;
    }
    int esq = ex4(T->Esquerda, nif);
    int dir = ex4(T->Direita, nif);
    if (T->Elemento.NIF == nif)
    {
        return 1 + esq + dir;
    }
    else
    {
        return esq + dir;
    }
}

// ex5

INFOAB ex5(PNodoAB T)
{
    INFOAB esq, dir, maior;
    if (ABVazia(T) || ABVazia(T->Esquerda) && ABVazia(T->Direita))
    {
        return T->Elemento;
    }
    if (!ABVazia(T->Esquerda))
    {
        esq = ex5(T->Esquerda);
    }
    if (!ABVazia(T->Esquerda))
    {
        dir = ex5(T->Direita);
    }
    maior = T->Elemento;

    if (esq.Data[2] > maior)
    {
        maior = esq;
    }
    else if (dir.Data[2] > maior)
    {
        maior = dir;
    }
    return maior;
}

// ex6

float ex6(PNodoAB T)
{
    float sum = 0;
    if (ABVazia(T))
    {
        return 0;
    }
    else
    {
        float esq = ex6(T->Esquerda);
        float dir = ex6(T->Direita);
        return T->Elemento.Pagamento + esq + dir;
    }
}

// ex7

PNodoAB ex7(PNodoAB T)
{
    PNodoAB copia = criarAB();
    if (ABVazia(T))
    {
        return T;
    }
    copia->Elemento = T->Elemento;
    copia->Esquerda = ex7(T->Esquerda);
    copia->Direita = ex7(T->Direita);

    return copia;
}

// ex8

int ex8(PNodoAB T1, PNodoAB T2)
{
    if (ABVazia(T1) && ABVazia(T2))
    {
        return 1;
    }
    if (ABVazia(T1) || ABVazia(T2))
    {
        return 0;
    }
    if (compararElementosAB(T1, T2) != 0)
    {
        return 0;
    }
    int esq = ex8(T1->Esquerda, T2->Esquerda);
    int dir = ex8(T1->Direita, T2->Direita);

    return esq && dir;
}

// ex9

PNodoAB ex9(PNodoAB T)
{
    PNodoAB espelho = criarAB();
    if (ABVazia(T))
    {
        return T;
    }
    else
    {
        espelho->Elemento = T->Elemento;
        espelho->Esquerda = ex9(T->Direita);
        espelho->Direita = ex9(T->Esquerda);
    }
    return espelho;
}

// ex10

int ex10(PNodoAB T)
{
    if (ABVazia(T))
    {
        return 0;
    }
    if (ABVazia(T->Esquerda) && (ABVazia(T->Direita)))
    {
        return 1 + ex10(T->Esquerda) + ex11(T->Direita);
    }

    return ex10(T->Esquerda) + ex11(T->Direita);
}

// ex11

int ex11(PNodoAB T)
{
    if (ABVazia(T))
    {
        return 0;
    }
    if (ABVazia(T->Esquerda) && !ABVazia(T->Direita) || !ABVazia(T->Esquerda) && ABVazia(T->Direita))
    {
        return 1 + ex10(T->Esquerda) + ex10(T->Direita);
    }

    return ex10(T->Esquerda) + ex10(T->Direita);
}

// ex 12

int ex12(PNodoAB T, INFOAB x)
{
    if (ABVazia(T))
    {
        return -1;
    }
    if (T = X)
    {
        return 0;
    }
    int esq = alturaAB(T->Esquerda);
    int dir = alturaAB(T->Direita);
    if (esq >= 0)
    {
        return esq + 1;
    }
    else if (dir >= 0)
    {
        return dir + 1;
    }
    return -1;
}

