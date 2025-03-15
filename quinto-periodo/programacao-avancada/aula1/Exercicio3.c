/*
 * 3) Crie um programa que resolva a questão da função horária da posição do Movimento Retilíneo Uniforme.
 * Peça ao usuário que informe a quantidade de tempo para a seguinte função horária:
 *
 * S = 12 + 2.8 * t
 *
 * Seu programa deve ser capaz de ler dois instantes de tempo e exibir as respostas na tela.
 */

#include <stdio.h>

int main()
{
    float primeiroInstante, segundoInstante;
    printf("Digite o primeiro instante de tempo: ");
    scanf("%f", &primeiroInstante);
    printf("Digite o segundo instante de tempo: ");
    scanf("%f", &segundoInstante);

    printf("Para t = %.2f, S = %.2f\n", primeiroInstante, 12 + 2.8 * primeiroInstante);
    printf("Para t = %.2f, S = %.2f\n", segundoInstante, 12 + 2.8 * segundoInstante);

    return 0;
}
