# PARA FAZER

| Item | Responsável | Estado |
| ---- | ----------- | ------ |
| 1- Implementar o vinculo de cooperado (item 3 do menu). | Miguel | OK |
| 2- Implementar o item 4 do menu. | luqueta | OK |
| 3- Implementar a regra: se o cooperado for removido, suas coletas também devem ser removidas. | pinto grande | OK |
| 4- Permitir cadastrar um material solicitando todas as informações de uma só vez, ou uma por vez. | Miguel | OK |
| 5- Conciliar a aplicação com o diagrama UML | Margola | OK |
| 6- Implementar o Cooperativa.RemoverPonto(PontoColeta) | Lusguinha | OK |
| 7- Implementar o Cooperativa.RemoverCooperado(Cooperado) | Lusguinha | OK |
| 8- No item 3 do menu, o correto seria vincular cooperados aos pontos. Não é isso que está sendo feito. | Miguel | OK |
| 9- Implementar o PontoColeta.RemoverCooperado(Cooperado) | Lusguinha | OK |

lucas, como precisamos gozar os dois overload de dados do cooperado, ja atualizei, porem precisamos atualizar o item 3 e 4 
da uma olhada no que eu fiz e bate no que falta do seu

somente o case 4

case 3:
                        Console.WriteLine("\n--- VINCULAR COOPERADO A PONTO ---");
                        
                        Console.Write("Digite o Nome do Ponto de Coleta: ");
                        string buscaPonto = Console.ReadLine();
                        PontoColeta ponto = coop.GetPontos().FirstOrDefault(p => p.Nome == buscaPonto);

                        Console.Write("Digite o CPF do Cooperado: ");
                        string buscaCpf = Console.ReadLine();
                        Cooperado cooperado = coop.GetCooperados().FirstOrDefault(c => c.CPF == buscaCpf);

                        // Valida se os dois foram encontrados
                        if (ponto != null && cooperado != null)
                        {
                            coop.Vincular(cooperado, ponto);
                            Console.WriteLine("\nSucesso! Cooperado vinculado ao ponto de coleta.");
                        }
                        else
                        {
                            Console.WriteLine("\nFalha na vinculação:");
                            if (ponto == null) Console.WriteLine("- Ponto de coleta não encontrado.");
                            if (cooperado == null) Console.WriteLine("- Cooperado não encontrado pelo CPF.");
                        }
                        break;

                    case 4:
                        Console.WriteLine("\n--- CADASTRO DE MATERIAL ---");
                        Console.Write("Digite o CPF do Cooperado que fez a coleta: ");
                        string cpfMat = Console.ReadLine();
                        
                        Cooperado cMat = coop.GetCooperados().FirstOrDefault(c => c.CPF == cpfMat);

                        if (cMat != null)
                        {
                            Console.WriteLine("\nTipos disponíveis:");
                            foreach (TipoMaterial tipo in Enum.GetValues(typeof(TipoMaterial)))
                            {
                                // Usando ToString() padrão do C#
                                Console.WriteLine($"{(int)tipo} - {tipo.ToString()}");
                            }

                            Console.Write("Tipo do material (número): ");
                            int tipoMaterialInput = int.Parse(Console.ReadLine());
                            TipoMaterial tipoMaterial = (TipoMaterial)tipoMaterialInput;

                            Console.Write("Peso (kg): ");
                            double peso = double.Parse(Console.ReadLine()); // Tem que ser double para bater com a classe Material

                            Console.Write("Data de coleta (ex: 12/05/2024): ");
                            DateTime dataColeta = DateTime.Parse(Console.ReadLine());

                            Console.WriteLine("\nTestar qual Overload?");
                            Console.WriteLine("1 - Enviar o Objeto Inteiro");
                            Console.WriteLine("2 - Enviar os Dados Separados");
                            Console.Write("Opção: ");
                            string escolha = Console.ReadLine();

                            if (escolha == "1")
                            {
                                // Método 1 (Objeto)
                                Material novoMat = new Material(tipoMaterial, peso, dataColeta);
                                cMat.RegistrarMaterial(novoMat);
                            }
                            else
                            {
                                // Método 2 (Sobrecarga / Dados primitivos)
                                cMat.RegistrarMaterial(tipoMaterial, peso, dataColeta);
                            }

                            Console.WriteLine("\nMaterial registrado com sucesso!");
                        }
                        else
                        {
                            Console.WriteLine("\nCooperado não encontrado.");
                        }
                        break;