#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasP.h"
#include "EADPilha.h"

void mostrarPilha(PNodoPilha S)
{
    PNodoPilha P = S;
    printf("TOPO\n");
    while (P != NULL)
    {
        mostrarElemento(P->Elemento);
        P = P->Ant;
    }
    printf("CAUDA\n");
}

// .1
PNodoPilha criarPilhaAleatoria(int N)
{
    PNodoPilha pilha;
    pilha = criarPilha();

    for (int i = 0; i < N; i++)
    {
        INFOP inf = criarElemento();
        pilha = push(inf, pilha);
    }

    return pilha;
}

// .2

INFOP ex2(PNodoPilha P)
{
    P = pop(P); /*Visto que posso alterar a pilha original,
                basta remover o primeiro elemento da pilha*/
    return P->Elemento;
}

//.3
INFOP ex3(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    int pos = 0;

    while (!pilhaVazia(P))
    {
        if (pos == 1)
        {
            return topo(P);
        }
        P = P->Ant;
        pos++;
    }
    return P->Elemento;
}
// .4
INFOP ex4(PNodoPilha P, int N)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    int k = 0;
    if (n <= 0 || pilhaVazia(P))
    {
        return vazio;
    }
    while (k < n && !pilhaVazia(P))

    {
        pop(P);
        k++;
    }
    return P->Elemento;
}

INFOP ex5(PNodoPilha P, int n)
{
    PNodoPilha aux = criarPilha();
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    if (n <= 0 || pilhaVazia(P))
    {
        return vazio;
    }
    while (!pilhaVazia(P))
    {
        aux = push(topo(P), aux);
    }
    INFOP resultado = vazio;
    while (k < n && !pilhaVazia(aux))
    {
        resultado = pop(aux); // qnd k < n  resultado vai ter o n-esimo elemento de P
        k++
    }
    while (!pilhaVazia(aux))
    {
        P = push(P, pop(aux));
    }
    return resultado;
}

// .6

INFOP ex6(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    if (pilhaVazia(P))
    {
        return vazio;
    }
    while (P->Ant != NULL)
    {
        P = P->Ant;
    }
    return P->Elemento;
}

//.7
INFOP ex7(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    INFOP fundo = vazio;
    PNodoPilha aux = criarPilha;
    if (pilhaVazia(P))
    {
        return fundo;
    }
    while (!pilhaVazia(P))
    {
        aux = push(topo(P), aux);
        P = pop(P);
    }
    fundo = topo(aux);
    while (!pilhaVazia(aux))
    {
        P = push(topo(aux), P);
        aux = pop(aux);
    }
    return fundo;
}

// .8
INFOP ex8(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    INFOP terceiro = vazio;
    PNodoPilha aux = criarPilha();
    int k = 0;

    // Verifica se a pilha é vazia ou tem menos de 3 elementos
    if (pilhaVazia(P) || tamanhoPilha(P) < 3)
    {
        return vazio;
    }

    while (!pilhaVazia(P) && k < 3)
    {
        aux = push(topo(P), aux);
        P = pop(P);
        k++;
    }

    if (k == 3)
    {
        terceiro = topo(aux);
    }

    while (!pilhaVazia(aux))
    {
        P = push(topo(aux), P);
        aux = pop(aux);
    }

    return terceiro;
}

// .9

PNodoPilha(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    INFOP terceiro = vazio;
    PNodoPilha aux = criarPilha();
    if (pilhaVazia(P))
    {
        return P;
    }
    while (!pilhaVazia(P))
    {
        P = pop(P);
        aux = push(topo(P), aux);
    }
    return aux;
}

// .10

PNodoPilha(PNodoPilha P)
{
    INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    INFOP topo_aux = vazio;
    PNodoPilha aux = criarPilha();
    if (pilhaVazia(P))
    {
        return P;
    }
    while (!pilhaVazia(P))
    {
        push(topo(P), aux);
        P = pop(P);
    }
    topo_aux = topo(aux);
    pop(aux);
    while (!pilhaVazia(P))
    {
        push(topo(aux), P);
        aux = pop(aux);
    }

    push(topo_aux, P);
    return P;
}

// .11

PNodoPilha ex11(PNodoPilha P)
{
    PNodoPilha par = criarPilha();
    PNodoPilha impar = criarPilha();
    if (PNodoPilha(P))
    {
        return P;
    }
    while (!pilhaVazia(P))
    {

        if (P->Elemento.NFatura % 2 == 0)
        {

            push(P->Elemento, par);
        }
        else
        {

            push(P->Elemento, impar);
        }
        P = pop(P);
    }

    while (!pilhaVazia(impar) && !pilhaVazia(par))
    {
        push(topo(par), P);
        pop(par);
        push(topo(impar), P);
        pop(impar);
    }
    return P;
}

// Ex Freq
PNodoPilha exFreq(PNodoPilha P, int n)
{
    PNodoPilha aux = criarPilha();
    int k = 1;

    while (k <= n && pilhaVazia(P))
    {
        aux = push(topo(P), aux);
        P = pop(P);
        k++;
    }
    while (pilhaVazia(P) == 0)
    {
        P = pop(P);
    }
    while (pilhaVazia(aux) == 0)
    {
        P = push(topo(aux), P);
        aux = pop(aux);
    }
    return P;
}

PNodoPilha exGPT(PNodoPilha P)
{
    PNodoPilha aux = criarPilha();
    if (pilhaVazia(P))
    {
        return P;
    }
    while (!pilhaVazia(P))
    {
        if (P->Elemento % 2 != 0)
        {
            push(pop(P), aux);
        }
        else
        {
            pop(P);
        }
    }
    while (!pilhaVazia(aux))
    {
        push(pop(aux), P)
    }
    return P;
}

PNodoPilha exGPT2(PNodoPilha P, PNodoPilha S)
{
    PNodoPilha PS = criarPilha();
    if (pilhaVazia(P) && pilhaVazia(S))
    {
        return PS; // Pretendo que de sempre return a pilha PS mesmo que seja inexistente
    }
    while (!pilhaVazia(P) && !pilhaVazia(S))
    {
        PS = push(topo(P), PS);
        pop(P);
        PS = push(topo(S), PS);
        pop(S);
    }
    if (!pilhaVazia(PS))
    {
        return PS;
    }
    else
    {
        destruirPilha(PS);
        return NULL;
    }
    return PS;
}

PNodoPilha exGPT3(PNodoPilha P)
{
    PNodoPilha aux = criarPilha();
    if (pilhaVazia(P))
    {
        return P;
    }
    while (!pilhaVazia(P))
    {
        if (P->Elemento % 3 == 0)
        {
            aux = push(pop(P), aux);
        }
        else
        {
            pop(P);
        }
    }
    return aux;
}