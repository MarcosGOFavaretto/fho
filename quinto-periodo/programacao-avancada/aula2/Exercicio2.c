/*
 * 2) Leia 2 valores inteiros (A e B). Após, o programa deve mostrar uma mensagem "Sao Multiplos" ou
 * "Nao sao Multiplos", indicando se os valores lidos são múltiplos entre si.
 *
 * Lembre-se de utilizar o operador de resto da divisão (%).
 */
#include <stdio.h>

int main()
{
    int valorA, valorB;

    printf("Digite o primeiro número: ");
    scanf("%d", &valorA);

    printf("Digite o segundo número: ");
    scanf("%d", &valorB);

    if (valorA % valorB == 0 || valorB % valorA == 0)
    {
        printf("Sao Multiplos\n");
    }
    else
    {
        printf("Nao sao Multiplos\n");
    }

    return 0;
}
