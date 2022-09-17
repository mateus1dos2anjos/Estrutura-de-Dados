/*
Questão 1. Implemente um TAD para representar uma Tabela de Dispersão (Hash Table).
Assuma que as chaves são valores inteiros entre 1 e n, o tamanho do arranjo é metade
do número de chaves possíveis (n/2). O usuário informa o valor de n. Utilize um método
para tratamento de colisões (encadeamento exterior, encadeamento interior ou endereçamento aberto).
Esse TAD deverá conter funções para:
*/

class Hash
{
private:
  int FuncaoHash(int valor);
  int max_itens;
  int max_posicoes;
  int quant_itens;
  int *estrutura;

public:
  // 1. Criar a tabela de dispersão;
  Hash(int max);

  // 5. Liberar a tabela de dispersão;
  ~Hash();

  // 2. Inserir elemento;
  void inserir(int valor);

  // 3. Recuperar/Buscar um determinado elemento;
  void buscar(int valor);

  // 4. Remover um determinado elemento;
  void deletar(int valor);

  // Imprimir a tabela hash;
  void imprimir();
};