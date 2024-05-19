#ifndef lista_h
#define lista_h

typedef struct celula tCelula;
typedef struct lista tLista;

#include "musica.h"
#include "playlist.h"
#include "pessoa.h"

//retorna primeira celula da lista
tCelula* retornaPrimeiro(tLista* lista);

//retorna prox celula
tCelula* retornaProx(tCelula *celula);

//função teste para imprimir amigos da pessoa
void imprimeAmigos(tLista* amigos);

//imprime a playlist
void imprimePlaylist(tPlaylist* playlist);

//imprime todas as playlists
void imprimePlaylists(tLista* p);

tCelula* liberaCelulaPessoa(tCelula* cel);

tCelula* liberaCelulaMusica(tCelula* cel);

//busca playlist pelo nome
tPlaylist* buscaPlaylist(tLista *lista, char* nome);

tLista* inicializaLista();

//Conta celulas na lista
int contaCelulas(tLista *l);

//inserção em uma lista generica
void insereNaLista(tLista* lista, void* conteudo);

//busca pessoa por nome. Caso nao encontrada, retorna NULL
tPessoa* buscaPessoa(tLista* lista, char* nome);

//busca musica por nome e artista. Caso nao encontrada, retorna NULL
tMusica* buscaMusica(tLista* lista, char* nomemusica, char* nomeartista);

//libera o sistema todo
void liberaListaPessoas(tLista* lista);

//libera a lista de musicas caso ela exista
void liberaListaMusicas(tLista* lista);

//libera a lista de playlists caso ela exista
void liberaListaPlaylists(tLista* lista);

// libera lista de amigos caso ela exista
void liberaListaAmigos(tLista* lista);

//funcao teste para imprimir as pessoas e seus amigos
void imprimePessoaComSeusAmigos(tLista *listadepessoas);

//verifica se a musica está presente nas playlists de um amigo
int musicaNasPlaylistsDosAmigos(char *nomemusica, char *nomeartista, tLista *playlists);

/*
evita a repetição de linhas em similaridades.txt
obs: p eh a pessoa e lista_de_amigos eh a lista_de_amigos de um amigo de p.
no caso, o objetivo eh tornar nula a presença de p na lista de amigos do seu amigo
e evitar casos como:
Pedro;Lucas;10
Lucas;Pedro;10
*/
void evitaRepetiçãoDeAmigos(tPessoa *p, tLista *lista_de_amigos);

// todas as funções abaixo sao descritas na main
tLista *inicializaAsPessoasNoApp();

void inicializaPlaylistsDasPessoas(tLista *pessoas);

void atualizaPlaylistsDasPessoas(tLista *pessoas);

void geraNovasPlaylistsDeArtistas(tLista *pessoas);

void geraArquivosPlaylists(tLista *pessoas);

void geraPlayedRefatorada(tLista *pessoas);

void geraSimilaridades(tLista *pessoas);



#endif
