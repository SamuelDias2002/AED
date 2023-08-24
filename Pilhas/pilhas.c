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

// .2 - Altera a pilha
INFOP funcao2(PNodoPilha Pilha)
{
  Pilha = pop(Pilha);

  return Pilha->Elemento;
}

// .3 - Não altera a pilha
INFOP funcao3(PNodoPilha Pilha)
{
  int pos = 0;
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};

  while (Pilha != NULL)
  {
    if (pos == 1)
      return topo(Pilha);
    Pilha = Pilha->Ant;
    pos++;
  }

  return vazio;
}

//.4
INFOP EX4(PNodoPilha P, int n)
{
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
  int k = 0;
  if (n <= 0 || pilhaVazia(P))
  {
    return vazio;
  }
  while (k < n && pilhaVazia(P) != 1)
  {
    pop(P);
    k++;
  }
  return P->Elemento;
}

//.5
INFOP EX5(PNodoPilha P, int n)
{
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
  int k = 0;
  PNodoPilha aux;
  aux = criarPilha();
  if (n <= 0 || pilhaVazia(P))
  {
    return vazio;
  }
  while (k < n && pilhaVazia(P) == 0)
  {
    aux = push(topo(P), aux);
    k++;
  }

  return topo(aux);
}

//.6
INFOP ex6(PNodoPilha P)
{
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};

  while (P->Ant != NULL)
  {
    pop(P);
  }
  return P->Elemento;
}

//.7
INFOP ex7(PNodoPilha P)
{
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
  INFOP fundo = vazio;

  if (pilhaVazia(P))
  {
    return fundo;
  }

  while (P != NULL)
  {
    fundo = P->Elemento;
    P = P->Ant;
  }

  return fundo;
}

INFOP ex8(PNodoPilha P)
{
  INFOP vazio = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
  PNodoPilha aux = criarPilha();
  INFOP terceiroElemento = vazio;

  // Passo 1: Copiar os 3 primeiros elementos de P para aux
  int k = 0;
  while (k < 3 && !pilhaVazia(P))
  {
    aux = push(topo(P), aux);
    k++;
  }

  // Passo 2: Verificar se há pelo menos 3 elementos em P
  if (k < 3)
  {
    return vazio;
  }

  // Passo 3: Recuperar o terceiro elemento a partir do fundo
  terceiroElemento = topo(aux);

  // Passo 4: Devolver os elementos de P para sua posição original
  while (!pilhaVazia(aux))
  {
    push(topo(aux), P);
  }

  return terceiroElemento;
}

PNodoPilha ex9(PNodoPilha P)
{

  PNodoPilha aux = criarPilha();
  if (pilhaVazia(P))
  {
    return P;
  }
  while (pilhaVazia(P) != 0)
  {
    pop(P);
    push(topo(P), aux);
  }
  while (pilhaVazia(aux) != 0)
  {
    pop(aux);
    push(topo(aux), P);
  }
  return P;
}

//.10 ??????'

PNodoPilha ex10(PNodoPilha P)
{
  PNodoPilha aux = criarPilha();
  if (pilhaVazia(P))
  {
    return P;
  }
  while (!pilhaVazia(P))
  {
    push(topo(P), aux); // Passar elementos da pilha P para a pilha aux

    // Então temos como topo da lista aux -> Elemento base da lista P
  }
  INFOP topo_aux = topo(aux); // Armazena o elemento base da pilha P
  pop(aux);                   // Remove esse elemento base na Pilha P
  while (!pilhaVazia(P))
  {
    push(topo(aux), P); // Passa a lista aux (excepto a base) para a pilha P, isto coloca o elemento
                        // no topo da pilha como a base da pilha P
  }

  push(topo_aux, P); // Coloca o elemento base da pilha P como novo elemento do topo da pilha P
  return P;
}

//.11
PNodoPilha ex11(PNodoPilha P)
{
  PNodoPilha par = criarPilha();
  PNodoPilha impar = criarPilha();

  while (!pilhaVazia(P))
  {
    pop(P);
    if (P->Elemento.NFatura % 2 == 0)
    {
      push(topo(P), par);
    }
    else
    {
      push(topo(P), impar);
    }
  }

  while (!pilhaVazia(impar) && !pilhaVazia(par))
  {
    push(topo(impar), P);
    pop(impar);
    push(topo(par), P);
    pop(par);
  }
  return P;
}

// Frequencia  2021/2022 Ex Pilhas

PNodoPilha exFreq(PNodoPilha P, int N)
{
  PNodoPilha aux = criarPilha();
  int k = 1;

  while (k <= N && pilhaVazia(P) == 0)
  {
    aux = push(topo(P), aux);
    P = pop(P);
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

int main()
{
  PNodoPilha Pilha;
  PNodoPilha Pilha1;
  int N;

  // .1
  // N = gerarNumeroInteiro(8, 15);
  N = 1;
  Pilha = criarPilhaAleatoria(N);
  Pilha1 = Pilha;
  mostrarPilha(Pilha);

  //.2 - Altera a pilha
  /*printf("\n\nEXC2\nO segundo elemento da pilha é: ");
  mostrarElemento(funcao2(Pilha));
  printf("\nA pilha ficou assim:\n");
  mostrarPilha(Pilha);*/

  //.3 - Não altera a pilha
  printf("\n\nEXC3\nO segundo elemento da pilha é: ");
  mostrarElemento(funcao3(Pilha1));
  printf("\nA pilha ficou assim:\n");
  mostrarPilha(Pilha1);

  return 0;
}