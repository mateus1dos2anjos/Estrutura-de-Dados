// Questão 5
// Implemente um TAD para representar uma lista encadeada circular (duplamente encadeada)
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
  Lista *ant;
};

/* declaração e inicialização da lista */
Lista *lst = NULL;

// 1. Criar uma lista vazia:
Lista *lst_cria(void)
{
  return NULL;
};

// 2. Inserir elemento;
/* inserção no início: retorna a lista atualizada */
Lista *lst_insere(Lista *lst, int val)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = val;
  if (lst == NULL) // caso em que a lista está vazia
  {
    lst = novo;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  else // caso em que a lista não está vazia
  {
    novo->prox = lst;
    lst->ant = novo;
    novo->ant = NULL;
    lst = novo;
  }
  return novo;
}

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
/* função busca: busca um elemento na lista */
Lista *lst_busca(Lista *lst, int val)
{
  Lista *p;
  for (p = lst; p != NULL; p = p->prox)
    if (p->info == val)
      return p;
  return NULL; /* não achou o elemento */
}

// 7. Remover um determinado elemento da lista:
/* retira elemento da lista */
/* função retira: remove elemento da lista */
Lista *lst_retira(Lista *lst, int val)
{
  Lista *p = lst_busca(lst, val); /* busca elemento */

  if (p == NULL)
    return lst; /* não achou: retorna lista inalterada */

  /* retira elemento (apontado por p) do encadeamento */
  if (lst == p) /* testa se é o primeiro elemento */
    lst = p->prox;
  else
    p->ant->prox = p->prox;

  if (p->prox != NULL) /* testa se é o último elemento */
    p->prox->ant = p->ant;

  free(p);

  return lst;
}

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
