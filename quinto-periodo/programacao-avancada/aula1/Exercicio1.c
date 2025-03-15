#include <stdio.h>
#include <math.h>

int main()
{
    int primeiroNumero, segundoNumero;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &primeiroNumero);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &segundoNumero);

    printf("\n");
    printf("Dobro do primeiro número: %d \n", 2 * primeiroNumero);
    printf("Multiplicação entre os dois números: %d \n", primeiroNumero * segundoNumero);
    printf("Resto da divisão do primeiro pelo segundo: %d \n", primeiroNumero % segundoNumero);
    printf("Divisão inteira do primeiro pelo segundo: %d \n", primeiroNumero / segundoNumero);

    return 0;
}