#include <iostream>
#include <stdlib.h> // para função malloc
#include "arn.h"

#define RED 1;
#define BLACK 0;

using namespace std;

typedef struct _arn Arn;

struct _arn
{
  int key;
  struct _arn *father;
  struct _arn *left;
  struct _arn *right;
  int color;
};

// Funções auxiliares:

// Acessando a cor de um nó
int get_color(Arn *r)
{
  if (r == NULL)
  {
    return BLACK;
  }
  else
  {
    return r->color;
  }
}

// Inverte a cor do pai e de seus filhos
void change_color(Arn *r)
{
  r->color = !r->color;
  if (r->left != NULL)
    r->left->color = !r->left->color;
  if (r->right != NULL)
    r->right->color = !r->right->color;
}

// Rotação à esquerda
Arn *left_roatation(Arn *r)
{
  Arn *s = r->right;
  r->right = s->left;
  s->left = r;
  s->color = r->color;
  r->color = RED;
  return s;
}

// Rotação à direita
Arn *right_roatation(Arn *r)
{
  Arn *s = r->left;
  r->left = s->right;
  s->right = r;
  s->color = r->color;
  r->color = RED;
  return s;
}

// 1. Criar a estrutura de dados;
Arn *arn_create(void)
{
  cout << "Estrutura criada com sucesso." << endl;
  return NULL;
}

// 2. Inserir um nó;

Arn *arn_insert_aux(Arn *r, int val, int &answer)
{
  if (r == NULL)
  {
    Arn *new_node;
    new_node = (Arn *)malloc(sizeof(Arn));
    if (new_node == NULL)
    {
      answer = 0;
      return NULL;
    }
    new_node->key = val;
    new_node->color = RED;
    new_node->right = NULL;
    new_node->left = NULL;
    answer = 1;
    return new_node;
  }

  if (val == r->key)
    answer = 0; // Valor duplicado
  else
  {
    if (val < r->key)
      r->left = arn_insert_aux(r->left, val, answer);
    else
      r->right = arn_insert_aux(r->right, val, answer);
  }

  if (get_color(r->right) == 1 && (get_color(r->left)) == 0)
  {
    r = left_roatation(r);
  }

  if ((get_color(r->left)) == 1 && get_color(r->left->left) == 1)
  {
    r = right_roatation(r);
  }

  if (get_color(r->left) == 1 && get_color(r->right) == 1)
  {
    change_color(r);
  }

  return r;
}

int arn_insert(Arn *r, int val)
{
  int answer;

  // Função responsável pela busca do local de inserção do nó
  r = arn_insert_aux(r, val, answer);
  if (r != NULL)
    r->color = BLACK;

  return answer;
}

// 3. Buscar um elemento;
Arn *arn_get_element(Arn *r, int v)
{
  if (r == NULL)
  {
    return NULL;
  }
  else if (v < r->key)
    return arn_get_element(r->left, v);
  else if (v > r->key)
    return arn_get_element(r->right, v);
  else
  {
    cout << "Resultado da busca: " << r->key << endl;
    return r;
  }
}

// 4. Liberar a estrutura de dados;
void arn_free(Arn *r)
{
  if (r != NULL)
  {
    arn_free(r->left);
    arn_free(r->right);
    free(r);
  }
}
