#ifndef musica_h
#define musica_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica tMusica;

tMusica* inicializaMusica(char* nome, char* artista);

char* retornaNome(tMusica* musica);

char* retornaArtista(tMusica* musica);

void liberaMusica(tMusica* musica);

#endif
