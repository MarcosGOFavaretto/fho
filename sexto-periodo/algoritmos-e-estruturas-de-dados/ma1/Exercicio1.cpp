#include <iostream>

#define TAMANHO_PILHA 10

using namespace std;

/**
 * 1) Implemente duas estruturas PILHAS em um ÚNICO VETOR. Comente no próprio código qual é o
 * TAD definido para essa estrutura. Dica: use dois indicadores de topo e crie cada pilha em
 * extremidades opostas desse vetor
 */

typedef struct
{
    /**
     * Como estrutura do TAD, optei por manter apenas um vetor, de
     * tamanho "TAMANHO_PILHA" e implementar o uso de topos diferentes.
     */
    int memoria[TAMANHO_PILHA];
    int topoPilhaUm, topoPilhaDois;
} Stacks;

void init(Stacks &pilhas)
{
    pilhas.topoPilhaUm = -1;
    pilhas.topoPilhaDois = TAMANHO_PILHA;
}

void push(Stacks &pilhas, int elemento, bool isPrimeiraPilha)
{

    bool isLimitePilhasAtingido = pilhas.topoPilhaDois - pilhas.topoPilhaUm == 1;
    if (isLimitePilhasAtingido)
    {
        cout << "O limite das pilhas foi atingido!" << endl;
        return;
    }

    if (isPrimeiraPilha)
    {
        pilhas.memoria[++pilhas.topoPilhaUm] = elemento;
    }
    else
    {
        pilhas.memoria[--pilhas.topoPilhaDois] = elemento;
    }
}

bool isEmpty(Stacks &pilhas)
{
    return (pilhas.topoPilhaUm == -1) && (pilhas.topoPilhaDois == TAMANHO_PILHA);
}

int pop(Stacks &pilhas, bool isPrimeiraPilha)
{

    if (isEmpty(pilhas))
    {
        cout << "A pilha está vazia!" << endl;
        return -1;
    }

    if (isPrimeiraPilha)
        return pilhas.memoria[pilhas.topoPilhaUm--];

    return pilhas.memoria[pilhas.topoPilhaDois++];
}

void show(Stacks &pilhas)
{

    cout << "Estado atual das pilhas" << endl;
    cout << "Primeira pilha" << endl;
    for (int i = pilhas.topoPilhaUm; i >= 0; i--)
    {
        cout << pilhas.memoria[i] << endl;
    }

    cout << "Segunda pilha" << endl;
    for (int i = pilhas.topoPilhaDois; i < TAMANHO_PILHA; i++)
    {
        cout << pilhas.memoria[i] << endl;
    }
    cout << "\n"
         << endl;
}

int main()
{

    Stacks pilhas;
    init(pilhas);

    cout << "Verificando se a pilha está vazia..." << endl;
    cout << "Esta vazia? " << (isEmpty(pilhas) ? "SIM" : "NÃO") << endl;

    cout << "\nPopulando as pilhas..." << endl;
    push(pilhas, 1, true);
    push(pilhas, 2, false);
    push(pilhas, 3, true);
    push(pilhas, 4, false);
    push(pilhas, 5, true);
    push(pilhas, 6, false);
    push(pilhas, 7, true);
    push(pilhas, 8, false);
    push(pilhas, 9, true);
    push(pilhas, 10, false);
    show(pilhas);

    cout << "Estourando o limite da pilha tentando inserir o elemento '99'..." << endl;
    push(pilhas, 99, true); // 11° elemento

    cout << "\nRemovendo o elemento: " << pop(pilhas, true) << endl;
    cout << "Removendo o elemento: " << pop(pilhas, false) << endl;

    cout << "\nTentando incluir o elemento novamente..." << endl;
    push(pilhas, 99, true);
    show(pilhas);

    cout << "Verificando se a pilha está vazia..." << endl;
    cout << "Esta vazia? " << (isEmpty(pilhas) ? "SIM" : "NÃO") << endl;

    return 0;
}