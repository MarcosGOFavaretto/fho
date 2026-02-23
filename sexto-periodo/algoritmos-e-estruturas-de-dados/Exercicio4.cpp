#include <iostream>
using namespace std;

#define LIMITE_CARACTERE 100
#define LIMITE_QUEUE 50

/**
 * 3. Sistema de Impressão
 * Simule uma fila de impressão onde cada documento tem:
 * a. Nome do arquivo
 * b. Número de páginas
 * c. Tempo estimado de impressão
 * Implemente funções para adicionar documentos, processar impressão (remove da fila) e mostrar
 * tempo total estimado para processar toda a fila.
 */

typedef struct
{
    char nomeArquivo[LIMITE_CARACTERE];
    int numPaginas;
    int tempoEstimado;
} Documento;

typedef struct
{
    Documento queue[LIMITE_QUEUE];
    int inicio, fim;
} Queue;

void init(Queue &q)
{
    q.inicio = 0;
    q.fim = 0;
}

bool isFull(Queue &q)
{
    return q.fim == LIMITE_QUEUE;
}

bool isEmpty(Queue &q)
{
    return q.inicio == q.fim;
}

void adicionarDocumento(Queue &q, const char nomeArquivo[], int numPaginas, int tempoEstimado)
{
    if (isFull(q))
    {
        cout << "Queue cheia! Não é possível adicionar mais documentos." << endl;
        return;
    }
    strncpy(q.queue[q.fim].nomeArquivo, nomeArquivo, LIMITE_CARACTERE - 1);
    q.queue[q.fim].nomeArquivo[LIMITE_CARACTERE - 1] = '\0';
    q.queue[q.fim].numPaginas = numPaginas;
    q.queue[q.fim].tempoEstimado = tempoEstimado;
    q.fim++;
}

void processarDocumento(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue vazia! Não há documentos para processar." << endl;
        return;
    }
    Documento doc = q.queue[q.inicio];
    cout << "Processando documento: " << doc.nomeArquivo << endl;
    cout << "Número de páginas: " << doc.numPaginas << endl;
    cout << "Tempo estimado: " << doc.tempoEstimado << " minutos" << endl;
    q.inicio++;
}

void mostrarTempoTotal(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue vazia!" << endl;
        return;
    }

    int tempoTotal = 0;
    for (int i = q.inicio; i < q.fim; i++)
    {
        tempoTotal += q.queue[i].tempoEstimado;
    }
    cout << "Tempo total estimado para processar a queue: " << tempoTotal << " minutos" << endl;
}

int main()
{
    Queue queueImpressao;
    init(queueImpressao);

    int opcao;
    while (true)
    {
        cout << "\nSistema de Impressão" << endl;
        cout << "1. Adicionar documento" << endl;
        cout << "2. Processar documento" << endl;
        cout << "3. Mostrar tempo total estimado" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        if (opcao == 1)
        {
            char nomeArquivo[LIMITE_CARACTERE];
            int numPaginas, tempoEstimado;

            cout << "Digite o nome do arquivo: ";
            cin.getline(nomeArquivo, LIMITE_CARACTERE);
            cout << "Digite o número de páginas: ";
            cin >> numPaginas;
            cout << "Digite o tempo estimado de impressão (em minutos): ";
            cin >> tempoEstimado;

            adicionarDocumento(queueImpressao, nomeArquivo, numPaginas, tempoEstimado);
        }
        else if (opcao == 2)
        {
            processarDocumento(queueImpressao);
        }
        else if (opcao == 3)
        {
            mostrarTempoTotal(queueImpressao);
        }
        else if (opcao == 4)
        {
            cout << "Saindo do sistema de impressão..." << endl;
            break;
        }
        else
        {
            cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}
