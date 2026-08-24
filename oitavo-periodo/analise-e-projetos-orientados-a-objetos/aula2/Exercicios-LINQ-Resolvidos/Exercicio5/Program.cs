namespace Exercicio5
{
    public class Program
    {
        static void Main(string[] args)
        {
            Queue<int> numeros = new Queue<int>();

            numeros.Enqueue(25);
            numeros.Enqueue(60);
            numeros.Enqueue(10);
            numeros.Enqueue(75);
            numeros.Enqueue(50);
            numeros.Enqueue(90);
            numeros.Enqueue(42);

            var maioresQueCinquenta = numeros.Where(numero => numero > 50);

            Console.WriteLine("Elementos maiores que 50:");

            foreach (var numero in maioresQueCinquenta)
            {
                Console.WriteLine(numero);
            }
        }
    }
}
