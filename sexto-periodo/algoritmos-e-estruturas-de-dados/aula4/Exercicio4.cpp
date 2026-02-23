#include <iostream>

using namespace std;

void encontrarValores(int *conjunto, int *pos, int *neg, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (conjunto[i] < 0)
            (*neg)++; // Se não usar o "*", estaremos mudando o endereço que ponteiro aponta, não o conteúdo da memória.
        else
            (*pos)++;
    }
}

int const TAMANHO = 10;

int main()
{

    int conjunto[TAMANHO] = {1, 23, -30, 666, -9, 12, 99, 54, 100};
    int pos = 0, neg = 0;

    int *ptPos, *ptNeg;

    ptPos = &pos;
    ptNeg = &neg;

    cout << "Executando a função ..." << endl;

    encontrarValores(conjunto, ptPos, ptNeg, TAMANHO);

    cout << "Função executada ..." << endl;
    cout << "Positivos: " << pos << endl;
    cout << "Negativos: " << neg << endl;
}