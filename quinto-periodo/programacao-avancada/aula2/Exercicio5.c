/*
 * 5) Faça um programa que leia 6 valores. Estes valores serão somente negativos ou positivos
 * (desconsidere os valores nulos). A seguir, mostre a quantidade de valores positivos digitados.
 */
#include <stdio.h>

int main()
{
    int i, valor, qtdPositivos = 0;

    for (i = 0; i < 6; i++)
    {
        printf("Digite um número: ");
        scanf("%d", &valor);

        if (valor > 0)
        {
            qtdPositivos++;
        }
    }

    printf("Quantidade de valores positivos: %d\n", qtdPositivos);

    return 0;
}
