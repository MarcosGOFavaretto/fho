#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 4

int main()
{

    int valores[QTD_LINHAS][QTD_COLUNAS];
    int diagonalPrincipal[QTD_LINHAS];
    int somaDiagonalPrincipal = 0;

    printf("Informe a matriz:\n");

    for (int i = 0; i < QTD_LINHAS; i++)
    {
        for (int j = 0; j < QTD_COLUNAS; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &valores[i][j]);

            if (i == j) {
                diagonalPrincipal[i] = valores[i][j];
            }
        }
    }

    printf("A diagonal principal é: ");
    for (int i = 0; i < QTD_LINHAS; i++)
    {
        printf("%d ", diagonalPrincipal[i]);
        somaDiagonalPrincipal += diagonalPrincipal[i];
    }

    printf("\nO dobro da diagonal é: ");
    for (int i = 0; i < QTD_LINHAS; i++)
    {
        printf("%d ", diagonalPrincipal[i] * 2);
    }

    printf("\nA somatória dos valores é: %d", somaDiagonalPrincipal);
    printf("\nA média é: %d \n\n", somaDiagonalPrincipal / QTD_LINHAS);

    printf("Matriz inserida: \n");
    for (int i = 0; i < QTD_LINHAS; i++)
    {
        for (int j = 0; j < QTD_COLUNAS; j++)
        {
            printf("%d ", valores[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}