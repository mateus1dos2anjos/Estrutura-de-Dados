#include <iostream>
#include "abb.h"

using namespace std;

int main(void)
{
  Abb *a;

  a = abb_create();

  a = abb_insert_recursive(a, 7);
  a = abb_insert_interactive(a, 4);
  a = abb_insert_recursive(a, 9);
  a = abb_insert_recursive(a, 2);
  a = abb_insert_recursive(a, 5);
  a = abb_insert_recursive(a, 6);
  a = abb_insert_recursive(a, 1);
  a = abb_insert_recursive(a, 8);
  a = abb_insert_recursive(a, 3);
  a = abb_insert_recursive(a, 10);

  a = abb_remove(a, 10);

  abb_get_element(a, 6);

  abb_print(a);

  abb_free(a);

  return 0;
}