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
        Jogadores[aaa].nome = nome;
        Jogadores[aaa].num = numero;
        printf("Cadastrado o jogador: Nome: %s Numero: %i", Jogadores[aaa].nome, Jogadores[aaa].num);
        scanf("");
    }
    PILHA *pilha = selection_sort(Jogadores, n);
    while(pilha_tamanho(pilha) > 0)
    {
      ITEM *aux = pilha_desempilhar(pilha);
      printf("Nome: %s\nNum: %i\n", aux->nome, aux->num);
    }
    pilha_apagar(&pilha);
}

PILHA *selection_sort(Jogador *Jogadores, int n)
{
  printf("\n\n----------- JOGADORES ------------\n\n");
  for(int i = 0; i < n; i++)
  {
    printf("%i: Nome: %s - Numero: %i\n", i, Jogadores[i].nome, Jogadores[i].num);
  }
  printf("\n ----------------------------------\n");
  int i, j, min, auxnu;
  char *auxno;
  for (i = 0; i < (n-1); i++) 
  {
    min = i;
    for (j = (i+1); j < n; j++) {
      if(Jogadores[j].num <= Jogadores[min].num) 
      {
        if (Jogadores[j].num == Jogadores[min].num)
        {
          printf("Vou comparar os dois nomes: \nNome J: %s\nNome min: %s", Jogadores[j].nome, Jogadores[min].nome);
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