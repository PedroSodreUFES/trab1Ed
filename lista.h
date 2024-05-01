#ifndef lista_h
#define lista_h

#include "musica.h"
#include "playlist.h"
#include "pessoa.h"

typedef struct celula tCelula;
typedef struct lista tLista;

tCelula* liberaCelula(tCelula* cel);

tLista* inicializaLista();

void inserePessoaNaLista(tLista* lista, tPessoa* pessoa);

void insereMusicaNaPlaylist(tLista* playlist, tMusica* musica);

void liberaLista(tLista* lista);

#endif
