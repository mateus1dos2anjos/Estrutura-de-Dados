/*
Implemente um TAD para representar uma Árvore Rubro-Negra. Deve-se tentar evitar a
formação de árvores degeneradas. Esse TAD deverá conter funções para:
*/

typedef struct _arn Arn;

// Funções auxiliares:

int get_color(Arn *r);

void change_color(Arn *r);

Arn *left_roatation(Arn *r);

Arn *right_roatation(Arn *r);

// 1. Criar a estrutura de dados;
Arn *arn_create(void);

// 2. Inserir um nó;
int arn_insert(Arn *r, int val); // r = raiz

Arn *arn_insert_aux(Arn *r, int val, int &answer);

// 3. Buscar um elemento;
Arn *arn_get_element(Arn *r, int val);

// 4. Liberar a estrutura de dados;
void arn_free(Arn *r);
