/*
 * 4) Faça um programa que calcule e exiba na tela os volumes de três esferas, sendo fornecido o valor de seu raio (R).
 * A fórmula para o cálculo é:
 *
 * V = (4.0/3) * PI * R^3
 *
 * Considere PI = 3.14159.
 */

#include <stdio.h>
#define PI 3.14159

int main()
{
    float r1, r2, r3;
    printf("Digite os valores dos três raios: ");
    scanf("%f %f %f", &r1, &r2, &r3);

    printf("Volume da primeira esfera: %.2f\n", (4.0 / 3) * PI * r1 * r1 * r1);
    printf("Volume da segunda esfera: %.2f\n", (4.0 / 3) * PI * r2 * r2 * r2);
    printf("Volume da terceira esfera: %.2f\n", (4.0 / 3) * PI * r3 * r3 * r3);

    return 0;
}
