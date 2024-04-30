#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct celula tCelula;
typedef struct lista tTipoLista;

tCelula* liberaCelula(tCelula* cel);

tTipoLista* inicializaLista();

void insereCelulaNaLista(tProduto* produto, tTipoLista* lista);

void retiraItem(tTipoLista* lista, int v);

void imprimeLista(tTipoLista* lista);

void liberaLista(tTipoLista* lista);

#endif
