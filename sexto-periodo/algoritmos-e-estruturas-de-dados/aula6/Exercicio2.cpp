#include <iostream>
using namespace std;

#define LIMITE_CARACTERE 50
#define LIMITE_FILA 50

/**
 * 2. Conversão de Decimal para Binário
 * Crie uma função que converte um número decimal para binário usando uma pilha. O algoritmo deve
 * empilhar os restos das divisões por 2 e depois desempilhar para formar o número binário.
 * Exemplo com o número 25:
 * • 25 / 2 = 12, resto 1 → empilha 1
 * • 12 / 2 = 6, resto 0 → empilha 0
 * • 6 / 2 = 3, resto 0 → empilha 0
 * • 3 / 2 = 1, resto 1 → empilha 1
 * • 1 / 2 = 0, resto 1 → empilha 1
 * Desempilhando: 11001 (que é 25 em binário)
 */

typedef struct
{
    int memoria[LIMITE_FILA];
    int topo;
} Stack;

void init(Stack &s)
{
    s.topo = -1;
}

void push(Stack &s, int el)
{
    if (s.topo + 1 == LIMITE_FILA)
    {
        cout << "Pilha cheia!" << endl;
    }
    else
    {
        s.topo++;
        s.memoria[s.topo] = el;
    }
}

int pop(Stack &s)
{
    if (s.topo - 1 < -1)
    {
        cout << "Pilha vazia!" << endl;
        return -1;
    }
    int el = s.memoria[s.topo];
    s.topo--;
    return el;
}

bool isEmpty(Stack &s)
{
    return s.topo == -1;
}

void decimalParaBinario(int numero)
{
    Stack s;
    init(s);

    if (numero == 0)
    {
        cout << "0";
        return;
    }

    while (numero > 0)
    {
        push(s, numero % 2); // sanvando o resto
        numero = numero / 2; // dividindo por 2 para continuar até o fim.
    }

    while (!isEmpty(s))
    {
        cout << pop(s);
    }
    cout << endl;
}

int main()
{
    int numero;
    cout << "Digite um número decimal: ";
    cin >> numero;

    cout << "O número " << numero << " em binário é: ";
    decimalParaBinario(numero);

    return 0;
}
