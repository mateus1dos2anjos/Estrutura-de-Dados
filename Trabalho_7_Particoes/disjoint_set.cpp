/*
Implemente um TAD para representar uma Coleção de Conjuntos Disjuntos.
Assuma que os elementos a serem armazenados nos conjuntos disjuntos são valores inteiros entre 1 e n.
O usuário informa o valor de n. O TAD deve conter as operações:
MakeSet(x), Find(x) e Union(x,y).
O TAD pode ser implementado utilizando-se árvores reversas, florestas, vetores ou listas.
A seu critério. Deve-se evitar a formação de árvores degeneradas.
Esse TAD deverá conter funções para:
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DisjointSet
{ // para representar um disjoint set
   unordered_map<int, int> parent;

public:
   // 1. Criar a estrutura de dados;
   void makeSet(vector<int> const &wholeset)
   {
      for (int i : wholeset) // criar n disjoint sets (um para cada item)
         parent[i] = i;
   }

   // 2. Dado dois elementos x e y, fazer a união entre os dois conjuntos aos quais pertencem x e y;
   void Union(int m, int n)
   {
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }

   // 3. Recuperar o representante de um determinado elemento x;
   int Find(int x)
   {
      if (parent[x] == x) // se x é a raiz
         return x;
      return Find(parent[x]); // chama recursivo para o pai até encontrarmos a raiz
   }
};

int main()
{
   vector<int> wholeset = {6, 7, 1, 2, 3}; // itens de wholeset
   DisjointSet dis;                        // inicializar a classe DisjointSet
   dis.makeSet(wholeset);                  // criar conjunto individual dos itens de wholeset
   dis.Union(7, 6);                        // União de 7 e 6 para o mesmo conjunto

   // 4. Verificar se dois elementos x e y fazem parte do mesmo conjunto;
   if (dis.Find(7) == dis.Find(6))
   { // se eles pertencem ao mesmo conjunto
      cout << "sim, pertencem ao mesmo conjunto." << endl;
   }
   else
   { // caso contrário
      cout << "Não, não pertencem ao mesmo conjunto." << endl;
   }

   if (dis.Find(3) == dis.Find(4))
   { // se eles pertencem ao mesmo conjunto
      cout << "sim, pertencem ao mesmo conjunto." << endl;
   }
   else
   { // caso contrário
      cout << "Não, não pertencem ao mesmo conjunto." << endl;
   }

   return 0;
}