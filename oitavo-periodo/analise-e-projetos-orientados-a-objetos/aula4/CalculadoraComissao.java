import java.lang.IllegalArgumentException;

public class CalculadoraComissao {

    private IComissao calculadora;

    public CalculadoraComissao(IComissao calculadora) {

        if (calculadora == null)
            throw new IllegalArgumentException("A regra de cálculo não foi informada!");

        this.calculadora = calculadora;
    }

    public double calcular(double valorDaVenda) {
        return calculadora.calcularComissao(valorDaVenda);
    }
}