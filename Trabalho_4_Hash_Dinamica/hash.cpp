#include <iostream>
#include "hash.h"
#include <stdlib.h>
#include <bitset>

using namespace std;

string toBinary(int n)
{
  string r;
  while (n != 0)
  {
    r += (n % 2 == 0 ? "0" : "1");
    n /= 2;
  }
  return r;
}

int Hash::funcaoHash(int valor)
{
  return (valor % max_posicoes);
}

// Construtor
Hash::Hash(int max, int tam_bucket)
{
  max_posicoes = max / 2;
  estrutura = (string **)malloc(max_posicoes * sizeof(string *));
  quant_itens = 0;
  max_itens = max;
  bucket_counter = 0;
  for (int i = 0; i < max_posicoes; i++)
  {
    estrutura[i] = (string *)malloc(8 * sizeof(string));
  }
  cout << "Tabela Hash criada!" << endl;
}

// Destrutor
Hash::~Hash()
{
  free(estrutura);
}

void Hash::inserir(int valor)
{
  cout << "Adicionando elemento a tabela hash. Calculando chave..." << endl;
  int chave = funcaoHash(valor);
  string *checker = estrutura[chave];
  string *last = checker;
  string bin = toBinary(chave);
  bitset<8> binario(bin); // binário com 8 bits
  int i = 1;
  bool check = true;
  while (check)
  {
    cout << "Bucket encontrado. Procurando subbuckets... " << endl;
    cout << "Iteracao: " << i << endl;
    last = checker;
    char checker_ = bin.back();
    i = i + 1;
  }
  // TO DO: implementar continuação de "inserir"
}

void Hash::deletar(int valor)
{
  // TO DO: implementar "deletar"
}

void Hash::buscar(int valor)
{
  // TO DO: implementar "buscar"
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