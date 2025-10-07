#include <iostream>
#include <cstring> // Incluindo a biblioteca para a função strlen
using namespace std;

#define LIMITE_CARACTERE 50
#define LIMITE_FILA 50

typedef struct
{
    char memoria[LIMITE_FILA];
    int topo;
} Stack;

void init(Stack &s)
{
    s.topo = -1;
}

void push(Stack &s, char el)
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

char pop(Stack &s)
{
    if (s.topo - 1 < -1)
    {
        cout << "Pilha vazia!" << endl;
        return '-';
    }
    char el = s.memoria[s.topo];
    s.topo--;
    return el;
}

bool isEmpty(Stack &s)
{
    return s.topo == -1;
}

bool verificarBalanceamento(char equacao[])
{
    Stack s;
    init(s);

    for (int i = 0; i < strlen(equacao); i++)
    { // Usando strlen
        char c = equacao[i];

        if (c == '(' || c == '[' || c == '{')
        {
            push(s, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (isEmpty(s))
            {
                return false;
            }
            char topo = pop(s);
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{'))
            {
                return false;
            }
        }
    }

    return isEmpty(s);
}

int main()
{
    char equacao[LIMITE_CARACTERE];
    cout << "Digite a equação para verificar se está balanceada: ";
    cin >> equacao;

    if (verificarBalanceamento(equacao))
    {
        cout << "Balanceado" << endl;
    }
    else
    {
        cout << "Não balanceado" << endl;
    }

    return 0;
}
