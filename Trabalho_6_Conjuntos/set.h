/*
Questão 1. Implemente um TAD para representar um Conjunto por meio de um vetor de bits. Assuma
que os elementos a serem armazenados em um conjunto são strings (cadeias de caracteres).
O usuário deve determinar a quantidade de elementos a serem gerenciados, bem como
fornecer esses elementos. Esse TAD deverá conter funções para:
*/

#include <stdlib.h>
#include <string>

using namespace std;

typedef struct set Set;

// 1. Criar a estrutura de dados (ou seja, criar um determinado conjunto);
set *setInit(int length, string *alphabet);

// 2. Inserir um elemento em um determinado conjunto;
int setInsertElement(set *s, string data);

// 3. Remover um elemento de um determinado conjunto;
int setRemoveElement(set *s, string data);

// 4. Fazer a união entre dois conjuntos;
set *setUnion(set *s1, set *s2);

// 5. Fazer a interseção entre dois conjuntos;
set *setIntersection(set *s1, set *s2);

// 6. Fazer a diferença entre dois conjuntos;
set *setDifference(set *s1, set *s2);

// 7. Verificar se um conjunto A é subconjunto de B;
int setIsSubset(set *s1, set *s2);

// 8. Verificar se dois conjuntos são iguais;
int setIsEqual(set *s1, set *s2);

// O complementar de s1 em relação a s2 é o conjunto s2 – s1;
// 9. Gerar o complemento de um determinado conjunto;
set *setGenerateComplement(set *s1, set *s2);

// 10. Verificar se um elemento pertence a um determinado conjunto;
int setIsMember(set *s, string data);

// 11. Recuperar o número de elementos de um determinado conjunto;
int setSize(set *s);

// Verificar se o conjunto s está vazio
int setIsEmpty(set *s);

// Imprimir o conjunto s
void setPrint(set *s);

// 12. Liberar a estrutura de dados (um determinado conjunto);
void setFree(set *s);
