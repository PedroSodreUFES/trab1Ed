#include "lista.h"

int main(){ //Lista principal (pessoa), lista de playlists e lista de amigos

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
    insereNaLista(play1, mus1);
    insereNaLista(play1, mus2);
    insereNaLista(play2, mus3);
    insereNaLista(play2, mus4);
    insereNaLista(play3, mus5);
    insereNaLista(play3, mus6);

    tPlaylist* playlist1 = inicializaPlaylist(play1, "playlist1");
    tPlaylist* playlist2 = inicializaPlaylist(play2, "playlist2");
    tPlaylist* playlist3 = inicializaPlaylist(play3, "playlist3");

    tLista* playlistsPedro = inicializaLista();
    tLista* playlistsMaria = inicializaLista();

    insereNaLista(playlistsPedro, playlist1);
    insereNaLista(playlistsPedro, playlist2);
    insereNaLista(playlistsMaria, playlist3);
    //printf("inseri musicas\n");

    tLista* amigos1 = inicializaLista();
    tLista* amigos2 = inicializaLista();

    tPessoa* Maria = inicializaPessoa("Maria", amigos2, playlistsMaria);

    insereNaLista(amigos1, Maria);

    tPessoa* Pedro = inicializaPessoa("Pedro", amigos1, playlistsPedro); //Vetor de vetor assim???
    insereNaLista(amigos2, Pedro);

    //printf("inseri playlists\n");

    insereNaLista(lista, Maria);
    insereNaLista(lista, Pedro);
    
    printf("\nPEDRO:\n\n");
    imprimePessoa(Pedro);
    printf("\nMARIA:\n\n");
    imprimePessoa(Maria);
    printf("\n");

    //printf("inseri pessoa na lista\n");

    liberaListaPessoas(lista);
    //printf("liberei lista\n");

    return 0;
}
