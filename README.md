# ED_SparseMatrix

## Visão Geral

Este programa foi projetado para permitir aos usuários interagir com matrizes esparsas. Uma matriz esparsa é uma matriz que contém principalmente zeros. Para economizar espaço, apenas os valores diferentes de zero são armazenados, além dos nós sentinelas.

Aqui está um resumo das opções do menu que o programa oferece:

### Menu de opções

1. **HowToUse**: Esta opcao apresenta ao usuario esse guia breve de como utilizar este programa

2. **Criar matriz**: Esta opcao permitira ao usuario criar uma nova matriz esparsa. Sera solicitado ao usuario que forneca o numero de linhas e colunas para a matriz

3. **Clonar uma matriz**: Esta opcao permitira ao usuario clonar uma matriz existente. O usuario devera fornecer o indice da matriz que sera clonada, a nova matriz sera alocada ao final da lista de matrizes

4. **Deletar uma matriz**: Esta opcao permitira ao usuario deletar uma matriz especifica. O usuario devera escolher a matriz a ser deletada

5. **Imprimir Matrizes**: Esta opcao permitira ao usuario imprimir todas as matrizes que estao armazenadas

6. **Inserir Valor**: Esta opcao permitira ao usuario inserir um valor em uma posicao especifica de uma matriz esparsa. O usuario devera escolher a matriz, inserir linha, coluna e o valor a ser inserido

7. Popular matriz**: Esta opcao permitira ao usuario preencher uma matriz inteira com valores de sua escolha

8. **Somar Matrizes**: Esta opcao permitira ao usuario somar duas matrizes esparsas juntas. O usuario devera escolher as duas matrizes a serem somadas

9. **Multiplicar Matrizes**: Esta opcao permitira ao usuario multiplicar duas matrizes esparsas juntas. O usuario devera escolher as duas matrizes a serem multiplicadas

10. **Importar uma matriz**: Esta opcao pede ao usuario que digite o nome do arquivo, entao o programa pega os valores do arquivo e transforma em uma matriz e insere no programa

11. **Exportar uma matriz**: Esta opcao escreve uma matriz escolhida pelo usuario em um arquivo .txt, o usuario fornece o nome do arquivo, se o arquivo existir, então, a funcao sobrescreve o arquivo, se o arquivo nao existir, a funcao cria o arquivo

12. **Info do Grupo**: Esta opcao apresentara informacoes sobre o grupo que criou o programa

13. **Sair**: Esta opcao encerra o programa

## Como utilizar

Ao iniciar o programa, o usuário será apresentado ao menu. Para selecionar uma opção, o usuário deve digitar o número correspondente à opção e pressionar Enter.

Por exemplo, para criar uma nova matriz, o usuário deve digitar 2 e pressionar Enter. O programa então solicitará ao usuário o número de linhas e colunas para a matriz.

As operações que requerem uma matriz, como inserir valor ou deletar uma matriz, pedirão ao usuário que especifique qual matriz ele gostaria de usar dentre as matrizes criadas. O usuário deve fazer isso digitando o índice da matriz, que começa em 0 e vai até n-1, onde n é o número total de matrizes.

As operações que requerem duas matrizes, como somar ou multiplicar matrizes, pedirão ao usuário que especifique quais matrizes ele gostaria de usar dentre as matrizes criadas. O usuário deve fazer isso digitando os índices das matrizes, que começam em 0 e vão até n-1, onde n é o número total de matrizes.