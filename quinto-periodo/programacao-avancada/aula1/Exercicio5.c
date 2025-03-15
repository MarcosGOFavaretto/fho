/*
 * 5) Renatinho quer calcular e mostrar a quantidade de litros de combustível gastos em uma viagem,
 * utilizando um automóvel que faz 13.8 KM/L. Para isso, ele pediu sua ajuda para desenvolver um programa.
 * Para efetuar o cálculo, é necessário informar o tempo gasto na viagem (em horas) e a velocidade média
 * durante ela (em km/h). Assim, pode-se obter a distância percorrida e, em seguida, calcular quantos litros seriam necessários.
 *
 * Mostre o valor com 3 casas decimais após o ponto.
 */

#include <stdio.h>

#define CONSUMO 13.8

int main()
{
    float tempo, velocidade, distancia, litros;

    printf("Digite o tempo gasto na viagem (horas): ");
    scanf("%f", &tempo);

    printf("Digite a velocidade média (km/h): ");
    scanf("%f", &velocidade);

    distancia = tempo * velocidade;
    litros = distancia / CONSUMO;

    printf("Quantidade de litros gastos: %.3f\n", litros);

    return 0;
}
