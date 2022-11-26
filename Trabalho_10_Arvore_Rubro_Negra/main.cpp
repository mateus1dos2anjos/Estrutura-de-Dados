#include <iostream>
#include "arn.h"

using namespace std;

int main(void)
{
  Arn *a;

  a = arn_create();

  arn_insert(a, 7);
  arn_insert(a, 4);
  arn_insert(a, 9);
  arn_insert(a, 2);
  arn_insert(a, 5);
  arn_insert(a, 6);
  arn_insert(a, 1);
  arn_insert(a, 8);
  arn_insert(a, 3);
  arn_insert(a, 10);

  arn_get_element(a, 11);

  arn_free(a);

  return 0;
}
