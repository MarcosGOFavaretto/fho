#include <iostream>
using namespace std;

/**
 * 16) Construa uma estrutura aluno com nome, ra e curso. Leia essas informações para 5 alunos,
 * armazenando em um vetor dessa estrutura. Depois, exiba as informações na tela.
 */

const int TAMANHO_VETOR = 5;

struct Aluno{
    char nome[50];
    int ra;
    char curso[50];
};

void preencherLista(Aluno alunos[TAMANHO_VETOR]) {
    cout << "Informe os dados dos alunos:" << endl;
    for (int linha = 0; linha < TAMANHO_VETOR; linha++)
    {
        cout << "Aluno " << linha + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> alunos[linha].nome; // Usamos "gets" para obter textos com espaços.
        cout << "Curso: ";
        cin >> alunos[linha].curso; // Usamos "gets" para obter textos com espaços.
        cout << "RA: ";
        cin >> alunos[linha].ra;
    }
    
}

void exibirLista(Aluno alunos[TAMANHO_VETOR]) {
    cout << "\nListagem dos alunos:" << endl;
    for (int linha = 0; linha < TAMANHO_VETOR; linha++)
    {
        cout << "Nome: " << alunos[linha].nome << endl;
        cout << "Curso: " << alunos[linha].curso << endl;
        cout << "RA: " << alunos[linha].ra << endl;
    }
}

int main()
{

    Aluno alunos[TAMANHO_VETOR];
    preencherLista(alunos);
    exibirLista(alunos);

    return 0;
}