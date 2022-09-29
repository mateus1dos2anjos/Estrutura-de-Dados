#include <iostream>
#include "heap.h"
#include <stdlib.h>

using namespace std;

typedef struct _heap Heap;

struct _heap
{
  int max;           /* tamanho maximo do heap */
  int pos;           /* proxima posicao disponivel no vetor */
  float *prioridade; /* vetor das prioridades */
};

Heap *criar(int max)
{
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->max = max;
  heap->pos = 0;
  heap->prioridade = (float *)malloc(max * sizeof(float));
  return heap;
}

static void troca(int a, int b, float *v)
{
  float f = v[a];
  v[a] = v[b];
  v[b] = f;
}

static void corrige_acima(Heap *heap, int pos)
{
  while (pos > 0)
  {

    int pai = (pos - 1) / 2;
    if (heap->prioridade[pai] < heap->prioridade[pos])
      troca(pos, pai, heap->prioridade);
    else
      break;
    pos = pai;
  }
}

void inserir(Heap *heap, float prioridade)
{
  if (heap->pos <= heap->max - 1)
  {
    heap->prioridade[heap->pos] = prioridade;
    corrige_acima(heap, heap->pos);
    heap->pos++;
    cout << "Elemento inserido com sucesso!" << endl;
  }
  else
    cout << "Opa! Nao foi possivel inserir. Heap cheio!" << endl;
}

void buscar(Heap *heap, float prioridade)
{
  Heap *h = heap;
  int cont = 0;
  for (int i = 0; i < h->pos; i++)
  {
    if (h->prioridade[i] == prioridade)
    {
      cont = 1;
      cout << "Resultado da Busca: " << h->prioridade[i] << endl;
    }
  }
  if (cont == 0)
  {
    cout << "Elemento não encontrado." << endl;
  }
};

static void corrige_abaixo(Heap *heap)
{
  int pai = 0;
  while (2 * pai + 1 < heap->pos)
  {
    int filho_esq = 2 * pai + 1;
    int filho_dir = 2 * pai + 2;
    int filho;
    if (filho_dir >= heap->pos)
      filho_dir = filho_esq;
    if (heap->prioridade[filho_esq] > heap->prioridade[filho_dir])
      filho = filho_esq;
    else
      filho = filho_dir;
    if (heap->prioridade[pai] < heap->prioridade[filho])

      troca(pai, filho, heap->prioridade);

    else

      break;
    pai = filho;
  }
}

float remover(Heap *heap)
{
  if (heap->pos > 0)
  {
    float topo = heap->prioridade[0];
    heap->prioridade[0] = heap->prioridade[heap->pos - 1];
    heap->pos--;
    corrige_abaixo(heap);
    cout << "Elemento removido com sucesso!" << endl;
    return topo;
  }
  else
  {
    cout << "Opa! Heap vazio!." << endl;
    return -1;
  }
}

void alterar(Heap *heap, float prioridade, float nova_prioridade)
{
  Heap *h = heap;
  int flag = 0;
  for (int i = 0; i < h->pos; i++)
  {
    if (h->prioridade[i] == prioridade)
    {
      h->prioridade[i] = nova_prioridade;
      corrige_abaixo(heap);
      corrige_acima(heap, heap->pos);
      cout << "Elemento " << prioridade << " alterado por elemento " << nova_prioridade << "." << endl;
      flag = 1;
    }
  }
  if (flag == 0)
  {
    cout << "Elemento não encontrado para alterar." << endl;
  }
};

void imprimir(Heap *heap)
{
  Heap *h = heap;
  for (int i = 0; i < h->pos; i++)
  {
    cout << h->prioridade[i] << endl;
  }
  cout << "Fim da Heap." << endl;
};

void liberar(Heap *heap)
{
  Heap *h = heap;
  free(h);
  free(h->prioridade);
}