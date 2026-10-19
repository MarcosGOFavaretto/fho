# Aula 01
- A aula será baseada no livro "Sistemas Operacionais - Tanenbaum". A ideia do professor, é que na aula, apenas seja exposto o que importa de cada capítulo.

## SMT
O Simultaneous Multithreading é uma tecnologia que permite que o Sistema Operacional trate um núcleo físico do processador como dois núcleos lógicos.

Com ela, os dois núcleos lógicos dividem os mesmos recursos do núcleo físico. Ou seja, não temos o dobro de núcleos na máquina, dado que cada thread é execultada dentro do mesmo núcleo, usando os mesmos recursos do físicos.

## Drivers
Os _drivers_ são _softwares_ que atuam como uma camada de abstração entre o Sistema Operacional e o _hardware_ da máquina, permitindo que o SO controle e utilize diferentes dispositivos, sem precisar conhecer nos detalhes o seu funcionamento.

> Exemplo:  
> 
> **Jogo → Sistema Operacional → Driver da GPU → Placa de vídeo → Imagem na tela**  
> 
> O jogo solicita ao **SO** que uma imagem seja renderizada. O **driver da GPU** traduz essas solicitações para comandos que a placa de vídeo consegue entender e executar.

# Aula 02

> Notas no bloco de notas

# Aula 03

# Aula 05 - Gerenciamento de memória

## Por que o gerenciamento de memória é necessário?

Em um ambiente com várias aplicações executando simultaneamente, dois problemas principais precisam ser resolvidos:

- **Proteção:** impedir que uma aplicação acesse ou modifique indevidamente a memória de outra aplicação ou do Sistema Operacional.
- **Relocação:** permitir que um processo seja carregado ou movido para diferentes regiões da memória física sem precisar alterar seus endereços lógicos.

O gerenciamento de memória é responsável por controlar a alocação, a utilização, a proteção e a liberação da memória, permitindo que vários processos compartilhem a RAM de maneira eficiente.

## Abstração da memória

O Sistema Operacional, com auxílio do hardware, impede que aplicações comuns acessem livremente os endereços físicos da RAM.

Em vez disso, cada processo possui seu próprio espaço de endereçamento virtual, que é independente do espaço dos demais processos.

Exemplo simplificado de dois processos com endereços virtuais iguais:

| Endereço Virtual | Endereço Físico - Processo A | Endereço Físico - Processo B |
| --- | --- | --- |
| 0x100 | 0x1100 | 0x2100 |
| 0x105 | 0x1105 | 0x2105 |
| 0x115 | 0x1115 | 0x2115 |

> Note que os dois processos utilizam os mesmos endereços virtuais, mas estes correspondem a endereços físicos diferentes. Endereços físicos também podem ser compartilhados entre processos quando o SO permite explicitamente.

A MMU (Memory Management Unit) é o hardware responsável pela tradução dos endereços virtuais para endereços físicos, utilizando mapeamentos configurados pelo Sistema Operacional.

Essa abstração é necessária por alguns motivos:

- **Segurança:** impede que um processo acesse regiões não autorizadas da memória, utilizando mecanismos de proteção.
- **Relocação:** permite alterar a localização física dos dados sem modificar os endereços virtuais utilizados pelo processo.
- **Multiprogramação:** permite executar vários processos com espaços de endereçamento independentes.
- **Memória virtual:** permite executar processos sem manter todas as suas páginas carregadas na RAM.

## Gerenciamento da memória livre

O Sistema Operacional precisa identificar quais regiões da memória física estão livres e quais estão ocupadas.

Duas estruturas apresentadas na aula são:

- **Mapa de bits:** utiliza bits para representar unidades de memória livres ou ocupadas. Por exemplo, 0 pode representar livre e 1, ocupada.
- **Listas encadeadas:** mantêm registros das regiões ocupadas e livres, contendo informações como endereço inicial e tamanho.

