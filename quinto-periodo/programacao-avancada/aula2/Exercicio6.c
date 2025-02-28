/*
 * 6) Faça um programa que calcule e exiba na tela os volumes de três esferas, sendo fornecido o valor
 * de seu raio (R). A fórmula para o cálculo é:
 *
 *      V = 4/3 * PI * R 3
 *
 * Considere PI = 3.14159
 * Além disso, seu programa deve ser capaz de indicar qual dos volumes é o maior dentre todos.
 */
#include <stdio.h>

#define PI 3.14159

int main()
{
    int i;
    float maiorVolume, raio, volume;

    for (i = 0; i < 3; i++)
    {
        printf("Digite o raio da esfera: ");
        scanf("%f", &raio);

        volume = 4.00 / 3.00 * PI * raio * raio * raio;
        printf("Volume da esfera: %.2f \n", volume);

        if (volume > maiorVolume)
        {
            maiorVolume = volume;
        }
    }

    printf("\nO maior volume medido foi de %.2f\n", maiorVolume);

    return 0;
}
