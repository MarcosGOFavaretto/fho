/*
 * 2) Faça um programa que receba uma palavra e a imprima de
 * trás-para-frente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[50];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);
    for (int i = tamanho - 1; i >= 0; i--)
    {
        printf("%c", palavra[i]);
    }

    printf("\n");

    return 0;
}
