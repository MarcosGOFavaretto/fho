public class ComissaoPremium implements IComissao {

    private static final double VALOR_PERCENTUAL_COMISSAO           = 7d;
    private static final double VALOR_MONETARIO_MINIMO_PARA_BONUS   = 1_000d;
    private static final double VALOR_MONETARIO_BONUS               = 30d;

    public double calcularComissao(double valorDaVenda) {

        double valorMonetarioComissao = valorDaVenda * VALOR_PERCENTUAL_COMISSAO / 100;

        if (valorDaVenda >= VALOR_MONETARIO_MINIMO_PARA_BONUS)
            valorMonetarioComissao += VALOR_MONETARIO_BONUS;

        return valorMonetarioComissao;
    }
}