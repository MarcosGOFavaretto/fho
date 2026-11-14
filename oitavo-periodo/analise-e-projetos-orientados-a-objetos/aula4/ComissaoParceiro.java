public class ComissaoParceiro implements IComissao {

    private static final double VALOR_PERCENTUAL_COMISSAO = 3D;
    private static final double VALOR_MONETÁRIO_MINIMO_DE_COMISSAO = 20.00D;

    public double calcularComissao(BigDecimal valorDaVenda) {

        double valorMonetarioComissao = valorDaVenda * VALOR_PERCENTUAL_COMISSAO / 100;

        return valorMonetarioComissao < VALOR_MONETÁRIO_MINIMO_DE_COMISSAO
                ? VALOR_MONETÁRIO_MINIMO_DE_COMISSAO
                : valorMonetarioComissao;

    }
}