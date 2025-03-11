# Exercícios de revisão sobre a camada OSI.
1. Explique a diferença entre a camada de Rede e Transporte.

A camada de rede é responsável pelo roteamento da informação para as máquinas que são destino da informação através de seus endereços físicos (MAC Address).

A de transporte é responsável por converter a informação de software para hardware. Nesta etapa, o dado que fora compactado, criptografado e vinculado à uma sessão, será convertido para informações binárias. Para o receptor da informação, nesta camada, o dado recebido será convertido para o nível de software.

2. Explique como acontece a transformação da informação em bit, segundo o modelo OSI.

No emissor, o dado presente na camada de aplicação é selecionado pelo usuário para que seja enviada ao receptor. Na camada de apresentação, o dado será compactado e criptografado. Na de sessão, serão agregados aos dados informações referentes ao emissor e o receptor da informação. Na de transporte, o dado será convertido para binário.

A conversão é feita com base em operações de resto, realizadas ao nível de hardware da máquina, seguindo a especificação da ASCII, onde cada registrador terá um número de 8 bits, que representa um caractere.

Uma vez convertida em bits, a informação passa a ser replicada por sinais elétricos, ou pulsos de luz, a depender da camada do meio físico.

3. Explique a camada de enlace de rede.

Ela é responsável por unir os bits recebidos pela rede em frames (um pequeno conjunto).
Nesta etapa, com o uso do bit verificador, também é verificado se o dado recebido e agrupado se encontra corrompido.
Vale ressaltar que, embora agrupados, os dados continuam desfigurados nesta camada.

4. Pensando no modelo OSI da camada 7 para a 1, qual a primeira camada que trata do Hardware? Explique ela.

Camada de transporte. Ela é responsável por converter a informação de software para hardware (bits), ou vice e versa.