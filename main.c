#include "lista.h"

int main()
{
    //inicializa as pessoas e seus amigos
    tLista *pessoas = inicializaAsPessoasNoApp();

    //inicializa as playlists originais das pessoas
    inicializaPlaylistsDasPessoas(pessoas);

    //cria as playlists de artistas sem musicas e salva arquivos com musicas
    // que podem ser repetidas
    //retira as playlists originais
    atualizaPlaylistsDasPessoas(pessoas);

    //gera listas de playlists por artistas com musicas não repetidas
    geraNovasPlaylistsDeArtistas(pessoas);

    //gera os arquivos txt das playlists por artista
    geraArquivosPlaylists(pessoas);

    //gera played-refatorada.tx
    geraPlayedRefatorada(pessoas);

    //gera similaridades.txt
    geraSimilaridades(pessoas);

    //libera tudo
    liberaListaPessoas(pessoas);

    return 0;
}


