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

tCelula* retornaProx(tCelula *celula){
    return celula->prox;
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

tPlaylist* buscaPlaylist(tLista* lista, char* nome){

    tCelula* cel = retornaPrimeiro(lista);
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

tMusica* buscaMusica(tLista* lista, char* nomemusica, char* nomeartista)
{
    if(lista==NULL)
    {
        return NULL;
    }

    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        if(strcmp(retornaNomeMusica(aux->conteudo), nomemusica) == 0 && strcmp(retornaArtista(aux->conteudo), nomeartista) == 0) return aux->conteudo;
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
    if(lista == NULL)
    {
        return;
    }
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

//função para teste: imprime a pessoa e seus amigos
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

//inicializa as pessoas de acordo com o arquivo amizade.txt
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
            // se a pessoa 1 não tiver amigos ainda
            if(retornaListaAmigos(p) == NULL)
            {
                tLista *l = inicializaLista();
                atribuiListaDeAmigos(l, p);
            }

            //se a pessoa 2 nao tiver amigos ainda
            if(retornaListaAmigos(p2) == NULL)
            {
                tLista *l = inicializaLista();
                atribuiListaDeAmigos(l, p2);
            }

            //obtem a lista de amigos de cada um
            tLista *friend_list_p1, *friend_list_p2;
            friend_list_p1 = retornaListaAmigos(p);
            friend_list_p2 = retornaListaAmigos(p2);

            //checagem para ver se as pessoas ja estao incluidas na lista de amigos ou nao
            if(buscaPessoa(friend_list_p1, nome2) != NULL)
            {
                printf("%s ja está inserida(o) na lista de %s\n", nome2, nome);
            }
            else
            {
                insereNaLista(friend_list_p1, p2);
            }

            //mesmo processo para a pessoa 2
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

//Recebe a lista de pessoas e as confere suas playlists no arquivo playlists.txt
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
            char artista[100], musica[100], linha[300];
            while(fscanf(playlist_file, "%[^\n]%*c", linha)==1)
            {
                fazNomeArtistaMusica(artista, musica, linha, indiceNomeArtista(linha));
                tMusica *m = inicializaMusica(musica, artista);
                insereNaLista(musicas, m);
            }
            //fecha o arquivo playlist
            fclose(playlist_file);
        }
    }
    fclose(file_pointer);
}

//remove as playlists originais e faz as playlists de artistas
void atualizaPlaylistsDasPessoas(tLista *pessoas)
{
    tCelula *cel_person = pessoas->primeiro, *cel_play, *cel_musica;
    system("mkdir Saidas_prog");
    //surfa pela lista de pessoas
    while(cel_person != NULL){
        //recebe a pessoa
        tPessoa *p = (tPessoa*)cel_person->conteudo;

        //faz o comando para criar a pasta da pessoa
        char cmnd[200] ="\0";
        sprintf(cmnd, "mkdir Saidas_prog/%s", retornaNomePessoa(p));
        system(cmnd);
        strcpy(cmnd, "\0");

        //retorna a lista de playlists da pessoa e cria uma nova lista de playlists para colocar as playlists com nome dos artistas
        tLista *lista_de_playlists = retornaListaPlaylists(p);
        cel_play = lista_de_playlists->primeiro;
        tLista *lista_nova_de_playlists = inicializaLista();

        //surfa pelas playlist da pessoa
        while(cel_play!=NULL)
        {
            tPlaylist *playlist = (tPlaylist*)cel_play->conteudo;
            tLista *lista_de_musicas = retornaListaMusicas(playlist);
            cel_musica = lista_de_musicas->primeiro;
            //surfa pela lista de musicas
            while(cel_musica!=NULL)
            {
                tMusica *musica = (tMusica*)cel_musica->conteudo;
                //recebe os dados do artista
                char *nomeartista = retornaArtista(musica);
                char *nomemusica = retornaNomeMusica(musica);
                //faz caminho da playlist.txt e cria as novas playlists
                char file_name[300], nome_artista_p[100];
                sprintf(nome_artista_p, "%s.txt", nomeartista);
                //se a playlist nao existe na nova lista de playlists
                if(buscaPlaylist(lista_nova_de_playlists, nome_artista_p)==NULL)
                {
                    tLista *new_music_list = inicializaLista();
                    tPlaylist *new_playlist = inicializaPlaylist(new_music_list, nome_artista_p);
                    insereNaLista(lista_nova_de_playlists, new_playlist);
                }
                //salva as playlists com liberdade a musicas repetidas
                sprintf(file_name, "Saidas_prog/%s/%s.txt", retornaNomePessoa(p), nomeartista);
                FILE *artist_playlist = fopen(file_name, "a");
                if(artist_playlist==NULL)
                {
                    printf("playlist do artista não abriu");
                    exit(1);
                }
                fprintf(artist_playlist, "%s - %s\n", retornaArtista(musica), retornaNomeMusica(musica));
                fclose(artist_playlist);
                cel_musica = cel_musica->prox;
            }
            cel_play = cel_play->prox;
        }
        liberaListaPlaylists(lista_de_playlists);
        atribuiListaDePlaylists(lista_nova_de_playlists ,p);
        cel_person = cel_person->prox;
    }
}

