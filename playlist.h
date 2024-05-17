#ifndef playlist_h
#define playlist_h

typedef struct playlist tPlaylist;

#include "lista.h"

tPlaylist* inicializaPlaylist(tLista* listaMusicas, char* nome);

tLista* retornaListaMusicas(tPlaylist* playlist);

char* retornaNomePlaylist(tPlaylist* playlist);

void liberaPlaylist(tPlaylist* playlist);

void atribuiListaDeMusicasNaPLaylist(tPlaylist *playlist, tLista *musicas);

#endif