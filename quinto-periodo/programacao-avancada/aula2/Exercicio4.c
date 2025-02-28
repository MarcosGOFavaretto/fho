/*
 * 4) Crie um programa que resolva a questão da função horária da posição do Movimento Retilíneo
 * Uniforme:
 *
 *  S = 20 + 3 * t
 *
 * Leia dois instantes de tempo e exiba as respostas na tela para cada um. Verifique se os resultados
 * são iguais, caso contrário, indique o maior e o menor.
 */
#include <stdio.h>

int main()
{
    int tempo1, tempo2, espaco1, espaco2;

    // Primeira entrada
    printf("Digite o primeiro instante de tempo: ");
    scanf("%d", &tempo1);

    espaco1 = 20 + 3 * tempo1;

    printf("Posição no tempo %d: %d\n", tempo1, espaco1);
    //

    // Segunda entrada
    printf("Digite o segundo instante de tempo: ");
    scanf("%d", &tempo2);

    espaco2 = 20 + 3 * tempo2;

    printf("Posição no tempo %d: %d\n", tempo2, espaco2);
    //

    if (espaco1 > espaco2)
    {
        printf("A maior posição é: %d\n", espaco1);
        printf("A menor posição é: %d\n", espaco2);
    }
    else if (espaco2 > espaco1)
    {
        printf("A maior posição é: %d\n", espaco2);
        printf("A menor posição é: %d\n", espaco1);
    }
    else
    {
        printf("As posições são iguais.\n");
    }

    return 0;
}
