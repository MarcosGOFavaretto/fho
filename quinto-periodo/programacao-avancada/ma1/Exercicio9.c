#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VELOCIDADE_DA_LUZ 300000000

int main()
{

    float velocidade = 0.00;
    float dilatacao = 0.00;

    printf("Informe a velocidade do objeto (em m/s): ");
    scanf("%f", &velocidade);

    for (float i = 0.5; i <= 5; i = i + 0.5)
    {

        dilatacao = i * sqrt((1 - pow(velocidade / VELOCIDADE_DA_LUZ, 2)));
        printf("O tempo (observador) e %.2f e o dilatado e %.2f \n\n", i, dilatacao);
    }

    return 0;
}
