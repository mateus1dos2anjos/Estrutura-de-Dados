/*
Questão 1. Implemente um TAD para representar uma Hash Estendível. Assuma que as chaves são
valores inteiros entre 1 e n. O usuário informa o valor de n e o tamanho do bucket (ou seja,
quantos elementos podem ser armazenados em um bucket). Esse TAD deverá conter
funções para:
*/

class Hash
{
private:
  string toBinary(int n);
  int funcaoHash(int valor);
  int max_itens;
  int max_posicoes;
  int quant_itens;
  int tam_bucket;
  int bucket_counter;
  string **estrutura;

public:
  // 1. Criar a tabela de dispersão;
  Hash(int max, int tam_bucket);

  // 5. Liberar a tabela hash;
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