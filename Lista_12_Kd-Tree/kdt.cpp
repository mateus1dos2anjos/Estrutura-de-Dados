// Implemente um TAD para representar uma Kd-Tree. Esse TAD deverá conter funções para:

#include <bits/stdc++.h>
using namespace std;

const int k = 2;

// Estrutura para representar um nó de Kd-Tree
struct Node
{
  int point[k]; // Para armazenar o ponto dimensional k
  Node *left, *right;
};

// Cria um nó de Kd-Tree
struct Node *newNode(int arr[])
{
  struct Node *temp = new Node;

  for (int i = 0; i < k; i++)
    temp->point[i] = arr[i];

  temp->left = temp->right = NULL;
  return temp;
}

// Insere um novo nó e retorna a raiz da árvore modificada
// O parâmetro depth é usado para decidir o axis de comparação
Node *insertRec(Node *root, int point[], unsigned depth)
{
  if (root == NULL)
    return newNode(point);

  // Calcula a dimensão atual (cd) da comparação
  unsigned cd = depth % k;

  // Compara o novo ponto com a raiz na dimensão atual 'cd'
  // e decide a subárvore esquerda ou direita
  if (point[cd] < (root->point[cd]))
    root->left = insertRec(root->left, point, depth + 1);
  else
    root->right = insertRec(root->right, point, depth + 1);

  return root;
}

// Função para inserir um novo ponto com ponto dado em Árvore KD e retorna a nova raiz.
// Ele usa principalmente recursivo acima função "inserirRec()"
Node *insert(Node *root, int point[])
{
  return insertRec(root, point, 0);
}

// Um método auxiliar para determinar se dois pontos são iguais no espaço K Dimensional
bool arePointsSame(int point1[], int point2[])
{
  for (int i = 0; i < k; ++i)
    if (point1[i] != point2[i])
      return false;

  return true;
}

// Pesquisa um Ponto representado por "point[]" na Kd-Tree.
// O parâmetro depth é usado para determinar o eixo atual.
bool searchRec(Node *root, int point[], unsigned depth)
{
  if (root == NULL)
    return false;
  if (arePointsSame(root->point, point))
    return true;

  // A dimensão atual é calculada usando a depth atual e o total de dimensões (k)
  unsigned cd = depth % k;

  // Compara o ponto com a raiz em relação ao cd (dimensão atual)
  if (point[cd] < root->point[cd])
    return searchRec(root->left, point, depth + 1);

  return searchRec(root->right, point, depth + 1);
}

// Pesquisa um ponto na Kd-Tree. Usa a função searchRec()
bool search(Node *root, int point[])
{
  // Passa a profundidade atual como 0
  return searchRec(root, point, 0);
}

int main()
{
  struct Node *root = NULL;
  int points[][k] = {{4, 7}, {18, 16}, {14, 16}, {7, 13}, {10, 2}, {3, 8}, {11, 20}};

  int n = sizeof(points) / sizeof(points[0]);

  for (int i = 0; i < n; i++)
    root = insert(root, points[i]);

  int point1[] = {18, 16};
  if (search(root, point1))
    cout << "Encontrado" << endl;
  else
    cout << "Não Encontrado" << endl;

  int point2[] = {8, 20};
  if (search(root, point2))
    cout << "Encontrado" << endl;
  else
    cout << "Não Encontrado" << endl;

  return 0;
}
