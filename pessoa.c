#include "pessoa.h"

struct pessoa{
    tLista* amigos;    
    tPlaylist** playlists;
    int numPlaylists;
    char* nomePessoa;
};

void inserePlaylist(tPessoa* pessoa, tPlaylist* playlist){
    (pessoa->numPlaylists)++;
    pessoa->playlists = realloc(pessoa->playlists, pessoa->numPlaylists*sizeof(tPlaylist*));
    pessoa->playlists[pessoa->numPlaylists - 1] = playlist;
}

tPessoa* inicializaPessoa(char* nome, int numPlaylists, tLista* amigos, tPlaylist** playlists){
    tPessoa* pessoa = malloc(sizeof(tPessoa));

    pessoa->nomePessoa = malloc(strlen(nome) + 1);
    strcpy(pessoa->nomePessoa, nome);

    pessoa->numPlaylists = numPlaylists;
    pessoa->amigos = amigos;
    pessoa->playlists = playlists;

    return pessoa;
}

char* retornaNome(tPessoa* pessoa){
    return pessoa->nomePessoa;
}

int retornaNumPlaylists(tPessoa* pessoa){
    return pessoa->numPlaylists;
}

tPessoa* retornaListaAmigos(tPessoa* pessoa){
    return pessoa->amigos;
}

tPlaylist** retornaVetorPlaylists(tPessoa* pessoa){
    return pessoa->playlists;
}

void liberaPessoa(tPessoa* pessoa){
    if(pessoa != NULL){
        free(pessoa->nomePessoa);
        liberaLista(pessoa->amigos);
        for(int i = 0; i < pessoa->numPlaylists; i++){
            liberaPlaylist(pessoa->playlists[i]);
        }
        free(pessoa->playlists);
        free(pessoa);
    }
}