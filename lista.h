#ifndef lista_h
#define lista_h

typedef struct celula tCelula;
typedef struct lista tLista;

#include "musica.h"
#include "playlist.h"
#include "pessoa.h"

tCelula* retornaPrimeiro(tLista* lista);

void imprimeAmigos(tLista* amigos);

void imprimePlaylist(tPlaylist* playlist);

void imprimePlaylists(tLista* p);

tCelula* liberaCelulaPessoa(tCelula* cel);

tCelula* liberaCelulaMusica(tCelula* cel);

tPlaylist* buscaPlaylist(tPessoa* pessoa, char* nome);

tLista* inicializaLista();

void insereNaLista(tLista* lista, void* conteudo);

tPessoa* buscaPessoa(tLista* lista, char* nome);

tMusica* buscaMusica(tLista* lista, char* nome);

void liberaListaPessoas(tLista* lista);

void liberaListaMusicas(tLista* lista);

void liberaListaPlaylists(tLista* lista);

void liberaListaAmigos(tLista* lista);

void imprimePessoaComSeusAmigos(tLista *listadepessoas);

tLista *inicializaAsPessoasNoApp();

void inicializaPlaylistsDasPessoas(tLista *pessoas);

void atualizaPlaylistsDasPessoas(tLista *pessoas);

#endif
