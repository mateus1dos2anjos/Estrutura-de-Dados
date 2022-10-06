#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
  cout << "Programa para testar Tabela Hash Dinamica\n";

  Hash tabela_hash_din(10, 2);

  tabela_hash_din.imprimir();

  tabela_hash_din.inserir(1);

  tabela_hash_din.inserir(2);

  tabela_hash_din.inserir(3);

  tabela_hash_din.inserir(4);

  tabela_hash_din.imprimir();

  tabela_hash_din.buscar(1);

  tabela_hash_din.buscar(35);

  tabela_hash_din.deletar(1);

  tabela_hash_din.imprimir();

  return 0;
}