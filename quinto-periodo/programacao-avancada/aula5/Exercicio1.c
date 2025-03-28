/*
 * 1) Entre com um nome e imprima o nome somente se a primeira
 * letra do nome for 'a' (maiuscula ou minuscula).
 */

#include <stdio.h>

int main()
{
    char nome[30];

    printf("Digite seu nome: ");
    scanf("%s", nome);

    char primeiroCaractere = nome[0];
    if (primeiroCaractere == 'A' || primeiroCaractere == 'a')
    {
        printf("%s\n", nome);
    }

    return 0;
}
