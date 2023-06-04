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
#include <iomanip>
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
/*
//---------------------------------------------------------------------------------------------------
ToDo
SparseMatrix* readSparseMatrix(string NomeDoArquivo){
}
ToDo
//---------------------------------------------------------------------------------------------------
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
}
ToDo
//---------------------------------------------------------------------------------------------------
SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){
  fazendo o codigo;
}
*/
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
  
  while(opc != 11){
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

    }else if(opc == 3){ // Imprimir Matrizes

      if(matrizes.empty()){
        printText(-1);
      }else{
        for(unsigned i = 0; i < matrizes.size(); ++i) {
          cout << "Matriz[" << i << "] (" << matrizes[i]->getQtdLinhas() << " x " << matrizes[i]->getQtdColunas() << "):\n";
          matrizes[i]->print();
          cout << endl;
        }
      }

    }else if(opc == 4){ // Inserir Valor

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

    }else if(opc == 5){ // Popular Matriz

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
          
          int valor{0};
          for(int j = 1; j <= matrizes[i]->getQtdLinhas(); ++j){
            for(int k = 1; k <= matrizes[i]->getQtdColunas(); ++k){
              cin >> valor;
              matrizes[i]->insert(j, k , valor);
            }
          }
          cout << "Matriz[" << i << "] populada com sucesso\n" << endl;
        }
      }

    }else if(opc == 6){ // Clonar uma matriz

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

    }else if(opc == 7){ // Somar Matrizes

    }else if(opc == 8){ // Multiplicar Matrizes

    }else if(opc == 9){ // Deletar uma Matriz

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

    }else if(opc == 10){ // Info do Grupo

      printText(9);
      
    }else if(opc == 11){ // Sair

      for(unsigned i = 0; i < matrizes.size(); ++i){
				delete matrizes[i];
      }
			matrizes.clear();

    }else{

      printText(-1);

    }

  }
  
  return 0;
}
// Obrigado por usar nosso programa :)