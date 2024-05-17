#include "pessoa.h"

struct pessoa{
    tLista* amigos;    
    tLista* playlists;
    char* nomePessoa;
};

void imprimePessoa(tPessoa* pessoa){
    imprimeAmigos(pessoa->amigos);
    imprimePlaylists(pessoa->playlists);
}

tPessoa* inicializaPessoa(char* nome, tLista* amigos, tLista* playlists){
    tPessoa* pessoa = malloc(sizeof(tPessoa));

    pessoa->nomePessoa = malloc(strlen(nome) + 1);
    strcpy(pessoa->nomePessoa, nome);

    pessoa->amigos = amigos;
    pessoa->playlists = playlists;

    return pessoa;
}

char* retornaNomePessoa(tPessoa* pessoa){
    return pessoa->nomePessoa;
}

tLista* retornaListaAmigos(tPessoa* pessoa){
    return pessoa->amigos;
}

tLista* retornaListaPlaylists(tPessoa* pessoa){
    return pessoa->playlists;
}

void liberaPessoa(tPessoa* pessoa){
    if(pessoa != NULL){
        free(pessoa->nomePessoa);
        liberaListaAmigos(pessoa->amigos);//libera a lista sem liberar os amigos
        if(pessoa->playlists!=NULL)// a pessoa pode nao ter nenhuma musica
        {
            liberaListaPlaylists(pessoa->playlists);
        }
        free(pessoa);
    }
}

void atribuiListaDeAmigos(tLista *lista_de_amigos, tPessoa *p)
{
    p->amigos = lista_de_amigos;
}

void atribuiListaDePlaylists(tLista *lista_de_playlists, tPessoa *p)
{
    p->playlists = lista_de_playlists;
}