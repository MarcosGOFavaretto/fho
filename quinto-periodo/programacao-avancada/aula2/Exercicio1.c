/*
 * 1) Faça um programa que calcule sua idade em dias e exiba a resposta na tela respeitando a seguinte
 * formatação:
 *
 * “A idade de 35 anos corresponde, aproximadamente, 12775 dias de vida”.
 *
 * Considere que um ano possua 365 dias. Depois, modifique o programa para aceitar duas idades e
 * descobrir qual pessoa é a mais velha.
 */
#include <stdio.h>

#define QUANTIDADE_DE_DIAS_NO_ANO 365

int main()
{
    int idade1, idade2, idadeEmDias1, idadeEmDias2;

    // Primeira pessoa
    printf("Digite a idade da primeira pessoa: ");
    scanf("%d", &idade1);

    idadeEmDias1 = idade1 * QUANTIDADE_DE_DIAS_NO_ANO;
    printf("A idade de %d anos corresponde, aproximadamente, a %d dias.\n", idade1, idadeEmDias1);
    //

    // Segunda pessoa
    printf("Digite a idade da segunda pessoa: ");
    scanf("%d", &idade2);

    idadeEmDias2 = idade2 * QUANTIDADE_DE_DIAS_NO_ANO;
    printf("A idade de %d anos corresponde, aproximadamente, a %d dias.\n", idade2, idadeEmDias2);
    //

    if (idade1 > idade2)
    {
        printf("A primeira pessoa é mais velha.\n");
    }
    else if (idade1 < idade2)
    {
        printf("A segunda pessoa é mais velha.\n");
    }
    else
    {
        printf("As duas pessoas têm a mesma idade.\n");
    }

    return 0;
}
