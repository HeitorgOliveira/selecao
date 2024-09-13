#include "jogador.h"
#include <stdlib.h>


struct item
{
    char *nome;
    int num;
};

ITEM *jogador_criar(char *nome, int num)
{
    ITEM *item = (ITEM*) malloc(sizeof(ITEM));
    if (item == NULL) return NULL;
    item->nome = nome;
    item->num = num;
    return item;
}

bool jogador_apagar(ITEM **item)
{
    if(item == NULL) return false;
    free(*item);
    *item = NULL;
    free(item);
    item = NULL;
}

int jogador_numero(ITEM *jogador)
{
    if (jogador == NULL) return -1;
    return jogador->num;
}