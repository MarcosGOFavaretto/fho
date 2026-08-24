namespace Exercicio2
{
    public class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int, string> alunos = new Dictionary<int, string>
            {
                { 1, "Ana" },
                { 2, "Bruno" },
                { 3, "Carlos" },
                { 4, "Daniela" },
                { 5, "Eduardo" }
            };

            var alunosFiltrados = alunos.Where(aluno => aluno.Key > 2);

            Console.WriteLine("Alunos com ID maior que 2:");

            foreach (var aluno in alunosFiltrados)
            {
                Console.WriteLine($"ID: {aluno.Key} - Nome: {aluno.Value}");
            }
        }
    }
}
