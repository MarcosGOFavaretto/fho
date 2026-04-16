namespace EcoVida
{
    public class Cooperativa
    {
        public string Nome { get; private set; }

        private List<PontoColeta> pontos = new List<PontoColeta>();
        private List<Cooperado> cooperados = new List<Cooperado>();

        private List<Material> materiais = new List<Material>();

        public static int TotalPontos { get; private set; }

        public Cooperativa(string nome)
        {
            Nome = nome;
        }

        public void AdicionarPonto(PontoColeta p)
        {
            pontos.Add(p);
            TotalPontos++;
        }

        public void AdicionarCooperado(Cooperado c)
        {
            cooperados.Add(c);
        }

        public void AdicionarMaterial(Material m)
        {
            materiais.Add(m);
        }

        public void Vincular(Cooperado c, PontoColeta p)
        {
            p.AdicionarCooperado(c);
        }

        public void RelatorioGeral()
        {
            if (cooperados.Count == 0)
            {
                Console.WriteLine("Nenhum cooperado cadastrado no momento.");
                return;
            }

            foreach (var c in cooperados)
            {
                Console.WriteLine($"{c.Nome} - Total: R$ {c.CalcularTotal():F2}");
            }
        }

        public List<Cooperado> GetCooperados() => cooperados;
        public List<PontoColeta> GetPontos() => pontos;

        public List<Material> GetMateriais() => materiais;

        public void RemoverPonto(PontoColeta p)
        {
            if (p == null)
            {
                Console.WriteLine("Ponto inválido.");
                return;
            }

            bool removido = pontos.Remove(p);

            if (removido)
            {
                TotalPontos = Math.Max(0, TotalPontos - 1);
                Console.WriteLine("Ponto removido com sucesso.");
            }
            else
            {
                Console.WriteLine("Ponto de coleta não encontrado.");
            }
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
                Console.WriteLine("Cooperado removido com sucesso.");
            }
            else
            {
                Console.WriteLine("Cooperado não encontrado.");
            }
        }
    }

}