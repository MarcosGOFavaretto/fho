/*
 * 3) Faça um que solicite ao usuário uma frase de - no máximo 150
 * caracteres - e conte quantas vogais (a, e, i , o, u) existem nela,
 * considerando tanto maiúsculas quanto minúsculas.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char frase[150];
    int qtdVogais = 0;

    printf("Digite uma frase (máximo de 150 caracteres): ");
    fgets(frase, sizeof(frase), stdin);

    for (int i = 0; frase[i] != '\0'; i++)
    {
        char letra = frase[i];
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        {
            qtdVogais++;
        }
    }
    printf("Quantidade de vogais: %d\n", qtdVogais);

    return 0;
}
