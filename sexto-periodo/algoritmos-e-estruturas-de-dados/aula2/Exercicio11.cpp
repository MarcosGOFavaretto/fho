#include <iostream>
using namespace std;

const int QTD_NUMEROS = 5;

void popularVetor(int vetor[QTD_NUMEROS])
{
    cout << "Informe os números (no máximo " << QTD_NUMEROS << "):" << endl;
    for (int i = 0; i < QTD_NUMEROS; i++)
    {
        cin >> vetor[i];
    }
}

void calcularModa(int vetor[QTD_NUMEROS])
{
    int ocorrencias[QTD_NUMEROS][2];
    int totalDistintos = 0;

    for (int i = 0; i < QTD_NUMEROS; i++)
    {
        ocorrencias[i][0] = 0;
        ocorrencias[i][1] = 0;
    }

    for (int i = 0; i < QTD_NUMEROS; i++)
    {
        int candidato = vetor[i];
        bool achou = false;
        for (int j = 0; j < totalDistintos; j++)
        {
            if (ocorrencias[j][0] == candidato)
            {
                ocorrencias[j][1]++;
                achou = true;
                break;
            }
        }
        if (!achou)
        {
            ocorrencias[totalDistintos][0] = candidato;
            ocorrencias[totalDistintos][1] = 1;
            totalDistintos++;
        }
    }

    int maxContagem = 0;
    for (int i = 0; i < totalDistintos; i++)
    {
        if (ocorrencias[i][1] > maxContagem)
        {
            maxContagem = ocorrencias[i][1];
        }
    }

    int qtdModa = 0;
    int moda = 0;
    for (int i = 0; i < totalDistintos; i++)
    {
        if (ocorrencias[i][1] == maxContagem)
        {
            qtdModa++;
            moda = ocorrencias[i][0];
        }
    }

    if (maxContagem == 1 || qtdModa > 1)
    {
        cout << "Nao existe moda" << endl;
    }
    else
    {
        cout << "Moda: " << moda << endl;
    }
}

int main()
{
    int numeros[QTD_NUMEROS];
    popularVetor(numeros);
    calcularModa(numeros);
}
