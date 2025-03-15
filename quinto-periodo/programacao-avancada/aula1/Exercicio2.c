#include <stdio.h>
#include <math.h>

int main()
{
    int idade, idade1, idade2;

    printf("Digite sua idade em anos: ");
    scanf("%d", &idade);

    printf("A idade de %d anos corresponde, aproximadamente, a %d dias de vida.\n", idade, idade * 365);

    printf("Digite a primeira idade: ");
    scanf("%d", &idade1);

    printf("Digite a segunda idade: ");
    scanf("%d", &idade2);

    if (idade1 > idade2)
        printf("A primeira pessoa é a mais velha.\n");
    else
        printf("A segunda pessoa é a mais velha.\n");

    return 0;
}