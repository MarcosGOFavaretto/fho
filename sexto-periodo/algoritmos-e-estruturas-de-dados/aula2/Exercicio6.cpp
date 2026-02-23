#include <iostream>
using namespace std;

/**
 * 6) Faça um TAD para uma conta bancária. A conta é representada por: número e saldo. As operações que os clientes podem realizar são:
 *  a) FazerConta: inicializa o número e saldo inicial (por referência).
 *  b) Depositar: deposita um valor na conta;
 *  c) Sacar: saca um valor na conta se o saldo permitir;
 *  d) VerSaldo: exbie o saldo da conta.
 */

typedef struct
{
    int codigo;
    float saldo;
} Conta;

Conta criarConta()
{

    Conta conta;
    conta.codigo = 1;
    conta.saldo = 100;

    return conta;
}

Conta depositar(Conta conta, float valor)
{
    cout << "Depositando o montante de R$ " << valor << " da conta!" << endl;
    conta.saldo += valor;
    return conta;
}

Conta sacar(Conta conta, float valor)
{

    cout << "Sacando o montante de R$ " << valor << " da conta!" << endl;
    if (valor > conta.saldo)
    {
        cout << "O saque de R$ " << valor << " é maior que o saldo da conta!" << endl;
        return conta;
    }

    conta.saldo -= valor;
    return conta;
}

void verSaldo(Conta conta)
{
    cout << "\nO saldo da conta '" << conta.codigo << "' é de R$ " << conta.saldo << "!" << endl;
}

int main()
{

    Conta minhaConta = criarConta();

    verSaldo(minhaConta);

    minhaConta = depositar(minhaConta, 100.30);
    verSaldo(minhaConta);

    minhaConta = sacar(minhaConta, 5.30);
    verSaldo(minhaConta);

    return 0;
}