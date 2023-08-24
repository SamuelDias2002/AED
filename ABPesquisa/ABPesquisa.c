#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABPorNiveis.h"

// Ex. A.1
PNodoAB construirABPAleatoria(int N)
{
  PNodoAB T;
  T = criarAB();
  for (int i = 0; i < N; i++)
  {
    INFOAB elArv = criarElementoAB();
    T = inserirABP(elArv, T);
  }
  return T;
}

// Ex. A.2
int numeroElementosABEsquerda(PNodoAB T)
{
  return numeroNodosAB(T->Esquerda);
}

int numeroElementosABDireita(PNodoAB T)
{
  return numeroNodosAB(T->Direita);
}

int alturaArbB(PNodoAB T)
{
  return alturaAB(T);
}

// Ex. A.3
PNodoAB maiorvalorNFatura(PNodoAB T)
{
  if (T == NULL)
  {
    return NULL;
  }
  if (T->Direita == NULL)
  {
    return T;
  }

  return maiorvalorNFatura(T->Direita);
}

/**
 * A.4 - Implementar uma função que dado uma ABP T, determine o nodo de T com menor valor da
chave (campo NFatura).

Sabemos que os valores menores que a "cabeça" da árvore são colocados no lado esquerdo da AB de pesquisa, então basta:
- Verificar se a árvore é vazia, caso sim o menor valor é NULL
- Se não for, procura no lado esquerdo.
- Se o lado esquerdo não existe, então o menor valor da chave é a cabeça
- Se ainda existe mais valores no lado esquerdo, vai percorrendo até chegar ao último
*/
PNodoAB menorvalorNFatura(PNodoAB T)
{
  if (T == NULL)
  {
    return NULL;
  }
  if (T->Esquerda == NULL)
  {
    return T;
  }

  return menorvalorNFatura(T->Esquerda);
}

/**
 * A.5 - Implementar uma função que dado uma ABP T e um valor inteiro A, determine o número de
elementos de T cujos valores do campo NFatura são superiores a A.

- Temos de verificar se a árvore é vazia, caso seja, há 0 elementos superiores a A
- Caso não seja vazia, temos de procurar à esquerda e à direita da árvore
- Se encontrar temos de somar 1 e voltar a correr a função (return 1 + esq + dir;)
- Se não encontrar, continua a correr a função (return esq + dir;)
*/
int numElementosMaioresA(PNodoAB T, int A)
{
  int dir, esq;

  if (ABVazia(T))
  {
    return 0;
  }
  dir = numElementosMaioresA(T->Direita, A);
  esq = numElementosMaioresA(T->Esquerda, A);

  if (T->Elemento.NFatura > A)
  {
    return 1 + esq + dir;
  }
  else
  {
    return esq + dir;
  }
}

/**
 * A.6 Implementar uma função uma função que dada uma ABP T e um valor inteiro A, devolva o
nodo associado ao elemento com valor do campo NFatura igual a A, se existir; se não existir,
deve devolve NULL.

- Temos de verificar se apenas há um elemento na AB de pesquisa (a "cabeça" da árvore), e comparar para ver se é o valor A,
devolve o nodo respetivo
- Se o lado esquerdo e o lado direito não forem vazios, temos de percorrer a função em ambos os lados
- Caso não sejam vazios e encontrarem o valor A, devolve o nodo respetivo (dir se for no lado direito, esq se for no lado esquerdo)
- Se não descobrir nada, devolve NULL
*/
PNodoAB nodoNFaturaigualA(PNodoAB T, int A)
{
  PNodoAB esq, dir;

  if (ABVazia(T->Direita) && ABVazia(T->Esquerda) && (T->Elemento.NFatura == A))
  {
    return T;
  }

  if (T->Direita != NULL)
  {
    dir = nodoNFaturaigualA(T->Direita, A);
  }
  if (T->Esquerda != NULL)
  {
    esq = nodoNFaturaigualA(T->Esquerda, A);
  }

  if (T->Direita != NULL && dir->Elemento.NFatura == A)
  {
    return dir;
  }
  if (T->Esquerda != NULL && esq->Elemento.NFatura == A)
  {
    return esq;
  }

  return NULL;
}
/**
 * A.7 Implementar uma função que dado uma ABP T e dois valores inteiros A e B (A < B), determine
o número de elementos de T cujos valores do campo NFatura são maiores ou iguais a A e
menores ou iguais a B

- Definir uma variavel count para servir como contador de elementos
- Verificar se a árvore é vazia. Caso seja, não há valores possiveis
- Se não for vazia e encontrar algum valor maior ou igual a A e menor ou igual a B aumenta a variável count em 1
- Precisamos de correr a árvore nos 2 lados, se descobrir somamos 1 ao contador
[count += ex7(T->Esquerda, A, B); e count += ex7(T->Direita, A, B);]
- Devolver a variavel que serve como contador

*/
int ex7(PNodoAB T, int A, int B)
{
  int count = 0;
  if (ABVazia(T))
  {
    return 0;
  }

  if (T->Elemento.NFatura >= A && T->Elemento.NFatura <= B)
  {
    count++;
  }
  if (T->Esquerda != NULL)
  {
    count += ex7(T->Esquerda, A, B);
  }
  if (T->Direita != NULL)
  {
    count += ex7(T->Direita, A, B);
  }
  return count;
}

