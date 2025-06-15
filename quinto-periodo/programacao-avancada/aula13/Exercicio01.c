#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Ponto;

typedef struct
{
    Ponto superiorEsquerdo;
    Ponto inferiorDireito;
} Retangulo;

double distancia(Ponto p1, Ponto p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Ponto maisProximoOrigem(Ponto p1, Ponto p2)
{
    Ponto origem = {0.0, 0.0};
    double d1 = distancia(p1, origem);
    double d2 = distancia(p2, origem);
    return (d1 < d2) ? p1 : p2;
}

int estaContido(Ponto p, Retangulo r)
{
    return (p.x >= r.superiorEsquerdo.x && p.x <= r.inferiorDireito.x &&
            p.y <= r.superiorEsquerdo.y && p.y >= r.inferiorDireito.y);
}

int main()
{
    Ponto p1, p2;
    Retangulo r;

    printf("Entre com as coordenadas x e y do primeiro ponto: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Entre com as coordenadas x e y do segundo ponto: ");
    scanf("%lf %lf", &p2.x, &p2.y);

    printf("Entre com as coordenadas x e y do ponto da superior esquerda do retangulo: ");
    scanf("%lf %lf", &r.superiorEsquerdo.x, &r.superiorEsquerdo.y);

    printf("Entre com as coordenadas x e y do ponto da inferior direita do retangulo: ");
    scanf("%lf %lf", &r.inferiorDireito.x, &r.inferiorDireito.y);

    printf("Distancia entre os dois pontos: %lf\n", distancia(p1, p2));

    Ponto prox = maisProximoOrigem(p1, p2);
    printf("Ponto mais proximo a origem: (%lf, %lf)\n", prox.x, prox.y);

    if (estaContido(p1, r))
        printf("O ponto (%lf, %lf) esta contido no retangulo!\n", p1.x, p1.y);
    else
        printf("O ponto (%lf, %lf) nao esta contido no retangulo!\n", p1.x, p1.y);

    if (estaContido(p2, r))
        printf("O ponto (%lf, %lf) esta contido no retangulo!\n", p2.x, p2.y);
    else
        printf("O ponto (%lf, %lf) nao esta contido no retangulo!\n", p2.x, p2.y);

    return 0;
}
