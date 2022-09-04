/* Implemente um programa que cria uma variável do TAD lista encadeada ordenada, criado
anteriormente, e utiliza cada uma de suas funções. */

#include <iostream>
#include "lista.h"

using namespace std;

int main(void)
{
  ListaHet *lst;       /* declara lista não iniciada */
  lst = lst_cria(); /* inicia lista vazia */

  lst = cria_ban(1011, 7000.0);

  lst_libera(lst);

  return 0;
}