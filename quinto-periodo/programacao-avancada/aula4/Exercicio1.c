#include <stdio.h>
#define ANOS_APURACAO 12
#define TRIPLO 3
#define DOBRO 2
/*
 * Suponha que a conta de energia de uma família está duplicando em anos ímpares e
 * triplicando em anos pares. Dessa forma, deseja-se saber os valores das contas ao longo de 12 anos.
 *
 * Assim, seu programa deve pedir para a família informar qual foi o valor gasto no primeiro ano e
 * guardar na primeira posição de um vetor que representará os anos em questão. Depois, preencha esse
 * vetor com os valores das contas para os demais anos através de um laço de repetição. Também, seu
 * programa deverá calcular qual foi a média de gasto com energia ao longo dos 12 anos.
 *
 * No final, seu programa deverá exibir o seguinte relatório:
 *      O histórico completo de contas (todos os valores do vetor);
 *      A frase "A media geral de gastos ao longo dos 12 anos foi: R$XXX.XX"
 *
 * Exemplo: Valor informado pela família: 1, seu vetor deverá conter: 1, 2, 6, 12, 36... e assim
 * sucessivamente.
 */
int main()
{

    float lancamentos[ANOS_APURACAO], valorAnoAnterior, fatorMultiplicacao, media;
    int i = 0;

    printf("Informe o valor que sua família gastou no ano atual: \n");
    scanf("%f", &valorAnoAnterior);

    lancamentos[i++] = valorAnoAnterior;

    for (; i < ANOS_APURACAO; i++)
    {
        if (i % 2 == 0)
        {
            fatorMultiplicacao = TRIPLO;
        }
        else
        {
            fatorMultiplicacao = DOBRO;
        }

        valorAnoAnterior = valorAnoAnterior * fatorMultiplicacao;
        lancamentos[i] = valorAnoAnterior;
    }

    printf("Histórico: \n");
    for (int i = 0; i < ANOS_APURACAO; i++)
    {
        printf("%.2f ", lancamentos[i]);
        media = media + lancamentos[i];
    }
    printf("\n");

    media = media / ANOS_APURACAO;

    printf("A media geral de gastos ao longo dos 12 anos foi: R$ %.2f \n", media);

    return 0;
}