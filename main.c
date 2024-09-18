#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "pilha.h"
//#include "jogador.h"

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

void shell_sort(Jogador* jogadores, int n);
//PILHA *selection_sort(Jogador *Jogadores, int num);

int main(void)
{
    int n;
    scanf("%i", &n);
    Jogador *Jogadores = malloc(sizeof(Jogador) * n);
    if (Jogadores == NULL) return 1;
    for(int aaa = 0; aaa < n; aaa++)
    {
        char nome[100];
        int numero;
        scanf("%s %i", nome, &numero);
        Jogadores[aaa].nome = strdup(nome);
        Jogadores[aaa].num = numero;
        scanf("");
    }
    shell_sort(Jogadores, n);
    for(int i = 0; i < n; i++)
    {
      printf("%s %i\n", Jogadores[i].nome, Jogadores[i].num);
    }
    // while(pilha_tamanho(pilha) > 0)
    // {
    //   ITEM *aux = pilha_desempilhar(pilha);
    //   printf("%s %i\n", aux->nome, aux->num);
    // }
    // pilha_apagar(&pilha);
}

// PILHA *selection_sort(Jogador *Jogadores, int n)
// {
//   int i, j, min, auxnu;
//   char auxno[100];
//   for (i = 0; i < (n-1); i++) 
//   {
//     min = i;
//     for (j = (i+1); j < n; j++) {
//       if(Jogadores[j].num <= Jogadores[min].num) 
//       {
//         if (Jogadores[j].num == Jogadores[min].num)
//         {
//           if (strcmp(Jogadores[j].nome, Jogadores[min].nome) == -1)
//           {
//               min = j;
//           }
//         }
//         else {
//           min = j;
//         }
//       }
//     }
//     if (i != min) {
//       auxnu = Jogadores[i].num;
//       strcpy(auxno, Jogadores[i].nome);
//       Jogadores[i].num = Jogadores[min].num;
//       strcpy(Jogadores[i].nome, Jogadores[min].nome);
//       Jogadores[min].num = auxnu;
//       strcpy(Jogadores[min].nome, auxno);
//     }
//     }
//     PILHA *pilha = pilha_criar();
//     for(int i = 0; i < n; i ++)
//     {
//       ITEM *aux = jogador_criar(Jogadores[i].nome, Jogadores[i].num);
//       pilha_empilhar(aux, pilha);
//     }
//     return pilha;
// }

void shell_sort(Jogador* Jogadores, int n) {
  int gap, i, j;
  Jogador temp;

  for (gap = n / 2; gap > 0; gap /= 2) {
      for (i = gap; i < n; i++) {
          temp = Jogadores[i];
          for (j = i; j >= gap && 
              (Jogadores[j - gap].num < temp.num || 
              (Jogadores[j - gap].num == temp.num && strcmp(Jogadores[j - gap].nome, temp.nome) > 0)); 
              j -= gap) {
              Jogadores[j] = Jogadores[j - gap];
          }
          Jogadores[j] = temp;
      }
  }
}