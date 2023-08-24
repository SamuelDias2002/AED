#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"

typedef struct{
  int   numAluno;     // chave, com valores entre 4000 e 4100
  float	 notaFreq;    // soma das notas das frequências ([0..16])
  float	 notaPratica; // soma das notas dos testes práticos ([0..4])
  int	aprovado;     // 0 (reprovado) e 1 (aprovado)
}INFOAB;


void mostrarElementoAB(INFOAB);

INFOAB criarElementoAB();

// comparação de 2 elementos do tipo INFOAB,
// segundo o campo numAluno (chave);
// devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB(INFOAB, INFOAB);

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

/* A.3 -
Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
determine os números de elementos da subárvore esquerda e da subárvore direita de T. */

void numNodosEsqDir(PNodoAB arvore, int *esq, int *dir) // Variaveis esq e dir para poder correr os dois lados da arvore
{
  if (arvore == NULL) // Se árvore for vazia temos 0 elementos no lado esquerdo e 0 elementos no lado direito
  {
    *esq = 0;
    *dir = 0;
  }
  else
  {
    /* Caso contrário, usamos a função numeroNodosAB para contar os nodos à direita e à esquerda
      numeroNodosAB adiciona 1 se encontrar algum valor diferente de NULL, caso contrário devolve 0
    */
    *dir = numeroNodosAB(arvore->Direita);
    *esq = numeroNodosAB(arvore->Esquerda);
  }
}

/**
 * A.4 - Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
        determine o número de elementos com valor no campo NIF igual a dado valor K.
        Use esta função, para determinar o número de elementos da árvore binária construída em 1
        com valor do NIF igual ao da raiz.

Definimos de novo variaveis inteiras esq e dir para podermos correr os dois lado da árvore
Se a arvore for vazia [Relembrar que ter ABVazia(arvore) é o mesmo que ter arvore == NULL, podemos de ter que
usar um dos dois dependendo do enunciado] devolve 0
Se não for vazia, corremos a arvore à esquerda (1) e à direita (2)
Se em (1) e em (2) descobrimos um k = Elemento.NIF (Elemento.NIF já é fornecido pelo professor) somamos 1 e voltamos a correr a função
de novo (return 1 + esq + dir;), caso contrário corremos a função de novo (esq + dir;)

 */
int numElementosNIFigualK(PNodoAB arvore, int k) // k <=> nif
{

  int esq, dir;
  if (ABVazia(arvore))
    return 0;
  esq = numElementosNIFigualK(arvore->Esquerda, k);
  dir = numElementosNIFigualK(arvore->Direita, k);
  if (arvore->Elemento.NIF == k)
    return 1 + esq + dir;
  else
    return esq + dir;
}

/**
 *  A.5 - Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
          determine o elemento de T com maior valor no campo Data[2] (ano).
 */
INFOAB ElementoMaiorAno(PNodoAB arvore)
{
  INFOAB esq, dir, maior;
  /*
  INFO AB é a estrutura de dados dada pelo professor
  Precisamos de definir variaveis do tipo estrutura INFOAB para correr à esquerda e à direita da árvore, mas
  também precisamos de definir uma varivavel para armazenar aquele que tem o maior valor no campo Data[2] (ano)
  */

  /* Condição de paragem. Se tanto a arvore à direita e à esquerda forem vazias, devolve o único elemento da árvore
  (Se quiseres, podes chamar a cabeça da árvore, apesar do termo não ser correto no papel, mas ajuda a entender) */
  if (arvore->Esquerda == NULL && arvore->Direita == NULL)
    return arvore->Elemento;

  /* Chamadas recursivas que enchem uma stack. Se a àrvore direita ou esquerda tiverem conteudo, temos de chamar a função
  para correr nesse lado da àrvore */
  if (arvore->Esquerda != NULL)
    esq = ElementoMaiorAno(arvore->Esquerda);
  if (arvore->Direita != NULL)
    dir = ElementoMaiorAno(arvore->Direita);

  /* A arvore é percorrida e verifica se encontra uma data maior que a "cabeça da árvore", que vai ser o maior no inicio da árvore
  (no sh*t Sherlock xD)
  Se ao percorrer na árvore esquerda ou direita encontrar algum elemento com o ano maior do que está armazenado no elemento "maior"
  substitui o maior por esse elemento e dá return ao maior quando acabar
  */
  maior = arvore->Elemento;
  if (arvore->Esquerda != NULL && esq.Data[2] > maior.Data[2])
    maior = esq;
  if (arvore->Direita != NULL && dir.Data[2] > maior.Data[2])
    maior = dir;

  return maior;
}

