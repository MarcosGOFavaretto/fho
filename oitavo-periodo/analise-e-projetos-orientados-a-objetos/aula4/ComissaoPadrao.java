public class ComissaoPadrao implements IComissao {

    private static final double VALOR_PERCENTUAL_COMISSAO = 5;

    public double calcularComissao(double valorDaVenda) {

        return valorDaVenda * VALOR_PERCENTUAL_COMISSAO / 100;

    }
}