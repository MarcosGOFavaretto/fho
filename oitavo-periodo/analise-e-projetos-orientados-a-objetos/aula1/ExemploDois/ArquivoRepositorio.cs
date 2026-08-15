namespace ExemploDois
{
    class ArquivoRepositorio
    {
        public void Salvar(Pedido pedido)
        {
            Console.WriteLine("Salvando o registro em disco...");
        }

        public void Salvar(string comentario)
        {
            Console.WriteLine("Salvando comentário em disco ...");
        }
    }
}