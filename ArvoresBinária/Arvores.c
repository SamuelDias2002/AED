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

// A.4

int ex4(PNodoAB A, int k)
{
    int esq, dir;
    if (ABVazia(A))
    {
        return 0;
    }

    esq = ex4(A->Esquerda, k);
    dir = ex4(A->Direita, k);

    if (A->Elemento.NIF == k)
    {
        return 1 + esq + dir;
    }
    else
    {
        return esq + dir;
    }
}

// A.5
INFOAB ex5(PNodoAB A)
{
    INFOAB esq, dir, maior;

    if (A->Esquerda == NULL && A->Direita == NULL || ABVazia(A))
    {
        return A->Elemento;
    }

    if (A->Esquerda != NULL)
    {
        esq = ex5(A->Esquerda);
    }
    if (A->Direita != NULL)
    {
        dir = ex5(A->Direita);
    }

    maior = A->Elemento;

    if (esq.Data[2] > maior.Data[2])
    {
        maior = esq;
    }
    if (dir.Data[2] > maior.Data[2])
    {
        maior = dir;
    }
    return maior;
}

// A.6
float ex6(PNodoAB A)
{
    if (ABVazia(A))
    {
        return 0;
    }
    else
    {
        float esq = ex6(A->Esquerda);
        float dir = ex6(A->Direita);
        return A->Elemento.Pagamento + esq + dir;
    }
}

// A.7

PNodoAB ex7(PNodoAB A)
{
    PNodoAB copia = criarAB();
    if (ABVazia(A))
    {
        return NULL;
    }
    else
    {
        copia->Elemento = A->Elemento;
        copia->Esquerda = ex7(A->Esquerda);
        copia->Direita = ex7(A->Direita);
    }

    return copia;
}

// A.8

int ex8(PNodoAB A1, PNodoAB A2)
{
    if (ABVazia(A1) && ABVazia(A2))
    {
        return 1;
    }

    if (ABVazia(A1) || ABVazia(A2))
    {
        return 0;
    }

    if (A1->Elemento != A2->Elemento)
    {
        return 0;
    }
    int esq = ex8(A1->Esquerda, A2->Esquerda);
    int dir = ex8(A1->Direita, A2->Direita);

    return esq && dir;
}

// A.9

PNodoAB ex9(PNodoAB A)
{
    PNodoAB inv = criarAB();
    if (ABVazia(A))
    {
        return A;
    }
    inv->Elemento = A->Elemento;
    inv->Esquerda = ex9(A->Direita);
    inv->Direita = ex9(A->Esquerda);

    return inv;
}

// A.10 ?????????????????

int ex10(PNodoAB A)
{
    if (ABVazia(A))
    {
        return 0;
    }
    else if (ABVazia(A->Esquerda) && ABVazia(A->Direita))
    {
        return 1;
    }
    else
    {
        return ex10(A->Esquerda) + ex10(A->Direita);
    }
}

// A.11

int ex11(PNodoAB A)
{
    if (ABVazia(A))
    {
        return 0;
    }
    if (ABVazia(A->Esquerda) && !ABVazia(A->Direita) || !ABVazia(A->Esquerda) && ABVazia(A->Direita))
    {
        return 1 + ex11(A->Esquerda) + ex11(A->Direita);
    }
    else
    {
        return ex11(A->Esquerda) + ex11(A->Direita);
    }
}

// A.12
int ex12(PNodoAB A, INFOAB X)
{
    if (PNodoAB(A))
    {
        return -1;
    }
    else if (compararElementosAB(A->Elemento, X) == 0)
    {
        return 0;
    }
    else
    {
        int esq = ex12(A->Esquerda);
        int dir = ex12(A->Direita);

        if (esq >= 0)
        {
            return 1 + ex12(A->Esquerda, X);
        }
        else if (dir >= 0)
        {
            return 1 + ex12(A->Direita, X);
        }
        else
        {
            return -1;
        }
    }
}

int ex13(PNodoAB A)
{
    if (ABVazia(A))
    {
        return 1; // Está completa
    }
    else if (ABVazia(A->Esquerda) && ABVazia(A->Direita))
    {
        return 0; // Não está completa
        /*
                a
               / \
            NULL NULL
        */
    }
    else if (!ABVazia(A->Direita) && ABVazia(A->Esquerda))
    {
        if (ABVazia(A->Direita->Esquerda) && ABVazia(A->Direita->Direita))
        {
            return 1;
            /*
             a
            / \
            b c
     */
        }
        else
        {
            return 0;

            /*
                a
               / \
              b  c
             / \
            d NULL
        */
        }
    }
    else
    {
        return ex13(A->Esquerda) && ex13(A->Direita);
    }
}