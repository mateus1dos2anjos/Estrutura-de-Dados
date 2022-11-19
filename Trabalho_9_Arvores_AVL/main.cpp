#include <iostream>
#include "avl.h"

using namespace std;

int main(void)
{
  Avl *a;

  a = avl_create();

  a = avl_insert(a, 7);
  a = avl_insert(a, 4);
  a = avl_insert(a, 9);
  a = avl_insert(a, 2);
  a = avl_insert(a, 5);
  a = avl_insert(a, 6);
  a = avl_insert(a, 1);
  a = avl_insert(a, 8);
  a = avl_insert(a, 3);
  a = avl_insert(a, 10);

  a = avl_remove(a, 1);

  avl_get_element(a, 6);

  avl_print(a);

  avl_free(a);

  return 0;
}
