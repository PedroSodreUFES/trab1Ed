#ifndef pessoa_h
#define pessoa_h

typedef struct pessoa tPessoa;

#include "lista.h"
#include "playlist.h"

void inserePlaylist(tPessoa* pessoa, tPlaylist* playlist);

tPessoa* inicializaPessoa(char* nome, int numPlaylists, tLista* amigos, tPlaylist** playlists);

char* retornaNomePessoa(tPessoa* pessoa);

int retornaNumPlaylists(tPessoa* pessoa);

tLista* retornaListaAmigos(tPessoa* pessoa);

tPlaylist** retornaVetorPlaylists(tPessoa* pessoa);

void liberaPessoa(tPessoa* pessoa);

#endif