namespace Exercicios_Aula_3
{
    public class Livro
    {

        static int _id = 0;
        string nome;

        // PROPRIEDADES SEMPRE SERÃO COM A 1a LETRA MAIÚSCULA.
        public int Id { get; private set;} = _id++;

        public string Nome
        {
            get { return nome; }
            set { nome = value; }

        }

        public string Autor { get; set; }
        public int Ano { get; set; }
        public bool Disponivel { get; set; }

        public string ToString()
        {
            return $"===========================================\nID:\t\t{Id}\nNome:\t\t{Nome}\nAutor:\t\t{Autor}\nAno:\t\t{Ano}\nDisponível:\t{Disponivel}\n";
        }

        public bool Emprestar()
        {
            if (Disponivel) { Disponivel = false; }

            return true;
        }

        public bool Devolver()
        {
            if (!Disponivel) { Disponivel = true; }
            return true;
        }
    }
}