#include <iostream>
using namespace std;

/**
 * A MODA de um vetor de números é o número m no vetor que é repetido com maior freqüência.
 * Se mais de um número for repetido com freqüência máxima igual, não existirá uma moda.
 * Escreva uma função em C que aceite um vetor de números e retorne a moda ou uma indicação de que a moda não existe.
 */

int calcularModa(int vetor[], int tamanho) {
    int valoresUnicos[100];
    int frequencias[100];
    int numUnicos = 0;

    // Contar as frequências
    for (int i = 0; i < tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < numUnicos; j++) {
            if (vetor[i] == valoresUnicos[j]) {
                frequencias[j]++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            valoresUnicos[numUnicos] = vetor[i];
            frequencias[numUnicos] = 1;
            numUnicos++;
        }
    }

    // Encontrar a maior frequência
    int maiorFreq = 0;
    int indiceModa = -1;
    int empates = 0;

    for (int i = 0; i < numUnicos; i++) {
        if (frequencias[i] > maiorFreq) {
            maiorFreq = frequencias[i];
            indiceModa = i;
            empates = 0;
        } else if (frequencias[i] == maiorFreq) {
            empates++;
        }
    }

    if (empates > 0) {
        return -1;  // Não existe moda
    } else {
        return valoresUnicos[indiceModa];
    }
}

int main() {
    int vetor[] = {1, 2, 2, 3, 4, 2, 5, 3, 3, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int resultado = calcularModa(vetor, tamanho);

    if (resultado == -1) {
        cout << "Não existe moda no vetor." << endl;
    } else {
        cout << "A moda do vetor é: " << resultado << endl;
    }

    return 0;
}
