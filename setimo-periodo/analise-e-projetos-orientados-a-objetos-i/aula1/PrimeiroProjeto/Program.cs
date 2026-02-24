namespace PrimeiroProjeto
{
    internal class RonaldoFenomeno
    {
        static void Main(string[] args)
        {

            // Declaração de variáveis
            int ano = 2026;
            string curso = "Engenharia de Computação";
            float dolar = 5.17f;
            bool status = false;
            //

            // Saída
            Console.WriteLine("Hello, World!");
            Console.WriteLine("Curso: " + curso); // concatenação
            Console.WriteLine($"O curso atual eh {curso} - O dolar atual esta em {dolar}"); // interpolação
            //

            // Entrada
            Console.WriteLine("Informe o valor do dolar:");
            dolar = float.Parse(Console.ReadLine());
            Console.WriteLine("Informe o ano:");
            ano = int.Parse(Console.ReadLine());
            Console.WriteLine("Informe o curso:");
            curso = Console.ReadLine();

            Console.WriteLine($"O dolar esta {dolar}. O ano e {ano}. O seu curso e: \n {curso}.");
            //

            // Condicional
            if (dolar <= 5.10)
            {
                Console.WriteLine("Sugiro a compra de dolar!");
            }
            else
                Console.WriteLine("Sugiro aguardar diminuir...");
            //
        }
    }
}