//Conta numero de celulas na lista
int contaCelulas(tLista *l)
{
    tCelula *c = retornaPrimeiro(l);
    int i=0;
    while(c!=NULL)
    {
        i++;
        c = retornaProx(c);
    }
    return i;
}

//atualiza as playlists de cada artista
void geraNovasPlaylistsDeArtistas(tLista *pessoas)
{
    tCelula *cel_person = pessoas->primeiro, *cel_play;
    //surfa pela lista de pessoas
    while(cel_person != NULL)
    {
        //recebe a pessoa
        tPessoa *p = (tPessoa*)cel_person->conteudo;
        //retorna a lista de playlists da pessoa
        tLista *lista_de_playlists = retornaListaPlaylists(p);
        cel_play = lista_de_playlists->primeiro;
        //surfa pelas playlists da pessoa
        while(cel_play!=NULL)
        {
            
            FILE *playlist_file;
            tPlaylist *playlist = (tPlaylist*)cel_play->conteudo;
            char file_path[300];
            sprintf(file_path, "Saidas_prog/%s/%s", retornaNomePessoa(p), retornaNomePlaylist(playlist));
            playlist_file = fopen(file_path, "r");
            if(playlist_file==NULL)
            {
                printf("a playlist %s não abriu\n", file_path);
                exit(1);
            }
            //surfa pela lista de musicas
            char linha[400];
            while(fscanf(playlist_file, "%[^\n]%*c", linha)==1)
            {
                //faz os dados da musica
                char nomeartista[300], nomemusica[100];
                fazNomeArtistaMusica(nomeartista, nomemusica, linha, indiceNomeArtista(linha));
                //se a musica nao tiver na playlist, inserir ela na playlist
                if(buscaMusica(retornaListaMusicas(playlist), nomemusica,nomeartista) ==NULL)
                {
                    tMusica *musica = inicializaMusica(nomemusica, nomeartista);
                    insereNaLista(retornaListaMusicas(playlist), musica);
                }
            }
           fclose(playlist_file);
           cel_play = cel_play->prox;
        }
        cel_person = cel_person->prox;
    }
}

//gera os arquivos de cada playlist
void geraArquivosPlaylists(tLista *pessoas)
{
    tCelula *cel_person = pessoas->primeiro, *cel_play, *cel_musica;
    //surfa pela lista de pessoas
    while(cel_person != NULL)
    {
        //recebe a pessoa
        tPessoa *p = (tPessoa*)cel_person->conteudo;
        //retorna a lista de playlists da pessoa
        tLista *lista_de_playlists = retornaListaPlaylists(p);
        cel_play = lista_de_playlists->primeiro;
        //surfa pelas playlists da pessoa
        while(cel_play!=NULL)
        {
            //realiza a abertura da file playlist
            FILE *playlist_file;
            tPlaylist *playlist = (tPlaylist*)cel_play->conteudo;
            char file_path[300];
            sprintf(file_path, "Saidas_prog/%s/%s", retornaNomePessoa(p), retornaNomePlaylist(playlist));
            playlist_file = fopen(file_path, "w");
            if(playlist_file==NULL)
            {
                printf("a playlist %s não abriu\n", file_path);
                exit(1);
            }
            //surfa pela lista de musicas
            tLista *lista_de_musicas = retornaListaMusicas(playlist);
            cel_musica = lista_de_musicas->primeiro;
            while(cel_musica != NULL)
            {
                //printa os dados da musica
                tMusica *musica = (tMusica*)cel_musica->conteudo;
                fprintf(playlist_file, "%s - %s\n", retornaArtista(musica), retornaNomeMusica(musica));
                cel_musica = cel_musica->prox;
            }
           fclose(playlist_file);
           cel_play = cel_play->prox;
        }
        cel_person = cel_person->prox;
    }
}

//gera played-refatorada.txt
void geraPlayedRefatorada(tLista *pessoas)
{
    FILE *fatorada_txt;
    char file_path[300];
    sprintf(file_path, "Saidas_prog/played-refatorada.txt");
    fatorada_txt = fopen(file_path, "w");
    if(fatorada_txt==NULL)
    {
        printf("a playlist %s não abriu\n", file_path);
        exit(1);
    }
    tCelula *cel_person = pessoas->primeiro, *cel_play, *cel_musica;
    //surfa pela lista de pessoas
    while(cel_person != NULL)
    {
        //recebe a pessoa
        tPessoa *p = (tPessoa*)cel_person->conteudo;
        fprintf(fatorada_txt,"%s;", retornaNomePessoa(p));
        //retorna a lista de playlists da pessoa e obtem a primeira playlist
        tLista *lista_de_playlists = retornaListaPlaylists(p);
        int contaCelula = contaCelulas(lista_de_playlists), i=0;
        fprintf(fatorada_txt, "%d;",  contaCelula);
        cel_play = lista_de_playlists->primeiro;
        //surfa pelas playlists da pessoa e printa as playlists da pessoa
        while(cel_play!=NULL)
        {
            i++;
            tPlaylist *playlist = (tPlaylist*)cel_play->conteudo;
            fprintf(fatorada_txt, "%s", retornaNomePlaylist(playlist));
            cel_play = cel_play->prox;
            if(i<contaCelula)
            {
                fprintf(fatorada_txt, ";");
            }
            else
            {
                fprintf(fatorada_txt, "\n");
            }
        }
        cel_person = cel_person->prox;
    }
    fclose(fatorada_txt);
}

