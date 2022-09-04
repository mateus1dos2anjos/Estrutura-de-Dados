// Questão 1
// Implemente um TAD para representar uma lista encadeada capaz de armazenar valores inteiros.
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
  novo->prox = lst;
  return novo;
};

// 3. Imprimir os valores armazenados na lista;
/* imprime valores dos elementos */
void lst_imprime(Lista *lst)
{
  Lista *p;
  for (p = lst; p != NULL; p = p->prox)
    cout << "info = " << p->info << endl; /* endl para pular linha*/
  cout << "fim" << endl;
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

// 5. Imprimir os valores armazenados na lista em ordem reversa (da cauda para a cabeça da lista):
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
/* retira elemento da lista */
Lista *lst_retira(Lista *lst, int val)
{
  Lista *ant = NULL; /* ponteiro para elemento anterior */
  Lista *p = lst;    /* ponteiro para percorrer a lista */
  /* procura elemento na lista, guardando anterior */
  while (p != NULL && p->info != val)
  {
    ant = p;
    p = p->prox;
  }
  /* verifica se achou elemento */
  if (p == NULL)
    return lst; /* não achou: retorna lista original */
  /* achou: retira */
  if (ant == NULL) /* retira elemento do inicio */
    lst = p->prox;
  else /* retira elemento do meio da lista */
    ant->prox = p->prox;
  free(p); /* libera espaço ocupado pelo elemento */
  return lst;
};

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