/**
 *  A.6 - Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
determine a soma do campo Pagamento de todos os elementos de
 * Se a arvore for vazia, a soma dos pagamentos é 0
 * Se não for vazia vai percorrer a árvore à esquerda e à direita, somando os valores do Elemento.Pagamento
*/

float ex6(PNodoAB arvore)
{

  if (ABVazia(arvore))
  {
    return 0;
  }
  else
  {
    float esq = ex6(arvore->Esquerda);
    float dir = ex6(arvore->Direita);
    return arvore->Elemento.Pagamento + esq + dir;
  }
}

/**
 * A.7 - Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
construa e devolva uma nova árvore binária do mesmo tipo que seja uma cópia de T

 * Para além de termos a arvore original, temos de criar uma nova árvore, neste caso denominada de cópia
 * Se a arvore original for vazia (NULL), a cópia também é automáticamente NULL
 * Caso contrário, definimos "cabeça" da árvore original como a "cabeça" da árvore copia, e os lados direito e esquerdo da árvore original
  como os lados direito e esquerdo da árvore cópia
 *
*/
PNodoAB ex7(PNodoAB arvore)
{
  PNodoAB copia = criarAB();
  if (ABVazia(arvore))
  {
    return NULL;
  }
  else
  {
    copia->Elemento = arvore->Elemento;
    copia->Esquerda = ex7(arvore->Esquerda);
    copia->Direita = ex7(arvore->Direita);
  }

  return copia;
}

/**
 * A.8 - Implemente uma função que dado duas árvores binárias, T1 e T2, com elementos do tipo
INFOAB, verifique se são iguais (T1 = T2).

 * Verifica se as 2 arvores são vazias, se não for devolve 0, se forem devolve 1
 * Caso contrário, vai comparar as árvores usando a função compararElementosAB
 * compararElementosAB usa o Elemento.NFatura para ver se são iguais, pois se forem, quer dizer que o resto dos elementos são iguais
 * Caso compararElementosAB seja 0, vai realizar a comparação para o lado esquerdo e para o lado direito, assim só devolve 0 se ambos
 os lados da árvore forem realmente 0
*/

int ex8(PNodoAB arvore1, PNodoAB arvore2)
{
  if (arvore1 == NULL || arvore2 == NULL)
  {
    return 0;
  }
  else if (arvore1 == NULL && arvore2 == NULL)
  {
    return 1;
  }
  else if (compararElementosAB(arvore1->Elemento, arvore2->Elemento) == 0)
  {
    return ex8(arvore1->Esquerda, arvore2->Esquerda) && ex8(arvore1->Direita, arvore2->Direita);
  }
}

//

/*
  A.9 - Implemente uma função que dada uma árvore binária T com elementos do tipo INFOAB,
construa e devolva uma nova árvore binária do mesmo tipo que seja a imagem espelhada de T
(isto é, todas as subárvores da esquerda são agora subárvores da direita e vice-versa).

  * Pensamento semelhante ao ex 7 mas o lado esquerdo da árvore copia tem de receber o lado direito da árvore original e
o lado direito da árvore cópia tem de receber o lado esquerdo da árvore original
*/
PNodoAB ex9(PNodoAB arvore)
{
  PNodoAB copia = criarAB();
  if (ABVazia(arvore))
  {
    return NULL;
  }
  else
  {
    copia->Elemento = arvore->Elemento;
    copia->Esquerda = ex9(arvore->Direita);
    copia->Direita = ex9(arvore->Esquerda);
  }

  return copia;
}

