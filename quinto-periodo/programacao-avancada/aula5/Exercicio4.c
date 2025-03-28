/*
 * 4) Faça um programa que transforme todas as vogais minúsculas
 * em uma frase de no máximo 10 caracteres para maiusculas.
 * Exemplo: "ola" ficaria "OlA".
 */

#include <stdio.h>

int main()
{
    char frase[100];

    printf("Digite uma frase (máximo de 100 caracteres): ");
    fgets(frase, sizeof(frase), stdin);

    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == 'a') { frase[i] = 'A'; }
        else if (frase[i] == 'e') { frase[i] = 'E'; }
        else if (frase[i] == 'i') { frase[i] = 'I'; }
        else if (frase[i] == 'o') { frase[i] = 'O'; }
        else if (frase[i] == 'u') { frase[i] = 'U'; }
    }

    printf("Frase com vogais maiúsculas: %s", frase);

    return 0;
}
