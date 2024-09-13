#include "pilha.h"
#include <stdlib.h>
#define MAX 1000000

struct pilha
{
    int tamanho;
    ITEM *itens[MAX];
};

PILHA *pilha_criar()
{
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));
    if (pilha == NULL) return NULL;
    pilha->tamanho = 0;
    return pilha;
}

bool pilha_empilhar(ITEM *item, PILHA * pilha)
{
    if (pilha == NULL) return false;
    if (item == NULL) return false;
    pilha->itens[pilha->tamanho++] = item;
    return true;
}

ITEM *pilha_desempilhar(PILHA *pilha)
{
    if (pilha == NULL) return NULL;

    if (pilha->tamanho <= 0)
    {
        return NULL;
    }
    ITEM *aux = pilha->itens[pilha->tamanho - 1];
    pilha->itens[pilha->tamanho - 1] = NULL;
    pilha->tamanho--;
    return aux;
}

bool pilha_apagar(PILHA **pilha)
{
    printf(".");
}

int pilha_tamanho(PILHA *pilha)
{
    if (pilha == NULL) return -1;
    return pilha->tamanho;
}