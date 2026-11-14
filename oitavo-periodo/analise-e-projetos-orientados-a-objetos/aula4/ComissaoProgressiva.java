public class ComissaoProgressiva implements IComissao {

    private static final double VALOR_PERCENTUAL_COMISSAO_NIVEL_UM = 4d;
    private static final double VALOR_PERCENTUAL_COMISSAO_NIVEL_DOIS = 6d;
    private static final double VALOR_MONETARIO_MAXIMO_PARA_NIVEL_UM = 1_000D;

    public double calcularComissao(double valorDaVenda) {
        return valorDaVenda / 100 * 
                (valorDaVenda > VALOR_MONETARIO_MAXIMO_PARA_NIVEL_UM
                    ? VALOR_PERCENTUAL_COMISSAO_NIVEL_DOIS
                    : VALOR_PERCENTUAL_COMISSAO_NIVEL_UM);
    }
    
}