namespace ExemploTres
{
    public class CalculadoraFrete
    {
        public decimal CalcularFrete(IFrete frete, decimal peso)
        {
            return frete.Calcular(peso);
        }
    }
}