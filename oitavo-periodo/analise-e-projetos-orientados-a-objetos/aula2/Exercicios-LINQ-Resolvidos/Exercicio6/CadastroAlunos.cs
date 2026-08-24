namespace Exercicio6
{
    public class CadastroAlunos
    {
        private readonly List<Aluno> alunos = new List<Aluno>();

        public bool InserirAluno(Aluno aluno)
        {
            if (alunos.Any(a => a.Id == aluno.Id))
                return false;

            alunos.Add(aluno);
            return true;
        }

        public void ListarAlunos()
        {
            if (!alunos.Any())
            {
                Console.WriteLine("Nenhum aluno cadastrado.");
                return;
            }

            foreach (var aluno in alunos.OrderBy(a => a.Id))
            {
                ExibirAluno(aluno);
            }
        }

        public void ListarAprovados()
        {
            var aprovados = alunos.Where(aluno => aluno.Nota >= 5m);

            if (!aprovados.Any())
            {
                Console.WriteLine("Nenhum aluno aprovado.");
                return;
            }

            foreach (var aluno in aprovados)
            {
                ExibirAluno(aluno);
            }
        }

        public void MostrarMediaTurma()
        {
            if (!alunos.Any())
            {
                Console.WriteLine("Nenhum aluno cadastrado.");
                return;
            }

            var media = alunos.Average(aluno => aluno.Nota);
            Console.WriteLine($"Média da turma: {media:F2}");
        }

        public void MostrarAlunosPorSituacao()
        {
            if (!alunos.Any())
            {
                Console.WriteLine("Nenhum aluno cadastrado.");
                return;
            }

            var alunosPorSituacao = alunos.GroupBy(aluno => aluno.Nota >= 5m ? "Aprovado" : "Reprovado");

            foreach (var grupo in alunosPorSituacao.OrderBy(grupo => grupo.Key))
            {
                Console.WriteLine($"{grupo.Key}:");

                foreach (var aluno in grupo)
                {
                    ExibirAluno(aluno);
                }

                Console.WriteLine();
            }
        }

        private void ExibirAluno(Aluno aluno)
        {
            Console.WriteLine($"ID: {aluno.Id} - Nome: {aluno.Nome} - Nota: {aluno.Nota:F2}");
        }
    }
}
