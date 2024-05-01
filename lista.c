#include "lista.h"

struct celula{ //celula da lista de amigos
    void* conteudo;
    tCelula* prox;
};

struct lista{
    tCelula* primeiro;
    tCelula* ultimo;
};

tCelula* liberaCelula(tCelula* cel){

    tCelula* prox = cel->prox;
    liberaPessoa(cel->conteudo);
    free(cel);

    return prox;
}

tLista* inicializaLista(){
    tLista* lista = malloc(sizeof(tLista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void inserePessoaNaLista(tLista* lista, tPessoa* pessoa){
    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->conteudo = pessoa;
    lista->ultimo->prox = NULL;
}

void insereMusicaNaPlaylist(tLista* playlist, tMusica* musica){
    tCelula* novo = malloc(sizeof(tCelula));

    if(playlist->ultimo == NULL){
        playlist->primeiro = playlist->ultimo = novo;
    } else{
        playlist->ultimo->prox = novo;
        playlist->ultimo = playlist->ultimo->prox;
    }

    playlist->ultimo->conteudo = musica;
    playlist->ultimo->prox = NULL;
}

// void imprimeLista(tLista* lista){
//     tCelula* aux;
//     aux = lista->primeiro;

//     while(aux != NULL){
//         printf("Nome: %s, preco: %d e codigo: %d\n", retornaNome(aux->produto), retornaPreco(aux->produto), retornaCodigo(aux->produto));
//         aux = aux->prox;
//     }
// }

void liberaLista(tLista* lista){
    tCelula *cel = lista->primeiro;

    while(cel != NULL){
        cel = liberaCelula(cel);
    }

    free(lista);
}
