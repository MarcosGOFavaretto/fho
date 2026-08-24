namespace Exercicio1
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<int> numeros = new List<int>
            {
                10, 15, 22, 31, 40, 53, 68, 71, 84, 99
            };

            var numerosPares = numeros.Where(numero => numero % 2 == 0);

            Console.WriteLine("Números pares:");

            foreach (var numero in numerosPares)
            {
                Console.WriteLine(numero);
            }
        }
    }
}
