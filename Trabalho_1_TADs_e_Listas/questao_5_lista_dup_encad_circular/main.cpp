/* Implemente um programa que cria uma variável do TAD lista encadeada circular (duplamente encadeada),
criado anteriormente, e utiliza cada uma de suas funções. */

#include <iostream>
#include "lista.h"

using namespace std;

int main(void)
{
  Lista *lst;       /* declara lista não iniciada */
  lst = lst_cria(); /* inicia lista vazia */

  lst = lst_insere(lst, 23); /* insere na lista o elemento 23 */
  lst = lst_insere(lst, 45); /* insere na lista o elemento 45 */
  lst = lst_insere(lst, 56); /* insere na lista o elemento 56 */
  lst = lst_insere(lst, 78); /* insere na lista o elemento 78 */

  lcirc_imprime(lst); /* imprimirá: 78 56 45 23 */

  lst_vazia(lst);

  lst_busca(lst, 56);

  lst = lst_retira(lst, 56);

  lcirc_imprime(lst); /* imprimirá: 78 45 23 */

  // lst_imprime_rec(lst); /* imprimirá: 78 45 23 */

  lst_libera(lst);

  return 0;
}