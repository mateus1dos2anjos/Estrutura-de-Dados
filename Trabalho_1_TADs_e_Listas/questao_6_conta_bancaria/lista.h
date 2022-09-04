typedef struct lista_het ListaHet;

// 1. Criar lista vazia
ListaHet *lst_cria(void);

// Depositar

static float depositar_ban(Bancaria *b, float deposito);

static float depositar_pou(Poupanca *p, float deposito);

static float depositar_fid(Fidelidade *f, float deposito);

// Sacar

static float sacar_ban(Bancaria *b, float saque);

static float sacar_pou(Poupanca *p, float saque);

static float sacar_fid(Fidelidade *f, float saque);

// Reder juros

static float render_juros_pou(Poupanca *p);

// Reder bonus

static float render_bonus_fid(Fidelidade *f);

/* Cria um nó com uma conta BANCARIA */
ListaHet *cria_ban(float numero, float saldo);

/* Cria um nó com uma conta POUPANCA */
ListaHet *cria_pou(float numero, float saldo);

/* Cria um nó com uma conta FIDELIDADE */
ListaHet *cria_fid(float numero, float saldo);

// 10. Liberar a lista;
/* libera a memória da lista */
void lst_libera(ListaHet *lst);
