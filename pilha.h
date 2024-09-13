#include <stdio.h>
#include "jogador.h"
#include <stdbool.h>

#ifndef PILHA_H
    #define PILHA_H

    typedef struct pilha PILHA;

    PILHA *pilha_criar();
    bool pilha_empilhar(ITEM *item, PILHA * pilha);
    ITEM *pilha_desempilhar(PILHA *pilha);
    bool pilha_apagar(PILHA **pilha);
    int pilha_tamanho(PILHA *pilha);
    
#endif
