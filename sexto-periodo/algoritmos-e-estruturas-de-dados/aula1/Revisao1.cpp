#include <iostream>
using namespace std;

int main()
{
    // cout é utilizado para escritada de informação na tela
    cout << "Hello World!\n";
    cout << "Nosso texto - frase \n\t"
         << "\nNosso texto - frase2"
         << endl;

    // Definindo uma variável
    int valor = 10;
    cout << "Valor da variável: " << valor << endl;
    //

    // Lendo valores do teclado e atribuindo a uma variável
    cout << "informe um novo valor para a variável: \n";
    cin >> valor;
    //

    cout << "O novo valor é: " << valor << endl;

    float mediaFinal;

    cout << "Informe a média desejada da disciplina de ED: " << endl;
    cin >> mediaFinal;

    // Exibindo o texto com os dois valores
    cout << "O valor da primeira variável é: " << valor << " .\nO valor da segunda variável é: " << mediaFinal << "." << endl;
    //

    return 0;
}