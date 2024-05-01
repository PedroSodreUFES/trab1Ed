#ifndef pessoa_h
#define pessoa_h

#include "lista.h"

typedef struct pessoa tPessoa;

void inserePlaylist(tPessoa* pessoa, tPlaylist* playlist);

tPessoa* inicializaPessoa(char* nome, int numPlaylists, tLista* amigos, tPlaylist** playlists);

char* retornaNome(tPessoa* pessoa);

int retornaNumPlaylists(tPessoa* pessoa);

tPessoa* retornaListaAmigos(tPessoa* pessoa);

tPlaylist** retornaVetorPlaylists(tPessoa* pessoa);

void liberaPessoa(tPessoa* pessoa);

#endif