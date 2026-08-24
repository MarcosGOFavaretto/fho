using System.Globalization;

namespace Exercicio6
{
    public class Program
    {
        static void Main(string[] args)
        {
            CadastroAlunos cadastro = new CadastroAlunos();
            int opcao;

            do
            {
                Console.WriteLine();
                Console.WriteLine("1 - Inserir aluno");
                Console.WriteLine("2 - Listar alunos");
                Console.WriteLine("3 - Listar aprovados");
                Console.WriteLine("4 - Mostrar média da turma");
                Console.WriteLine("5 - Mostrar alunos por situação");
                Console.WriteLine("0 - Sair");
                Console.Write("Opção: ");

                if (!int.TryParse(Console.ReadLine(), out opcao))
                {
                    Console.WriteLine("Opção inválida.");
                    opcao = -1;
                    continue;
                }

                Console.WriteLine();

                switch (opcao)
                {
                    case 1:
                        InserirAluno(cadastro);
                        break;
                    case 2:
                        cadastro.ListarAlunos();
                        break;
                    case 3:
                        cadastro.ListarAprovados();
                        break;
                    case 4:
                        cadastro.MostrarMediaTurma();
                        break;
                    case 5:
                        cadastro.MostrarAlunosPorSituacao();
                        break;
                    case 0:
                        Console.WriteLine("Programa encerrado.");
                        break;
                    default:
                        Console.WriteLine("Opção inválida.");
                        break;
                }
            }
            while (opcao != 0);
        }

        private static void InserirAluno(CadastroAlunos cadastro)
        {
            Console.Write("ID: ");

            if (!int.TryParse(Console.ReadLine(), out int id))
            {
                Console.WriteLine("ID inválido.");
                return;
            }

            Console.Write("Nome: ");
            string nome = Console.ReadLine() ?? string.Empty;

            if (string.IsNullOrWhiteSpace(nome))
            {
                Console.WriteLine("Nome inválido.");
                return;
            }

            Console.Write("Nota: ");
            string notaTexto = (Console.ReadLine() ?? string.Empty).Replace(',', '.');

            if (!decimal.TryParse(notaTexto, NumberStyles.Number, CultureInfo.InvariantCulture, out decimal nota))
            {
                Console.WriteLine("Nota inválida.");
                return;
            }

            if (nota < 0m || nota > 10m)
            {
                Console.WriteLine("A nota deve estar entre 0 e 10.");
                return;
            }

            Aluno aluno = new Aluno(id, nome.Trim(), nota);

            if (cadastro.InserirAluno(aluno))
                Console.WriteLine("Aluno cadastrado com sucesso.");
            else
                Console.WriteLine("Já existe um aluno com esse ID.");
        }
    }
}