/**
 * A.10 - Implemente uma função que, dada uma árvore binária T com elementos do tipo INFOAB,
determine o número de nodos de T que são folhas (nodos sem filhos).

 * Pretendemos descobrir os nodos da árvore que são folhas (nodos sem filhos) então basta:
 * Ver se a árvore é vazia, se sim, não tem folhas (a árvore não tem elementos xD)
 * Caso não esteja vazia, corre para o lado esquerdo e para o lado direito, vendo se tem elementos ou não
 * Tem elementos? Return 1
 * No fim, corremos a função de novo no lado esquerdo e no lado direito da árvore, somando os resultados
 * (vai ser sempre uma soma 1+1+1+1...)

*/
int ex10(PNodoAB arvore)
{
  if (ABVazia(arvore))
  {
    return 0;
  }
  else if (arvore->Esquerda == NULL && arvore->Direita != NULL)
  {
    return 1;
  }
  else
  {
    return ex10(arvore->Esquerda) + ex10(arvore->Direita);
  }
}

/* A.11 - Implemente uma função que, dada uma árvore binária T com elementos do tipo INFOAB,
determine o número de nodos de T que têm um e um só filho.
*/
int ex11(PNodoAB A)
{
  // Verifica se a árvore é vazia
  if (ABVazia(A))
  {
    return 0; // Árvore vazia, nenhum nó com apenas um filho
  }
  // Verifica se o nó atual possui apenas um filho
  if (ABVazia(A->Esquerda) && !ABVazia(A->Direita) || !ABVazia(A->Esquerda) && ABVazia(A->Direita))
  {
    return 1 + ex11(A->Esquerda) + ex11(A->Direita); // Nó com apenas um filho, retorna 1 + recursão para os filhos
  }
  else
  {
    return ex11(A->Esquerda) + ex11(A->Direita); // Nó com dois filhos, recursão para os filhos
  }
}

/**
A.12 Implemente uma função que, dados uma árvore binária T com elementos do tipo INFOAB e um
elemento X do tipo INFOAB (X pertence a T), devolva o nível de um nodo da árvore que
contém o X.

 * Primeiro vamos ver se a àrvore é vazia, se sim return -1 (não pode ser NULL, porque queremos saber qual é
o nível onde o elemento X está)
 * Se não for vazia, vamos comparar elementos (compararElementosAB, again) entre o elemento X e a "cabeça" da árvore, se os
elementos forem iguais, então devolve 0 (o nivel é 0);
 * Caso contrário procura no lado esquerdo e no lado direito, se encontrar, retorna o nível onde o encontrou, caso contrário
 retorna -1 (não encontrou em lado nenhum)
*/

int ex12(PNodoAB arvore, INFOAB X)
{
  if (arvore == NULL)
  {
    return -1;
  }
  else if (compararElementosAB(arvore->Elemento, X) == 0)
  {
    return 0;
  }
  else
  {
    int esq = ex12(arvore->Esquerda, X);
    int dir = ex12(arvore->Direita, X);

    if (esq >= 0)
    {
      return 1 + esq;
    }
    else if (dir >= 0)
    {
      return 1 + dir;
    }
    else
    {
      return -1;
    }
  }
}

int main()
{
  PNodoAB arvore;
  int N;

  // A. 1
  N = gerarNumeroInteiro(1, 15);
  arvore = criarABAleatoria(N);
  // A.2
  printf("Mostrar árvore  de %d elementos criada no A. 1:\n", N);
  printf("\nEm ordem:\n");
  mostrarEmOrdemAB(arvore);
  printf("\nPré-ordem:\n");
  mostrarPreOrdemAB(arvore);
  printf("\nPós ordem:\n");
  mostrarPosOrdemAB(arvore);
  printf("%d\n", numeroNodosAB(arvore));

  // A. 3
  int numElementosSubArvEsq = 0,
      numElementosSubArvDir = 0;
  numNodosEsqDir(arvore, &numElementosSubArvEsq, &numElementosSubArvDir);
  printf("\nA subarvore esquerda tem %d elementos.\nA subarvore direita tem %d elementos.\n", numElementosSubArvEsq, numElementosSubArvDir);

  // A. 4

  int NIFprimeiroElemento = arvore->Elemento.NIF;
  int numElementosIgualNIF = numElementosNIFigualK(arvore, NIFprimeiroElemento);
  printf("\nHá %d elementos com o NIF igual a %d.", numElementosIgualNIF, NIFprimeiroElemento);

  // A. 5
  int maiorAnoDaArv = ElementoMaiorAno(arvore).Data[2];
  printf("\nO maior ano presente na árvore é: %d", maiorAnoDaArv);

  // A.6
  float sum = ex6(arvore);

  return 0;
}