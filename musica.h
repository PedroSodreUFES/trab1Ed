#ifndef musica_h
#define musica_h

typedef struct musica tMusica;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tMusica* inicializaMusica(char* nome, char* artista);

char* retornaNomeMusica(tMusica* musica);

char* retornaArtista(tMusica* musica);

void liberaMusica(tMusica* musica);

int indiceNomeArtista(char *linha);

void fazNomeArtistaMusica(char *nomeartista, char *nomemusica, char *linha, int indice);

#endif
