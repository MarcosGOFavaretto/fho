namespace ExemploTres
{
    class Program
    {
        static void Main(string[] args)
        {
            CalculadoraFrete calculadora = new CalculadoraFrete();
            var frete1 = calculadora.CalcularFrete(new Sedex(), 0.15m);
            var frete2 = calculadora.CalcularFrete(new Pac(), 0.8m);
            Console.WriteLine($"Frete 1 = {frete1} — Frete 2 = {frete2}");
        }
    }
}