#ifndef JOGADOR_H
    #define JOGADOR_H
    #include <stdbool.h>

    typedef struct item ITEM;

    ITEM *jogador_criar(char *nome, int num);
    bool jogador_apagar(ITEM **jogador);
    int jogador_numero(ITEM *jogador);

#endif