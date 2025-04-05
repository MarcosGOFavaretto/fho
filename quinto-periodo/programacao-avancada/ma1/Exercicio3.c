#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    float resultado = 0;

    printf("Informe um numero inteiro e positivo: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("ERRO: Numeros negativos ou nulos nao sao permitidos!\n");
    }

    // TODO: impedir que o usuário informe números quebrados.

    for (int i = 1; i <= n; i++)
    {
        resultado = resultado + (1.00 / i);
    }

    printf("A harmonica do %d é: %.2f \n", n, resultado);
    return 0;
}