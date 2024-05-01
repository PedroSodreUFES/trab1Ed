#ifndef pessoa_h
#define pessoa_h

typedef struct pessoa tPessoa;

#include "lista.h"

void inserePlaylist(tPessoa* pessoa, tPlaylist* playlist);

tPlaylist* buscaPlaylist(tPessoa* pessoa, char* nome);

tPessoa* inicializaPessoa(char* nome, int numPlaylists, tLista* amigos, tPlaylist** playlists);

char* retornaNomePessoa(tPessoa* pessoa);

int retornaNumPlaylists(tPessoa* pessoa);

tLista* retornaListaAmigos(tPessoa* pessoa);

tPlaylist** retornaVetorPlaylists(tPessoa* pessoa);

void liberaPessoa(tPessoa* pessoa);

#endif