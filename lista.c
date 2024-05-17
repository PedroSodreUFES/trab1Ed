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

void imprimePessoaComSeusAmigos(tLista *listadepessoas)
{
    tCelula *cel = listadepessoas->primeiro;
    tCelula *proxCel;

    while(cel != NULL){
        tPessoa *p = (tPessoa*)cel->conteudo;
        printf("Nome do Usuario: %s\n", retornaNomePessoa(p));
        if(retornaListaAmigos(p)!=NULL)
        {
            imprimeAmigos(retornaListaAmigos(p));
        }
        else
        {
            printf("A pessoa indicada não tem amigos\n");
        }
        cel = cel->prox;
    }
}

tLista *inicializaAsPessoasNoApp()
{
    // retorna lista de pessoas com seus amigos;

    // verifica se o arquivo amigos.txt existe
    tLista *pessoas = inicializaLista();
    FILE *file_pointer;
    file_pointer = fopen("./Entrada/amizade.txt", "r");
    if (file_pointer == NULL)
    {
        printf("Arquivo "
               "amizade.txt"
               " não foi aberto corretamente\n");
        exit(1);
    }
    char n, nome[100];
    // inicializa as pessoas
    while (1)
    {
        fscanf(file_pointer, "%[^\n;]%c", nome, &n);
        tPessoa *p = inicializaPessoa(nome, NULL, NULL);
        insereNaLista(pessoas, p);
        // Quando as pessoas pararem de ser citadas, quebra a leitura de pessoas
        if (n != ';')
        {
            break;
        }
    }
    // faz a lista de amigos de cada um
    char nome2[100];
    while (fscanf(file_pointer, "%[^;]%*c%[^\n]%*c", nome, nome2) == 2)
    {
        tPessoa *p = buscaPessoa(pessoas, nome);   // retorna primeira pessoa
        tPessoa *p2 = buscaPessoa(pessoas, nome2); // retorna segunda pessoa
        // caso sejam pessoas iguais
        if (p == p2)
        {
            printf("As pessoas buscadas são iguais e não foram registradas como amigas\n");
        }
        // caso a primeira pessoa nao seja encontrada
        else if (p == NULL)
        {
            printf("A primeira pessoa buscada não foi encontrada\n");
        }
        // caso a segunda pessoa nao seja encontrada
        else if (p2 == NULL)
        {
            printf("A segunda pessoa buscada não foi encontrada\n");
        }
        // caso de registro como amigos
        else
        {
            if(retornaListaAmigos(p) == NULL)
            {
                tLista *l = inicializaLista();
                atribuiListaDeAmigos(l, p);
            }
            if(retornaListaAmigos(p2) == NULL)
            {
                tLista *l = inicializaLista();
                atribuiListaDeAmigos(l, p2);
            }
            tLista *friend_list_p1, *friend_list_p2;
            friend_list_p1 = retornaListaAmigos(p);
            friend_list_p2 = retornaListaAmigos(p2);
            if(buscaPessoa(friend_list_p1, nome2) != NULL)
            {
                printf("%s ja está inserida(o) na lista de %s\n", nome2, nome);
            }
            else
            {
                insereNaLista(friend_list_p1, p2);
            }
            if(buscaPessoa(friend_list_p2, nome) != NULL)
            {
                printf("%s ja está inserida(o) na lista de %s\n", nome, nome2);
            }
            else
            {
                insereNaLista(friend_list_p2, p);
            }
        }
    }
    fclose(file_pointer);
    return pessoas;
}

void inicializaPlaylistsDasPessoas(tLista *pessoas)
{
    //inicializa as playlists de geral
    FILE *file_pointer, *playlist_file;
    file_pointer = fopen("./Entrada/playlists.txt", "r");
    if(file_pointer==NULL)
    {
        printf("arquivo de playlists não existe\n");
        exit(1);
    }
    //le o nome de cada um e suas playlists
    char nome[100], nomeplaylist[100], c;
    int nplaylists, i;
    while(fscanf(file_pointer, "%[^;];%d;", nome, &nplaylists)==2)
    {
        tPessoa *p = buscaPessoa(pessoas, nome);
        //se a pessoa não existe
        if(p==NULL)
        {
            printf("Pessoa não existe na lista\n");
            fscanf(file_pointer, "%*[^\n]%*c");
            continue;
        }
        //se for pedido para ler 0 playlists
        if(nplaylists==0)
        {
            printf("não é possivel registrar 0 playlists para %s", nome);
            fscanf(file_pointer, "%*[^\n]%*c");
            continue;
        }
        //recupera a lista de playlists da pessoa
        tLista *l = retornaListaPlaylists(p);
        //se a pessoa nao tiver uma playlist
        if(l==NULL)
        {
            l = inicializaLista(l);
            atribuiListaDePlaylists(l, p);
        }
        //ler as playlists
        for(i=0 ; i<nplaylists ; i++)
        {
            //le cada playlist
            fscanf(file_pointer, "%[^\n;]%*c", nomeplaylist);
            tPlaylist *p = inicializaPlaylist(NULL, nomeplaylist);
            insereNaLista(l, p);
            //path da playlist
            char str[300];
            sprintf(str, "./Entrada/%s", nomeplaylist);
            playlist_file = fopen(str, "r");
            if(playlist_file==NULL)
            {
                printf("A playlist %s não existe\n", nomeplaylist);
                exit(1);
            }
            //faz a lista de musicas da playlist
            tLista *musicas = inicializaLista();
            atribuiListaDeMusicasNaPLaylist(p, musicas);
            //Coloca as musicas na playlist
            char artista[100], musica[100];
            while(fscanf(playlist_file, "%[^-]%*c%*c%[^\n]%*c", artista, musica)==2)
            {
                artista[strlen(artista)-1]='\0';
                tMusica *m = inicializaMusica(musica, artista);
                insereNaLista(musicas, m);
            }
            //fecha o arquivo playlist
            fclose(playlist_file);
        }
    }
    fclose(file_pointer);
}