1) Conforme ultima aula, explique ao menos 1 protocolo de cada camada do modelo TCP/IP.
- Camada "Aplicação": DHCP, que é responsável pela configuração dinâmica dos endereços IP de cada equipamento da rede.
- Camada "Transporte": TCP, controla o fluxo para que não hajam congestionamentos na comunicação, refaz a transmissão de datagramas falhos e faz a ordenação dos pacotes que foram transmitidos.
- Camada "Rede": ICMP, reponsável por determinar se algum determinado host está acessível na rede.
- Camada "Enlace": ARP, que resolve os IPs com base nos endereços MAC.

2) O Protocolo SNMP é utilizado para qual finalidade, cite um exemplo da sua utilização.
É um protocolo utilizado para o monitoramento do equipamento de redes, como roteadores, computadores, etc.

3) Com relação a protocolos da camada de Roteamento, existe um protocolo que utiliza um algoritmo para encontrar a melhor rota, qual o nome dele, explique como ele funciona e qual topologia de rede comumente é utilizado.
O OSPF é um protocolo para o roteamento dinâmico entre os roteadores de borda (assim como o RIP), porém, busca sempre o caminho mais curto. Utiliza o algoritmo de Dijkstra. Estrela estendida.

4) Na camada de aplicação, é utilizado diversos protocolos, e cada um deles em seu porta padrão. Cite ao menos 3 protocolos, para que servem e qual a porta padrão dele.
- DHCP: Utilizado para a criação de endereços IPs. Portas 67 e 68.
- DNS: Utilizado para a resolução dos endereços IPs com base em domínios. Porta 53.
- HTTPS: Protocolo seguro para transmissão de hipertexto. Usa a porta 443.

5) O protocolo BGP é utilizado para Roteamento, de qual forma?
Ele cria uma tabela que lista as rotas para interligar os sistemas autônomos (redes). Utilizado para a comunicação entre os ASes.

6) Com base no modelo TCP/IP podemos ter protocolos da camada de acesso a rede, qual o padrão de protocolo de acesso a rede para comunicação de radio frequência utilizando 5Ghtz? Explique.
Este é o protocolo 802.11, comumente conhecido como Wi-Fi. É dividido em a, b, g, n e ac. Onde o 'a', 'n' e 'ac' fazem o uso da frequência 5Ghtz para a transferência de dados.

7) Em uma rede existem protocolos como serviço, que se tornam essenciais em uma rede, para o seu funcionamento, cite ao menos um deles e explique.
SMTP. Este protocolo é utilizado para enviar e-mails na rede.

8) No modelo TCP/IP existem dois principais protocolos de transporte, explique cada um deles, e de exemplo. Complemente mencionando um protocolo de aplicação que utiliza cada um deles.
- TCP
    - Controla o fluxo para que não hajam congestionamentos na comunicação, refaz a transmissão de datagramas falhos e faz a ordenação dos pacotes que foram transmitidos.
    - Usamos ele quando precisamos garantir que a informação chegará completa no destino.
    - O protocolo faz o uso do bit de verificação para saber se o dado está completo ou não.
- UDP
    - Não controla fluxo.
    - Não faz o reenvio em caso de falhas.
    - Não realiza a ordenação dos dados.
    - Protocolo mais rápido, devido ao fato de não haver validação do dado estar completo.
    - O Skype é um exemplo que implementa o uso deste protocolo.

O SSH utiliza o TCP, enquanto o DHCP utiliza o UDP.