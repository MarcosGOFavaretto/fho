/*
 * 5) Pesquise o uso da biblioteca <string.h> e como descobrir o tamanho
 * de uma string através das funções dessa biblioteca. Faça um programa
 * exemplo que peça o nome de uma pessoa e devolva o tamanho desse nome.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nome[50];

    printf("Digite seu nome: \n");
    fgets(nome, sizeof(nome), stdin);
    int qtdCaracteres = 0;

    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ') // ignora espacos
        {
            qtdCaracteres++;
        }
    }

    printf("Quantidade de caracteres: %d \n", qtdCaracteres);

    return 0;
}
