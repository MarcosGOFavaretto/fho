#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUANTIDADE_NUMEROS 20

int main()
{

    int numeros[QUANTIDADE_NUMEROS];
    double desvio = 0.0;
    double media = 0.0;

    for (int i = 0; i < QUANTIDADE_NUMEROS; i++)
    {
        printf("Informe o %dº numero: ", i + 1);
        scanf("%d", &numeros[i]);
        media = media + numeros[i];
    }

    media = media / QUANTIDADE_NUMEROS;

    for (int i = 0; i < QUANTIDADE_NUMEROS; i++)
    {
        desvio = pow((i - media * i), 2);
    }

    desvio = sqrt(desvio / QUANTIDADE_NUMEROS);

    printf("O desvio padrão é: %.2f", desvio);
    return 0;
}
