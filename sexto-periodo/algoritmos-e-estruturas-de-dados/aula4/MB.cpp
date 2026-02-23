#include <iostream>

using namespace std;

/**
 * 1) Escreva uma função recursiva que retorne o resultado de x^n (x elevado a n). Sua
 * função deve ter a chamada de float potencia(float x, int n).
 */
float potencia(float x, int n)
{

    if (n == 0)
        return 1;

    if (n == 1)
        return x;

    return x * potencia(x, n - 1);
}

int main()
{

    float base = 0.0;
    int elevado = 0;

    cout << "Informe a base: " << endl;
    cin >> base;

    cout << "Informe a potência: " << endl;
    cin >> elevado;

    cout << "O resultado é: " << potencia(base, elevado) << endl;

    return 0;
}