#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Node.h"

class SparseMatrix {
  private:
    Node* m_head;
    int qtd_lin;
    int qtd_col;

  public:
    SparseMatrix(int n, int m);

    int getQtdLinhas();

    int getQtdColunas();

    int getSize();

    ~SparseMatrix();

    void insert(int i, int j, double value);

    double get(int i, int j);

    void print();
};

#endif