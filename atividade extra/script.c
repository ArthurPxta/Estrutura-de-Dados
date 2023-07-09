#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
#include <math.h>

struct arvore
{
    int chave;
    void *info;
    struct arvore *esq;
    struct arvore *dir;
};



Arvore buscarElemento(Arvore a, int x)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (a->chave == x)
        {
            return a;
        }
        else
        {
            Arvore tempEsquerda = buscarElemento(a->esq, x);
            if (tempEsquerda != NULL) {
               return tempEsquerda;
            } else {
               return buscarElemento(a->dir, x);
            }
        }
    }
}

void *retornarElemento(Arvore a, int x, void *info)
{
    if(verificarSeExiste(a,x))
    {
        Arvore aux = buscarElemento(a,x);
        printf("O elemento é: %d", aux->chave);
        void *retorno = aux->info;
        return retorno;
    }

}

Arvore inserir(Arvore a, int chave, int chavePai, char direcao, void *info)
{

    if(a->chave == -1){
        a->chave = chave;
        a->info = info;
        return a;
    }

   Arvore noPai = buscarElemento(a, chavePai);

   if (noPai == NULL)
   {
      printf("Nao existe no com a chave %d\n", chavePai);
      return a;
   }

   if (direcao == 'e') {
      if (noPai->esq != NULL) {
         printf("Ja existe um no a esquerda do no com a chave %d\n", chavePai);
         return a;
      }
   } else if (direcao == 'd') { 
      if (noPai->dir != NULL) {
         printf("Ja existe um no a direita do no com a chave %d\n", chavePai);
         return a;
      } 

   } else {
      printf("Direcao invalida!\n");
      return a;
   } 

    if (a == NULL)
    {
        a = (Arvore)malloc(sizeof(Arvore));
        a->chave = chave;
        a->info = info;
        a->esq = NULL;
        a->dir = NULL;
    }    else  {
         char resposta;
        printf("Ja existe um no com a chave %d\nDeseja Inserir em uma nova posicao ? (S/N)", chavePai);
        scanf("%c", &resposta);
         if (resposta == 'S' || resposta == 's')
         {
               printf("Digite a nova chave: ");
               scanf("%d", &chavePai);
               printf("Digite a nova direcao: ");
               scanf("%c", &direcao);
               inserir(a, chave, chavePai, direcao, info);
         }
         else
         {
               return a;
         }
    }
    return a;
}

Arvore inicializarArvore()
{
    Arvore a = (Arvore)malloc(sizeof(struct arvore));
    a->esq = NULL;
    a->dir = NULL;
    a->chave = -1;
    return a;
}

int calcularAltura(Arvore a)
{

    int hd, he;

    if (a == NULL)
        return 0;
    else
    {
        he = calcularAltura(a->esq);
        hd = calcularAltura(a->dir);
        if (he > hd)
            return he + 1;
        else
            return hd + 1;
    }
}

void imprimirLargura(Arvore a, int noDesejado)
{
    if (a != NULL)
    {
        if (noDesejado == 0)
        {
            printf("[%d]", a->info);
        }
        else
        {
            imprimirLargura(a->esq, noDesejado - 1);
            imprimirLargura(a->dir, noDesejado - 1);
        }
    }
}

void imprimirArvore(Arvore a)
{
   int altura = calcularAltura(a);
   int i;
   for (i = 0; i < altura; i++)
   {
      printf("Nivel %d: ", i);
      imprimirLargura(a, i);
      printf("\n");
   }
}

Arvore liberarArvore(Arvore a)
{
  if (a != NULL) {
    liberarArvore(a->esq);
    liberarArvore(a->dir);
    free(a);
  }
  return NULL;
}

int verificarSeExiste(Arvore a, int x)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if (a->chave == x)
        {
            return 1;
        }
        else
        {
            return verificarSeExiste(a->esq, x) || verificarSeExiste(a->dir, x);
        }
    }
}