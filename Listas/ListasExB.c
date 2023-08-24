#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h";
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"

int main()
{

    // B.3

    int ex3B(PNodo L, float a)
    {

        if (a > 2.0 && a < 1.0)
        {
            perror("Erro");
        }
        if (listaVazia(L))
        {
            return 0;
        }
        else
        {
            if (L->Elemento.altura > a)
            {
                return 1 + ex3B(L->Prox, a);
            }
            return ex3B(L->Prox, a);
        }
    }

    int ex4B(PNodo L, float a)
    {
        int cont = 0;
        if (a < 1920 || a > 2022)
        {
            return 0;
        }
        while (listaVazia(L) != 1)
        {
            if (L->Elemento.ano == a)
            {
                cont++;
            }
            L = L->Prox;
        }
        return cont;
    }

    int ex4Brec(PNodo L, float a)
    {
        if (listaVazia(L))
        {
            return 0;
        }
        else
        {
            if (L->Elemento.ano == a)
            {
                return 1 + ex4Brec(L->Prox, a);
            }
            return ex4Brec(L->Prox, a);
        }
    }

    PNodo ex5B(PNodo L, int N)
    {
        if (N >= tamanhoLista(L))
        {
            while (listaVazia(L) != 1)
            {
                PNodo aux;
                L = L->Prox;
                free(aux);
            }
            return NULL;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                PNodo aux;
                L = L->Prox;
                aux = removerLista(L);
                free(aux);
            }
        }
        return L;
    }

    PNodo ex5Brec(PNodo L, int N)
    {
        PNodo aux;
        if (listaVazia(L) || N <= 0)
        {
            return L;
        }
        else if (N >= tamanhoLista(L))
        {

            aux = removerLista(L);
            return ex5Brec(L->Prox, N - tamanhoLista(L));
        }
        else
        {
            aux = removerLista(L);
            return ex5Brec(L->Prox, N - 1);
        }
    }

    PNodo ex6B(PNodo L) // COMPLETAR
    {
        PNodo M = NULL;
        PNodo F = NULL;
        PNodo aux;
        while (!listaVazia(L))
        {
            for (int i = 0; i < tamanhoLista(L); i++)
            {
                aux = L;

                if (aux->Elemento.Genero == 0)
                {
                    L->Prox;
                    inserirListaInicio(aux->Elemento, M);
                }
                else
                {
                    L->Prox;
                    inserirListaInicio(aux->Elemento, F);
                }
            }
        }
        return M;
    }
}