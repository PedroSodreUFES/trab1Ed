#ifndef lista_h
#define lista_h

typedef struct celula tCelula;
typedef struct lista tLista;

#include "musica.h"
#include "playlist.h"
#include "pessoa.h"

tCelula* liberaCelulaPessoa(tCelula* cel);

tCelula* liberaCelulaMusicaMusica(tCelula* cel);

tLista* inicializaLista();

void inserePessoaNaLista(tLista* lista, tPessoa* pessoa);

void insereMusicaNaPlaylist(tLista* playlist, tMusica* musica);

tPessoa* buscaPessoa(tLista* lista, char* nome);

tMusica* buscaMusica(tLista* lista, char* nome);

void liberaListaPessoas(tLista* lista);

void liberaListaMusicas(tLista* lista);

#endif