### Fragmentação da memória

A fragmentação ocorre quando a organização da memória provoca desperdício ou dificulta novas alocações.

- **Fragmentação interna:** existe espaço desperdiçado dentro de uma região alocada. Exemplo: reservar 8 KB para um processo que utiliza apenas 6 KB.
- **Fragmentação externa:** existe memória livre suficiente no total, mas distribuída em regiões separadas que não comportam uma solicitação contígua.

A compactação é uma técnica que movimenta regiões ocupadas para reunir espaços livres, combatendo a fragmentação externa. Entretanto, movimentar dados possui custo de processamento.

### Políticas de alocação

Estratégias para selecionar uma região livre:

| Política | Funcionamento |
| --- | --- |
| First Fit | Escolhe a primeira região livre suficientemente grande |
| Next Fit | Continua a busca a partir da última posição utilizada |
| Best Fit | Escolhe a menor região que comporta a solicitação |
| Worst Fit | Escolhe a maior região livre |

Nenhuma política é necessariamente melhor em todas as situações.

Outras técnicas complementares são o Buddy System, que divide e reúne blocos em potências de dois, e o Slab, utilizado para administrar objetos pequenos dentro de regiões de memória.

## Swapping e memória virtual

O swapping é uma estratégia que permite liberar RAM transferindo temporariamente o conteúdo de um processo para o armazenamento secundário, como SSD ou HD.

Exemplo: uma máquina possui 8 GB de RAM, mas os processos demandam, juntos, 12 GB. O SO pode retirar temporariamente processos da RAM e recuperá-los posteriormente.

No swapping clássico, o processo é transferido integralmente.

> O swapping não aumenta a quantidade de RAM física. Ele utiliza armazenamento secundário como apoio, com desempenho inferior ao da RAM.

Já a memória virtual permite que um processo execute sem estar completamente carregado na memória física.

Exemplo: uma aplicação utiliza um espaço virtual de 2 GB, mas está acessando ativamente apenas 150 MB. O SO pode manter na RAM as páginas necessárias e carregar outras conforme surgirem acessos.

Isso é possível porque os programas normalmente não utilizam todas as suas instruções e dados simultaneamente.

A memória virtual também fornece isolamento, proteção e independência entre a organização virtual e a física.

## Paginação

A página é uma unidade de tamanho fixo da memória virtual. O quadro, também chamado de moldura, é uma unidade de mesmo tamanho da memória física (RAM).

A paginação associa páginas virtuais a quadros físicos.

Ela permite distribuir as páginas de um processo por diferentes regiões da RAM, sem exigir que todo o processo ocupe uma única região física contínua.

Exemplo:
![](exemplo_mapeamento_paginas_memoria.svg)

Se uma aplicação utiliza 16 KB de espaço virtual e cada página possui 4 KB, esse espaço corresponde a quatro páginas virtuais.

Essas páginas não precisam ocupar quadros consecutivos e nem todas precisam estar residentes ao mesmo tempo.

### Tradução de endereços na paginação

Um endereço virtual pode ser dividido em:

- **Número da página:** identifica qual página virtual está sendo acessada.
- **Deslocamento (offset):** identifica a posição do dado dentro daquela página.

A tabela de páginas informa o quadro físico correspondente. O deslocamento é preservado.

Exemplo:

- Endereço virtual: 1.300
- Tamanho da página: 1.024 bytes
- Página virtual: 1
- Deslocamento: 276
- Quadro físico correspondente: 4

Endereço físico = (4 × 1.024) + 276 = 4.372.

Portanto, o endereço virtual 1.300 corresponde ao endereço físico 4.372 nesse mapeamento.

## Tabela de páginas

A tabela de páginas é uma estrutura que registra a associação entre páginas virtuais e quadros físicos, além de informações de controle.

Cada entrada pode possuir:

