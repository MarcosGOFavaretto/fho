#include <iostream>
using namespace std;

void merge(int v[], int inicio, int meio, int fim) {
    int iEsq;
    int iDir;
    int k = 0;
    int* temp = (int*)malloc(sizeof(int) * (fim - inicio + 1));

    iEsq = inicio;
    iDir = meio + 1;

    while (iEsq <= meio && iDir <= fim) {
        if (v[iEsq] <= v[iDir]) {
            temp[k] = v[iEsq];
            k++;
            iEsq++;
        }
        else {
            temp[k] = v[iDir];
            k++;
            iDir++;
        }
    }

    while (iEsq <= meio) {
        temp[k] = v[iEsq];
        k++;
        iEsq++;
    }

    while (iDir <= fim) {
        temp[k] = v[iDir];
        k++;
        iDir++;
    }

    for (int i = inicio; i <= fim; i++) {
        v[i] = temp[i - inicio];
    }

    free(temp);
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

typedef struct NoArvore {
    int conteudo;
    NoArvore* esq;
    NoArvore* dir;
};

NoArvore* raiz = NULL;

void inserirNaArvore(int conteudo) {
    NoArvore* el = (NoArvore*)malloc(sizeof(NoArvore));
    el->conteudo = conteudo;
    el->dir = NULL;
    el->esq = NULL;

    if (raiz == NULL) {
        raiz = el;
    }
    else {
        NoArvore* aux = raiz;
        while (true) {
            if (conteudo <= aux->conteudo) {
                if (aux->esq == NULL) {
                    aux->esq = el;
                    return;
                }
                aux = aux->esq;
            }
            else {
                if (aux->dir == NULL) {
                    aux->dir = el;
                    return;
                }
                aux = aux->dir;
            }
        }
    }
}

NoArvore* buscarArvore(int conteudo) {
    NoArvore* aux = raiz;
    while (true) {
        if (aux->conteudo == conteudo)
            return aux;
        else if (conteudo <= aux->conteudo) {
            if (aux->esq == NULL)
                return NULL;
            aux = aux->esq;
        }
        else {
            if (aux->dir == NULL)
                return NULL;
            aux = aux->dir;
        }
    }
}

void inOrdemArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        inOrdemArvore(raiz->esq);
        cout << raiz->conteudo << "\t";
        inOrdemArvore(raiz->dir);
    }
}

void preOrdemArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->conteudo << "\t";
        preOrdemArvore(raiz->esq);
        preOrdemArvore(raiz->dir);
    }
}

void removerArvore(int elemento) {
    NoArvore* pai = NULL;
    NoArvore* aux = raiz;

    while (aux != NULL && elemento != aux->conteudo) {
        pai = aux;
        if (elemento <= aux->conteudo)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (aux == NULL) { 
        cout << "Não há elemento";
        return;
    }

    NoArvore* removido = aux;

    if (removido->esq == NULL && removido->dir == NULL) {
        if (pai == NULL)
            raiz = NULL;
        else if (pai->esq == removido) {
            pai->esq = NULL;
        }
        else {
            pai->dir = NULL;
        }
        free(removido);
        return;
    }

    if (removido->esq == NULL || removido->dir == NULL) {
        NoArvore* promovido = NULL;
        if (removido->esq != NULL)
            promovido = removido->esq;
        else
            promovido = removido->dir;

        if (pai->esq == removido)
            pai->esq = promovido;
        else
            pai->dir = promovido;

        free(removido);
        return;
    }

    NoArvore* paiSucessor = removido;
    NoArvore* sucessor = removido->dir;

    while (sucessor->esq != NULL) {
        paiSucessor = sucessor;
        sucessor = sucessor->esq;
    }

    removido->conteudo = sucessor->conteudo;

    if (paiSucessor == removido)
        paiSucessor->dir = sucessor->dir;
    else
        paiSucessor->esq = sucessor->dir;

    free(sucessor);
}

#include <iostream>

using namespace std;

typedef struct No {
    int valor;
    No *prox;
} No;

No* head = NULL;

void inserir(int valor, int posicao) 
{
    No* elemento = (No*)malloc(sizeof(No));
    elemento->valor = valor;
    if (posicao == 0) {
        elemento->prox = head;
        head = elemento;
    } else {
        No* aux = head;
        for (int i = 0; i < posicao - 1; i++)
            aux = aux->prox;
        elemento->prox = aux->prox;
        aux->prox = elemento;
    }
}

int remover(int posicao) {
    if (posicao == 0) {
        No* removido = head;
        head = removido->prox;
        int valor = removido->valor;
        free(removido);
        return valor;
    } else {
        No* aux = head;
        for (int i = 0; i < posicao - 1; i++) {
            aux = aux->prox;
        }
        No* removido = aux->prox;
        aux->prox = removido->prox;
        int valor = removido->valor;
        free(removido);
        return valor;
    }
}

void visualizar() 
{
    No* aux = head;
    while (aux != NULL) {
        cout << aux->valor << "\t";
        aux = aux->prox;
    }
}

int main()
{
    inserir(1, 0);
    inserir(2, 0);
    inserir(3, 0);

    visualizar();
    
    inserir(3, 0);
    inserir(5, 0);
    inserir(8, 0);
    cout << endl;
    visualizar();
    
    remover(0);
    
    cout << endl;
    visualizar();

    inserir(44, 1);
    inserir(55, 5);

    cout << endl;
    visualizar();

    cout << endl << "Conseguimos navegar em todos os elementos usando ponteiros!" << endl;
    cout << head->valor << endl;
    cout << endl;
    cout << head->prox->valor << endl;
    cout << endl;
    cout << head->prox->prox->valor << endl;
    cout << endl;
    cout << head->prox->prox->prox->valor << endl;

    return 0;
}


int main() {
    inserirNaArvore(12);
    inserirNaArvore(32);
    inserirNaArvore(9);
    inserirNaArvore(4);
    inserirNaArvore(22);
    inserirNaArvore(13);
    inserirNaArvore(51);
    inserirNaArvore(7);
    inserirNaArvore(40);

    NoArvore* retorno = buscarArvore(5);

    if (retorno != NULL) {
        cout << "Valor encontrado!" << endl;
        cout << "NoArvore a direita do valor encontrado:" << retorno->dir->conteudo << endl;
        cout << "NoArvore a esquerda do valor encontrado:" << retorno->esq->conteudo << endl;
        cout << "NoArvore a direita da esquerda do valor enc:" << retorno->esq->dir->conteudo << endl;
    }
    else
        cout << "Valor inexistente!" << endl;

    cout << endl;
    cout << "Executando o percurso inOrdemArvore: " << endl;
    inOrdemArvore(raiz);

    cout << endl;
    cout << "Executando o percurso preOrdemArvore " << endl;
    preOrdemArvore(raiz);

    removerArvore(12);

    return 0;
}

int main() {
    int v[] = { 3, 1, 2, 5, 10, 11, 23, 40 };
    int tam = sizeof(v) / sizeof(v[0]);

    mergeSort(v, 0, tam-1);

    for (int i = 0; i < tam; i++) {
        cout << v[i] << "\t";
    }

    return 0;
}
