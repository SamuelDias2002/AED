#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h";
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"


/* Ficha Prática 

int ex1FP(PNodo L, int mes)
{
    if (listaVazia(L) == 1)
    {
        return 0;
    }
    else
    {
        if (L->Elemento.data[1] == mes)
        {
            return 1 + ex1FP(L->Prox, mes);
        }
        else
        {
            return ex1FP(L->Prox, mes);
        }
    }
}

void ex2FP12(PNodo L, int M)
{
    // 1)
    PNodo Lista;
    Lista = criarListaAleatoria(15);
    // 2)
    printf("\nLista Inicio -> Fim\n");
    mostrarListaInicioRec(Lista);

    // 3)
    M = Lista->Prox->Elemento.data[1];

    // 4)

    int cont = 0;
    while (listaVazia(Lista) != 1)
    {
        if (Lista->Elemento.data[1] != M)
        {
            cont++;
        }
        else
        {
            Lista = Lista->Prox;
        }
    }

    // 5)
    printf("Elementos da lista com data[1] != M:\n %d", &cont);
} */