// Questão 4
// Implemente um TAD para representar uma lista encadeada circular (simplesmenteencadeada)
// capaz de armazenar valores inteiros. Esse TAD deverá conter funções para:

#include <iostream>
#include <stdlib.h> // para função malloc
#include "lista.h"

using namespace std;

typedef struct lista Lista;

struct lista
{
  int info;
  Lista *prox;
};

/* declaração e inicialização da lista */
Lista *lst = NULL;

// 1. Criar uma lista vazia:
Lista *lst_cria(void)
{
  return NULL;
};

// 2. Inserir elemento no início:
/* inserção no início: retorna a lista atualizada */
Lista *lst_insere(Lista *lst, int val)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista) + 1);
  novo->info = val;
  if (lst == NULL)
  {
    lst = novo;
    novo->prox = novo;
  }
  else
  {
    novo->prox = lst;
    Lista *p = lst;
    while (p->prox != lst)
    {
      p = p->prox;
    }
    lst = novo;
    p->prox = lst;
  }
  return novo;
};

// 3. Imprimir os valores armazenados na lista;
/* função imprime: imprime valores dos elementos */
void lcirc_imprime(Lista *lst)
{
  Lista *p = lst; /* faz p apontar para o nó inicial */
  /* testa se lista não é vazia e então percorre com do-while */
  if (p)
  {
    do
    {
      cout << "info = " << p->info << endl; /* imprime informação do nó */
      p = p->prox;                          /* avança para o próximo nó */
    } while (p != lst);
    cout << "fim" << endl;
  }
}

// 4. Imprimir os valores armazenados na lista usando recursão;
/* função imprime recursiva */
void lst_imprime_rec(Lista *lst, Lista *ini)
{
  if (!lst_vazia(lst))
  {
    /* imprime primeiro elemento */
    cout << "info = " << lst->info << endl;
    if (lst->prox != ini)
    {
      /* imprime sub-lista */
      lst_imprime_rec(lst->prox, ini);
    }
  }
  else
  {
    cout << "Lista vazia." << endl;
  }
}

// 5. Verificar se a lista está vazia (retorna 1 se vazia ou 0 se não vazia):
/* retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *lst)
{
  return (lst == NULL);
};

// 6. Recuperar/Buscar um determinado elemento da lista:
/* busca um elemento na lista */
Lista *lst_busca(Lista *lst, int val)
{
  Lista *p = lst;
  if (p != NULL)
  {
    do
    {
      if (p->info == val)
      {
        cout << "Valor=" << p->info << endl;
        return p;
      }
      p = p->prox; /* avança para o próximo nó */
    } while (p != lst);
  }
  return NULL; /* não achou o elemento */
};

// 7. Remover um determinado elemento da lista:
/* retira elemento da lista */
Lista *lst_retira(Lista *lst, int val)
{
  Lista *p;
  Lista *seguinte; /* ponteiro para elemento anterior */
  if (lst != NULL)
  {
    p = lst;
    seguinte = p->prox;
    while (seguinte != lst)
    {
      if (seguinte->info == val)
      { // remover no caso q é o elemento do meio ou o último da lista
        p->prox = seguinte->prox;
        free(seguinte);
        return lst;
      }
      p = seguinte;
      seguinte = seguinte->prox;
    }
    if (seguinte->info == val)
    {

      if (seguinte == p) // remover no caso q so tem um elemento na lista
      {
        lst = NULL;
        return lst;
      }
      p->prox = seguinte->prox; // remover no caso q é o primeiro elemento da lista
      lst = seguinte->prox;
      free(seguinte);
      return lst;
    }
  }
  return lst;
};

// 8. Remover um determinado elemento da lista usando recursão;
/* Função retira recursiva */
Lista *lst_retira_rec(Lista *lst, int val)
{
  if (!lst_vazia(lst))
  {
    /* verifica se elemento a ser retirado é o primeiro */
    if (lst->info == val)
    {
      Lista *t = lst; /* temporário para poder liberar */
      lst = lst->prox;
      free(t);
    }
    else
    {
      /* retira de sub-lista */
      lst->prox = lst_retira_rec(lst->prox, val);
    }
  }
  return lst;
}

// 9. Liberar a lista;
/* libera a memória da lista */
void lst_libera(Lista *lst)
{
  Lista *p = lst;
  do
  {
    Lista *t = p->prox; /* guarda referência para o próximo elemento */
    free(p);            /* libera a memória apontada por p */
    p = t;              /* faz p apontar para o próximo */
  } while (p != lst);
};
