/*
* Universidade Federal do Ceará - Campus Quixadá
* QXD0010 – Estruturas de Dados(2023.1)
* Prof. Atílio Gomes Luiz

* Lucas Anthony Soares de Sousa - (539300) - lucasanthony@alu.ufc.br
* Beatriz Nascimento de Oliveira - (537634) - beatriznascimento@alu.ufc.br
*/

#include <cstdlib> //TEST
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "SparseMatrix.h"
#include "PrintText.h" // Criação de uma biblioteca apenas para imprimir grandes textos

using namespace std;

void clearScreen() { //TEST
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//---------------------------------------------------------------------------------------------------
SparseMatrix* readSparseMatrix(string NomeDoArquivo){
  fstream arquivo;
  arquivo.open(NomeDoArquivo, ios::in);

  if(arquivo.is_open()){
    SparseMatrix* novaMatriz;
    stringstream ss;
    string linha;
    int aux_linha, aux_coluna, i{0};
    double aux_val;

    while(!arquivo.eof()){
      getline(arquivo, linha);
      if(i == 0){
        ss << linha;
        ss >> aux_linha >> aux_coluna;
        novaMatriz = new SparseMatrix(aux_linha, aux_coluna);
        ++i;
        ss.str("");
        ss.clear();
      }else{
        ss << linha;
        ss >> aux_linha >> aux_coluna >> aux_val;
        novaMatriz->insert(aux_linha, aux_coluna, aux_val);
        ss.str("");
        ss.clear();
      }
    }

    cout << "Matriz importada com sucesso\n" << endl;
    return novaMatriz;
  }else{
    cout << "Nao foi possivel abrir o arquivo" << endl;
    return nullptr;
  }
}

//---------------------------------------------------------------------------------------------------
void writeSparseMatrix(string NomeDoArquivo, SparseMatrix* A){
  fstream arquivo;

  arquivo.open(NomeDoArquivo, ios::out | ios::trunc);

  if(arquivo.is_open()){
    arquivo << A->getQtdLinhas() << " " << A->getQtdColunas() << endl; // Escreve a quantidade de lin e col

    for(int i = 1; i <= A->getQtdLinhas(); ++i){
      for(int j = 1; j <= A->getQtdColunas(); ++j){
        if(A->get(i, j) != 0){
          arquivo << i << " " << j << " " << A->get(i, j) << endl;
        }
      }
    }

    cout << "Matriz exportada com sucesso\n" << endl;
    arquivo.close();
  }else{
    cout << "Nao foi possivel abrir o arquivo";
  }
}

//---------------------------------------------------------------------------------------------------
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
  SparseMatrix* C = new SparseMatrix(A->getQtdLinhas(), B->getQtdColunas());

  for(int i = 1; i <= C->getQtdLinhas(); ++i){
    for(int j = 1; j <= C->getQtdColunas(); ++j){
      double soma = (A->get(i, j) + B->get(i, j));
      C->insert(i, j, soma);
    }
  }

  return C;
}

//---------------------------------------------------------------------------------------------------
SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){
  SparseMatrix* C = new SparseMatrix(A->getQtdLinhas(), B->getQtdColunas());

  for(int i = 1; i <= A->getQtdLinhas(); ++i){ // percorre linhas
    for(int j = 1; j <= B->getQtdColunas(); ++j){ // percorre colunas
      double soma{0};
      for(int k = 1; k <= A->getQtdColunas(); ++k){
        soma += (A->get(i, k) * B->get(k, j));
      }
      C->insert(i, j, soma);
    }
  }

  return C;
}

//---------------------------------------------------------------------------------------------------
SparseMatrix* clone(SparseMatrix* A){
  SparseMatrix* novaMatriz = new SparseMatrix(A->getQtdLinhas(), A->getQtdColunas());

  for(int i = 1; i <= A->getQtdLinhas(); ++i){
    for(int j = 1; j <= A->getQtdColunas(); ++j){
      novaMatriz->insert(i, j, (A->get(i, j)));
    }
  }

  return novaMatriz;
}

