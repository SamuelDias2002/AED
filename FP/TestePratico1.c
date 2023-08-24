
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesPrimarias.h"
#include "ListasLigadasSimples.h"

// implementar as fun��es neste local
PNodo criarListaAleatoria(int N)
{
    int k;
    PNodo L;
    INFO X;
    L = criarLista();
    for (k = 1; k <= N; k++)
    {
        X = criarElemento();
        L = inserirListaInicio(X, L);
    }
    return L;
}

// fun��o da pergunta 1

int ex1(PNodo L, float NF)
{
    int cont = 0;
    while (listaVazia(L) != 1)
    {
        int cont = 0;
        if (L->Elemento.notaFreq >= NF)
        {
            cont++;
        }
        else
        {
            L = L->Prox;
        }
    }
    return cont;
}
// programa principal
int main()
{
    // Alinea a)
    PNodo Lista;
    Lista = criarListaAleatoria(15);
    
    // Alinea b)
    printf("\nLista Inicio -> Fim\n");
    mostrarListaInicioRec(Lista);

    //  Alinea c)
    float nota;
    nota = Lista->Elemento.notaFreq;

    // Alinea d)
    ex1(Lista, nota);
    // Alinea e)
    printf("Elementos da lista com notaFreq maior ou igual à variavel nota:\n %d", ex1(Lista, nota));
}
