#ifndef lista_h
#define lista_h

typedef struct celula tCelula;
typedef struct lista tLista;

#include "musica.h"
#include "playlist.h"
#include "pessoa.h"

tCelula* liberaCelula(tCelula* cel);

tLista* inicializaLista();

void inserePessoaNaLista(tLista* lista, tPessoa* pessoa);

void insereMusicaNaPlaylist(tLista* playlist, tMusica* musica);

void liberaLista(tLista* lista);

#endif
