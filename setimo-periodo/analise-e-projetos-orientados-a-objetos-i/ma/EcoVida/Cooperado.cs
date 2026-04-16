using System;
using System.Collections.Generic;

namespace EcoVida
{
    public class Cooperado
    {
        public string Nome { get; private set; }
        public string CPF { get; private set; }

        private List<Material> materiais;

        public Cooperado(string nome, string cpf)
        {
            Nome = nome;
            CPF = cpf;
            materiais = new List<Material>();
        }
        public void RegistrarMaterial(Material m)
        {
            materiais.Add(m);
        }
        public void RegistrarMaterial(TipoMaterial tipo, double peso, string data)
        {
            Material m = new Material(tipo, peso, data);
            materiais.Add(m);
        }

        public double CalcularTotal()
        {
            double soma = 0;
            foreach (Material m in materiais)
            {
                soma += m.CalcularValor();
            }
            return soma;
        }

        public List<Material> GetMateriais()
        {
            return materiais;
        }

        public void RemoverTodasAsColetas()
        {
            materiais.Clear();
        }
    }
}