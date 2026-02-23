#include <iostream>
using namespace std;

const int QUANTIDADE_LINHAS = 5;
const int QUANTIDADE_COLUNAS = 5;

/**
 * 8) Faça uma função que recebe, por parâmetro, uma matriz A(5,5) e retorna a soma dos seus
 * elementos.
 */

void popularMatriz(int matrizParaPopular[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS])
{
    for (int linha = 0; linha < QUANTIDADE_LINHAS; linha++)
    {
        for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
        {
            cout << "Informe a posição [" << linha << "][" << coluna << "]: " << endl;
            cin >> matrizParaPopular[linha][coluna];
        }
    }
}

int somarElementosDaMatriz(int matrizParaSomar[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS])
{

    int resultado = 0;
    for (int linha = 0; linha < QUANTIDADE_LINHAS; linha++)
    {
        for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
        {
            resultado += matrizParaSomar[linha][coluna];
        }
    }

    return resultado;
}

int main()
{

    int matriz[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
    popularMatriz(matriz);

    int soma = somarElementosDaMatriz(matriz);

    cout << "\nO resultado da soma dos elementos da matriz informada é: " << soma << endl;

    return 0;
}