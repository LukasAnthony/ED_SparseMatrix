#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int n, int m){
  if(n <= 0 || m <= 0){
    throw std::range_error("Error: tamanho invalido\n");
  }

  m_head = new Node(nullptr, nullptr, 0, 0, 0);
  qtd_lin = n;
  qtd_col = m;
  Node* aux = m_head;

// Alocação de Nós para as Linhas:
  for(int i = 1; i <= n; ++i){
    aux->abaixo = new Node(nullptr, nullptr, i, 0, 0);
    aux = aux->abaixo;
    aux->direita = aux;
  }
  aux->abaixo = m_head;

// Voltar para o começo(m_head)
  aux = m_head;

// Alocação de Nós para as Colunas:
  for(int i = 1; i <= m; ++i){
    aux->direita = new Node(nullptr, nullptr, 0, i, 0);
    aux = aux->direita;
    aux->abaixo = aux;
  }
  aux->direita = m_head;
}

//----------------------------------------------------------------------------------
int SparseMatrix::getQtdLinhas(){
  return qtd_lin;
}

//----------------------------------------------------------------------------------
int SparseMatrix::getQtdColunas(){
  return qtd_col;
}

//----------------------------------------------------------------------------------
int SparseMatrix::getSize(){
  return (qtd_lin * qtd_col);
}

//----------------------------------------------------------------------------------
SparseMatrix::~SparseMatrix(){
  Node* aux1 = m_head->abaixo;
  Node* aux2;
  Node* temp;

// Loop para aux1 percorrer as linhas, começando da segunda, até chegar na primeira(m_head)
  while(aux1 != m_head){
    aux2 = aux1->direita;

// Apagar as colunas
    while(aux2 != aux1){
      temp = aux2;
      aux2 = aux2->direita;
      delete temp;
    }

// aux1 desce para a próxima linha e deleta o nó sentinela da linha anterior
    temp = aux1;
    aux1 = aux1->abaixo;
    delete temp;
  }

// Deletar os nós sentinelas da coluna
  aux1 = aux1->direita;
  while(aux1 != m_head){
    temp = aux1;
    aux1 = aux1->direita;
    delete temp;
  }

// Deletar o m_head
  delete m_head;
}

//----------------------------------------------------------------------------------
void SparseMatrix::insert(int i, int j, double value){
  if(i <= 0 || j <= 0 || i > qtd_lin || j > qtd_col){
    throw std::range_error("Error: indice invalido\n");
  }
  if(value == 0){
    return;
  }

  Node* aux_lin = m_head;
  Node* aux_col = m_head;

// Laço para chegar na linha desejada
  while(aux_lin->linha != i){
    aux_lin = aux_lin->abaixo;
  }
// Laço para andar nas colunas até chegar no nó que antecede(pela esquerda) o nó que será inserido na posição (i, j)
  while(aux_lin->direita->coluna < j && aux_lin->direita->coluna != 0){
    aux_lin = aux_lin->direita;
  }

// Laço para chegar na coluna desejada
  while(aux_col->coluna != j){ 
    aux_col = aux_col->direita;
  }
// Laço para descer nas linhas até chegar no nó que antecede(por cima) o nó que será inserido na posição (i, j)
  while(aux_col->abaixo->linha < i && aux_col->abaixo->linha != 0){
    aux_col = aux_col->abaixo;
  }

// Verificar se nó já existe, se existir apenas substitui o valor, se não, cria um novo nó
  if(aux_lin->direita->coluna == j && aux_col->abaixo->linha == i){
    aux_lin->direita->valor = value;
  }else{
    Node* newNode = new Node(aux_lin->direita, aux_col->abaixo, i, j, value);
    aux_lin->direita = newNode;
    aux_col->abaixo = newNode;
  }
}

//----------------------------------------------------------------------------------
double SparseMatrix::get(int i, int j){
  if(i <= 0 || j <= 0 || i > qtd_lin || j > qtd_col){
    throw std::range_error("Error: indice invalido\n");
  }

  Node* aux = m_head;

// Laço para chegar na linha desejada
  while(aux->linha != i){
    aux = aux->abaixo;
  }

// Laço para tentar chegar na coluna desejada, se existir um nó nessa coluna
  while(aux->direita->coluna != 0 && aux->direita->coluna <= j){
    aux = aux->direita;
  }

// Verificar se aux está na posição certa, se existir e retornar o valor, caso contrario, retornar 0
  if(aux->linha == i && aux->coluna == j){
    return aux->valor;
  }else{
    return 0;
  }
}

//----------------------------------------------------------------------------------
void SparseMatrix::print(){
  Node* aux = m_head;
  Node* aux2;

  for(int i = 0; i < qtd_lin; ++i){
    aux = aux->abaixo;
    aux2 = aux;

    std::cout << "[ ";
    for(int j = 1; j <= qtd_col; ++j){
//Se existir um próximo nó, entra nele e imprime seu valor 
      if(aux2->direita->coluna == j){
        aux2 = aux2->direita;
        std::cout << aux2->valor << " ";
//Sem coluna para imprimir(Imprimir 0)
      }else{
        std::cout << 0 << " ";
      }
    }
    std::cout << "]" << std::endl;
  }
}