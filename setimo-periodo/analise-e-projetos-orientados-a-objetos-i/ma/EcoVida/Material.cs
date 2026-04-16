namespace EcoVida
{
    public class Material
    {
        public TipoMaterial Tipo { get; private set; }
        public double Peso { get; private set; }
        public string Data { get; private set; }

        public double Preco { get; private set; }

        private static int _id;

        private void setID() {
            _id++;
        }

        public int getID() {
            return _id;
        }

        public Material(TipoMaterial tipo, double peso, string data)
        {
            setID();
            Tipo = tipo;
            Peso = peso;
            Data = data;
        }

        public double CalcularValor()
        {
            this.Preco = Peso * TabelaPreco.GetPreco(Tipo);
            return this.Preco;
        }
    }
}