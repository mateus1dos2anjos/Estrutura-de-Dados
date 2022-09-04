/* Implemente um programa que cria uma variável do TAD lista encadeada ordenada, criado
anteriormente, e utiliza cada uma de suas funções. */

#include <iostream>
#include "lista.h"

using namespace std;

int main(void)
{
  Lista *lst;       /* declara lista não iniciada */
  lst = lst_cria(); /* inicia lista vazia */

  Lista *lst2;       /* declara lista não iniciada */
  lst2 = lst_cria(); /* inicia lista vazia */

  lst = lst_insere_ordenado(lst, 23); /* insere na lista o elemento 23 */
  lst = lst_insere_ordenado(lst, 45); /* insere na lista o elemento 45 */
  lst = lst_insere_ordenado(lst, 56); /* insere na lista o elemento 56 */
  lst = lst_insere_ordenado(lst, 78); /* insere na lista o elemento 78 */

  lst2 = lst_insere_ordenado(lst2, 23); /* insere na lista o elemento 23 */
  lst2 = lst_insere_ordenado(lst2, 45); /* insere na lista o elemento 45 */
  lst2 = lst_insere_ordenado(lst2, 56); /* insere na lista o elemento 56 */
  // lst2 = lst_insere_ordenado(lst2, 78); /* insere na lista o elemento 78 */

  int res = lst_igual(lst, lst2);
  cout << "Resultado 1 para listas iguais e 0 para listas diferentes. Resultado = " << res << endl;

  lst_imprime(lst); /* imprimirá: 23 45  56 78 */

  lst_imprime_rec_inv(lst); /* imprimirá: 78 56 45 23 */
  cout << "fim" << endl;

  lst_vazia(lst);

  lst_busca(lst, 78);

  lst = lst_retira(lst, 78);

  lst_imprime(lst); /* imprimirá: 23 45 56 */

  lst = lst_retira(lst, 45);

  lst_imprime(lst); /* imprimirá: 23 56 */

  lst_imprime_rec(lst); /* imprimirá: 23 56 */
  cout << "fim" << endl;

  lst = lst_insere_ordenado(lst, 22); /* insere na lista o elemento 22 */

  lst_retira_rec(lst, 23);

  lst_imprime_rec(lst); /* imprimirá: 56 */
  cout << "fim" << endl;

  lst_libera(lst);

  return 0;
}