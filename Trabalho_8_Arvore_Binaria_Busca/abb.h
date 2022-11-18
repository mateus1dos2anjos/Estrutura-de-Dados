// Implemente um TAD para representar uma Árvore Binária de Busca. Deve-se tentar evitar
// a formação de árvores degeneradas. Esse TAD deverá conter funções para:

typedef struct _abb Abb;

// 1. Criar a estrutura de dados;
Abb *abb_create(void);

// 2. Inserir um nó de forma recursiva;
Abb *abb_insert_recursive(Abb *r, int val); // r = raiz

// 3. Inserir um nó de forma iterativa;
Abb *abb_insert_interactive(Abb *r, int val);

// 4. Remover um nó;
Abb *abb_remove(Abb *r, int val);

// 5. Buscar um elemento;
Abb *abb_get_element(Abb *r, int val);

// 6. Liberar a estrutura de dados;
void abb_free(Abb *r);

// Imprimir a árvore;
void abb_print(Abb *r);