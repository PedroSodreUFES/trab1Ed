#include "lista.h"

int main(int agrc, char **argv)
{
    tLista *pessoas = inicializaAsPessoasNoApp();
    inicializaPlaylistsDasPessoas(pessoas);
    atualizaPlaylistsDasPessoas(pessoas);
    liberaListaPessoas(pessoas);
    return 0;
}


