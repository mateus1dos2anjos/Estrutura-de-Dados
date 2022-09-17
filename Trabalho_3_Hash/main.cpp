#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
  cout << "Programa para testar Tabela Hash\n";

  Hash tabela_hash(6);

  tabela_hash.imprimir();

  tabela_hash.inserir(1);

  tabela_hash.inserir(2);

  tabela_hash.inserir(3);

  tabela_hash.inserir(4);

  tabela_hash.imprimir();

  tabela_hash.buscar(1);

  tabela_hash.buscar(35);

  tabela_hash.deletar(1);

  tabela_hash.imprimir();

  return 0;
}