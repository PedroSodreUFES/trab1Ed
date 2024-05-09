#ifndef pessoa_h
#define pessoa_h

typedef struct pessoa tPessoa;

#include "lista.h"

void imprimePessoa(tPessoa* pessoa);

tPessoa* inicializaPessoa(char* nome, tLista* amigos, tLista* playlists);

char* retornaNomePessoa(tPessoa* pessoa);

tLista* retornaListaAmigos(tPessoa* pessoa);

tLista* retornaListaPlaylists(tPessoa* pessoa);

void liberaPessoa(tPessoa* pessoa);

#endif