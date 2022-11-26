#include <iostream>
#include <stdlib.h> // para função malloc
#include "avl.h"

using namespace std;

typedef struct _avl Avl;

struct _avl
{
  int key;
  int fb; /*fator de balanceamento*/
  struct _avl *father;
  struct _avl *left;
  struct _avl *right;
};

static Avl *right_rotation(Avl *r)
{
  Avl *father = r->father, *t = r->left, *m = t->right;
  t->right = r;
  r->father = t;
  r->left = m;
  if (m)
    m->father = r;
  t->father = father;
  if (father)
  {
    if (father->right == r)
      father->right = t;
    else
      father->left = t;
  }
  t->fb = r->fb = 0;
  return t;
}

static Avl *left_rotation(Avl *r)
{
  Avl *father = r->father, *t = r->right, *m = t->left;
  t->left = r;
  r->father = t;
  r->right = m;
  if (m)
    m->father = r;
  t->father = father;
  if (father)
  {
    if (father->right == r)
      father->right = t;
    else
      father->left = t;
  }
  t->fb = r->fb = 0;
  return t;
}

Avl *avl_right_left_rotation(Avl *r)
{
  Avl *t = r->right, *s = t->left;
  Avl *T2 = s->left, *T3 = s->right;
  s->left = r;
  s->right = t;
  r->right = T2;
  t->left = T3;
  r->fb = (s->fb == 1) ? -1 : 0;
  t->fb = (s->fb == -1) ? 1 : 0;
  s->fb = 0;
  return s;
}

Avl *avl_left_right_rotation(Avl *r)
{
  Avl *p = r->left, *q = p->right;
  Avl *T2 = q->left, *T3 = q->right;
  q->left = p;
  q->right = r;
  p->right = T2;
  r->left = T3;
  p->fb = (q->fb == 1) ? -1 : 0;
  r->fb = (q->fb == -1) ? 1 : 0;
  q->fb = 0;
  return q;
}

// 1. Criar a estrutura de dados;
Avl *avl_create(void)
{
  cout << "Estrutura criada com sucesso." << endl;
  return NULL;
}

static Avl *avl_insert_aux(Avl *r, int val, int *flag)
{
  if (r == NULL)
  {
    r = (Avl *)malloc(sizeof(Avl));
    r->left = r->right = NULL;
    r->key = val;
    r->fb = 0;
    *flag = 1;
  }
  else if (r->key > val)
  {
    r->left = avl_insert_aux(r->left, val, flag);
    if (*flag)
    {                /* r cresceu à esquerda (ou seja, he aumentou)*/
      switch (r->fb) /* análise do fator de balanceamento de r */
      {
      case 1: /* antes: hd>he, depois: hd=he, pois he aumentou */
        r->fb = 0;
        *flag = 0;
        break;

      case 0: /* antes: hd=he, depois: hd<he, pois he aumentou */
        r->fb = -1;
        break;

      case -1: /* antes: hd<he, depois: hd-he = -2, pois he aumentou */
        if (r->left->fb == -1)
          r = right_rotation(r);
        else
          r = avl_left_right_rotation(r);
        *flag = 0;
        break;
      }
    }
  }
  else if (r->key < val)
  {
    r->right = avl_insert_aux(r->right, val, flag);
    if (*flag)
    {
      switch (r->fb) /* análise do fator de balanceamento de r */
      {
      case 1: /* antes: hd>he, depois: hd-he = 2, pois hd aumentou */
        if (r->right->fb == 1)
          r = left_rotation(r);
        else
          r = avl_right_left_rotation(r);
        *flag = 0;
        break;

      case 0: /* antes: hd=he, depois: hd>he, pois hd aumentou */
        r->fb = 1;
        break;

      case -1: /* antes: hd<he, depois: hd=he, pois hd aumentou */
        r->fb = 0;
        *flag = 0;
        break;
      }
    }
  }
  return r;
}

// 2. Inserir um nó;
Avl *avl_insert(Avl *r, int val)
{
  int flag = 0;
  return avl_insert_aux(r, val, &flag);
}

