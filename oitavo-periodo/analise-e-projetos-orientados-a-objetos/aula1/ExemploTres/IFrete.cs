namespace ExemploTres
{
    public interface IFrete
    {
        public decimal Calcular(decimal peso)
        {
            return peso * GetTaxa();
        }
        public decimal GetTaxa();
    }
}