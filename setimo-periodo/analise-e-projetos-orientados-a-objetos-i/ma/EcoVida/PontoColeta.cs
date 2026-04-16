namespace EcoVida
{
    public class PontoColeta
    {
        public string Nome { get; private set; }
        public string Endereco { get; private set; }

        private List<Cooperado> cooperados = new List<Cooperado>();

        public PontoColeta(string nome, string endereco)
        {
            Nome = nome;
            Endereco = endereco;
        }

        public void AdicionarCooperado(Cooperado c)
        {
            cooperados.Add(c);
        }

        public List<Cooperado> GetCooperados()
        {
            return cooperados;
        }

        public void RemoverCooperado(Cooperado c)
        {
            if (c == null)
            {
                Console.WriteLine("Cooperado inválido.");
                return;
            }

            bool removido = cooperados.Remove(c);

            if (removido)
            {
                Console.WriteLine("Cooperado removido do ponto com sucesso.");
            }
            else
            {
                Console.WriteLine("Cooperado não encontrado neste ponto.");
            }
        }
    }
}