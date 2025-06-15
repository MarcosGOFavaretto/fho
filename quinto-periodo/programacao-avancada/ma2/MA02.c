#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    char codigo[10];
    float valorDeCompra;
    float valorDeVenda;
    float lucro;
} Ativo;

Ativo ativos[100] = {
        {"PETR4", 20.0, 25.0, 5.0},
        {"VALE3", 30.0, 35.0, 5.0},
        {"ITUB4", 15.0, 20.0, 5.0},
        {"ABEV3", 10.0, 12.0, 2.0},
        {"BBAS3", 25.0, 30.0, 5.0}
    };

int total = 5;

void listarAtivos() {
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("| Código             | Valor Compra       | Valor Venda        | Lucro              |\n");
    printf("+--------------------+--------------------+--------------------+--------------------+\n");
    for (int i = 0; i < total; i++) {
        Ativo ativo = ativos[i];
        printf("| %-18s | %-18.2f | %-18.2f | %-18.2f |\n", ativo.codigo, ativo.valorDeCompra, ativo.valorDeVenda, ativo.lucro);
    }
    printf("+-----------------------------------------------------------------------------------+\n");    
};

void buscarAtivo(char codigo[]) {
    int verificaCodigo = -1;

    for (int i = 0; i < total; i++) {
        if(strcmp(ativos[i].codigo, codigo) == 0) {
            verificaCodigo = i;
            break;
        }
    }

    if (verificaCodigo != -1) {
        printf("+-----------------------------------------------------------------------------------+\n");
        printf("| Código             | Valor Compra       | Valor Venda        | Lucro              |\n");
        printf("+--------------------+--------------------+--------------------+--------------------+\n");
        printf("| %-18s | %-18.2f | %-18.2f | %-18.2f |\n", ativos[verificaCodigo].codigo, ativos[verificaCodigo].valorDeCompra, ativos[verificaCodigo].valorDeVenda, ativos[verificaCodigo].lucro);
        printf("+-----------------------------------------------------------------------------------+\n");
    }
    else {
        printf("Ativo não encontrado...");
    }

};

void cadastrarAtivo()
{

    Ativo novoAtivo;

    printf("Informe o código do ativo (no máximo 10 caracteres):\n");
    scanf("%s", novoAtivo.codigo);
    novoAtivo.codigo[strcspn(novoAtivo.codigo, "\n")] = 0;

    printf("Informe o valor de compra:\n");
    scanf("%f", &novoAtivo.valorDeCompra);

    printf("Informe o valor de venda:\n");
    scanf("%f", &novoAtivo.valorDeVenda);

    novoAtivo.lucro = novoAtivo.valorDeVenda - novoAtivo.valorDeCompra;
    ativos[total++] = novoAtivo;

    printf("Ativo criado com sucesso!\n");
}

void atualizarAtivo(char codigo[10])
{

    Ativo ativoAtualizado;

    printf("Informe o código do ativo (no máximo 10 caracteres):\n");
    fgets(ativoAtualizado.codigo, sizeof(ativoAtualizado.codigo), stdin);
    ativoAtualizado.codigo[strcspn(ativoAtualizado.codigo, "\n")] = 0;

    printf("Informe o valor de compra:\n");
    scanf("%f", &ativoAtualizado.valorDeCompra);

    printf("Informe o valor de venda:\n");
    scanf("%f", &ativoAtualizado.valorDeVenda);

    ativoAtualizado.lucro = ativoAtualizado.valorDeVenda - ativoAtualizado.valorDeCompra;

    int indiceAtivoParaAtualizar = 0;
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(ativos[i].codigo, codigo) == 0)
        {
            indiceAtivoParaAtualizar = i;
            break;
        }
    }

    printf("%d \n", indiceAtivoParaAtualizar);
    ativos[indiceAtivoParaAtualizar] = ativoAtualizado;

    printf("Ativo atualizado com sucesso!\n");
}

void excluirAtivo(char codigo[10])
{

    int indiceItemParaCopiar = 0;
    for (int i = 0; i < 100; i++)
    {

        if (strcmp(ativos[i].codigo, codigo) == 0 && indiceItemParaCopiar < 100) {
            indiceItemParaCopiar++;
        }

        ativos[i] = ativos[indiceItemParaCopiar];
        indiceItemParaCopiar++;
    }

    printf("Ativo excluido com sucesso!\n");
    total--;
}

int main() {

    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar ativo\n");
        printf("2. Listar ativos\n");
        printf("3. Buscar ativo por código\n");
        printf("4. Atualizar ativo\n");
        printf("5. Excluir ativo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarAtivo();
        } else if (opcao == 2) {
            listarAtivos();
        } else if (opcao == 3) {
            char codigo[10];
            printf("Digite o codigo do ativo: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = 0;
            buscarAtivo(codigo);
        } else if (opcao == 4) {
            char codigo[10];
            printf("Digite o codigo do ativo: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = 0;

            atualizarAtivo(codigo);
        } else if (opcao == 5) {
            char codigo[10];
            printf("Digite o codigo do ativo: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = 0;

            excluirAtivo(codigo);
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}