# Aula 1 - 18/02/2025
## História das redes de computadores

A primeira experiência com redes de computadores se deu em 1965 por Lawrence Roberts e Thomas Merril, um em na universidade em Massachusetts e outro na Califórnia.

A internet teve seu início em 1969, para uso militares e em universidades.

Em 1996, 30 mil pessoas tinham acesso a internet no Brasil.

## Comunicação
* Informação: texto, voz, imagem convertida em sinal digital ou analógico.
* Transmissão: smartphone, computador ou tablet que deseja enviar essa informação.
* Canal: meio em que a comunicação passa, pode ser pelo ar, fio de cobre ou fibra ótica.
* Receptor: computador, smartphone ou tablet que receberá a informação.
* Protocolo: conjunto de regras pré-definidas entre o emissor e o receptor.

## Definição de redes

Segundo Tenenbaum:
- Conjunto de módulos e processadores capazes de trocar informações e recursos entre si.
- Não há limite de participantes de uma rede.
- Ativos de rede são equipamentos que necessitam de eletricidade para atuar na rede.*
- Passivos de rede são dispositivos que não necessitam de energia.*

> \* Definição simplificada, não definitiva.

## Tipos de rede
O primeiro tipo de rede é o ponto a ponto (P2P), onde os integrantes da rede compartilham informações e recursos entre si, sem a necessidade da centralização (em um servidor, por exemplo) do dado.

> "O Torrent é um exemplo de comunicação ponto a ponto".

O outro tipo é a rede cliente/servidor, onde os dispositivos (clientes) tem acesso a informação e recursos compartilhados que estão centralizados em um servidor (host).

## Redes determinísticas e não determinísticas

Nas determinísticas, há o controle de tempo para a inserção de informações na rede.

Contrária à primeira, as não determiníticas não possuem controle de tempo, cada host pode enviar suas informações na quantidade que quiser e na hora que quiser.

> É como se a determinística fosse uma partida de volei comum, e a não determinística é uma partida de vôlei com inúmeras bolas sendo utilizadas ao mesmo tempo.

## Topologia de rede

É a disposição física o qual se conecta os nós (componentes da rede) de uma rede mediante a combinação de padrões e protocolos.

### Barramento
Todos os dispositivos recebem a informação que era destinada à um dos dispositivos, dado que estão interligados pelo mesmo cabo. O dispositivo ao qual a informação não é o destino, ignora os pacotes recebidos.
A desvantagem é a lentidão, segurança e fragilidade da rede, dado que o rompimento em qualquer local do cabo, tornará todos os dispositivos offline.

![topologia barramento](imagens/imagens/image.png)

### Estrela
Nesta topologia, os dispositivos da rede são interligados em um nó central.
A vantagem é que os dispositivos são independentes, porém, um problema no nó central pode parar a rede toda.

![topologia estrela](imagens/imagens/image-1.png)

### Anel
Cada dispositivo é interligado com outros dois dispositivos. A vantagem é que um dispositivo será isolado da rede somente se a comunicação com os dois dispositivos falhar.

![](imagens/image-2.png)

### Estrela estendida
É uma evolução da topologia estrela, com vários nós centralizadores, que por si, são centralizados em outro nó.

![](imagens/image-3.png)

### Topologia completa
Por fim, na topologia completa, todos os nós são interligados entre si.
A comunicação é mais rápida e direta, porém, é uma topologia que apresenta maiores custos de desenvolvimento e manutenção.

![](imagens/image-4.png)

### Exemplo prático
Na FHO, os laboratórios possuem a topologia estrela. Entre os laboratórios dos prédios, temos a estrela estendida. Entre os prédios e o servidor central, temos a topologia anel.

## Abrangência de redes
Para a classificação das redes é considerado o tipo de conexão e a amplitude geográfica.
- PAN (Personal Area Network): rede que conecta dispositivos pessoais, como o _smartphone_ e o fone de ouvido.
- LAN (Local Area Network): abrange um prédio ou campus.
- MAN (Metropolitan Area Network): abrange uma cidade.
- WAN (Wide Area Network): abrange o espaço de um país.

A internet é a conexão entre as "ANs", em ordem decrescente de tamanho geográfico.

---

