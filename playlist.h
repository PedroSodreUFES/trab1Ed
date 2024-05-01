#ifndef playlist_h
#define playlist_h

#include "lista.h"

typedef struct playlist tPlaylist;

tPlaylist* inicializaPlaylist(tLista* listaMusicas, char* nome);

tLista* retornaListaMusicas(tPlaylist* playlist);

char* retornaNome(tPlaylist* playlist);

void liberaPlaylist(tPlaylist* playlist);

#endif