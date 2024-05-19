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

int indiceNomeArtista(char *linha)
{
    char str[4] = " - ";
    int i=0, j=0, k, a=0, cont;
    for(i=0 ; i<strlen(linha) ; i++)
    {
        cont=0;
        for(j=0, k=i ; j<3 ; j++, k++)
        {
            if(linha[k]!=str[j])
            {
                break;
            }
            cont++;
            if(cont==3)
            {
                a=1;
            }
        }
        if(a==1)
        {
            return i;
        }
    }
}

void fazNomeArtistaMusica(char *nomeartista, char *nomemusica, char *linha, int indice)
{
    int i, j;
    for(i=0 ; i<indice ; i++)
    {
        nomeartista[i]=linha[i];
    }
    nomeartista[indice] = '\0';
    for(i=indice+3 , j=0 ; i<strlen(linha) ; i++, j++)
    {
        nomemusica[j]=linha[i];
    }
    nomemusica[j]='\0';
}

