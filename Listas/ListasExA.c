
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
  double ex3(PNodo L, int num)
  {
    float sum = 0;
    while (listaVazia(L) != 1)
    {
      if (L->Elemento.NIF == num)
        sum += L->Elemento.Pagamento;
      L = L->Prox;
    }
    return sum;
  }
  printf("Digite o NIF\n");
  int nifUso;
  scanf("%d", &nifUso);
  float tryIT = ex3(Lista, nifUso);

  double ex3rec(PNodo L, int num)
  {
    if (listaVazia(L) == 0)
    {
      return 0;
    }
    else
    {
      if (L->Elemento.NIF == num)
      {
        return L->Elemento.Pagamento + ex3rec(L->Prox, num);
      }
    }
  }
  float tryRec = ex3rec(Lista, nifUso);
  printf("\nEX 3\n[REC] Soma dos pagamentos das faturas que contêm o NIF %d: %f$\n", nifUso, ex3rec);
  printf("[ITER] Soma dos pagamentos das faturas que contêm o NIF %d: %f$\n", nifUso, ex3);

  // A.4
  int ex4(PNodo L, float pag)
  {
    if (listaVazia(L) == 1)
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
  printf("Digite o valor pagamento:\n");
  float valorPag;
  scanf("%f", &valorPag);
  int qntElemRec = ex4(Lista, valorPag);
  printf("\n\nEX 4\n[REC] Quantidade de elementos com pagamento >= %f: %d elementos\n", valorPag, qntElemRec);

  // A.5

  float ex5(PNodo L, float maior)
  {
    if (listaVazia(L) == 1)
    {
      return maior;
    }
    else
    {
      if (L->Elemento.Pagamento >= maior)
      {
        return ex5(L->Prox, L->Elemento.Pagamento);
      }
      else
      {
        return ex5(L->Prox, maior);
      }
    }
  }
  float maiorREC = ex5(Lista, 0);
  printf("\n\nEX 5\n[REC] O maior pagamento da lista é --> %f\n", ex5);

  // A.6

  INFO ex6(PNodo L, float k)
  {
    INFO menorElemento = {.NFatura = 0, .NIF = 0, .Data[0] = 0, .Data[1] = 0, .Data[2] = 0, .Pagamento = 0};
    while (listaVazia(L) != 1)
    {
      if (L->Elemento.Pagamento >= k)
      {
        menorElemento = L->Elemento;
        L = L->Elemento;
      }
    }
    return menorElemento;
  }

  // A.7
  PNodo ex7(PNodo L, int num)
  {
    while (listaVazia(L) != 1)
    {
      if (L->Elemento.NFatura == num)
      {
        removerLista(L->Elemento, L);
      }
      else
      {
        L = L->Prox;
      }
    }
  }

  // A.8

  PNodo ex8(PNodo L)
  {
    float maior = ex5(L);
    PNodo temp = L, prev;

    while (temp != NULL && temp->Elemento.Pagamento < maior)
    {
      prev = temp;
      temp = temp->Prox
    }
    while (temp != NULL)
    {
      while (temp != NULL && temp->Elemento.Pagamento >= maior)
      {
        prev = temp;
        temp = temp->Prox;
      }

      if (temp == NULL)
      {
        return L;
      }
      prev->Prox = temp->Prox;
    }
    return L;
  }

  // A.9

  PNodo ex9(PNodo L, int num)
  {
    if (listaVazia(L) == 1)
    {
      return L;
    }
    else if (L->Elemento.NIF == num)
    {
      PNodo aux = L;
      L = L->Prox;
      removerLista(aux->Elemento, L);
      free(aux);
      L->Prox = ex9(L, num);
    }
    else
    {
      L->Prox = ex9(L->Prox, num);
    }
    return L;
  }

  // A.10

  PNodo ex10(PNodo L, int n)
  {
    if (n > tamanhoLista(L))
    {
      libertarLista(L);
      mostrarListaInicioRec(L);
    }
    else
    {
      while (n > 0)
      {
        PNodo aux = L;
        L = L->Prox;
        removerLista(aux->Elemento, L);
        L->Prox;
        n--;
      }
      return L;
    }
  }

  // A.11
  PNodo ex11(PNodo L, int n)
  {
    PNodo p = L;
    while (p != NULL && p->Elemento.Nfatura != N)
    {
      p = p->Prox;
    }
    if (p == NULL)
    {
      return NULL;
    }
    else
    {
      PNodo NL = p->Prox;
      p->Prox = NULL;
      return NL;
    }
  }

  /* Frequencia ano passado exercicio B*/

  PNodo removerN(PNodo L)
  {
    PNodo aux;
    if (L == NULL)
    {
      return L;
    }
    else if (L->Elemento >= 0)
    {
      aux = L;
      L = L->Prox;
      aux = libertarNodo(aux);
      return L;
    }
    L->Prox = removerN(L->Prox);
  }

  // A.12
  PNodo ex12(PNodo L)
  {
    if (L == NULL || L->Prox == NULL)
    { // lista vazia ou com apenas um elemento
      return L;
    }

    int trocou = 0;
    PNodo atual = L;
    PNodo anterior = NULL;

    while (atual->Prox != NULL)
    {
      if (atual->Elemento.NIF > atual->Prox->Elemento.NIF)
      {
        PNodo Proximo = atual->Prox;
        atual->Prox = Proximo->Prox;
        Proximo->Prox = atual;

        if (anterior != NULL)
        {
          anterior->Prox = Proximo;
        }
        else
        {
          L = Proximo;
        }

        anterior = Proximo;
        trocou = 1;
      }
      else
      {
        anterior = atual;
        atual = atual->Prox;
      }
    }

    if (trocou)
    {
      L = ex12(L);
    }

    return L;
  }

  // A.13

  PNodo ex13(PNodo L, int x)
  {
    PNodo aux;

    if (listaVazia(L) = 1)
    {
      return L;
    }
    else if (L->Elemento.NIF == x)
    {
      aux = L;
      L = L->Prox;
      aux = removerLista(aux);
      return ex13(L, x);
    }
    L->Prox = ex13(L, x);
    return L;
  }

  // A.14

  PNodo ex14(PNodo L, int x)
  {
    PNodo aux;
    if (listaVazia(L))
    {
      return L;
    }
    else if (L->Elemento.NIF >= x)
    {
      aux = L;
      L = L->Prox;
      aux = removerLista(aux);
      return ex14(L, x);
    }
    L->Prox = ex14(L, x);
    return L;
  }

  // A.15

  int ex15(PNodo L, float x, float y)
  {
    int count = 0;

    if (listaVazia(L))
    {
      return count;
    }
    else if (L->Elemento.Pagamento > y && L->Elemento.Pagamento < x)
    {
      count++;
    }
    return ex15(L->Prox, x, y);
  }

  /* A.16
*/
  PNodo ex16(PNodo L, float k1, float k2) {
   int tam = tamanhoLista(L);
   if (tam < 2) {
     return L;
   }
   PNodo aux = L;
   int metade = tam / 2;
   for (int i = 1; i <= metade; i++) {
     aux->Elemento.Pagamento += k1;
     aux = aux->Prox;
   }
   for (int i = metade + 1; i <= tam; i++) {
     aux->Elemento.Pagamento += k2;
     aux = aux->Prox;
   }
   ex16(L->Prox, k1, k2);
   return L;
 }

 int tamanhoLista(PNodo L) {
   if (L == NULL) {
     return 0;
   }
   return 1 + tamanhoLista(L->Prox);
 }


  // A.18

  INFO ex18(PNodo L, int y)
  {
    PNodo aux;

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
      INFO maior_Proximo = ex18(L->Prox, y);
      if (maior_Proximo.Pagamento > L->Elemento.Pagamento)
      {
        return maior_Proximo;
      }
      else
      {
        return L->Elemento;
      }
    }
  }

  // A.20

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
      L->Prox = ex19(L->Prox);
      return L;
    }
  }

  // A.21

  PNodo ex21(PNodo L)
  {
    PNodo aux;
    if (listaVazia(L) || L->Prox == NULL || L->Prox->Prox == NULL)
    {
      return L;
    }
    else
    {
      aux = L;
      L = L->Prox;
      aux = removerLista(aux);
      free(aux);
      L->Prox = ex21(L->Prox);
      return L;
    }
  }

  // A.23

  PNodo ex23(PNodo L)
  {
    PNodo aux;
    if (listaVazia(L))
    {
      return L;
    }
    else
    {
      aux = L;
      L = L->Prox;
      libertarLista(aux);
      free(aux);
      return ex23(L->Prox);
    }
  }

  // A.24

  PNodo ex24(PNodo L, Pnodo BL)
  {
    PNodo aux;
    if (listaVazia(L))
    {
      return BL;
    }
    else
    {
      BL = ex24(L->Prox, L);
      L->Prox = BL;
      return aux;
    }
  }
  // A.25
  PNodo ex25(PNodo L, int N)
  {
    PNodo aux
        // Percorre a lista até o n-ésimo elemento
        for (int i = 0; i < N && aux != NULL; i++)
    {
      NULL = aux;
      L = aux;
      L = L->Prox;
    }

    // Se o elemento foi encontrado, remove-o
    if (aux != NULL)
    {
      NULL->Prox = aux->Prox;
      free(aux);
    }

    return L;
  }
}
