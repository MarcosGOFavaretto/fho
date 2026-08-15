namespace ExemploDois
{
    class Program
    {
        static void Main(string[] args)
        {
            Pedido pedido = new Pedido();
            pedido.AdicionarProduto("Bota de rodeio");
            pedido.AdicionarProduto("Jurupinga");
            pedido.AdicionarProduto("Pinguinha de mel");
            pedido.AdicionarProduto("Show sertanejo");

            Imposto imposto = new Imposto();
            Console.WriteLine(imposto.CalcularTaxa(pedido));

            ArquivoRepositorio arquivo = new ArquivoRepositorio();
            arquivo.Salvar(pedido);
        }
    }
}