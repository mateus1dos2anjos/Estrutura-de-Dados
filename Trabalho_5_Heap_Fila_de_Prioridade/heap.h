/*
Questão 1. Implemente um TAD para representar uma Heap. Assuma que os elementos a serem
armazenados na Heap são valores inteiros entre 1 e n. O usuário informa o valor de n.
Você pode escolher implementar uma Min Heap e/ou uma Max Heap. Esse TAD deverá conter
funções para:
*/

typedef struct _heap Heap;

// 1. Criar uma Heap;
Heap *criar(int max);

// 2. Inserir um elemento;
void inserir(Heap *heap, float prioridade);

// 3. Recuperar/Buscar um determinado elemento;
void buscar(Heap *heap, float prioridade);

// 4. Remover um determinado elemento;
float remover(Heap *heap);

// Imprimir a Heap;
void imprimir(Heap *heap);

// 5. Alterar o valor de um determinado elemento;
void alterar(Heap *heap, float prioridade, float nova_prioridade);

// 6. Liberar a estrutura de dados;
void liberar(Heap *heap);