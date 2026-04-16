namespace EcoVida
{
    class Program
    {
        static void Main()
        {
            Cooperativa coop = new Cooperativa("EcoVida");

            Console.Clear();
            Console.WriteLine("=== FHO-EcoVida: Sistema de Coleta ===");

            int opcao;
            do
            {
                Console.WriteLine("\n1 - Cadastrar Cooperado");
                Console.WriteLine("2 - Cadastrar Ponto");
                Console.WriteLine("3 - Vincular Cooperado - Ponto");
                Console.WriteLine("4 - Registrar Material");
                Console.WriteLine("5 - Remover Cooperado");
                Console.WriteLine("6 - Relátorio Completo dos Cooperados");
                Console.WriteLine("7 - Vincular Material - Cooperado");
                Console.WriteLine("0 - Sair");

                opcao = int.Parse(Console.ReadLine().ToString());

                switch (opcao)
                {
                    case 1:
                        Console.WriteLine("CADASTRO COOPERADO");
                        Console.Write("Nome: ");
                        string nome = Console.ReadLine().ToString();
                        Console.Write("CPF: ");
                        string cpf = Console.ReadLine().ToString();

                        coop.AdicionarCooperado(new Cooperado(nome, cpf));
                        break;

                    case 2:
                        Console.WriteLine("CADASTRO PONTO");
                        Console.Write("Nome do ponto: ");
                        string np = Console.ReadLine().ToString();
                        Console.Write("Endereço: ");
                        string end = Console.ReadLine().ToString();

                        coop.AdicionarPonto(new PontoColeta(np, end));
                        break;

                    case 3:
                        Console.WriteLine("\n--- VINCULAR COOPERADO A PONTO ---");
                        Console.Write("Nome do Ponto de Coleta: ");
                        string buscaPonto = Console.ReadLine();
                        PontoColeta ponto = coop.GetPontos().FirstOrDefault(p => p.Nome == buscaPonto);

                        Console.Write("CPF do Cooperado: ");
                        string buscaCpf = Console.ReadLine();
                        Cooperado cooperado = coop.GetCooperados().FirstOrDefault(c => c.CPF == buscaCpf);

                        if (ponto != null && cooperado != null)
                        {
                            coop.Vincular(cooperado, ponto);
                            Console.WriteLine("\nCooperado vinculado ao ponto de coleta.");
                        }
                        else
                        {
                            Console.WriteLine("\nFalha na vinculação:");
                            if (ponto == null) Console.WriteLine("- Ponto de coleta não encontrado.");
                            if (cooperado == null) Console.WriteLine("- Cooperado não encontrado pelo CPF.");
                        }

                        break;

                    case 4:
                        Console.WriteLine("CADASTRO MATERIAL");

                        foreach (TipoMaterial tipo in Enum.GetValues(typeof(TipoMaterial)))
                        {
                            Console.WriteLine($"{(int)tipo} - {tipo}");
                        }

                        Console.Write("Tipo do material: ");
                        int tipoMaterialInput = int.Parse(Console.ReadLine());

                        TipoMaterial tipoMaterial = (TipoMaterial)tipoMaterialInput;

                        Console.Write("Peso: ");
                        float peso = float.Parse(Console.ReadLine());

                        Console.Write("Data de coleta: ");
                        string dataColeta = Console.ReadLine();
                        
                        Material m = new Material(tipoMaterial, peso, dataColeta);
                        coop.AdicionarMaterial(m);

                        break;
                    case 5:
                        Console.WriteLine("Digite o CPF do cooperado para remover:");
                        string cpfBusca = Console.ReadLine();

                        Cooperado cooperadoRemover = null;
                        List<Cooperado> cooperadosCadastrados = coop.GetCooperados();
                        foreach (Cooperado c in cooperadosCadastrados)
                        {
                            if (c.CPF == cpfBusca)
                            {
                                cooperadoRemover = c;
                            }
                        }
                        if (cooperadoRemover != null)
                        {
                            cooperadoRemover.RemoverTodasAsColetas();
                            cooperadosCadastrados.Remove(cooperadoRemover);
                            Console.WriteLine("Cooperado e coletas removidos com sucesso!");
                        }
                        else
                        {
                            Console.WriteLine("Cooperado não encontrado.");
                        }
                        break;
                    case 6:
                        Console.WriteLine("\n--- RELATÓRIO DE COOPERADOS ---");
                        coop.RelatorioGeral();
                        break;
                    case 7:
                        Console.WriteLine("\n--- VINCULAR MATERIAL / COOPERADO ---");

                        Console.Write("CPF do Cooperado: ");
                        string cpf2 = Console.ReadLine();
                        Cooperado cooperado2 = coop.GetCooperados().FirstOrDefault(c => c.CPF == cpf2);

                        Console.WriteLine("\n--- MATERIAIS DISPONÍVEIS ---");
                        foreach (Material mm in coop.GetMateriais())
                        {
                            Console.WriteLine($"ID: {mm.getID()}, Tipo: {mm.Tipo}, Peso: {mm.Peso}, Data: {mm.Data}");
                        }

                        Console.Write("ID do Material (digite 0 para cadastrar): ");
                        int idMaterial = int.Parse(Console.ReadLine());
                        Material material = coop.GetMateriais().FirstOrDefault(m => m.getID() == idMaterial);

                        if (idMaterial == 0)
                        {
                            Console.WriteLine("CADASTRO MATERIAL");

                            foreach (TipoMaterial tipo in Enum.GetValues(typeof(TipoMaterial)))
                            {
                                Console.WriteLine($"{(int)tipo} - {tipo}");
                            }

                            Console.Write("Tipo do material: ");
                            int tipoMaterialInput2 = int.Parse(Console.ReadLine());

                            TipoMaterial tipoMaterial2 = (TipoMaterial)tipoMaterialInput2;

                            Console.Write("Peso: ");
                            float peso2 = float.Parse(Console.ReadLine());

                            Console.Write("Data de coleta: ");
                            string dataColeta2 = Console.ReadLine();

                            Material m2 = new Material(tipoMaterial2, peso2, dataColeta2);
                            coop.AdicionarMaterial(m2);
                            cooperado2.RegistrarMaterial(m2);
                            Console.WriteLine("Material cadastrado e vinculado ao cooperado com sucesso!");
                        }

                        if (cooperado2 != null && material != null)
                        {
                            cooperado2.RegistrarMaterial(material);
                            Console.WriteLine("Material vinculado ao cooperado com sucesso!");
                        }
                        else
                        {
                            Console.WriteLine("Falha no vínculo:");
                            if (cooperado2 == null) Console.WriteLine("- Cooperado não encontrado.");
                            if (material == null) Console.WriteLine("- Material não encontrado.");
                        }

                        break;
                }
            } while (opcao != 0);
        }
    }
}