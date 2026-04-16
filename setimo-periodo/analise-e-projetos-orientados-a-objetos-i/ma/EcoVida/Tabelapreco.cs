
namespace EcoVida
{
    public static class TabelaPreco
    {
        public static double GetPreco(TipoMaterial tipo)
        {
            return tipo switch
            {
                TipoMaterial.Papel => 0.50,
                TipoMaterial.Plastico => 1.20,
                TipoMaterial.Vidro => 0.80,
                TipoMaterial.Metal => 2.50,
                TipoMaterial.Organico => 0.10,
                _ => 0
            };
        }
    }
}