/*
 * 8) Faça um programa que calcule a RESISTÊNCIA de um equipamento dado as seguintes informações:
 *
 * a. O usuário irá informar a tensão;
 * b. O usuário irá informar a potência do equipamento;
 * Sabendo que:
 *
 * Equação 1: P(potência) = U(tensão).I(corrente)
 * Equação 2: U(tensão)=R(resistência).I(corrente)
 *
 * Manipule as equações de tal forma a encontrar a equação para descobrir a resistência.
 */
#include <stdio.h>

int main()
{
    float u, p, r;

    printf("Digite a tensão (V): ");
    scanf("%f", &u);

    printf("Digite a potência (W): ");
    scanf("%f", &p);

    if (p == 0)
    {
        printf("Potência inválida! Não é possível calcular a resistência.\n");
    }
    else
    {
        r = (u * u) / p;
        printf("A resistência do equipamento é: %.2f ohms\n", r);
    }

    return 0;
}
