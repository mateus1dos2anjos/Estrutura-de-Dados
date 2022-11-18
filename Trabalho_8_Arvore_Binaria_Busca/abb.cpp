#include <iostream>
#include <stdlib.h> // para função malloc
#include "abb.h"

using namespace std;

typedef struct _abb Abb;

struct _abb
{
  int key;
  Abb *father;
  Abb *left;
  Abb *right;
};

// 1. Criar a estrutura de dados;
Abb *abb_create(void)
{
  cout << "Estrutura criada com sucesso." << endl;
  return NULL;
}

static Abb *create_child(Abb *father, int val)
{
  Abb *node = (Abb *)malloc(sizeof(Abb));
  node->key = val;
  node->father = father;
  node->left = node->right = NULL;
  return node;
}

// 2. Inserir um nó de forma recursiva;
Abb *abb_insert_recursive(Abb *r, int val)
{
  if (r == NULL)
  {
    cout << "Chave " << val << " inserida com sucesso." << endl;
    return create_child(r, val);
  }
  else if (val < r->key)
  {
    if (r->left == NULL)
    {
      cout << "Chave " << val << " inserida com sucesso." << endl;
      r->left = create_child(r, val);
    }
    else
    {
      r->left = abb_insert_recursive(r->left, val);
    }
  }
  else if (val > r->key)
  {
    if (r->right == NULL)
    {
      cout << "Chave " << val << " inserida com sucesso." << endl;
      r->right = create_child(r, val);
    }
    else
      r->right = abb_insert_recursive(r->right, val);
  }
  return r;
}

// 3. Inserir um nó de forma iterativa;
Abb *abb_insert_interactive(Abb *r, int val)
{
  Abb *z = create_child(NULL, val);
  if (r == NULL)
    return z; /* a arvore era vazia */
  else
  {
    Abb *father = NULL;
    Abb *x = r;
    while (x != NULL)
    {
      father = x;
      x = (val < x->key) ? x->left : x->right;
    }
    z->father = father;
    if (val < father->key)
      father->left = z;
    else
      father->right = z;
    cout << "Chave " << val << " inserida com sucesso." << endl;
    return r;
  }
}

// 4. Remover um nó;
Abb *abb_remove(Abb *r, int val)
{
  if (r == NULL)
    return NULL;
  else if (val < r->key)
    r->left = abb_remove(r->left, val);
  else if (val > r->key)
    r->right = abb_remove(r->right, val);
  else
  { /* achou o nó a remover */
    if (r->right == NULL && r->right == NULL)
    { /* nó sem filhos */
      free(r);
      r = NULL;
    }
    else if (r->left == NULL)
    { /* nó só tem filho à direita */
      Abb *t = r;
      r = r->right;
      r->father = t->father;
      free(t);
    }
    else if (r->right == NULL)
    { /* só tem filho à esquerda */
      Abb *t = r;
      r = r->left;
      r->father = t->father;
      free(t);
    }
    else
    { /* nó tem os dois filhos: busca o sucessor */
      Abb *sucessor = r->right;
      while (sucessor->left != NULL)
        sucessor = sucessor->left;
      r->key = sucessor->key; /* troca as chaves */
      sucessor->key = val;
      /* liga o filho do sucessor e o avo */
      if (sucessor->father->left == sucessor)
        sucessor->father->left = sucessor->right; /* se sucessor for filho à esquerda */
      else
        sucessor->father->right = sucessor->right; /* se sucessor for filho à direita */
      if (sucessor->right != NULL)
        sucessor->right->father = sucessor->father;
      free(sucessor);
    }
  }
  return r;
}

// 5. Buscar um elemento;
Abb *abb_get_element(Abb *r, int v)
{
  if (r == NULL)
  {
    cout << "Resultado da busca: Árvore vazia." << endl;
    return NULL;
  }
  else if (v < r->key)
    return abb_get_element(r->left, v);
  else if (v > r->key)
    return abb_get_element(r->right, v);
  else
    cout << "Resultado da busca: " << r->key << endl;
  return r;
}

// 6. Liberar a estrutura de dados;
void abb_free(Abb *r)
{
  if (r != NULL)
  {
    abb_free(r->left);
    abb_free(r->right);
    free(r);
  }
}

// Imprimir a árvore;
void abb_print(Abb *r)
{
  if (r != NULL)
  {
    cout << "Chave: " << r->key << endl;
    abb_print(r->left);
    abb_print(r->right);
  }
}