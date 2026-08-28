namespace ExercicioLinq
{
    public class NonNegativeException : Exception
    {
        public NonNegativeException(string mensagem) : base(mensagem)
        {
        }
    }

    public class Aluno
    {
        public string Nome { get; set; }
        public string Curso { get; set; }
        public string Cidade { get; set; }
        public decimal Media { get; set; }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            //A lista de alunos
            List<Aluno> alunos = new List<Aluno>
            {
                new Aluno { Nome = "Ana", Curso = "Engenharia de Computação", Cidade = "Leme", Media = 8.5m },
                new Aluno { Nome = "Bruno", Curso = "Administração", Cidade = "Leme", Media = 6.0m },
                new Aluno { Nome = "Carlos", Curso = "Engenharia de Computação", Cidade = "Araras", Media = 7.5m },
                new Aluno { Nome = "Daniela", Curso = "Administração", Cidade = "Araras", Media = 9.0m },
                new Aluno { Nome = "Eduardo", Curso = "Sistemas de Informação", Cidade = "Limeira", Media = 5.5m },
                new Aluno { Nome = "Fernanda", Curso = "Sistemas de Informação", Cidade = "Leme", Media = 7.0m }
            };

            Console.WriteLine("1 - Sem erros");
            Console.WriteLine("2 - NullReferenceException");
            Console.WriteLine("3 - DivideByZeroException");
            Console.WriteLine("4 - NonNegativeException");
            Console.WriteLine("5 - ArgumentNullException");
            Console.WriteLine("6 - Exception");
            Console.Write("Escolha uma opção: ");

            int opcao = Convert.ToInt32(Console.ReadLine());

            try
            {
                if (opcao == 2)
                {
                    alunos.Add(null);
                }
                else if (opcao == 3)
                {
                    int valor = 10;
                    int divisor = 0;

                    Console.WriteLine(valor / divisor);
                }
                else if (opcao == 4)
                {
                    alunos[0].Media = -1;
                }
                else if (opcao == 5)
                {
                    alunos = null;
                }
                else if (opcao == 6)
                {
                    throw new Exception("Ocorreu um erro.");
                }

                if (alunos == null)
                    throw new ArgumentNullException("alunos");

                foreach (Aluno aluno in alunos)
                {
                    if (aluno == null)
                        throw new NullReferenceException("Aluno nulo.");

                    if (aluno.Media < 0)
                        throw new NonNegativeException("A média não pode ser negativa.");
                }

                var porCidade = alunos.GroupBy(a => a.Cidade);

                Console.WriteLine("\nAlunos agrupados por cidade:");

                foreach (var cidade in porCidade)
                {
                    Console.WriteLine("\n" + cidade.Key);

                    foreach (Aluno aluno in cidade)
                    {
                        Console.WriteLine($"{aluno.Nome} - {aluno.Curso} - Média: {aluno.Media}");
                    }
                }

                var porCurso = alunos.GroupBy(a => a.Curso);

                Console.WriteLine("\nAlunos agrupados por curso:");

                foreach (var curso in porCurso)
                {
                    Console.WriteLine("\n" + curso.Key);

                    foreach (Aluno aluno in curso)
                    {
                        Console.WriteLine($"{aluno.Nome} - {aluno.Cidade} - Média: {aluno.Media}");
                    }
                }

                //Filtrando os alunos os aprovados
                var aprovados = alunos.Where(a => a.Media >= 7)
                                      .GroupBy(a => a.Curso);

                Console.WriteLine("\nAlunos aprovados agrupados por curso:");

                foreach (var curso in aprovados)
                {
                    Console.WriteLine("\n" + curso.Key);

                    foreach (Aluno aluno in curso)
                    {
                        Console.WriteLine($"{aluno.Nome} - {aluno.Cidade} - Média: {aluno.Media}");
                    }
                }
            }
            catch (NullReferenceException ex)
            {
                Console.WriteLine("NullReferenceException: " + ex.Message);
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine("DivideByZeroException: " + ex.Message);
            }
            catch (NonNegativeException ex)
            {
                Console.WriteLine("NonNegativeException: " + ex.Message);
            }
            catch (ArgumentNullException ex)
            {
                Console.WriteLine("ArgumentNullException: " + ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception: " + ex.Message);
            }

            Console.WriteLine("\nFim do programa.");
        }
    }
}ccd