| Informação | Função |
| --- | --- |
| Número do quadro | Identifica a posição física da página |
| Presente/Ausente | Informa se a página está residente |
| Proteção | Controla permissões de leitura, escrita e execução |
| Referenciada (R) | Indica se a página foi acessada no período observado |
| Modificada (M) | Indica se a página foi alterada e pode precisar ser preservada |

Essas informações permitem ao SO controlar os acessos e tomar decisões sobre quais páginas devem permanecer na RAM.

### Tabelas multinível e invertidas

Quando o espaço virtual é muito grande, uma tabela de páginas linear pode consumir muita memória.

Existem alternativas:

- **Tabela multinível:** divide o mapeamento em níveis, permitindo manter estruturas apenas para regiões utilizadas.
- **Tabela invertida:** organiza as entradas em função dos quadros físicos, identificando qual página e processo ocupam cada quadro.

A principal finalidade é administrar o custo de armazenamento e consulta dos mapeamentos.

## TLB - Translation Lookaside Buffer

A **TLB** é um cache de traduções de endereços, utilizado para acelerar o processo de paginação.

Sem ela, a MMU precisaria consultar repetidamente as estruturas da tabela de páginas para traduzir endereços.

A TLB mantém traduções utilizadas recentemente.

Existem duas situações:

- **TLB Hit:** a tradução é encontrada na TLB, permitindo o acesso sem percorrer novamente a tabela.
- **TLB Miss:** a tradução não está na TLB e precisa ser obtida por outro mecanismo, como a consulta à tabela de páginas.

> Um TLB Miss não significa necessariamente que a página esteja ausente da RAM. A página pode estar presente e apenas sua tradução não estar armazenada na TLB.

Em determinados sistemas, o SO participa diretamente do tratamento dos misses da TLB. Isso não significa que a TLB seja uma estrutura de software: normalmente continua sendo hardware.

## Falta de página - Page Fault

A falta de página ocorre quando um acesso não pode ser concluído com o mapeamento disponível, exigindo tratamento pelo sistema.

Quando uma página válida está ausente da RAM, o SO precisa providenciar seu conteúdo.

O procedimento pode envolver:

1. Identificar a página e verificar se o acesso é permitido.
2. Localizar um quadro livre ou escolher uma página para substituição.
3. Preservar o conteúdo da página removida, caso necessário.
4. Disponibilizar a página solicitada na RAM.
5. Atualizar os mapeamentos e permitir que a instrução seja retomada.

Uma falta de página não exige obrigatoriamente leitura de disco. Uma página nova pode, por exemplo, ser inicializada diretamente na RAM.

Também é importante distinguir:

- **Falta menor:** pode ser resolvida sem E/S de armazenamento.
- **Falta maior:** exige E/S para recuperar o conteúdo necessário.

No tratamento de faltas, uma página limpa pode ser descartada sem gravação se seu conteúdo continuar recuperável. Uma página suja possui modificações que precisam ser preservadas antes da reutilização do quadro.

## Algoritmos de substituição de páginas

Quando não existem quadros livres suficientes, o Sistema Operacional precisa selecionar uma página para retirar da RAM.

Os algoritmos de substituição procuram realizar essa escolha, preferencialmente evitando retirar páginas que serão utilizadas novamente em breve.

### Algoritmo ótimo

Seleciona a página cujo próximo acesso ocorrerá mais distante no futuro.

É considerado ótimo porque minimiza as faltas de página para uma sequência conhecida.

Entretanto, não pode ser implementado perfeitamente na prática, pois o SO não conhece todos os acessos futuros.

### FIFO - First In, First Out

Remove a página que está há mais tempo na memória, independentemente de quando ela foi utilizada pela última vez.

Exemplo:

Memória com três quadros contendo as páginas 1, 2 e 3, nessa ordem de chegada.

Ao solicitar a página 4, o FIFO remove a página 1, mesmo que ela tenha sido acessada recentemente.

Sua vantagem é a simplicidade. A desvantagem é poder retirar páginas frequentemente utilizadas.

