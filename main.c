#include "lista.h"

int main(){

    tLista* lista = inicializaLista();

    tMusica* mus1 = inicializaMusica("16 toneladas", "Noriel Vilela");
    tMusica* mus2 = inicializaMusica("Another Brick in the Wall", "Pink Floyd");
    tMusica* mus3 = inicializaMusica("16 toneladas", "Noriel Vilela");
    tMusica* mus4 = inicializaMusica("Another Brick in the Wall", "Pink Floyd");
    tMusica* mus5 = inicializaMusica("I Will Survive", "Gloria Gaynor");
    tMusica* mus6 = inicializaMusica("Nao quero dinheiro", "Tim Maia");

    tLista* play1 = inicializaLista();
    tLista* play2 = inicializaLista();
    tLista* play3 = inicializaLista();
    insereMusicaNaPlaylist(play1, mus1);
    insereMusicaNaPlaylist(play1, mus2);
    insereMusicaNaPlaylist(play2, mus3);
    insereMusicaNaPlaylist(play2, mus4);
    insereMusicaNaPlaylist(play3, mus5);
    insereMusicaNaPlaylist(play3, mus6);
    //printf("inseri musicas\n");
    tPlaylist* playlist1 = inicializaPlaylist(play1, "Playlist1");
    tPlaylist* playlist2 = inicializaPlaylist(play2, "Playlist2");
    tPlaylist* playlist3 = inicializaPlaylist(play3, "Playlist3");
    //printf("inicializei playlists\n");

    tLista* amigos1 = inicializaLista();
    tLista* amigos2 = inicializaLista();

    tPessoa* Maria = inicializaPessoa("Maria", 0, amigos2, NULL);

    inserePessoaNaLista(amigos1, Maria);

    tPessoa* Pedro = inicializaPessoa("Pedro", 0, amigos1, NULL); //Vetor de vetor assim???
    inserePessoaNaLista(amigos2, Pedro);
    ///printf("PIMBA\n");

    inserePlaylist(Pedro, playlist1);
    inserePlaylist(Pedro, playlist2);
    inserePlaylist(Maria, playlist3);
    //printf("inseri playlists\n");

    inserePessoaNaLista(lista, Maria);
    inserePessoaNaLista(lista, Pedro);
    //printf("insei pessoa na lista\n");

    liberaListaPessoas(lista);
    //printf("liberei lista\n");

    return 0;
}
