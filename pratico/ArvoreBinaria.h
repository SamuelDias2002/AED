
struct NodoAB
{
    INFOAB Elemento;
    struct NodoAB *Esquerda;
    struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

// Operações sobre o Nodo

PNodoAB criarNodoAB(INFOAB);

PNodoAB libertarNodoAB(PNodoAB);

// Operações sobre a EAD Árvore Binária

PNodoAB criarAB();

PNodoAB destruirAB(PNodoAB);

int ABVazia(PNodoAB);

int numeroNodosAB(PNodoAB);

int alturaAB(PNodoAB);

void mostrarEmOrdemAB(PNodoAB);

void mostrarPreOrdemAB(PNodoAB);

void mostrarPosOrdemAB(PNodoAB);

// devolve um ponteiro para o nodo
//   com o elemento a pesquisar
PNodoAB pesquisarAB(INFOAB, PNodoAB);

// inserir de forma que fique equilibrada
PNodoAB inserirPorAlturaAB(INFOAB, PNodoAB);

// requisito: existe na árvore binária
//   um nodo com o elemento a remover
PNodoAB removerAB(INFOAB, PNodoAB);

#include "ArvoreBinaria.c"
