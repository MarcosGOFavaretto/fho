namespace Exemplo_Construtor
{
    public class Program
    {
        static void Main(string[] args)
        {
            Livro novoLivro = new Livro("Senhor dos Anéis", "Tolkien", 1950);

            Console.WriteLine(novoLivro.Nome);
            Console.WriteLine(novoLivro.Autor);
        }
    }
}