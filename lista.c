#include "lista.h"

struct celula{ //celula da lista de amigos
    void* conteudo;
    tCelula* prox;
};

struct lista{
    tCelula* primeiro;
    tCelula* ultimo;
};

/*
struct Pessoa{
    tLista *listademaigos;    
    tPlaylist **playlists;
    int nplaylists;
    char nomepessoa[30];
}
*/

/*
struct playlist
{
    tLista *musicas;
    char nomedaplaylist[50];
}
*/

/*
struct musica
{
    char nomedamusica[40], nomedoartista[40];
}
*/

//Buscar pessoa pelo nome
//Buscar Playlist pelo nome
//Busca Musica na Playlist

//

tCelula* liberaCelula(tCelula* cel){

    tCelula* prox = cel->prox;
    liberaProduto(cel->produto);
    free(cel);

    return prox;
}

tTipoLista* inicializaLista(){
    tTipoLista* lista = malloc(sizeof(tTipoLista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereCelulaNaLista(tProduto* produto, tTipoLista* lista){

    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->produto = produto;
    lista->ultimo->prox = NULL;
}

void retiraItem(tTipoLista* lista, int preco){
    tCelula* ant = NULL;
    tCelula* p = lista->primeiro;

    while(p != NULL && retornaPreco(p->produto) != preco){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return;

    if(p == lista->primeiro && p == lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        liberaCelula(p);
        return; 
    }

    if(p == lista->ultimo){
        lista->ultimo = ant; 
        ant->prox = NULL; 
        liberaCelula(p);
        return;
    }

    if(p == lista->primeiro){
        lista->primeiro = p->prox;    
    } else{
        ant->prox = p->prox;
    } 

    liberaCelula(p);
}

void imprimeLista(tTipoLista* lista){
    tCelula* aux;
    aux = lista->primeiro;

    while(aux != NULL){
        printf("Nome: %s, preco: %d e codigo: %d\n", retornaNome(aux->produto), retornaPreco(aux->produto), retornaCodigo(aux->produto));
        aux = aux->prox;
    }
}

void liberaLista(tTipoLista* lista){
    tCelula *cel = lista->primeiro;

    while(cel != NULL){
        cel = liberaCelula(cel);
    }

    free(lista);
}
