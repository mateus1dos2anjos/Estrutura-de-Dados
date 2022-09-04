// Questão 6
// Implemente um TAD para representar uma lista encadeada ordenada capaz de armazenar contas bancárias,
// contas poupanças ou contas bônus. Esse TAD deverá conter funções para:

#include <iostream>
#include <stdlib.h> // para função malloc
#include "lista.h"

/* Definição dos tipos de objetos */
#define BAN 0
#define POU 1
#define FID 2

using namespace std;

// Conta bancária: BAN
typedef struct bancaria Bancaria;
struct bancaria
{
  float numero;
  float saldo;
  // credito
  // debito
};

// Conta poupança: POU
typedef struct poupanca Poupanca;
struct poupanca
{
  float numero;
  float saldo;
  // credito
  // debito
  // render juros
};

// Conta fidelidade: FID
typedef struct fidelidade Fidelidade;
struct fidelidade
{
  float numero;
  float saldo;
  float bonus;
  // credito
  // debito
  // render juros.
  // a cada operação de crédito realizado, 1% do valor de creditado é acumulado ao bônus da conta.
  // A função render bônus deve adicionar o valor do bônus no saldo da conta e, em seguida,
  // zerar o valor do bônus.
  // render bonus
};

/* Definição do nó da estrutura */
typedef struct lista_het ListaHet;
struct lista_het
{
  int tipo;
  void *info;
  ListaHet *prox;
};

/* declaração e inicialização da lista */
ListaHet *lst = NULL;

// Depositar

static float depositar_ban(Bancaria* b, float deposito){
  return b->saldo = b->saldo + deposito;
}

static float depositar_pou(Poupanca* p, float deposito){
  return p->saldo = p->saldo + deposito;
}

static float depositar_fid(Fidelidade* f, float deposito){
  f->bonus = 0.01 * deposito;
  return f->saldo = f->saldo + deposito;
}

// Sacar

static float sacar_ban(Bancaria* b, float saque){
  return b->saldo = b->saldo - saque;
}

static float sacar_pou(Poupanca* p, float saque){
  return p->saldo = p->saldo - saque;
}

static float sacar_fid(Fidelidade* f, float saque){
  return f->saldo = f->saldo + saque;
}

// Reder juros

static float render_juros_pou(Poupanca* p){
  p->saldo = p->saldo + (p->saldo * 0.05);
  return p->saldo;
}

// Reder bonus

static float render_bonus_fid(Fidelidade* f){
  f->saldo = f->saldo + f->bonus;
  f->bonus = 0.0;
  return f->saldo;
}


/* Cria um nó com uma conta BANCARIA */
ListaHet *cria_ban(float numero, float saldo)
{
  Bancaria *b;
  ListaHet *l;
  /* aloca retângulo */
  b = (Bancaria *)malloc(sizeof(Bancaria));
  b->numero = numero;
  b->saldo = saldo;

  /* aloca nó */
  l = (ListaHet *)malloc(sizeof(ListaHet));
  l->tipo = BAN;
  l->info = b;
  l->prox = NULL;

  return l;
}

/* Cria um nó com uma conta POUPANCA */
ListaHet *cria_pou(float numero, float saldo)
{
  Poupanca *p;
  ListaHet *l;
  /* aloca retângulo */
  p = (Poupanca *)malloc(sizeof(Poupanca));
  p->numero = numero;
  p->saldo = saldo;

  /* aloca nó */
  l = (ListaHet *)malloc(sizeof(ListaHet));
  l->tipo = POU;
  l->info = p;
  l->prox = NULL;

  return l;
}

/* Cria um nó com uma conta FIDELIDADE */
ListaHet *cria_fid(float numero, float saldo)
{
  Fidelidade *f;
  ListaHet *l;
  /* aloca retângulo */
  f = (Fidelidade *)malloc(sizeof(Fidelidade));
  f->numero = numero;
  f->saldo = saldo;

  /* aloca nó */
  l = (ListaHet *)malloc(sizeof(ListaHet));
  l->tipo = POU;
  l->info = f;
  l->prox = NULL;

  return l;
}

// 1. Criar uma lista vazia:
ListaHet *lst_cria(void)
{
  return NULL;
};

// ...

// 10. Liberar a lista;
/* libera a memória da lista */
void lst_libera(ListaHet *lst)
{
  ListaHet *p = lst;
  while (p != NULL)
  {
    ListaHet *t = p->prox; /* guarda referência para o próximo elemento */
    free(p);               /* libera a memória apontada por p */
    p = t;                 /* faz p apontar para o próximo */
  }
};