# Aula 2 - 25/02/2025
## Modelo de Referência OSI (ISO 7498)
- É um modelo de referência que dita algumas regras (padrões) a respeito da comunicação entre dispositivos de diferentes tecnologias, hardware e softwares.

![modelo osi](imagens/image-5.png)
![types of attaks at osi layers](imagens/image-7.png)

> Das camadas 1 a 3, estamos tratando de hardwares.
> O TCP/IP é uma implementação das camadas OSI.

### Camada Física
- Responsável pela transmissão dos _bits_ através do meio.ls
- É a camada que faz a leitura dos pulsos no meio de transmissão, como os do cabo de rede.
- Tópicos envolvidos:
    - Topologia (estudada na aula passada);
    - Meios de transmissão (estudada na aula passada);
    - Sentido de transmissão (simples, half-duplex e full-duplex);
    - Sincronismo;
    - Dentre outros.

### Camada de Enlace
- É a camada que lida com o tráfego de quadros (grupo de bits) transmitidos.
> Ela une alguns bits e grupos, chamadas de quadros ou frames.
- Nela, também é determinada as formas de controle de acesso ao meio de transmissão.
- Os dados nesta camada ainda são desfigurados.
- Ela determina, através de um bit de controle, se a comunicação entre o receptor e o emissor está corrompida ou não. Caso o bit de controle não seja recebido por uma das partes, ela solicita o valor novamente ao emissor.
- Tópicos envolvidos:
    - Controle de acesso ao meio: token, CSMA, CSMA/CD, etc.
    - Técnicas de controle de erros: paridade, check sum, CRC, etc.

> Um CRC é um mecanismo de detecção de erro comumente usado em redes de computador e de armazenamento para identificar dados alterados ou corrompidos durante a transmissão. - Cisco.

### Camada de Rede
- Padroniza e define os endereços das máquinas da rede de coputadores.
- Gere o tráfego e rotas da rede.

### Camada de Transporte
- Transição (conversão) entre o software e o hardware.
- Abstrai a evolução dos hardwares para não afetar as camadas superiores.
- Valida se a informação recebida ou enviada está completa, antes ou após o empacotamento para transmissão.

### Camada de Sessão
- Permite que usuários possam estabelecer sessões entre as máquinas da rede.
- Nela, também é tratada a etapa de sincroninismo da comunicação, caso tenha havido alguma oscilação no processo.
- Gerenciamento de atividades (transações).

### Camada de Apresentação
- E uma camada de tradução dos dados, chamada de codificação, para o uso da próxima camada.
- Realiza uma criptografia básica do dado.
- Compacta os dados.

### Camada da Aplicação
- Esta camada oferece o acesso as aplicações que estão sendo executadas nos computadores ligados na rede.

