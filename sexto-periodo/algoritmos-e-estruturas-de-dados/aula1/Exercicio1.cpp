#include <iostream>
using namespace std;

/**
 * 1) Escreva um programa simples C++ para calcular o raio de uma esfera (v = 4/3 x Pi x R3). Os valores
 * devem ser informados via teclado.
 */
int main()
{

    const int PI = 3.1415;

    float raio = 0.0;
    cout << "Informe o raio: ";
    cin >> raio;

    float volumeEsfera = 4 / 3 * PI * (raio * raio * raio);

    cout << "O volume da esfera é: " << volumeEsfera << endl;

    return 0;
}