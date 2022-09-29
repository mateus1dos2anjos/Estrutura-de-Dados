#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
  cout << "Programa para testar Heap" << endl;

  Heap *heap;
  heap = criar(3);

  inserir(heap, 10);
  inserir(heap, 20);
  inserir(heap, 30);

  remover(heap);

  alterar(heap, 20, 21);

  imprimir(heap);

  buscar(heap, 20);

  buscar(heap, 21);

  liberar(heap);

  return 0;
}