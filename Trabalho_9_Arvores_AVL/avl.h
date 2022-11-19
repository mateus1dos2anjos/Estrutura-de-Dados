/*
Implemente um TAD para representar uma Árvore AVL. Deve-se tentar evitar a formação
de árvores degeneradas. Esse TAD deverá conter funções para:
*/

typedef struct _avl Avl;

// Funções auxiliares:

static Avl *right_rotation(Avl *r);

static Avl *left_rotation(Avl *r);

// rotacao direita esquerda
Avl *avl_right_left_rotation(Avl *r);

// rotacao esquerda direita
Avl *avl_left_right_rotation(Avl *r);

// 1. Criar a estrutura de dados;
Avl *avl_create(void);

static Avl *avl_insert_aux(Avl *r, int val, int *flag);

// 2. Inserir um nó;
Avl *avl_insert(Avl *r, int val); // r = raiz

// Funções auxiliares para Remover um nó:

static Avl *left_rot(Avl *r);

static Avl *right_left_rot(Avl *r);

static Avl *right_rot(Avl *r);

static Avl *left_right_rot(Avl *r);

static Avl *avl_remove_aux(Avl *r, int val, int *delta_h);

// 3. Remover um nó;
Avl *avl_remove(Avl *r, int val);

// 4. Buscar um elemento;
Avl *avl_get_element(Avl *r, int val);

// 5. Liberar a estrutura de dados;
void avl_free(Avl *r);

// Imprimir a árvore;
void avl_print(Avl *r);

// Imprimir a árvore;
void avl_print(Avl *r);
