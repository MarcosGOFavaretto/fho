namespace Exercicios_Aula_3
{
    public class Program
    {

        static List<Livro> Livros = new List<Livro>();

        static void Main(string[] args)
        {

            int opcao = 0;
            do
            {
                Console.WriteLine(
                    "\n\n--------------ESCOLHA UMA OPÇÃO!--------------\n\n"
                    + "\n\t0 -> Cadastrar."
                    + "\n\t1 -> Visualizar."
                    + "\n\t2 -> Emprestar."
                    + "\n\t3 -> Devolver."
                    + "\n\t4 -> Sair."
                );

                opcao = int.Parse(Console.ReadLine());
                switch (opcao)
                {
                    case 0:
                        CadastrarLivro();
                        break;
                    case 1:
                        VisualizarLivros();
                        break;
                    case 2:
                        EmprestarLivro();
                        break;
                    case 3:
                        DevolverLivro();
                        break;
                    default:
                        return;

                }
            } while (true);

        }

        static void CadastrarLivro()
        {
            Console.WriteLine("\nInforme os dados do livro!\n");
            Livro novoLivro = new Livro();

            Console.Write("Nome: ");
            novoLivro.Nome = Console.ReadLine();
            Console.Write("Autor: ");
            novoLivro.Autor = Console.ReadLine();
            Console.Write("Ano: ");
            novoLivro.Ano = int.Parse(Console.ReadLine());
            novoLivro.Disponivel = true;

            Livros.Add(novoLivro);
        }

        static void VisualizarLivros()
        {
            Console.WriteLine("\nConsultando livros!\n");
            foreach (var livro in Livros)
            {
                Console.Write(livro.ToString());
            }
        }

        static void EmprestarLivro()
        {
            Console.WriteLine("\nEmprestando um livro!\n");

            Console.Write("Informe o identificador do livro: ");
            int id = int.Parse(Console.ReadLine());

            foreach (var livro in Livros)
            {
                if (id == livro.Id)
                {
                    Console.WriteLine($"Emprestando o livro {livro.Id} - {livro.Nome}");
                    livro.Emprestar();

                    break;
                }
            }
        }

        static void DevolverLivro()
        {
            Console.WriteLine("\nDevolvendo um livro!\n");

            Console.Write("Informe o identificador do livro: ");
            int id = int.Parse(Console.ReadLine());

            foreach (var livro in Livros)
            {
                if (id == livro.Id)
                {
                    Console.WriteLine($"Devolvendo o livro {livro.Id} - {livro.Nome}");
                    livro.Devolver();

                    break;
                }
            }
        }
    }
}