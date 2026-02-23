#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int TAM = 15;
int *VETOR = NULL;

clock_t startTime;

void startClock()
{
    startTime = clock();
}

double stopClock()
{
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

void gerarNumerosVetor()
{
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        VETOR[i] = rand() % (TAM + 1);
    }
}

void merge(int v[], int inicio, int meio, int fim)
{
    int i = inicio, j = meio + 1, k = 0;
    int tamTemp = fim - inicio + 1;
    int *temp = new int[tamTemp];

    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= meio)
        temp[k++] = v[i++];
    while (j <= fim)
        temp[k++] = v[j++];

    for (int x = 0; x < tamTemp; x++)
        v[inicio + x] = temp[x];

    delete[] temp;
}

void mergeSort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

struct NoLista
{
    int valor;
    NoLista *prox;
};

NoLista *head = NULL;

void inserirFimLista(int valor)
{
    NoLista *novo = new NoLista();
    novo->valor = valor;
    novo->prox = NULL;

    if (head == NULL)
    {
        head = novo;
        return;
    }

    NoLista *aux = head;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;
}

struct NoArvore
{
    int valor;
    NoArvore *esq;
    NoArvore *dir;
};

NoArvore *raiz = NULL;

void inserirArvore(int valor)
{
    NoArvore *novo = new NoArvore();
    novo->valor = valor;
    novo->esq = novo->dir = NULL;

    if (raiz == NULL)
    {
        raiz = novo;
        return;
    }

    NoArvore *aux = raiz;
    while (true)
    {
        if (valor <= aux->valor)
        {
            if (aux->esq == NULL)
            {
                aux->esq = novo;
                return;
            }
            aux = aux->esq;
        }
        else
        {
            if (aux->dir == NULL)
            {
                aux->dir = novo;
                return;
            }
            aux = aux->dir;
        }
    }
}

void converterListaParaArvore()
{
    NoLista *aux = head;
    while (aux != NULL)
    {
        inserirArvore(aux->valor);
        aux = aux->prox;
    }
}

void inOrder(NoArvore *r)
{
    if (r != NULL)
    {
        inOrder(r->esq);
        cout << r->valor << " ";
        inOrder(r->dir);
    }
}

NoArvore *buscarNaArvore(int valor)
{
    NoArvore *aux = raiz;
    while (aux != NULL)
    {
        if (valor == aux->valor)
            return aux;
        if (valor < aux->valor)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return NULL;
}

int buscaVetor(int valor)
{
    for (int i = 0; i < TAM; i++)
    {
        if (VETOR[i] == valor)
            return i;
    }
    return -1;
}

double executarMergeSort()
{
    gerarNumerosVetor();

    startClock();
    mergeSort(VETOR, 0, TAM - 1);
    double tempo = stopClock();

    cout << "Vetor ordenado: \n";
    for (int i = 0; i < TAM; i++)
    {
        cout << VETOR[i] << " ";
    }
    cout << "\n";

    return tempo;
}

double executarListaArvore()
{
    head = NULL;
    raiz = NULL;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        inserirFimLista(rand() % (TAM + 1));
    }

    startClock();
    converterListaParaArvore();

    cout << "Árvore ordenada: \n";
    inOrder(raiz);
    cout << "\n";

    return stopClock();
}

int main()
{
    VETOR = new int[TAM];
    int opcao;

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Executar apenas MERGE SORT\n";
        cout << "2 - Executar apenas LISTA + ARVORE\n";
        cout << "3 - Executar as duas abordagens e comparar\n";
        cout << "4 - Buscar um valor no VETOR\n";
        cout << "5 - Buscar um valor na ARVORE\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 0)
            break;

        if (opcao == 1)
        {
            double t = executarMergeSort();
            cout << "Tempo MERGE SORT: " << t << " segundos\n";
        }

        else if (opcao == 2)
        {
            double t = executarListaArvore();
            cout << "Tempo LISTA + ARVORE: " << t << " segundos\n";
        }

        else if (opcao == 3)
        {
            double t1 = executarMergeSort();
            cout << "Tempo MERGE SORT: " << t1 << " s\n";

            double t2 = executarListaArvore();
            cout << "Tempo LISTA + ARVORE: " << t2 << " s\n";
        }

        else if (opcao == 4)
        {
            int x;
            cout << "Valor para buscar: ";
            cin >> x;

            startClock();
            int pos = buscaVetor(x);
            double t = stopClock();

            if (pos == -1)
                cout << "Valor NAO encontrado\n";
            else
                cout << "Valor encontrado na posicao " << pos << "\n";

            cout << "Tempo de busca no vetor: " << t << " s\n";
        }

        else if (opcao == 5)
        {
            int x;
            cout << "Valor para buscar: ";
            cin >> x;

            startClock();
            NoArvore *p = buscarNaArvore(x);
            double t = stopClock();

            if (p == NULL)
                cout << "Valor NAO encontrado\n";
            else
                cout << "Valor encontrado na arvore!\n";

            cout << "Tempo de busca na arvore: " << t << " s\n";
        }

        else
        {
            cout << "Opcao invalida!\n";
        }
    }

    delete[] VETOR;
    return 0;
}
