typedef struct lista Lista;

/* retira elemento da lista */
Lista *lst_cria(void);

/* inserção no início: retorna a lista atualizada */
Lista *lst_insere_ordenado(Lista *lst, int val);

/* imprime valores dos elementos */
void lst_imprime(Lista *lst);

/* imprime recursivamente valores dos elementos */
void lst_imprime_rec(Lista *lst);

/* imprime recursivamente invertida valores dos elementos */
void lst_imprime_rec_inv(Lista *lst);

/* retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *lst);

/* busca um elemento na lista */
Lista *lst_busca(Lista *lst, int val);

/* retira elemento da lista */
Lista *lst_retira(Lista *lst, int val);

/* retira recursivamente elemento da lista */
Lista *lst_retira_rec(Lista *lst, int val);

int lst_igual(Lista *lst1, Lista *lst2);

/* libera a memória da lista */
void lst_libera(Lista *lst);
