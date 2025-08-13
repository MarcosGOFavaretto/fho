#include <iostream>
using namespace std;

/**
 * 8) Faça um programa que contenha uma função capaz de calcular a velocidade média de um móvel,
 * dado como entrada a variação de espaço Si e Sf e os tempos Ti e Tf. A função deve receber os
 * parâmetros por valor.
 */

float calcularVelocidadeMedia(float posicaoInicial, float posicaoFinal, int tempoInicial, int tempoFinal)
{
    float velocidadeMedia = (posicaoFinal - posicaoInicial) / (tempoFinal - tempoInicial);
    return velocidadeMedia;
}

int main()
{

    float posicaoInicial = 0.0;
    float posicaoFinal = 0.0;
    int tempoInicial = 0;
    int tempoFinal = 0;

    cout << "Informe a posição INICIAL do objeto (em metros): ";
    cin >> posicaoInicial;

    cout << "Informe a posição FINAL do objeto (em metros): ";
    cin >> posicaoFinal;

    cout << "Informe o tempo INICIAL do movimento (em segundos): ";
    cin >> tempoInicial;

    cout << "Informe o tempo FINAL do movimento (em segundos): ";
    cin >> tempoFinal;

    cout << "A velocidade média é de: " << calcularVelocidadeMedia(posicaoInicial, posicaoFinal, tempoInicial, tempoFinal) << " m/s." << endl;
    return 0;
}