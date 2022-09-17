#include <iostream>
#include "hash.h"
#include <stdlib.h>

using namespace std;

int Hash::FuncaoHash(int valor)
{
  return (valor % max_posicoes);
}
// Construtor
Hash::Hash(int max)
{
  max_posicoes = max / 2;
  estrutura = (int *)malloc(max_posicoes * sizeof(int));
  quant_itens = 0;
  max_itens = max;
  for (int i = 0; i < max_posicoes; i++)
  {
    estrutura[i] = -1;
  }
}

// Destrutor
Hash::~Hash()
{
  free(estrutura);
}

void Hash::inserir(int valor)
{
  if (quant_itens == max_posicoes)
  {
    cout << "Opa! Lista cheia, nao foi possível inserir o elemento!" << endl;
  }
  else
  {
    int i = FuncaoHash(valor);
    while (estrutura[i] > 0) // Utilizando Encadeamento Interior
    {
      i = (i + 1) % max_posicoes;
    }
    estrutura[i] = valor;
    quant_itens++;
    cout << "Elemento " << estrutura[i] << " inserido com sucesso!" << endl;
  }
}

void Hash::deletar(int valor)
{
  int i = FuncaoHash(valor);
  bool teste = false;
  int cont = 0;
  while (estrutura[i] != -1)
  {
    if (estrutura[i] == valor)
    {
      estrutura[i] = -2;
      cout << "Elemento Removido!" << endl;
      quant_itens--;
      teste = true;
      break;
    }
    cont++;
    if (cont >= max_posicoes)
    {
      break;
    }
    i = (i + 1) % max_posicoes;
  }
  if (!teste)
  {
    cout << "O elemento nao foi encontrado!\n";
    cout << "Nenhum elemento foi removido!\n";
  }
}

void Hash::buscar(int valor)
{
  int i = FuncaoHash(valor);
  bool busca = false;
  int cont = 0;
  while (estrutura[i] != -1)
  {
    if (estrutura[i] == valor)
    {
      busca = true;
      cout << "Resultado da busca: " << estrutura[i] << endl;
      break;
    }
    cont++;
    if (cont >= max_posicoes)
    {
      break;
    }
    i = (i + 1) % max_posicoes;
  }
  if (!busca)
  {
    cout << "Elemento não encontrado!" << endl;
  }
}

void Hash::imprimir()
{
  if (quant_itens == 0)
  {
    cout << "Lista vazia!" << endl;
  }
  else
  {
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++)
    {
      if (estrutura[i] > 0)
      {
        cout << i << ":" << estrutura[i] << endl;
      }
    }
  }
}