namespace Exemplo_Biblioteca
{
    public class Program
    {
        static void Main(string[] args)
        {
            // Aqui vamos manipular a classe Livro através de instãncias dessa classe (objeto).

            // Criamos o primeiro objeto do tipo LIvro a linha "new Livro()" chama o construtor da classe.
            Livro objLivro = new();

            // Acessando e manipulando os atributos
            objLivro.SetTitulo("1984");
            objLivro.Ano = 1984;
            objLivro.Autor = "George Orwell";
            objLivro.IsDisponivel = true;

            objLivro.ExibirInformacoes();
            objLivro.Emprestar();
            objLivro.ExibirInformacoes();
            objLivro.Devolver();
            objLivro.ExibirInformacoes();
        }
    }
}