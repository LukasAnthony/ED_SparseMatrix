#ifndef PRINTTEXT_H
#define PRINTTEXT_H

#include <iostream>

using namespace std;

void printText(int x){
  if(x == 0){

    cout << "----------------------------\n"
            "|     Menu de opcoes:      |\n"
            "----------------------------\n"
            "| 1.  HowToUse             |\n"
            "| 2.  Criar uma Matriz     |\n"
            "| 3.  Clonar uma Matriz    |\n"
            "| 4.  Deletar uma Matriz   |\n"
            "| 5.  Imprimir Matrizes    |\n"
            "| 6.  Inserir Valor        |\n"
            "| 7.  Popular Matriz       |\n"
            "----------------------------\n"
            "| 8.  Somar Matrizes       |\n"
            "| 9.  Multiplicar Matrizes |\n"
            "----------------------------\n"
            "| 10. Importar uma Matriz  |\n"
            "| 11. Exportar uma Matriz  |\n"
            "----------------------------\n"
            "| 12. Info do Grupo        |\n"
            "| 13. Sair                 |\n"
            "----------------------------\n" << endl;

  }else if(x == 1){

    cout << "Documentacao Rapida - Projeto de matriz Esparsa\n"
        "Este programa permite ao usuario interagir com matrizes esparsas. Uma matriz esparsa e uma matriz que contem principalmente zeros. Para economizar espaco, apenas os valores diferentes de zero sao armazenados, alem dos nos sentinelas.\n"
        "Aqui estao as opcoes do menu que o programa oferece:\n\n"
        "1. HowToUse: Esta opcao apresenta ao usuario esse guia breve de como utilizar este programa.\n\n"
        "2. Criar matriz: Esta opcao permitira ao usuario criar uma nova matriz esparsa. Sera solicitado ao usuario que forneca o numero de linhas e colunas para a matriz.\n\n"
        "3. Clonar uma matriz: Esta opcao permitira ao usuario clonar uma matriz existente. O usuario devera fornecer o indice da matriz que sera clonada, a nova matriz sera alocada ao final da lista de matrizes.\n\n"
        "4. Deletar uma matriz: Esta opcao permitira ao usuario deletar uma matriz especifica. O usuario devera escolher a matriz a ser deletada.\n\n"
        "5. Imprimir Matrizes: Esta opcao permitira ao usuario imprimir todas as matrizes que estao armazenadas.\n\n"
        "6. Inserir Valor: Esta opcao permitira ao usuario inserir um valor em uma posicao especifica de uma matriz esparsa. O usuario devera escolher a matriz, inserir linha, coluna e o valor a ser inserido.\n\n"
        "7. Popular matriz: Esta opcao permitira ao usuario preencher uma matriz inteira com valores de sua escolha.\n\n"
        "8. Somar Matrizes: Esta opcao permitira ao usuario somar duas matrizes esparsas juntas. O usuario devera escolher as duas matrizes a serem somadas.\n\n"
        "9. Multiplicar Matrizes: Esta opcao permitira ao usuario multiplicar duas matrizes esparsas juntas. O usuario devera escolher as duas matrizes a serem multiplicadas.\n\n"
        "10. Importar uma matriz: Esta opcao escreve uma matriz escolhida pelo usuario em um arquivo .txt, o usuario fornece o nome do arquivo, se o arquivo existir, então, a funcao sobrescreve o arquivo, se o arquivo nao existir, a funcao cria o arquivo.\n\n"
        "11. Exportar uma matriz: Esta opcao pede ao usuario que digite o nome do arquivo, entao o programa pega os valores do arquivo e transforma em uma matriz e insere no programa.\n\n"
        "12. Grupo: Esta opcao apresentara informacoes sobre o grupo que criou o programa.\n\n"
        "13. Sair: Esta opcao encerra o programa.\n\n"
        "Ao iniciar o programa, o usuario sera ao este menu. Para selecionar uma opcao, o usuario deve digitar o numero correspondente a opcao e pressionar Enter.\n"
        "Por exemplo, para criar uma nova matriz, o usuario deve digitar 2 e pressionar Enter. O programa entao solicitara ao usuario o numero de linhas e colunas para a matriz.\n\n"
        "As operacoes que requerem uma matriz, como inserir valor ou deletar uma matriz, pedirao ao usuario que especifique qual matriz ele gostaria de usar dentre as matrizes criadas. O usuario deve fazer isso digitando o indice da matriz, que comeca em 0 e vai ate n-1, onde n e o numero total de matrizes.\n\n"
        "As operacoes que requerem duas matrizes, como somar ou multiplicar matrizes, pedirao ao usuario que especifique quais matrizes ele gostaria de usar dentre as matrizes criadas. O usuario deve fazer isso digitando os indices da matrizes, que comecam em 0 e vao ate n-1, onde n e o numero total de matrizes.\n" << endl;

  }else if(x == 2){
    
    cout << " ___ ___          __  __      _       _             ___                               \n"
            "| __|   \\   ___  |  \\/  |__ _| |_ _ _(_)______ ___ | __|____ __  __ _ _ _ ___ __ _ ___\n"
            "| _|| |) | |___| | |\\/| / _` |  _| '_| |_ / -_|_-< | _|(_-< '_ \\/ _` | '_(_-</ _` (_-<\n"
            "|___|___/        |_|  |_\\__,_|\\__|_| |_/__\\___/__/ |___/__/ .__/\\__,_|_| /__/\\__,_/__/\n"
            "                                                          |_|                         \n";

  }else if(x == 9){

    cout << "----------------------------------------\n"
            "| Grupo de Est. de Dados:              |\n"
            "----------------------------------------\n"
            "| Nome: Beatriz Nascimento de Oliveira |\n"
            "| Matricula: 537634                    |\n"
            "| Email: beatriznascimento@alu.ufc.br  |\n"
            "----------------------------------------\n"
            "| Nome: Lucas Anthony Soares de Sousa  |\n"
            "| Matricula: 539300                    |\n"
            "| Email: lucasanthony@alu.ufc.br       |\n"
            "----------------------------------------\n" << endl;

  }else if(x == -1){

    cout << "---------------------------------------------------\n"
            "|                      AVISO                      |\n"
            "---------------------------------------------------\n"
            "|                                                 |\n"
            "| Voce nao criou nenhuma matriz, se desejar, voce |\n"
            "| pode criar uma nova matriz escolhendo a opcao 2 |\n"
            "| no menu                                         |\n"
            "|                                                 |\n"
            "---------------------------------------------------\n" << endl;

  }else if(x == -2){

    cout << "---------------------------------------------------\n"
            "|                      AVISO                      |\n"
            "---------------------------------------------------\n"
            "|                                                 |\n"
            "| Essa matriz nao existe em sua lista de matrizes |\n"
            "| criadas, se desejar, voce pode consultar suas   |\n"
            "| matrizes escolhendo a opcao 5 no menu           |\n"
            "|                                                 |\n"
            "---------------------------------------------------\n" << endl;

  }else if(x == -3){

    cout << "----------------------------------------------------\n"
            "|                       AVISO                      |\n"
            "----------------------------------------------------\n"
            "|                                                  |\n"
            "| Por favor, digite uma opcao valida(entre 1 e 13) |\n"
            "|                                                  |\n"
            "----------------------------------------------------\n" << endl;

  }else if(x == -4){

    cout << "------------------------------------\n"
            "|              AVISO               |\n"
            "------------------------------------\n"
            "|                                  |\n"
            "| Numero de matrizes insuficientes |\n"
            "|                                  |\n"
            "------------------------------------\n" << endl;

  }else if(x == -5){

    cout << "-----------------------------------\n"
            "|              AVISO              |\n"
            "-----------------------------------\n"
            "|                                 |\n"
            "| Matrizes nao compativeis para a |\n"
            "| soma(tamanhos diferentes)       |\n"
            "|                                 |\n"
            "-----------------------------------\n" << endl;

  }else if(x == -6){

    cout << "--------------------------------------------------\n"
            "|                     AVISO                      |\n"
            "--------------------------------------------------\n"
            "|                                                |\n"
            "| Matrizes nao compativeis para a multiplicacao  |\n"
            "| (quantidade de colunas da primeira e diferente |\n"
            "| da quantidade de linhas da segunda)            |\n"
            "|                                                |\n"
            "--------------------------------------------------\n" << endl;

  }else if(x == -7){

    cout << "-----------------------------------------\n"
            "|                 AVISO                 |\n"
            "-----------------------------------------\n"
            "|                                       |\n"
            "| Tamanho invalido, por favor escolha   |\n"
            "| tamanhos maiores que 0 para as linhas |\n"
            "| e colunas                             |\n"
            "|                                       |\n"
            "-----------------------------------------\n" << endl;

  }
}

#endif