### LRU - Least Recently Used

Remove a página que está há mais tempo **sem ser utilizada**.

Diferentemente do FIFO, considera o último acesso, e não o momento em que a página entrou na memória.

Exemplo:

- Página 1: acessada recentemente.
- Página 2: não é acessada há muito tempo.
- Página 3: acessada após a página 2.

O LRU selecionaria a página 2.

A desvantagem é o custo para acompanhar os acessos.

> Nos slides, o professor utiliza a sigla MRU para "Menos Recentemente Usada". A sigla correta em inglês é LRU. MRU normalmente representa "Most Recently Used", outro critério de substituição.

### NUR/NRU - Não Usada Recentemente

Utiliza os bits R (Referenciada) e M (Modificada) para classificar as páginas.

| Classe | R | M | Situação |
| --- | --- | --- | --- |
| 0 | 0 | 0 | Não referenciada e não modificada |
| 1 | 0 | 1 | Não referenciada e modificada |
| 2 | 1 | 0 | Referenciada e não modificada |
| 3 | 1 | 1 | Referenciada e modificada |

O algoritmo seleciona uma página da classe de menor número que não esteja vazia.

Dessa maneira, evita preferencialmente retirar páginas referenciadas recentemente.

### Segunda Chance

É uma melhoria do FIFO.

Quando uma página candidata à remoção possui R = 1, o algoritmo concede uma segunda chance:

- Zera o bit R.
- Coloca a página no final da ordem de exame.
- Continua procurando outra página.

Quando encontra uma página com R = 0, ela pode ser substituída.

### Relógio - Clock

Implementa o princípio da Segunda Chance com uma estrutura circular e um ponteiro.

O ponteiro percorre as páginas verificando o bit R:

- **R = 1:** zera R e avança.
- **R = 0:** seleciona a página para substituição.

A vantagem é evitar movimentar constantemente páginas em uma fila.

### NFU e Envelhecimento

O **NFU (Not Frequently Used)** utiliza contadores para acompanhar a frequência aproximada de utilização das páginas.

O **Envelhecimento (Aging)** melhora essa abordagem, reduzindo gradualmente o peso de referências antigas.

Isso permite aproximar o comportamento do LRU sem registrar exatamente todos os acessos.

### Conjunto de trabalho - Working Set

O conjunto de trabalho representa as páginas utilizadas por um processo durante um intervalo recente de execução.

A ideia é manter na RAM as páginas que fazem parte da atividade atual do processo.

Uma página que não pertence ao conjunto de trabalho pode ser uma boa candidata à substituição.

### WSClock

O WSClock combina o algoritmo do relógio com o conceito de conjunto de trabalho.

Considera informações como:

- Bit de referência.
- Tempo desde a última utilização.
- Estado de modificação da página.

O objetivo é encontrar páginas antigas que possam ser removidas com baixo custo.

## Políticas de alocação local e global

A substituição de páginas também depende de quais quadros podem ser escolhidos.

- **Alocação local:** um processo substitui apenas páginas pertencentes ao seu próprio conjunto de quadros.
- **Alocação global:** o sistema pode selecionar quadros elegíveis de outros processos.

A alocação local oferece maior isolamento entre os processos, mas pode limitar a redistribuição dos recursos.

A alocação global permite adaptar a distribuição de memória conforme a demanda, mas um processo pode afetar o desempenho dos demais.

## Thrashing - Ultrapaginação

A ultrapaginação ocorre quando os processos possuem memória insuficiente para manter suas páginas utilizadas frequentemente.

Isso provoca um número elevado de faltas de página e transferências entre RAM e armazenamento secundário.

Consequentemente, o sistema gasta muito tempo movimentando páginas, em vez de executar instruções úteis.

Uma estratégia de controle é a **PFF (Page Fault Frequency)**, que acompanha a frequência de faltas para orientar a quantidade de quadros destinada a cada processo.