//---------------------------------------------------------------------------------------------------
int main(){
  printText(2);

  vector<SparseMatrix*> matrizes;
  int opc{0};
  
  while(opc != 13){
    printText(0);
    cin >> opc;
    clearScreen();

    if(opc == 1){ // HowToUse

      printText(1);

    }else if(opc == 2){ // Criar Matriz

      try{
        int i, j;
        cout << "Digite a quantidade de linhas e colunas(respectivamente) da matriz que deseja criar: " << endl;
        cin >> i >> j;
        SparseMatrix* tempAux = new SparseMatrix(i, j);
        matrizes.push_back(tempAux);
        cout << "Matriz[" << matrizes.size()-1 << "] criada com sucesso\n" << endl;
      }catch(std::range_error& e){
        std::cerr << e.what() << '\n';
      }

    }else if(opc == 3){ // Clonar uma matriz

      if(matrizes.empty()){
        printText(-1);
      }else{
        cout << "Digite o indice da Matriz que deseja clonar:" << endl;
        int i;
        cin >> i;

        if(i < 0 || i >= matrizes.size()){
          printText(-2);
        }else{
          matrizes.push_back(clone(matrizes[i]));
          cout << "Matriz[" << i << "] clonada com sucesso\n" << endl;
        }
      }

    }else if(opc == 4){ // Deletar uma Matriz

      if(matrizes.empty()){
        printText(-1);
      }else{
        cout << "Digite o indice da Matriz que deseja deletar:" << endl;
        int i;
        cin >> i;

        if(i < 0 || i >= matrizes.size()){
          printText(-2);
        }else{
          SparseMatrix *tempAux = matrizes[i];
          matrizes.erase(matrizes.begin() + i);
          delete tempAux;
          cout << "Matriz[" << i << "] deletada com sucesso\n" << endl;
        }
      }

    }else if(opc == 5){ // Imprimir Matrizes

      if(matrizes.empty()){
        printText(-1);
      }else{
        for(unsigned i = 0; i < matrizes.size(); ++i) {
          cout << "Matriz[" << i << "] (" << matrizes[i]->getQtdLinhas() << " x " << matrizes[i]->getQtdColunas() << "):\n";
          matrizes[i]->print();
          cout << endl;
        }
      }

    }else if(opc == 6){ // Inserir Valor

      if(matrizes.empty()){
        printText(-1);
      }else{
        cout << "Digite em qual matriz deseja inserir o valor:" << endl;
        int i;
        cin >> i;

        if(i < 0 || i >= matrizes.size()){
          printText(-2);
        }else{
          try{
            int x, y;
            double valor;
            cout << "Digite a posicao(linha e coluna) e o valor:" << endl;
            cin >> x >> y >> valor;
            matrizes[i]->insert(x, y, valor);
            cout << "Inserido com sucesso\n" << endl;
          }catch(std::range_error& e){
            std::cerr << e.what() << '\n';
          }
        }
      }

    }else if(opc == 7){ // Popular Matriz

      if(matrizes.empty()){
        printText(-1);
      }else{
        int i;
        cout << "Digite o indice da Matriz que deseja popular:" << endl;
        cin >> i;

        if(i < 0 || i >= matrizes.size()){
          printText(-2);
        }else{
          if(matrizes[i]->getSize() == 1){
            cout << "Digite 1 valor para popular a Matriz[" << i << "]" << endl;
          }else{
            cout << "Digite " << matrizes[i]->getSize() << " valores para popular a Matriz[" << i << "]" << endl;
          }
          
          double valor{0};
          for(int j = 1; j <= matrizes[i]->getQtdLinhas(); ++j){
            for(int k = 1; k <= matrizes[i]->getQtdColunas(); ++k){
              cin >> valor;
              matrizes[i]->insert(j, k , valor);
            }
          }
          cout << "Matriz[" << i << "] populada com sucesso\n" << endl;
        }
      }

    }else if(opc == 8){ // Somar Matrizes

      if(matrizes.empty()){
        printText(-1);
      }else if(matrizes.size() < 2){
        cout << "Numero de matrizes insuficientes\n" << endl;
      }else{
        cout << "Digite os indices das matrizes que deseja somar:" << endl;
        int i, j;
        cin >> i >> j;

        if(i < 0 || i >= matrizes.size() || j < 0 || j >= matrizes.size()){
          printText(-2);
        }else if(matrizes[i]->getQtdLinhas() != matrizes[j]->getQtdLinhas() || matrizes[i]->getQtdColunas() != matrizes[j]->getQtdColunas()){
          cout << "Matrizes nao compativeis para a soma(tamanhos diferentes)\n" << endl;
        }else{
          matrizes.push_back(sum(matrizes[i], matrizes[j]));
          cout << "Matrizes somadas com sucesso, nova matriz criada na lista\n" << endl;
        }
      }

    }else if(opc == 9){ // Multiplicar Matrizes

      if(matrizes.empty()){
        printText(-1);
      }else if(matrizes.size() < 2){
        cout << "Numero de matrizes insuficientes\n" << endl;
      }else{
        cout << "Digite os indices das matrizes que deseja multiplicar:" << endl;
        int i, j;
        cin >> i >> j;

        if(i < 0 || i >= matrizes.size() || j < 0 || j >= matrizes.size()){
          printText(-2);
        }else if(matrizes[i]->getQtdColunas() != matrizes[j]->getQtdLinhas()){
          cout << "Matrizes nao compativeis para a multiplicacao(quantidade de colunas da primeira e diferente da quantidade de linhas da segunda)\n" << endl;
        }else{
          matrizes.push_back(multiply(matrizes[i], matrizes[j]));
          cout << "Matrizes multiplicadas com sucesso, nova matriz criada na lista\n" << endl;
        }
      }

    }else if(opc == 10){ // Importar uma Matriz(.txt)

      cout << "Digite o nome do arquivo para importar a Matriz(recomendado: \"matrizes.txt\"):" << endl;
      string nomeArqv;
      cin >> nomeArqv;

      SparseMatrix* novaMatriz = readSparseMatrix(nomeArqv);
      if(novaMatriz != nullptr){
        matrizes.push_back(novaMatriz);
      }else{
        delete novaMatriz;
      }

    }else if(opc == 11){ // Exportar uma Matriz(.txt)

      if(matrizes.empty()){
        printText(-1);
      }else{
        cout << "Digite o indice da Matriz que deseja escrever no arquivo:" << endl;
        int i;
        cin >> i;

        if(i < 0 || i >= matrizes.size()){
          printText(-2);
        }else{
          string nomeArqv;
          cout << "Digite o nome do arquivo para salvar sua matriz(recomendado: \"matrizes.txt\")" << endl;
          cin >> nomeArqv;
          writeSparseMatrix(nomeArqv, matrizes[i]);
        }
      }

    }else if(opc == 12){ // Info do Grupo

      printText(9);
      
    }else if(opc == 13){ // Sair

      for(unsigned i = 0; i < matrizes.size(); ++i){
        delete matrizes[i];
      }
      matrizes.clear();

      break;

    }
    
  }
  return 0;
}
// Obrigado por usar nosso programa :)