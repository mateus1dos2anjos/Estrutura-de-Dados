// Questão 3
// Implemente um TAD para representar uma lista duplamente encadeada e ordenada capaz de armazenar valores inteiros.
// Esse TAD deverá conter funções para:

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
/* insere_ordenado: insere elemento em ordem */
Lista *lst_insere_ordenado(Lista *lst, int val)
{
  Lista *novo;
  Lista *ant = NULL; /* ponteiro para elemento anterior */
  Lista *p = lst;    /* ponteiro para percorrer a lista */
  /* procura posição para inserção */
  while (p != NULL && p->info < val)
  {
    ant = p;
    p = p->prox;
  }
  /* cria novo elemento */
  novo = (Lista *)malloc(sizeof(Lista));
  novo->info = val;
  /* encadeia elemento */
  if (ant == NULL)
  { /* insere elemento no início */

    novo->prox = lst;
    novo->ant = NULL;
    if (lst != NULL)
    {
      lst->ant = novo;
    }
    lst = novo;
  }
  else
  { /* insere elemento no meio da lista */
    novo->prox = ant->prox;
    if (p != NULL)
    {
      p->ant = novo;
    }
    novo->ant = ant;
    ant->prox = novo;
  }
  return lst; /* retorna ponteiro para o primeiro elemento */
}

// 3. Imprimir os valores armazenados na lista;
/* imprime valores dos elementos */
void lst_imprime(Lista *lst)
{
  Lista *p;
  for (p = lst; p != NULL; p = p->prox)
  {
    cout << "info = " << p->info << endl; /* endl para pular linha*/
  }
  cout << "fim " << endl;
};

// 4. Imprimir os valores armazenados na lista usando recursão;
/* função imprime recursiva */
void lst_imprime_rec(Lista *lst)
{
  if (!lst_vazia(lst))
  {
    /* imprime primeiro elemento */
    cout << "info = " << lst->info << endl;
    /* imprime sub-lista */
    lst_imprime_rec(lst->prox);
  }
}

// 5. Imprimir os valores armazenados na lista em ordem reversa;
/* função imprime recursiva invertida */
void lst_imprime_rec_inv(Lista *lst)
{
  if (!lst_vazia(lst))
  {
    /* imprime sub-lista */
    lst_imprime_rec_inv(lst->prox);
    /* imprime ultimo elemento */
    cout << "info = " << lst->info << endl;
  }
}

// 6. Verificar se a lista está vazia (retorna 1 se vazia ou 0 se não vazia):
/* retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *lst)
{
  return (lst == NULL);
};

// 7. Recuperar/Buscar um determinado elemento da lista:
/* busca um elemento na lista */
Lista *lst_busca(Lista *lst, int val)
{
  Lista *p;
  for (p = lst; p != NULL; p = p->prox)
  {
    if (p->info == val)
      return p;
  }
  return NULL; /* não achou o elemento */
};

// 8. Remover um determinado elemento da lista:
/* função retira: remove elemento da lista */
Lista *lst_retira(Lista *lst, int val)
{
  Lista *p = lst_busca(lst, val); /* busca elemento */

  if (p == NULL)
    return lst; /* não achou: retorna lista inalterada */
  /* retira elemento (apontado por p) do encadeamento */
  if (lst == p)
  { /* testa se é o primeiro elemento */
    lst = p->prox;
  }
  else
  {
    p->ant->prox = p->prox;
  }
  if (p->prox != NULL)
  { /* testa se é o último elemento */
    p->prox->ant = p->ant;
  }
  free(p);

  return lst;
}

// 9. Remover um determinado elemento da lista usando recursão;
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

// 10. Liberar a lista;
/* libera a memória da lista */
void lst_libera(Lista *lst)
{
  Lista *p = lst;
  while (p != NULL)
  {
    Lista *t = p->prox; /* guarda referência para o próximo elemento */
    free(p);            /* libera a memória apontada por p */
    p = t;              /* faz p apontar para o próximo */
  }
};

// 11. Verificar se duas listas são iguais;
int lst_igual(Lista *lst1, Lista *lst2)
{
  Lista *p1; /* ponteiro para percorrer l1 */
  Lista *p2; /* ponteiro para percorrer l2 */
  for (p1 = lst1, p2 = lst2;
       p1 != NULL && p2 != NULL;
       p1 = p1->prox, p2 = p2->prox)
  {
    if (p1->info != p2->info)
      return 0;
  }
  return p1 == p2;
}
