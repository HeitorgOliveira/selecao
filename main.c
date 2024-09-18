#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "jogador.h"

typedef struct
{
    char *nome;
    int num;
} Jogador;

struct item
{
  char *nome;
  int num;
};

void shell_sort(Jogador* Jogadores, int num);
PILHA *selection_sort(Jogador *Jogadores, int num);

int main(void)
{
    int n;
    printf("Digite o numero de Jogadores: ");
    scanf("%i", &n);
    Jogador *Jogadores = malloc(sizeof(Jogador) * n);
    if (Jogadores == NULL) return 1;
    for(int aaa = 0; aaa < n; aaa++)
    {
        printf("Jogador %i (nome numero): \n", aaa+1);
        char nome[100];
        int numero;
        scanf("%s %i", nome, &numero);
        Jogadores[aaa].nome = strdup(nome);
        Jogadores[aaa].num = numero;
        scanf("");
    }
    PILHA *pilha = selection_sort(Jogadores, n);
    while(pilha_tamanho(pilha) > 0)
    {
      ITEM *aux = pilha_desempilhar(pilha);
      printf("Nome: %s Num: %i\n", aux->nome, aux->num);
    }
    pilha_apagar(&pilha);
}

PILHA *selection_sort(Jogador *Jogadores, int n)
{
  int i, j, min, auxnu;
  char auxno[100];
  for (i = 0; i < (n-1); i++) 
  {
    min = i;
    for (j = (i+1); j < n; j++) {
      if(Jogadores[j].num <= Jogadores[min].num) 
      {
        if (Jogadores[j].num == Jogadores[min].num)
        {
          if (strcmp(Jogadores[j].nome, Jogadores[min].nome) == -1)
          {
              min = j;
          }
        }
        else {
          min = j;
        }
      }
    }
    if (i != min) {
      auxnu = Jogadores[i].num;
      strcpy(auxno, Jogadores[i].nome);
      Jogadores[i].num = Jogadores[min].num;
      strcpy(Jogadores[i].nome, Jogadores[min].nome);
      Jogadores[min].num = auxnu;
      strcpy(Jogadores[min].nome, auxno);
    }
    }
    PILHA *pilha = pilha_criar();
    for(int i = 0; i < n; i ++)
    {
      ITEM *aux = jogador_criar(Jogadores[i].nome, Jogadores[i].num);
      pilha_empilhar(aux, pilha);
    }
    return pilha;
}