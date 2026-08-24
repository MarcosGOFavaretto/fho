namespace Exercicio3
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<Produto> produtos = new List<Produto>
            {
                new Produto("Teclado", 150m),
                new Produto("Mouse", 80m),
                new Produto("Monitor", 1200m),
                new Produto("Headset", 250m),
                new Produto("Webcam", 320m)
            };

            var produtosCrescente = produtos.OrderBy(produto => produto.Preco);
            var produtosDecrescente = produtos.OrderByDescending(produto => produto.Preco);

            Console.WriteLine("Produtos por preço crescente:");

            foreach (var produto in produtosCrescente)
            {
                Console.WriteLine($"{produto.Nome} - R$ {produto.Preco:F2}");
            }

            Console.WriteLine();
            Console.WriteLine("Produtos por preço decrescente:");

            foreach (var produto in produtosDecrescente)
            {
                Console.WriteLine($"{produto.Nome} - R$ {produto.Preco:F2}");
            }
        }
    }
}
