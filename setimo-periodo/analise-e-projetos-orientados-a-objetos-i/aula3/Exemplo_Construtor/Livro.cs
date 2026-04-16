namespace Exemplo_Construtor
{
    public class Livro
    {

        static int _id = 0;

        public int Codigo { get; private set; }
        public string Nome { get; private set; }
        public string Autor { get; private set; }
        public int Ano { get; private set; }
        public bool Disponibilidade { get; set; }

        public Livro(string nome, string autor, int ano)
        {
            Console.WriteLine("Um objeto livro está sendo criado!!!");
            this.Codigo = _id++;
            this.Nome = nome;
            this.Autor = autor;
            this.Ano = ano;
            this.Disponibilidade = true;
        }
    }
}