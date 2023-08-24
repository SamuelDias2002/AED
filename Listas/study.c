#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h";
#include "OperacoesPrimariasA.h"
#include "ListasLigadasSimples.h"
#include "ListasExerciciosA.h"

int main()
{
    PNodo Lista;
    int TAM;

    // A.1
    TAM = gerarNumeroInteiro(0, 15);
    printf("TAM = %d\n\n", TAM);
    Lista = criarListaAleatoria(TAM);

    // A.2
    printf("Lista Fim -> Inicio\n");
    mostrarListaFimRec(Lista);
    printf("\nLista Inicio -> Fim\n");
    mostrarListaInicioRec(Lista);

    // A.3
    double ex3(PNodo L, int nif)
    {
        double sum = 0;
        if (listaVazia(L) = 1)
        {
            return 0;
        }
        else
        {
            if (L->Elemento.NIF == nif)
            {
                sum += sum L->Elemento.Pagamento;
                return L->Elemento.Pagamento + ex3(L->Prox, nif);
            }
        }
    }

    int ex4(PNodo L, int pag)
    {
        if (listaVazia(L))
        {
            return 0;
        }
        else
        {
            if (L->Elemento.Pagamento >= pag)
            {
                return 1 + ex4(L->Prox, pag);
            }
            else
            {
                return ex4(L->Prox, pag);
            }
        }
    }

    float ex5(PNodo L, int maior)
    {
        if (listaVazia)
        {
            return maior;
        }
        else if (L->Elemento.Pagamento >= maior)
        {

            return ex5(L->Prox, L->Elemento.Pagamento)
        }
        else
        {
            return ex5(L->Prox, maior);
        }
    }

    INFO ex6(PNodo L, int num)
    {
        INFO menorElemento = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
        while (listaVazia(L) != 1)
        {
            if (L->Elemento.Pagamento == num)
            {
                menorElementoo = L->Elemento;
                L = L->Prox;
            }
            return menorElemento;
        }
    }

    PNodo ex7(PNodo L, float k)
    {
        if (listaVazia(L) == 0)
        {
            return L;
        }
        else if (L->Elemento.Pagamento == k)
        {
            PNodo aux;
            aux = L;
            L = L->Prox;
            aux = removerLista(aux);
            free(aux);
            return L;
        }
        else
        {
            L->Prox = ex7(L->Prox, k);
            return L;
        }
    }

    PNodo ex7(PNodo L, float k)
    {
        while (listaVazia(L) != 1)
        {
            if (L->Elemento.Pagamento == k)
            {
                return removerLista(L->Elemento, L);
            }
            else
            {
                L = L->Prox;
            }
        }
    }

    PNodo ex8(PNodo L)
    {
        float maior = ex5(L, int n);
        PNodo aux;
        if (listaVazia(L) == 1)
        {
            return L;
        }
        else if (L->Elemento.Pagamento < maior)
        {
            aux = L;
            L = L->Prox;
            aux = removerLista(L);
            free(aux);
            return ex8(L);
        }
        else
        {
            L->Prox = ex8(L->Prox);
            return L;
        }
    }

    PNodo ex9(PNodo L, int n)
    {
        if (listaVazia(L) == 1)
        {
            return L;
        }
        else if (L->Elemento.NIF == n)
        {
            PNodo aux;
            aux = L;
            L = L->Prox;
            aux = removerLista(aux);
            free(aux);
            L->Prox = ex9(L->Prox, num);
        }
        else
        {
            L->Prox = ex9(L->Prox, num);
        }
    }

    PNodo ex13(PNodo L, int num)
    {
        if (listaVazia(L))
        {
            return L;
        }
        else if (L->Elemento.NIF == num)
        {
            PNodo aux;
            aux = L;
            L = L->Prox;
            removerLista(aux);
            free(aux);
            return ex13(L, num);
        }
        else
        {
            L->Prox = ex13(L, num);
            return L;
        }
    }

    PNodo ex14(PNodo L, int X)
    {
        if (listaVazia(L))
        {
            return L;
        }
        else if (L->Elemento.NIF >= X)
        {
            PNodo aux;
            aux = L;
            aux = removerLista(aux);
            free(aux);
            return ex14(L, X);
        }
        else
        {
            L->Prox = ex14(L, X);
            return L;
        }
    }

    int ex15(PNodo L, float x, float y)
    {

        if (listaVazia(L))
        {
            return 0;
        }
        else if (L->Elemento.Pagamento > x && L->Elemento.Pagamento < y)
        {
            return 1 + ex15(L->Prox, x, y);
        }
        else
        {
            return ex15(L->Prox, x, y);
        }
    }

    PNodo ex16(PNodo L, float k1, float k2)
    {
        int tam = tamanhoLista(L);
        int metade = tam / 2;
        if (tam < 2)
        {
            return L;
        }
        else
        {
            PNodo aux = L;

            for (int i = 0; i <= metade; i++)
            {
                aux->Elemento.Pagamento += k1;
                aux = aux->Prox;
            }
            for (int i = metade + 1; i <= tam; i++)
            {
                aux->Elemento.Pagamento += k2;
                aux = aux->Prox;
            }
            return ex16(L->Prox;)
        }
    }

    INFO ex18(PNodo L, float y)
    {
        Pnodo aux;
        if (listaVazia(L))
        {
            return L;
        }
        else if (L->Elemento.Pagamento >= y)
        {
            return ex18(L->Prox, y);
        }
        else
        {
            INFO maior = ex18(L->Prox, y);
            if (maior > L->Elemento.Pagamento)
            {
                return maior;
            }
            else
            {
                return L->Elemento.Pagamento;
            }
        }
    }

    PNodo ex20(PNodo L)
    {
        PNodo aux;
        if (listaVazia(L))
        {
            return L;
        }
        else if (L->Prox == NULL)
        {
            aux = L;
            L = NULL;
            aux = removerLista(aux);
            return L;
        }
        else if (L->Prox->Prox == NULL)
        {
            aux = L;
            L = NULL;
            aux = removerLista(aux);
            return L;
        }
        else
        {
            return ex20(L->Prox);
        }
    }
    PNodo ex21(PNodo L)
    {
        PNodo aux;
        if (listaVazia(L))
        {
            return L;
        }
        else if (L->Prox == NULL)
        {
            return L;
        }
        else if (L->Prox->Prox == NULL)
        {
            return L;
        }
        else
        {
            aux = L;
            L = NULL;
            aux = removerLista(aux);
            return L;
        }
    }

    PNodo ex23(PNodo L)
    {
        if (listaVazia(L))
        {
            return L;
        }
        else
        {
            PNodo aux;
            aux = L;
            L = L->Prox;
            libertarLista(aux);
            free(aux);
        }
        return L;
    }

    PNodo ex24(PNodo L, PNodo IL)
    {
        PNodo aux;
        if (listaVazia(L))
        {
            return L;
        }
        else
        {
            IL = ex24(L->Prox, L);
            L->Prox = IL;
            return aux;
        }
    }

    PNodo ex25(PNodo L, int N)
    {
        PNodo aux;
        for (int i = 0; i < N && listaVazia(aux) != 1; i++)
        {
            L = aux;
            L = L->Prox;
        }
        if (listaVazia(aux) == 1)
        {
            NULL->Prox = aux->Prox;
            free(aux);
        }
    }

    int ex3B(PNodo L, int a)
    {
        if (a >= 1 && a <= 2)
        {
            if (listaVazia(L) == 1)
            {
                return 0;
            }
            else if (L->Elemento.altura == a)
            {
                return 1 + ex3B(L->Prox, a);
            }
            else
            {
                return ex3B(L->Prox, a);
            }
        }
        else
        {
            printf("erro\n");
            return 0;
        }
    }

    int ex4B(PNodo L, int ano)
    {
        if (ano >= 1920 && a <= 2020)
        {
            if (listaVazia(L) == 1)
            {
                return 0;
            }
            else if (L->Elemento.ano == ano)
            {
                return 1 + ex4B(L->Prox, ano);
            }
            else
            {
                return ex4B(L->Prox, ano);
            }
        }
        else
        {
            return 0;
        }
    }

    int ex4B_it(PNodo L, int ano)
    {
        while (listaVazia(L) != 1)
        {
            int cont = 0;
            if (a < 1920 || a > 2022)
            {
                return 0;
            }
            if (L->Elemento.ano == ano)
            {
                cont++;
            }
            L = L->Prox;
            else
            {
                return cont;
            }
        }
    }

    PNodo ex5(PNodo L, int N)
    {
        if (N >= tamanhoLista(L))
        {
            while (listaVazia(L) != 1)
            {
                PNodo aux;
                aux = L;
                free(aux);
            }
            return L;
        }
        else
        {
            for (int i = 0; i < N; ++)
            {
                PNodo aux;
                aux = L;
                aux = removerLista(L);
                free(aux);
            }
        }
    }

    PNodo ex6(PNodo L)
    {
        PNodo M;
        PNodo F;

        while (!listaVazia(L))
        {
            PNodo aux;
            if (aux->Elemento.Genero == 0)
            {
                L->Prox;
                inserirListaInicio(aux->Elemento, M);
            }
            else if (aux->Elemento.Genero == 1)
            {
                L->Prox;
                inserirListaInicio(aux->Elemento, F);
            }

            L = L->Prox;
        }
    }

    PNodo exFreq(PNodo L)
    {
        PNodo aux;
        if (listaVazia(L) == 1)
        {
            return L;
        }
        else if (L->Elemento >= 0)
        {
            aux = L;
            L = L->Prox;
            aux = libertarNodo(aux);
            free(aux);
            return L;
        }
        L->Prox = exFreq(L->Prox);
    }

    PNodo exExame(PNodo L, int X)
    {
        if (listaVazia(L) == 1)
        {
            return L;
        }
        else if (L->Elemento != X)
        {
            L = L->Prox;
            return L;
        }
        else
        {
            return exExame(L->Prox, X);
        }
    }
}