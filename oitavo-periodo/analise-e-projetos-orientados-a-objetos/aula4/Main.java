public class Main {
    public static final void main(String[] args) {

        testarCalculadoraPadrao();
        testarCalculadoraPremium();
        testarCalculadoraParceiro();
        testarCalculadoraProgressiva();
        
    }

    private static final double[] VALORES_MONETARIOS_PARA_TESTE = new double[] {
        200.00d,
        500.00d,
        1_000.00d,
        2_000.00d,
        1_500.00d
    };

    private static void testarCalculadoraPadrao() {

        System.out.println("Testando o cálculo de comissão padrão!");

        CalculadoraComissao calculadora = new CalculadoraComissao(new ComissaoPadrao());

        for (double valorDaVenda : VALORES_MONETARIOS_PARA_TESTE)
            System.out.println(valorDaVenda + " -> " + calculadora.calcular(valorDaVenda));

        System.out.println("");

    }

    private static void testarCalculadoraPremium() {

        System.out.println("Testando o cálculo de comissão premium!");

        CalculadoraComissao calculadora = new CalculadoraComissao(new ComissaoPremium());

        for (double valorDaVenda : VALORES_MONETARIOS_PARA_TESTE)
            System.out.println(valorDaVenda + " -> " + calculadora.calcular(valorDaVenda));

        System.out.println("");

    }

    private static void testarCalculadoraParceiro() {

        System.out.println("Testando o cálculo de comissão parceiro!");

        CalculadoraComissao calculadora = new CalculadoraComissao(new ComissaoParceiro());

        for (double valorDaVenda : VALORES_MONETARIOS_PARA_TESTE)
            System.out.println(valorDaVenda + " -> " + calculadora.calcular(valorDaVenda));

        System.out.println("");

    }

    private static void testarCalculadoraProgressiva() {

        System.out.println("Testando o cálculo de comissão progressiva!");

        CalculadoraComissao calculadora = new CalculadoraComissao(new ComissaoProgressiva());

        for (double valorDaVenda : VALORES_MONETARIOS_PARA_TESTE)
            System.out.println(valorDaVenda + " -> " + calculadora.calcular(valorDaVenda));

        System.out.println("");

    }
}