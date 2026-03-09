namespace Exemplo_Biblioteca
{
    public class Livro
    {
        // Atributos
        private string titulo;
        public string Autor { get; set; } // Isso é uma propriedade.
        public int Ano { get; set; }
        public bool IsDisponivel { get; set; }
        public DateTime dtDevolucao { get; private set; }

        // Construtor

        // Métodos
        public string GetTitulo()
        {
            return titulo;
        }

        public void SetTitulo(string titulo)
        {
            this.titulo = titulo;
        }

        public void VerDisponibilidade()
        {
            if (IsDisponivel)
                Console.WriteLine("Disponível!");
            else
                Console.WriteLine("Não disponível!");
        }

        public void ExibirInformacoes()
        {
            // regras para exibir as informações
            Console.WriteLine($"Título: {GetTitulo()} \nAutor: {Autor} \nAno: {Ano}");
            Console.Write($"Disponibilidade: ");
            this.VerDisponibilidade();
        }

        private bool AtualizarDisponibilidade()
        {
            this.IsDisponivel = !this.IsDisponivel;
            return this.IsDisponivel;
        }

        public void Emprestar()
        {
            if (!IsDisponivel) return;
           AtualizarDisponibilidade();
        }

        public void Devolver()
        {

            if (IsDisponivel) return;

            this.dtDevolucao = DateTime.Now;
            this.AtualizarDisponibilidade();
        }
    }
}