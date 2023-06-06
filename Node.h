#ifndef NODE_H
#define NODE_H

class Node {
  friend class SparseMatrix;

  private:
    Node* direita;
    Node* abaixo;
    int linha;
    int coluna;
    double valor;
  
  public:
    Node(Node* direita, Node* abaixo, int linha, int coluna, const double& valor){
      this->direita = direita;
      this->abaixo = abaixo;
      this->linha = linha;
      this->coluna = coluna;
      this->valor = valor;
    }
};

#endif