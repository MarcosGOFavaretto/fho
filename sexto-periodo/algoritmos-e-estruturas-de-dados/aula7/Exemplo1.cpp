#include <iostream>
using namespace std;

typedef struct No
{
    int valor;
    No *proximo;
} No;

No *head = NULL;

void inserir(int valor, int posicao)
{
    if (head == NULL && posicao == 0)
    {
        No *elemento = (No *)malloc(sizeof(No));
        elemento->valor = valor;
        elemento->proximo = NULL;
        head = elemento;
    }
    else
    {
        if (head != NULL && posicao == 0)
        {
            No *elemento = (No *)malloc(sizeof(No));
            elemento->valor = valor;
            elemento->proximo = head;

            head = elemento;
        }
        else
        {
            No *aux = head;

            for (int i = 0; i < posicao - 1; i++)
            {
                aux = aux->proximo;
            }

            No *elemento = (No *)malloc(sizeof(No));
            elemento->valor = valor;
            elemento->proximo = aux->proximo;

            aux->proximo = elemento;
        }
    }
}

void visualizar()
{
    No *auxiliar = head;
    while (auxiliar != NULL)
    {
        cout << auxiliar->valor << "\t";
        auxiliar = auxiliar->proximo;
    }

    cout << "\nFim!" << endl;
}

int main()
{
    inserir(1, 0);
    inserir(2, 0);
    inserir(3, 0);

    visualizar();

    inserir(3, 0);
    inserir(5, 0);
    inserir(6, 0);

    visualizar();

    inserir(44, 1);
    inserir(55, 5);

    visualizar();

    return 0;
}