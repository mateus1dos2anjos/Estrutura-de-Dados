/* Implemente um programa que cria uma variável do TAD lista encadeada, criado
anteriormente, e utiliza cada uma de suas funções. */

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

  lst_imprime(lst); /* imprimirá: 78 56 45 23 */

  lst_imprime_rec_inv(lst); /* imprimirá: 23 45 56 78 */
  cout << "fim" << endl;

  lst_vazia(lst);

  lst_busca(lst, 78);

  lst = lst_retira(lst, 78);

  lst_imprime(lst); /* imprimirá: 56 45 23 */

  lst = lst_retira(lst, 45);

  lst_imprime(lst); /* imprimirá: 56 23 */

  lst_imprime_rec(lst); /* imprimirá: 56 23 */
  cout << "fim" << endl;

  lst_retira_rec(lst, 23);

  lst_imprime_rec(lst); /* imprimirá: 56 */
  cout << "fim" << endl;

  lst_libera(lst);

  return 0;
}