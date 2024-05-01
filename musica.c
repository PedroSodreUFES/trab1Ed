#include "musica.h"

struct musica{
    char* nomeMusica;
    char* nomeArtista;
};

tMusica* inicializaMusica(char* nome, char* artista){
    tMusica* musica = malloc(sizeof(tMusica));

    musica->nomeMusica = malloc(strlen(nome)+1);
    strcpy(musica->nomeMusica, nome);
    musica->nomeArtista = malloc(strlen(artista)+1);
    strcpy(musica->nomeArtista, artista);

    return musica;
}

char* retornaNomeMusica(tMusica* musica){
    return musica->nomeMusica;
}

char* retornaArtista(tMusica* musica){
    return musica->nomeArtista;
}

void liberaMusica(tMusica* musica){
    if(musica != NULL){
        free(musica->nomeArtista);
        free(musica->nomeMusica);
        free(musica);
    }
}

