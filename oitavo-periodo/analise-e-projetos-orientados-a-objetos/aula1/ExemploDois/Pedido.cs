namespace ExemploDois
{
    class Pedido
    {
        private List<ItemPedido> Itens = new List<ItemPedido>();

        public List<ItemPedido> GetItens()
        {
            return Itens;
        }

        public void AdicionarProduto(string nome)
        {
            GetItens().Add(new ItemPedido(nome));
        }
    }
}