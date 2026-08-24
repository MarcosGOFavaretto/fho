namespace Exercicio4
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<Aluno> alunos = new List<Aluno>
            {
                new Aluno("Ana", "Leme"),
                new Aluno("Bruno", "Pirassununga"),
                new Aluno("Carlos", "Leme"),
                new Aluno("Daniela", "Araras"),
                new Aluno("Eduardo", "Pirassununga"),
                new Aluno("Fernanda", "Leme")
            };

            var alunosPorCidade = alunos.GroupBy(aluno => aluno.Cidade);

            foreach (var grupo in alunosPorCidade)
            {
                Console.WriteLine($"Cidade: {grupo.Key}");

                foreach (var aluno in grupo)
                {
                    Console.WriteLine($"- {aluno.Nome}");
                }

                Console.WriteLine();
            }
        }
    }
}
