#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "set.h"
#include <string>

using namespace std;

typedef struct set Set;

struct set
{
  int length_alphabet;
  int length;
  int *elements;
  string *alphabet;
};

int setIsEmpty(set *s)
{
  for (int i = 0; i < s->length_alphabet; i++)
  {
    if (s->elements[i] == 1)
      return 0;
  }
  return 1;
}

void setPrint(set *s)
{
  if (setIsEmpty(s))
  {
    cout << "Conjunto vazio!" << endl;
  }
  else
  {
    cout << "{" << endl;
    for (int i = 0; i < s->length_alphabet; i++)
    {
      if (s->elements[i] == 1)
      {
        cout << s->alphabet[i] << endl;
      }
    }
    cout << "} \n" << endl;
  }
}

int seekIndex(string *alphabet, int alphabet_length, string data)
{
  int i;
  for (i = 0; i < alphabet_length; i++)
  {
    if (alphabet[i] == data)
    {
      return i;
    }
  }
  return -1;
}

int setIsMember(set *s, string data)
{
  int i = seekIndex(s->alphabet, s->length_alphabet, data);
  if (i == -1)
  {
    return -1;
  }
  if (s->elements[i] == 1)
  {
    return 1;
  }
  return 0;
}

set *setInit(int length_alphabet, string *alphabet)
{
  set *s = (set *)malloc(sizeof(set));
  s->length = 0;
  s->alphabet = alphabet;
  s->elements = (int *)malloc(length_alphabet * sizeof(int));
  s->length_alphabet = length_alphabet;
  for (int i = 0; i < length_alphabet; i++)
  {
    s->elements[i] = 0;
  }
  return s;
}

int setInsertElement(set *s, string data)
{
  if (setIsMember(s, data) || setIsMember(s, data) == -1)
  {
    return 0;
  }

  int i = seekIndex(s->alphabet, s->length_alphabet, data);
  s->elements[i] = 1;
  return 1;
}

int setRemoveElement(set *s, string data)
{
  if (!setIsMember(s, data) || setIsMember(s, data) == -1)
  {
    return 0;
  }

  int i = seekIndex(s->alphabet, s->length_alphabet, data);
  s->elements[i] = 0;
  return 1;
}

set *setUnion(set *s1, set *s2)
{
  set *s3 = setInit(s1->length_alphabet, s1->alphabet);
  int i;
  for (i = 0; i < s1->length_alphabet; i++)
  {
    if (s1->elements[i] == 1)
    {
      s3->elements[i] = 1;
    }
  }
  for (i = 0; i < s2->length_alphabet; i++)
  {
    if (s2->elements[i] == 1)
    {
      s3->elements[i] = 1;
    }
  }

  return s3;
}

set *setIntersection(set *s1, set *s2)
{
  set *s3 = setInit(s1->length_alphabet, s1->alphabet);
  for (int i = 0; i < s1->length_alphabet; i++)
  {
    if (s1->elements[i] == 1 && s2->elements[i] == 1)
    {
      s3->elements[i] = 1;
    }
  }
  return s3;
}

set *setDifference(set *s1, set *s2)
{
  set *s3 = setInit(s1->length_alphabet, s1->alphabet);
  for (int i = 0; i < s1->length_alphabet; i++)
  {
    if (s1->elements[i] == 1 && s2->elements[i] == 0)
    {
      s3->elements[i] = 1;
    }
  }
  return s3;
}

int setSize(set *s)
{
  int count = 0;
  for (int i = 0; i < s->length_alphabet; i++)
  {
    if (s->elements[i] == 1)
    {
      count++;
    }
  }
  return count;
}

int setIsSubset(set *s1, set *s2)
{
  for (int i = 0; i < s1->length_alphabet; i++)
  {
    if (s1->elements[i] == 1 && s2->elements[i] == 0)
    {
      cout << "não é subconjunto" << endl;
      return 0;
    }
  }
  cout << "é subconjunto" << endl;
  return 1;
}

int setIsEqual(set *s1, set *s2)
{
  for (int i = 0; i < s1->length_alphabet; i++)
  {
    if ((s1->elements[i] == 1 && s2->elements[i] == 0) || (s1->elements[i] == 0 && s2->elements[i] == 1))
    {
      cout << "os conjuntos não são iguais" << endl;
      return 0;
    }
  }
  cout << "os conjuntos são iguais" << endl;
  return 1;
}

set *setGenerateComplement(set *s)
{
  set *s2 = setInit(s->length_alphabet, s->alphabet);
  int i;
  for (i = 0; i < s->length_alphabet; i++)
  {
    if (s->elements[i] == 0)
    {
      s2->elements[i] = 1;
    }
    else
    {
      s2->elements[i] = 0;
    }
  }
  return s2;
}

set *setGenerateComplement(set *s1, set *s2)
{
  set *s3 = setDifference(s2, s1);
  return s3;
}

void setFree(set *s)
{
  free(s->alphabet);
  free(s);
}
