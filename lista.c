#include "lista.h"

struct celula{ //celula da lista de amigos
    void* conteudo;
    tCelula* prox;
};

struct lista{
    tCelula* primeiro;
    tCelula* ultimo;
};

tCelula* retornaPrimeiro(tLista* lista){
    return lista->primeiro;
}

void imprimeAmigos(tLista* amigos){
    tCelula* c = amigos->primeiro;
    tCelula* aux;

    while(c != NULL){
        aux = c->prox;
        printf("Amigos: ");
        printf("%s\n\n", retornaNomePessoa(c->conteudo));
        c = aux;
    }
}

void imprimePlaylist(tPlaylist* playlist){
    tCelula* c = retornaPrimeiro(retornaListaMusicas(playlist));
    tCelula* aux;

    while(c != NULL){
        aux = c->prox;
        printf("%s\n", retornaArtista(c->conteudo));
        printf("%s\n", retornaNomeMusica(c->conteudo));
        c = aux;
    }
}

void imprimePlaylists(tLista* p){
    tCelula* c = p->primeiro;
    tCelula* aux;

    while(c != NULL){
        aux = c->prox;
        imprimePlaylist(c->conteudo);
        c = aux;
    }
}

tCelula* liberaCelulaPessoa(tCelula* cel){

    tCelula* prox = cel->prox;
    liberaPessoa(cel->conteudo);
    free(cel);

    return prox;
}

tCelula* liberaCelulaMusica(tCelula* cel){

    tCelula* prox = cel->prox;
    liberaMusica(cel->conteudo);
    free(cel);

    return prox;
}

tPlaylist* buscaPlaylist(tPessoa* pessoa, char* nome){

    tCelula* cel = retornaPrimeiro(retornaListaPlaylists(pessoa));
    tCelula* aux;

    while(cel != NULL){
        aux = cel->prox;
        if(strcmp(retornaNomePlaylist(cel->conteudo), nome) == 0) return cel->conteudo;
        cel = aux;
    }

    return NULL;
}

tLista* inicializaLista(){
    tLista* lista = malloc(sizeof(tLista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereNaLista(tLista* lista, void* conteudo){
    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->conteudo = conteudo;
    lista->ultimo->prox = NULL;
}

tPessoa* buscaPessoa(tLista* lista, char* nome){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        if(strcmp(retornaNomePessoa(aux->conteudo), nome) == 0) return aux->conteudo;
        aux = aux->prox;
    }

    return NULL;
}

tMusica* buscaMusica(tLista* lista, char* nome){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        if(strcmp(retornaNomeMusica(aux->conteudo), nome) == 0) return aux->conteudo;
        aux = aux->prox;
    }

    return NULL;
}

void liberaListaPessoas(tLista* lista){
    tCelula *cel = lista->primeiro;

    while(cel != NULL){
        cel = liberaCelulaPessoa(cel);
    }

    free(lista);
}

void liberaListaMusicas(tLista* lista){
    tCelula *cel = lista->primeiro;

    while(cel != NULL){
        cel = liberaCelulaMusica(cel);
    }

    free(lista);
}

void liberaListaPlaylists(tLista* playlists){
    tCelula *cel = playlists->primeiro;
    tCelula* aux;

    while(cel != NULL){
        aux = cel->prox;
        liberaPlaylist(cel->conteudo);
        free(cel);
        cel = aux;
    }

    free(playlists);
}

void liberaListaAmigos(tLista* lista){
    tCelula *cel = lista->primeiro;
    tCelula *proxCel;

    while(cel != NULL){
        proxCel = cel->prox;
        free(cel);
        cel = proxCel;
    }

    free(lista);
}