/*
 * 3) Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade
 * deste item. A seguir, calcule e mostre o valor da conta a pagar.
 *
 * CODIGO | ESPECIFICACAO | PREÇO |
 * 1 | Cachorro Quente | R$ 04,00 |
 * 2 | X-Salada | R$ 04,50 |
 * 3 | X-Bacon | R$ 05,00 |
 * 4 | Torrada Simples | R$ 02,00 |
 * 5 | Refrigerante | R$ 01,50 |
 *
 */
#include <stdio.h>

#define CODIGO_CACHORRO_QUENTE 1
#define CODIGO_X_SALADA 2
#define CODIGO_X_BACON 3
#define CODIGO_TORRADA_SIMPLES 4
#define CODIGO_REFRIGERANTE 5

#include <stdio.h>

int main()
{
    int codigo, quantidade;
    float total;

    printf("Digite o códig do item: ");
    scanf("%d", &codigo);

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    if (codigo == CODIGO_CACHORRO_QUENTE)
    {
        total = quantidade * 4.00;
    }
    else if (codigo == CODIGO_X_SALADA)
    {
        total = quantidade * 4.50;
    }
    else if (codigo == CODIGO_X_BACON)
    {
        total = quantidade * 5.00;
    }
    else if (codigo == CODIGO_TORRADA_SIMPLES)
    {
        total = quantidade * 2.00;
    }
    else if (codigo == CODIGO_REFRIGERANTE)
    {
        total = quantidade * 1.50;
    }
    else
    {
        printf("Codigo invalido!!");
        return 1;
    }

    printf("Total: R$ %.2f\n", total);

    return 0;
}
