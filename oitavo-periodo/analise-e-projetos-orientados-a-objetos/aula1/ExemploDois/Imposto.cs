namespace ExemploDois
{
    public class Imposto
    {

        private const decimal TAXA = 0.25m;

        public decimal CalcularTaxa(Pedido pedido)
        {
            return pedido.GetItens().Count * TAXA;
        }
    }
}