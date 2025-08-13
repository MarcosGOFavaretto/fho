#include <iostream>
using namespace std;

/**
 * 7) Faça uma função que recebe um valor inteiro e verifica se o valor é positivo ou negativo. A função
 * deve retornar um valor booleano para o programa principal.
 */

bool isPositivo(int candidato)
{
    return candidato >= 0;
}

int main()
{

    int candidato = 0;
    cout << "Informe um número: " << endl;
    cin >> candidato;

    cout
        << "O número é "
        << (isPositivo(candidato) ? "Positivo" : "Negativo")
        << "!"
        << endl;

    return 0;
}