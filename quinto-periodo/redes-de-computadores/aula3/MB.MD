# Lista de Exercícios – Redes de Computadores

1) Explique as 4 principais topologias de redes.
    * Barramento: Todos os dispositivos recebem a informação que era destinada à um dos dispositivos, dado que estão interligados pelo mesmo cabo. O dispositivo ao qual a informação não é o destino, ignora os pacotes recebidos. A desvantagem é a lentidão, segurança e fragilidade da rede, dado que o rompimento em qualquer local do cabo, tornará todos os dispositivos offline.
    * Estrela: Nesta topologia, os dispositivos da rede são interligados em um nó central. A vantagem é que os dispositivos são independentes, porém, um problema no nó central pode parar a rede toda.
    * Estrela estendida: Cada dispositivo é interligado com outros dois dispositivos. A vantagem é que um dispositivo será isolado da rede somente se a comunicação com os dois dispositivos falhar.
    * Anel: É uma evolução da topologia estrela, com vários nós centralizadores, que por si, são centralizados em outro nó.

2) Para se ter comunicação em redes de computadores do que precisamos? Explique cada um dos elementos.
    * Emissor: aquele que provém a informação.
    * Canal: o meio o qual a informação será transmitida.
    * Receptor: o destinatário da informação.

3) Quais os tipos de Redes que existe? Explique cada um deles.
O primeiro tipo de rede é o ponto a ponto (P2P), onde os integrantes da rede compartilham informações e recursos entre si, sem a necessidade da centralização (em um servidor, por exemplo) do dado.
O outro tipo é a rede cliente/servidor, onde os dispositivos (clientes) tem acesso a informação e recursos compartilhados que estão centralizados em um servidor (host).

4) Explique como é estruturada a Internet.
A internet é uma rede de comunicação entre diferentes dispositivos no mundo todo. A comunicação segue a definição do modelo de referência OSI (Interconexão de Sistemas Abertos), que dita sete camadas (etapas) para que a comunicação ocorra: física, enlace, rede, transporte, sessão, apresentação e aplicação.

5) Cite pelo menos uma característica importante de cada uma das camadas do modelo OSI.
    * Física: Responsável pela transmissão de bits através do meio físico (cabos, ondas eletromagnéticas, etc.).
    * Enlace de Dados: Garante a comunicação confiável entre dispositivos adjacentes, corrigindo erros de transmissão.
    * Rede: Responsável pelo roteamento dos pacotes entre redes diferentes, utilizando endereços IP.
    * Transporte: Assegura a entrega confiável ou não dos dados, usando protocolos como TCP e UDP.
    * Sessão: Estabelece, mantém e finaliza sessões de comunicação entre aplicações.
    * Apresentação: Faz a conversão e compressão dos dados, garantindo que diferentes sistemas possam interpretá-los corretamente.
    * Aplicação: Interface entre o usuário e a rede, fornecendo serviços como e-mail, web e transferência de arquivos.

6) Explique como é feito o encapsulamento do TCP/IP.
    * Aplicação: Os dados da aplicação (exemplo: um e-mail) são gerados.
    * Transporte: O TCP (ou UDP) adiciona um cabeçalho com informações como portas de origem e destino.
    * Internet: O IP adiciona um cabeçalho com os endereços de origem e destino.
    * Acesso à Rede: O quadro de dados é montado, incluindo o cabeçalho da camada de enlace e o tráiler para controle de erros, antes de ser transmitido pela camada física.

7) Na camada de Enlace do modelo OSI, explique como é o funcionamento dela.
A camada de Enlace do modelo OSI tem a função de garantir uma comunicação confiável entre dois dispositivos diretamente conectados. Ela divide os dados em quadros e adiciona informações de controle, como endereços MAC. Também gerencia o acesso ao meio de transmissão para evitar colisões.

8) No modelo TCP/IP temos uma camada que é responsável pelo envio da informação, qual é essa camada, e quais os tipos de protocolos de envio da informação? Explique cada um deles.
Camada de transporte. Ela utiliza dois protocolos:
- TCP
    - Confiável, orientado à conexão.
    - Garante a entrega ordenada e sem erros dos pacotes.
    - Utilizado em aplicações como HTTP, e-mails e transferência de arquivos.
- UDP
    - Não confiável, sem garantia de entrega ou ordem.
    - Menos sobrecarga, mais rápido.
    - Usado em streaming, jogos online e VoIP.

9) Explique as 7 camadas do modelo OSI.
    - Física: Define os meios físicos de transmissão (cabos, sinais elétricos, ondas de rádio).
    - Enlace de Dados: Controla o acesso ao meio físico, detecta e corrige erros.
    - Rede: Roteia os pacotes entre redes diferentes (exemplo: IP).
    - Transporte: Garante a comunicação ponta a ponta e pode oferecer confiabilidade (exemplo: TCP, UDP).
    - Sessão: Gerencia a comunicação entre aplicações (exemplo: autenticação, sincronização).
    - Apresentação: Faz a codificação, compressão e criptografia dos dados.
    - Aplicação: Interage diretamente com o usuário e fornece serviços de rede.

10) Explique a relação do modelo OSI com o TCP/IP.
O modelo OSI é teórico e detalhado, enquanto o modelo TCP/IP é uma aplicação real dos conceitos do modelo OSI. O TCP/IP agrupa algumas camadas do OSI, ficando assim:
    - Aplicação, Apresentação e Sessão → Aplicação
    - Transporte → Transporte
    - Rede → Internet
    - Enlace e Física → Acesso à Rede