### Exemplo prático
> Conteúdo retirado do [GeekForGeeks](https://www.geeksforgeeks.org/open-systems-interconnection-model-osi).

Let us suppose, Person A sends an e-mail to his friend Person B.

Step 1: Person A interacts with e-mail application like Gmail, outlook, etc. Writes his email to send. (This happens at Application Layer).

Step 2: At Presentation Layer, Mail application prepares for data transmission like encrypting data and formatting it for transmission.

Step 3: At Session Layer, there is a connection established between the sender and receiver on the internet.

Step 4: At Transport Layer, Email data is broken into smaller segments. It adds sequence number and error-checking information to maintain the reliability of the information.

Step 5: At Network Layer, addressing of packets is done in order to find the best route for transfer.

Step 6: At Data Link Layer, data packets are encapsulated into frames, then MAC address is added for local devices and then it checks for error using error detection.

Step 7: At Physical Layer, Frames are transmitted in the form of electrical/ optical signals over a physical network medium like ethernet cable or WiFi.

After the email reaches the receiver i.e. Person B, the process will reverse and decrypt the e-mail content. At last, the email will be shown on Person B email client.

---

# Aula 3 - 11/03/2025

## Modelos TCP/IP
- Ele é a implementação do modelo de referência OSI.
- Dentro das camadas do TCP/IP, cada protocolo tem a sua porta padrão por convenção. Exemplo: SMTP: 25 ou 587.
- O modelo é formado por quatro camadas.
![alt text](imagens/image-6.png)

> Protolocos por camada  
> ![alt text](imagens/image-9.png)

> Exemplo prático apresentado pelo professor
>   - Aplicação: dado bruto que será transmitido na rede.
>   - Transporte: o dado será encapsulado com os dados das portas do protocolo que será usado (TCP ou IP).
>   - Rede: onde os dados serão encapsulados novamente, com os endereços IP do emissor e receptor.
>   - Enlace: onde será feito o encapsulamento com o endereço MAC, para a transmissão.

### Aplicação
Nesta camada estão as aplicações que serão utilizadas pelo usuário para realizar a comunicação. Elas fazem o uso das camadas para a comunicação em rede.

### Transporte
- É a camada responsável pela transferência de dados entre duas máquinas.
- A camada de transporte oferece para o nível de aplicação um conjunto de funções e procedimentos para o acesso ao sistema de comunicação de modo a permitir a criação e a utilização de aplicações de forma independente da implementação da rede. As interfaces dos sistemas operativos, como o socket ou TLI (Unix) e Winsocket (Windows) fornecem um conjunto de funções-padrão para permitir tal acesso (driver da placa de rede).
- Principais protocolos desta camada: UDP (não orientada a conexão) e TCP (orientada a conexão).

* TCP (Transmission Control Protocol)
    - Controla o fluxo para que não hajam congestionamentos na comunicação, refaz a transmissão de datagramas falhos e faz a ordenação dos pacotes que foram transmitidos.
    - Usamos ele quando precisamos garantir que a informação chegará completa no destino.
    - O protocolo faz o uso do bit de verificação para saber se o dado está completo ou não.

* UDP (User Datagram Protocol)
    - Não controla fluxo.
    - Não faz o reenvio em caso de falhas.
    - Não realiza a ordenação dos dados.
    - Protocolo mais rápido, devido ao fato de não haver validação do dado estar completo.
    - O Skype é um exemplo que implementa o uso deste protocolo.

### Internet
- Responsável pelas permissões do envio dos pacotes e garantia de que os dados cheguem ao destino final.
- Realiza o roteamento entre os equipamentos da rede.
- Protocolos: IP e ICMP.

* IP (Internet Protocol)
    - Realiza roteamento e endereçamento de pacotes de dados para que eles possam viajar pelas redes e chegar ao destino correto.
    - Ele atribui um endereço exclusivo, dentro da rede, para cada equipamento, a fim de que ele possa ser encontrado, para completar o processo de comunicação.
    - Utiliza 32 bits para representar o endereço da máquina, de acordo com o IPv4.

* ICMP (Internet Control Message Protocol)
    - Utilizado para determinar se o host está acessível.

> O comando `ping` utiliza o protocolo ICMP para verificar se um host está disponível. Ao utilizá-lo, chegamos até a segunda camada do TCP.
> ```
> C:\Users\ARS_USER_B10L1_10>ping 172.20.51.178
> 
> Disparando 172.20.51.178 com 32 bytes de dados:
> Resposta de 172.20.51.178: bytes=32 tempo=1ms TTL=128
> Resposta de 172.20.51.178: bytes=32 tempo=1ms TTL=128
> Resposta de 172.20.51.178: bytes=32 tempo=1ms TTL=128
> Resposta de 172.20.51.178: bytes=32 tempo=1ms TTL=128
> 
> Estatísticas do Ping para 172.20.51.178:
>   Pacotes: Enviados = 4, Recebidos = 4, Perdidos = 0 (0% de
>             perda),
> Aproximar um número redondo de vezes em milissegundos:
>     Mínimo = 1ms, Máximo = 1ms, Média = 1ms
> ```

> Com o Wireshark, podemos analisar todo o conteúdo que entra e sai do computador.
> Exemplo de um ping que foi feito na minha máquina no laboratório:
> ![alt text](imagens/image-8.png)

### Enlace
TODO

> [Indicação do professor](https://www.youtube.com/watch?v=HNQD0qJ0TC4&pp=ygUHTklDSy5CUg%3D%3D).

---

# Aula 4 - 18/03/2025

<TODO>

- Protocolos: Ethernet, SFP, 1000 base x e 802.11 (a, b, g, n e ac).

---

# Aula 5 - 25/03/2025 - Protocolos da camada de Internet do TCP/IP
[Como funciona a Internet? Parte 2: Sistemas Autônomos, BGP, PTTs.](https://www.youtube.com/watch?v=C5qNAT_j63M&list=PLk5G8sJqhL_lNcPdhzVUBb_frxI5jnf7G&index=2)
[Introdução ao roteamento de pacotes IP](https://www.youtube.com/watch?v=y9Vx5l-th9Y)

## Sistemas Autônomos
Os sistemas autônomos são as grandes redes que, combinada aos outros sistemas autônomos, formam a internet.
![sistemas autônomos](imagens/image-12.png)

Esses sistemas se ligam com base em acordos comerciais, entre empresas e países, por exemplo.

> "A internet é a ligação de várias WANs".

## Protocolos de roteamento da camada de rede/internet
Os protocolos são separados pelo tipo da rede em questão.

### ISIS
<TODO>

### EGP
- Utilizado para a comunicação entre os ASes.

### BGP
- Cria uma tabela que lista as rotas para interligar os sistemas autônomos (redes).
- Utilizado para a comunicação entre os ASes.

### ICMP
- Utilizado para determinar se o host está acessível.

### RIP
Utilizado para o roteamento de roteadores de borda (aquele que fica na provedora de internet). Baseia-se no algoritmo vetor-distância.

### OSPF
É um protocolo para o roteamento dinâmico entre os roteadores de borda (assim como o RIP), porem, utiliza sempre o caminho mais curto. Utiliza o algoritmo de Dijkstra.

## Protocolos da camada de aplicação
### DHCP
Este protocolo dita a configuração dinâmica de endereços IPs. Por meio do serviço de DHCP, que implementa o protocolo, é atribuído para cada equipamento participante da rede, um endereço único (dentro da rede) de IP.
O serviço do DHCP fica hospedado em um servidor, onde utilizamos o recurso.

A imagem a seguir mostra o procedimento.
![alt text](imagens/image-10.png)

### DNS
Ele é responsável por resolver os domínios, determinando o endereço IP do serviço que está sendo acessado.
[Como funciona a Internet? Parte 3: DNS](https://www.youtube.com/watch?v=ACGuo26MswI).

> No endereço `fho.edu.br`, está oculto o "." no final do endereço. Na resolução do DNS, cada servidor redireciona a resolução, da esquerda para a direita, para outro servidor que contem a informação

### FTP/SFTP
São protocolos para transferência de arquivos.

### SSH
Protocolo para o acesso à prompts de comando remotos.

### RDP
Protocolo de acesso remoto para os ambientes Windows.

### SNMP
É um protocolo utilizado para o monitoramento do equipamento de redes.

### IMAP
Protocolo para o recebimento e-mail.

### POP3
Semelhante ao IMAP, porém, o recebimento é feito através do download dos e-mails do servidor para a máquina do usuário.

### SMTP
Protocolo para o envio de e-mails.

> ![alt text](imagens/image-12.png)

### HTTP
Protocolo utilizado para a transmissão de hipertexto e hipermídia.

### HTTPS
Este protocolo fornece a transmissao de hipertexto e hipermidia tambem, porém, utiliza criptografia.

### NTP
Utilizado para a sincronização de data e hora nos equipamentos da rede.

## Protocolos de enlace
### Ethernet
protoclo de conexão que garante como os hardwares se comunicam através do meio físico.

### ARP
Resolve o IP com base no MAC.

### PPP
<TODO>

---

# Aula 6 - 01/04/2025 - 

## Multiplexação de sinais

A multiplexação de sinais é a transmissão de informações simultâneas por um mesmo canal. Neste cenário, as informações que precisam chegar ao destinatário são segmentadas, e transmitidas juntas.

![alt text](https://gammak.com.br/wp-content/uploads/2024/02/WDM-demonstracao.gif)

## NTP
Como citado anteriormente, o NTP é responsável pela sincronização de data e hora entre equipamentos na rede. O Brasil possui seu próprio servitor, o NTP.br.
[Vídeo da NIC.BR](https://www.youtube.com/watch?v=hyCrd0x2yGg)

## Governança
[Vídeo NIC.BR](https://www.youtube.com/watch?v=ZYsjMEISR6E)