Se a demanda total continuar superior à memória disponível, pode ser necessário reduzir o número de processos competindo pela RAM.

## Tamanho das páginas

A escolha do tamanho das páginas influencia o desempenho e o aproveitamento da memória.

| Páginas pequenas | Páginas grandes |
| --- | --- |
| Menor fragmentação interna | Podem produzir maior fragmentação interna |
| Maior quantidade de páginas | Menor quantidade de páginas |
| Tabelas potencialmente maiores | Menor quantidade de entradas de mapeamento para a mesma região |
| Alocação com granularidade mais fina | Cada página cobre uma região maior |

Não existe um tamanho universalmente ideal.

## Compartilhamento de páginas e bibliotecas

O SO pode permitir que diferentes processos compartilhem determinadas páginas físicas.

Isso evita manter cópias desnecessárias do mesmo conteúdo na RAM.

Exemplo: dois processos utilizando o mesmo código de uma biblioteca podem compartilhar páginas de instruções, mantendo separados seus dados privados.

O compartilhamento reduz o consumo de memória, mas deve respeitar as permissões e os requisitos de isolamento.

Nem todas as páginas podem ser compartilhadas livremente.

## Política de limpeza e armazenamento secundário

O SO pode utilizar uma rotina de paginação executada em segundo plano para preparar quadros que poderão ser reutilizados.

Essa rotina pode identificar páginas candidatas à remoção e antecipar a gravação daquelas que foram modificadas.

O armazenamento secundário pode conter áreas de **swap**, utilizadas para preservar determinados conteúdos retirados da RAM.

Durante algumas operações de entrada e saída, certas páginas precisam permanecer fixadas na memória, impedindo que seus quadros sejam reutilizados enquanto a operação depende deles.

## Segmentação

A **segmentação** é uma técnica que divide o espaço de endereçamento de um processo em regiões lógicas de tamanhos variáveis.

Exemplo de segmentos:

- Código do programa.
- Dados.
- Pilha de execução.
- Tabelas e outras estruturas.

Cada segmento pode possuir base, tamanho e permissões próprios.

Na segmentação pura, um endereço é representado pelo identificador do segmento e um deslocamento.

**Diferença entre paginação e segmentação:**

| Paginação | Segmentação |
| --- | --- |
| Divide em blocos de tamanho fixo | Divide em regiões lógicas de tamanho variável |
| Utiliza páginas e quadros | Utiliza segmentos |
| Não exige continuidade física entre páginas | Na segmentação pura, cada segmento residente ocupa uma região física contínua |
| Pode causar fragmentação interna | Pode causar fragmentação externa |

A segmentação permite administrar separadamente diferentes regiões de um programa, inclusive seu crescimento e suas permissões.

Paginação e segmentação também podem ser utilizadas em conjunto.

## Resumo geral

O gerenciamento de memória permite que diferentes processos utilizem a RAM de maneira protegida e eficiente.

- **Espaço virtual:** fornece a cada processo sua própria visão de memória.
- **MMU:** traduz endereços virtuais para físicos.
- **Swapping:** transfere processos entre RAM e armazenamento secundário.
- **Memória virtual:** permite executar processos sem manter todas as suas páginas residentes.
- **Paginação:** divide o espaço virtual em páginas e a RAM em quadros.
- **Tabela de páginas:** registra os mapeamentos e permissões.
- **TLB:** acelera a tradução de endereços.
- **Falta de página:** exige tratamento quando um acesso não pode ser atendido.
- **Algoritmos de substituição:** selecionam páginas que poderão sair da RAM.
- **Thrashing:** ocorre quando o excesso de faltas compromete o desempenho.
- **Segmentação:** organiza a memória em regiões lógicas de tamanhos variáveis.

**A principal ideia é que o Sistema Operacional administra a memória física, enquanto cada processo utiliza seu próprio espaço virtual de endereçamento.**
