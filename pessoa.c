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

tPlaylist* buscaPlaylist(tPessoa* pessoa, char* nome){
    for(int i = 0; i < pessoa->numPlaylists; i++){
        if(strcmp(retornaNomePlaylist(pessoa->playlists[i]), nome) == 0) return pessoa->playlists[i];
    }
    return NULL;
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

char* retornaNomePessoa(tPessoa* pessoa){
    return pessoa->nomePessoa;
}

int retornaNumPlaylists(tPessoa* pessoa){
    return pessoa->numPlaylists;
}

tLista* retornaListaAmigos(tPessoa* pessoa){
    return pessoa->amigos;
}

tPlaylist** retornaVetorPlaylists(tPessoa* pessoa){
    return pessoa->playlists;
}

void liberaPessoa(tPessoa* pessoa){
    if(pessoa != NULL){
        free(pessoa->nomePessoa);
        if(pessoa->amigos != NULL) liberaListaPessoas(pessoa->amigos); //QUALQUER COISA TIRA ISSO AQUI
        if(pessoa->numPlaylists > 0){
           for(int i = 0; i < pessoa->numPlaylists; i++){
                liberaPlaylist(pessoa->playlists[i]);
            } 
        }
        if(pessoa->playlists != NULL) free(pessoa->playlists);
        free(pessoa);
    }
}