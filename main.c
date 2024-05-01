#include "lista.h"

int main(){

    tLista* lista = inicializaLista();

    tMusica* mus1 = inicializaMusica("16 toneladas", "Noriel Vilela");
    tMusica* mus2 = inicializaMusica("Another Brick in the Wall", "Pink Floyd");
    tMusica* mus3 = inicializaMusica("I Will Survive", "Gloria Gaynor");

    printf("inicializei musicas\n");

    tLista* play1 = inicializaLista();
    tLista* play2 = inicializaLista();
    printf("inicializei listas\n");
    insereMusicaNaPlaylist(play1, mus1);
    insereMusicaNaPlaylist(play1, mus2);
    insereMusicaNaPlaylist(play2, mus1);
    insereMusicaNaPlaylist(play2, mus2);
    insereMusicaNaPlaylist(play2, mus3);
    printf("inseri musicas\n");
    tPlaylist* playlist1 = inicializaPlaylist(play1, "Playlist1");
    tPlaylist* playlist2 = inicializaPlaylist(play2, "Playlist2");
    printf("inicializei playlists\n");

    tLista* amigos = inicializaLista();
    tPessoa* Pedro = inicializaPessoa("Pedro", 0, amigos, NULL); //Vetor de vetor assim???
    printf("PIMBA\n");

    inserePlaylist(Pedro, playlist1);
    inserePlaylist(Pedro, playlist2);
    printf("inseri playlists\n");

    inserePessoaNaLista(lista, Pedro);
    printf("insei pessoa na lista\n");

    liberaListaPessoas(lista);
    printf("liberei lista\n");

    return 0;
}
