/*
 * 2) Ler um número inteiro n. Escrever a soma de todos os números pares de 2 até n.
 */

#include <stdio.h>

int main()
{
    int n, soma = 0;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i += 2)
    {
        soma += i;
    }

    printf("A soma dos números pares de 2 até %d é: %d\n", n, soma);
    return 0;
}