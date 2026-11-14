# Exercício 1 — Strategy: Cálculo de Comissões

**Linguagem:** C# / .NET  
**Dificuldade:** Intermediária  
**Tempo sugerido:** 20–30 minutos

## 1. Cenário

Você está desenvolvendo um ERP que precisa calcular a comissão dos vendedores de uma empresa.

Atualmente, existem três políticas de comissão, e cada uma possui suas próprias regras.

| Política | Regra de cálculo |
|---|---|
| **Padrão** | Comissão de 5% sobre a venda. |
| **Premium** | Comissão de 7%. Para vendas a partir de R$ 1.000,00, acrescenta R$ 30,00 de bônus. |
| **Parceiro** | Comissão de 3%, com um mínimo garantido de R$ 20,00 por venda. |

A empresa pretende adicionar novas políticas futuramente, sem precisar modificar o serviço responsável pelo cálculo.

## 2. Sua missão

Implemente o padrão **Strategy** para que o sistema consiga calcular comissões utilizando diferentes políticas.

Requisitos:

1. Crie uma interface para representar uma política de comissão.
2. Implemente as três políticas.
3. Crie uma classe `CalculadoraComissao`, responsável por utilizar a política recebida.
4. Permita que a política seja definida pelo construtor.
5. O código da `CalculadoraComissao` não pode depender diretamente das classes concretas das políticas.
6. Utilize `decimal` para os valores monetários.

> **Restrição principal:** não utilize `if`, `else` ou `switch` dentro de `CalculadoraComissao` para identificar a política. Condicionais são permitidas dentro das estratégias para aplicar suas regras de negócio.

## 3. Resultados esperados

Utilize os seguintes casos para verificar sua implementação.

| Valor da venda | Padrão | Premium | Parceiro |
|---|---:|---:|---:|
| R$ 200,00 | R$ 10,00 | R$ 14,00 | R$ 20,00 |
| R$ 500,00 | R$ 25,00 | R$ 35,00 | R$ 20,00 |
| R$ 1.000,00 | R$ 50,00 | R$ 100,00 | R$ 30,00 |
| R$ 2.000,00 | R$ 100,00 | R$ 170,00 | R$ 60,00 |

## 4. Exemplo de utilização desejada

Seu código deve permitir algo semelhante a isto:

```csharp
var calculadora = new CalculadoraComissao(
    new ComissaoPremium()
);

decimal comissao = calculadora.Calcular(1000m);

Console.WriteLine(comissao); // 100
```

E também:

```csharp
var calculadora = new CalculadoraComissao(
    new ComissaoParceiro()
);

decimal comissao = calculadora.Calcular(500m);

Console.WriteLine(comissao); // 20
```

> Observe que a classe `CalculadoraComissao` deve funcionar independentemente da política fornecida. Os dois trechos são exemplos independentes de utilização.

## 5. Desafio adicional

Após terminar a implementação, a empresa solicita uma quarta política:

**Comissão Progressiva**

- Até R$ 1.000,00: 4% sobre o valor total.
- Acima de R$ 1.000,00: 6% sobre o valor total.

A taxa é aplicada ao valor integral da venda, sem divisão em faixas.

Implemente a nova política **sem modificar a classe `CalculadoraComissao`**.

O resultado para uma venda de R$ 1.500,00 deve ser **R$ 90,00**.

## 6. Critérios de avaliação

- [ ] Utilizou corretamente interface e polimorfismo.
- [ ] Separou as regras de negócio em estratégias.
- [ ] Manteve a `CalculadoraComissao` independente das implementações.
- [ ] Aplicou composição e injeção de dependência.
- [ ] Conseguiu adicionar a quarta política sem alterar a calculadora.

**Entrega:** envie o código C# para revisão, incluindo as estratégias, a calculadora e a demonstração de uso. A revisão deverá verificar o uso do Strategy, a organização das responsabilidades e se a aplicação do padrão faz sentido nesse cenário.