/**
 * A.8 -Implementar uma função que dado uma ABP T e dois valores inteiros A e B (A < B), determine
o número de elementos de T cujos valores do campo NFatura são menores que A ou maiores
que B.

- Mesma ideia do A.7
*/

int ex7(PNodoAB T, int A, int B)
{
  int count = 0;
  if (ABVazia(T))
  {
    return 0;
  }

  if (T->Elemento.NFatura >= B && T->Elemento.NFatura <= A)
  {
    count++;
  }
  if (T->Esquerda != NULL)
  {
    count += ex7(T->Esquerda, A, B);
  }
  if (T->Direita != NULL)
  {
    count += ex7(T->Direita, A, B);
  }
  return count;
}

/**
 * A.9 - Remover da ABP T construída em 1 um qualquer elemento X do tipo INFOAB, caso exista.
Mostre a árvore obtida após aquela operação.

- Verificar se existe um nodo igual a 1, usando a função pesquisarABP, dada pelo professor
- Caso exista, remove usando outra função dada pelo professor (removerABP), que devolve a árvore sem o elemento
- Caso contrário, devolve a árvore como está, porque não existe o tal elemento
*/
PNodoAB removerElemento(INFOAB X, PNodoAB arvore)
{
  if (pesquisarABP(X, arvore) == 1)
    return removerABP(X, arvore);
  else
    return arvore;
}

/**
 * A.10 - Implementar uma função que dado uma ABP T, transforme esta ABP num vetor ordenado
crescentemente. Comece por alocar dinamicamente o vetor.

- Antes de alocarmos dinamicamente o vetor, precisamos de verificar se a árvore não é vazia, se for vazia devolve pos
- Se não for, verificamos se não é vazia no lado esquerdo, se sim definimos a variavel pos para executar a função de forma recursiva
- Agora sim, alocamos dinamicamente o vetor. O vetor vai ser definido de forma crescente pelo NFatura.
- Aumentamos o pos em 1 valor para continuar a alocar os valores no vetor
- Executamos o função de forma recursiva para o lado direito, e assim ordenamos a árvore no vetor em ordem crescente


*/
int ordenaEmVetor(PNodoAB arvore, int *v, int pos)
{
  if (arvore == NULL)
    return pos;

  if (arvore->Esquerda != NULL)
    pos = ordenaEmVetor(arvore->Esquerda, v, pos);

  v[pos] = arvore->Elemento.NFatura;
  pos++;

  if (arvore->Direita != NULL)
    pos = ordenaEmVetor(arvore->Direita, v, pos);

  return pos;
}

/**
 * A.11 - Implementar uma função que dado uma ABP T, determine o nível da folha mais próxima (em
altura) da raiz de T e o nível da folha mais afastada (em altura) da raiz de T.

 [Not sure se é isto, mas provavelmente está errado...]

- Primeiro temos de saber se a árvore está vazia, caso contrário devolve 0
- Caso contrário, temos de saber se o nodo é uma folha (lado esquerdo e lado vazio = NULL)
- Se for, faz comparações entre os niveis, e devolve o nível atual
- Executa de forma recursiva para o lado esquerdo e o lado direito
*/

int ex11(PNodoAB T, int nivelAtual, int nivelMin, int nivelMax)
{
  if (T == NULL)
  {
    return 0; // árvore vazia
  }
  if (T->Esquerda == NULL && T->Direita == NULL) // é uma folha
  {
    if (nivelAtual < nivelMin)
    {
      nivelMin = nivelAtual;
      return nivelAtual;
    }
    if (nivelAtual > nivelMax)
    {
      nivelMax = nivelAtual;
      return nivelAtual;
    }
  }
  ex11(T->Esquerda, nivelAtual + 1, nivelMin, nivelMax);
  ex11(T->Direita, nivelAtual + 1, nivelMin, nivelMax);
}

/**
 * A.12 - Implementar uma função que dado uma ABP T, remova o maior elemento (considerando o valor
da chave) de T. Mostre a árvore obtida após aquela operação. Otimizar o algoritmo (percorrer a
ABP uma unica vez).

Como os valores maiores que a cabeça estão sempre no lado direito da AB de pesquisa, basta:
- Verificar se a árvore é vazia, se sim, devolver a árvore (Devolver T ou NULL é igual)
- Verificar se o lado direito é NULL, ou seja se é o último elemento, isto é, se é o maior elemento da arvore
- Usar a função removerABP que remove e devolve a árvore com o elemento removido
- Executar de forma recursiva para o lado direito de cada nodo
*/
PNodoAB ex12(PNodoAB T)
{
  if (T == NULL)
  {
    return T;
  }
  else
  {
    if (T->Direita == NULL)
    {
      return removerABP(T->Elemento, T);
    }
    else
    {
      return ex12(T->Direita);
    }
  }
}

/**
 * A.13 - Implementar uma função que dado uma ABP T, remova o menor elemento (considerando o
valor da chave) de T. Mostre a árvore obtida após aquela operação. Otimizar o algoritmo
(percorrer a ABP uma unica vez).

- Mesma ideia do A.12, mas para o lado esquerdo (armazena os valores menores que a "cabeça" da árvore)
*/

PNodoAB ex13(PNodoAB T)
{
  if (T == NULL)
  {
    return T;
  }
  else
  {
    if (T->Esquerda == NULL)
    {
      return removerABP(T->Elemento, T);
    }
    else
    {
      return ex13(T->Esquerda);
    }
  }
}

int main(void)
{
}