//faz o arquivo similaridades.txt
void geraSimilaridades(tLista *pessoas)
{
    FILE *similaridades_txt;
    char file_path[300];
    int cont;
    sprintf(file_path, "Saidas_prog/similaridades.txt");
    similaridades_txt = fopen(file_path, "w");
    if(similaridades_txt==NULL)
    {
        printf("a playlist %s não abriu\n", file_path);
        exit(1);
    }
    tCelula *cel_person = pessoas->primeiro, *cel_play, *cel_musica, *cel_amigo;
    //surfa pela lista de pessoas
    while(cel_person != NULL)
    {
        //recebe a pessoa e sua lista de amigos
        tPessoa *p = (tPessoa*)cel_person->conteudo;
        tLista *lista_de_amigos = retornaListaAmigos(p);

        cel_amigo = lista_de_amigos->primeiro;
        //surfa pelos amigos da pessoa
        while(cel_amigo)
        {
            //se o amigo ja foi scaneado antes, nao operar novamente
            if(cel_amigo->conteudo ==NULL)
            {
                cel_amigo = cel_amigo->prox;
                continue;    
            }

            //recebe o amigo e sua lista de playlists
            tPessoa *friend = (tPessoa*)cel_amigo->conteudo;
            tLista *friend_playlists = retornaListaPlaylists(friend);

            cel_play = retornaListaPlaylists(p)->primeiro;
            //surfa pela playlist da pessoa
            cont=0;
            while(cel_play != NULL)
            {
                //recebe a playlist e aponta para a primeira musica;
                tPlaylist *playlist = (tPlaylist*)cel_play->conteudo;
                cel_musica = retornaListaMusicas(playlist)->primeiro;
                while(cel_musica != NULL)
                {
                    //recebe a musica e ve se ela ta na playlist do amigo
                    tMusica *m = (tMusica*)cel_musica->conteudo;
                    if(musicaNasPlaylistsDosAmigos(retornaNomeMusica(m), retornaArtista(m), friend_playlists))
                    {
                        cont++;
                    }
                    cel_musica = cel_musica->prox;
                }
                cel_play= cel_play->prox;
            }
            //printa as similaridades com o amigo
            fprintf(similaridades_txt, "%s;%s;%d\n", retornaNomePessoa(p), retornaNomePessoa(friend), cont);
            
            //Seta NULL a pessoa na lista de amigos do amigo para que não haja repetições
            evitaRepetiçãoDeAmigos(p, retornaListaAmigos(friend));
            
            cel_amigo = cel_amigo->prox;
        }
        cel_person = cel_person->prox;
    }
    fclose(similaridades_txt);
}


//diz se uma musica de alguem está na playlist de seu amigo
int musicaNasPlaylistsDosAmigos(char *nomemusica, char *nomeartista, tLista *playlists)
{
    tCelula *cel_playlist, *cel_musica;

    //obtem primeira playlist e surfa pelas playlists
    cel_playlist = playlists->primeiro;
    while(cel_playlist != NULL)
    {
        //obtem primeira musica
        tPlaylist *playlist = (tPlaylist*)cel_playlist->conteudo;
        cel_musica = retornaListaMusicas(playlist)->primeiro;
        
        //surfa pelas musicas
        while(cel_musica!=NULL)
        {
            //se as musicas forem iguais, retornar verdadeiro
            tMusica *m = (tMusica*)cel_musica->conteudo;
            if(strcmp(nomemusica, retornaNomeMusica(m))==0 && strcmp(nomeartista, retornaArtista(m)) == 0)
            {
                return 1;
            }
            cel_musica = cel_musica->prox;
        }
        cel_playlist = cel_playlist->prox;
    }

    //se nenhuma musica for igual, retornar 0
    return 0;
}


//evita repetições em similaridades.txt
void evitaRepetiçãoDeAmigos(tPessoa *p, tLista *lista_de_amigos)
{
    tCelula *cel_amigo= retornaPrimeiro(lista_de_amigos);
    while(cel_amigo != NULL)
    {
        //se o amigo for p, coloca o conteudo da celula como NULL
        tPessoa *friend = (tPessoa*)cel_amigo->conteudo;
        if(friend == p)
        {
            cel_amigo->conteudo = NULL;
            return;
        }
        cel_amigo = cel_amigo->prox;
    }
}