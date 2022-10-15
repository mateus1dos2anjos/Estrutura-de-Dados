#include <iostream>
#include "set.h"

using namespace std;

set *createNewSet()
{
  cout << "Digite a quantidade de elementos que pode ser gerenciado (universo):" << endl;
  int n;
  cin >> n;

  cout << "Digite os " << n << " elementos que podem ser gerenciados (universo):" << endl;
  string *alphabet = (string *)malloc(n * sizeof(string));
  for (int i = 0; i < n; i++)
  {
    string element;
    cin >> element;
    alphabet[i] = element;
  }
  set *c1 = setInit(n, alphabet);
  return c1;
}

int main()
{
  cout << "Programa para testar Sets: \n";

  set *c1 = createNewSet();
  setInsertElement(c1, "pedra");
  setPrint(c1);

  set *c2 = createNewSet();
  setInsertElement(c2, "tesoura");
  setInsertElement(c2, "pedra");
  setPrint(c2);

  set *c3 = setUnion(c1, c2);
  cout << "União:" << endl;
  setPrint(c3);
  free(c3);

  set *c4 = setIntersection(c1, c2);
  cout << "Interseccao:" << endl;
  setPrint(c4);
  free(c4);

  set *c5 = setDifference(c1, c2);
  cout << "Diferenca C1 - C2:" << endl;
  setPrint(c5);
  free(c5);

  set *c6 = setDifference(c2, c1);
  cout << "Diferenca C2 - C1:" << endl;
  setPrint(c6);
  free(c6);

  setIsSubset(c1, c2);

  setIsSubset(c2, c1);

  int tam = setSize(c2);
  cout << tam << endl;

  setIsEqual(c1, c2);

  set *c7 = setGenerateComplement(c1, c2);
  cout << "O complementar de c1 em relação a c2 é o conjunto:" << endl;
  setPrint(c7);
  free(c7);

  setFree(c1);
  setFree(c2);

  return 0;
}
