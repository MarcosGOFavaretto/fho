using System;

class Program
{
    static void Main()
    {

        string nome1, nome2, nome3;
        int quantidade1, quantidade2, quantidade3;

        Console.WriteLine("Nome do Produto 1:");
        nome1 = Console.ReadLine();
        Console.WriteLine("Quantidade em estoque: ");
        quantidade1 = int.Parse(Console.ReadLine());

        Console.WriteLine("Nome do Produto 2:");
        nome2 = Console.ReadLine();
        Console.WriteLine("Quantidade em estoque: ");
        quantidade2 = int.Parse(Console.ReadLine());

        Console.WriteLine("Nome do Produto 3:");
        nome3 = Console.ReadLine();
        Console.WriteLine("Quantidade em estoque: ");
        quantidade3 = int.Parse(Console.ReadLine());

        string produtoMenorEstoque = nome1;
        int menorEstoque = quantidade1;

        if (quantidade2 < menorEstoque)
        {
            produtoMenorEstoque = nome2;
            menorEstoque = quantidade2;
        }

        if (quantidade3 < menorEstoque)
        {
            produtoMenorEstoque = nome3;
            menorEstoque = quantidade3;
        }

        Console.WriteLine($"\nProduto com menor estoque: {produtoMenorEstoque}");
        Console.WriteLine($"Quantidade: {menorEstoque}");
    }
}