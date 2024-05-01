#include "playlist.h"

struct playlist
{
    tLista* musicas;
    char* nomedaplaylist;
};

tPlaylist* inicializaPlaylist(tLista* listaMusicas, char* nome){
    tPlaylist* playlist = malloc(sizeof(tPlaylist));

    playlist->nomedaplaylist = malloc(strlen(nome)+1);
    strcpy(playlist->nomedaplaylist, nome);

    playlist->musicas = listaMusicas;

    return playlist;
}

tLista* retornaListaMusicas(tPlaylist* playlist){
    return playlist->musicas;
}

char* retornaNome(tPlaylist* playlist){
    return playlist->nomedaplaylist;
}

void liberaPlaylist(tPlaylist* playlist){
    if(playlist != NULL){
        liberaLista(playlist->musicas);
        free(playlist->nomedaplaylist);
        free(playlist);
    }
}