static Avl *left_rot(Avl *r)
{
  Avl *t = r->right, *m = t->left;
  t->left = r;
  r->right = m;
  if (t->fb == 1)
  {
    t->fb = 0;
    r->fb = 0;
  }
  else
  {
    t->fb = -1;
    r->fb = 1;
  }
  return t;
}

static Avl *right_left_rot(Avl *r)
{
  Avl *t = r->right, *s = t->left, *T2 = s->left, *T3 = s->right;
  s->left = r;
  s->right = t;
  r->right = T2;
  t->left = T3;
  switch (s->fb)
  {
  case -1:
    r->fb = s->fb = 0;
    t->fb = 1;
    break;
  case 0:
    r->fb = s->fb = t->fb = 0;
    break;
  case 1:
    r->fb = -1;
    s->fb = t->fb = 0;
    break;
  }
  return s;
}

static Avl *right_rot(Avl *r)
{
  Avl *t = r->left, *m = t->right;
  t->right = r;
  r->left = m;
  if (t->fb == -1)
  {
    t->fb = 0;
    r->fb = 0;
  }
  else
  {
    t->fb = 1;
    r->fb = -1;
  }
  return t;
}

static Avl *left_right_rot(Avl *r)
{
  Avl *p = r->left, *q = p->right, *T2 = q->left, *T3 = q->right;
  q->left = p;
  q->right = r;
  p->right = T2;
  r->left = T3;
  switch (q->fb)
  {
  case -1:
    r->fb = 1;
    q->fb = p->fb = 0;
    break;
  case 0:
    r->fb = q->fb = p->fb = 0;
    break;
  case 1:
    r->fb = q->fb = 0;
    p->fb = -1;
    break;
  }
  return q;
}

static Avl *avl_remove_aux(Avl *r, int val, int *delta_h)
{
  if (!r)
    return NULL;
  else if (val < r->key)
  {
    r->left = avl_remove_aux(r->left, val, delta_h);
    r->fb -= *delta_h;
    if (r->fb == 2)
    {
      if (r->right->fb == 1)
      {
        r = left_rot(r);
        *delta_h = -1;
      }
      else if (r->right->fb == 0)
      {
        r = left_rot(r);
        *delta_h = 0;
      }
      else if (r->right->fb == -1)
      {
        r = right_left_rot(r);
        *delta_h = -1;
      }
    }
    else
      *delta_h = ((r->fb == 1) ? 0 : -1); /*a sad mantém a altura do nó*/
  }
  else if (val > r->key)
  {
    cout << "1. Caso que falta fazer." << endl;
  }
  else
  {                                          /* achou o nó para remover – remoção semelhante à abb */
    if (r->left == NULL && r->right == NULL) /* nó folha */
    {
      free(r);
      *delta_h = -1;
      r = NULL;
    }
    else if (r->right == NULL) /* só um filho, à esquerda */
      cout << "2. Caso que falta fazer." << endl;
  }

  return r;
}

// 3. Remover um nó;
Avl *avl_remove(Avl *r, int val)
{
  int delta_h = 0;
  return avl_remove_aux(r, val, &delta_h);
}

// 4. Buscar um elemento;
Avl *avl_get_element(Avl *r, int v)
{
  if (r == NULL)
  {
    cout << "Resultado da busca: Árvore vazia." << endl;
    return NULL;
  }
  else if (v < r->key)
    return avl_get_element(r->left, v);
  else if (v > r->key)
    return avl_get_element(r->right, v);
  else
  {
    cout << "Resultado da busca: " << r->key << endl;
    return r;
  }
}

// 5. Liberar a estrutura de dados;
void avl_free(Avl *r)
{
  if (r != NULL)
  {
    avl_free(r->left);
    avl_free(r->right);
    free(r);
  }
}

// Imprimir a árvore;
void avl_print(Avl *r)
{
  if (r != NULL)
  {
    cout << "Chave: " << r->key << endl;
    avl_print(r->left);
    avl_print(r->right);
  }
}
