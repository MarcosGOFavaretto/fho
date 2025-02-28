/*
 * 7) Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto
 * em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está sobre um
 * dos eixos cartesianos ou na origem (x = y = 0).
 *
 *   Q2 |  Q1
 * -----|-----
 *   Q3 |  Q4
 *
 * Se o ponto estiver na origem, escreva a mensagem “Origem”.
 * Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.
 */
#include <stdio.h>

int main()
{
    float x, y;

    printf("Digite as coordenadas x: \n");
    scanf("%f", &x);

    printf("Digite as coordenadas y: \n");
    scanf("%f", &y);

    if (x == 0 && y == 0)
    {
        printf("Origem\n");
    }
    else if (x == 0)
    {
        printf("Origem no eixo Y\n");
    }
    else if (y == 0)
    {
        printf("Origem no eixo X\n");
    }
    else if (x > 0 && y > 0)
    {
        printf("Quadrante 1\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("Quadrante 2\n");
    }
    else if (x < 0 && y < 0)
    {
        printf("Quadrante 3\n");
    }
    else
    {
        printf("Quadrante 4\n");
    }

    return 0;
}
