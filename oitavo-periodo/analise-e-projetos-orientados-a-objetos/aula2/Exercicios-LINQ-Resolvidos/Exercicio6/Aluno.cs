namespace Exercicio6
{
    public class Aluno
    {
        public int Id { get; set; }
        public string Nome { get; set; }
        public decimal Nota { get; set; }

        public Aluno(int id, string nome, decimal nota)
        {
            Id = id;
            Nome = nome;
            Nota = nota;
        }
    }
}
