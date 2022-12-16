<img src="./Imagens/identidade_visual_novo_logo.png" align="right"
     alt="Logo EESC" height="200">

# BugsBots-Aprimoramento-do-Formiga

  Projeto de SAA0356 - Sistemas Embarcados para Veículos Aéreos 2022.2
  
  Ministrante: Prof. Dr. Glauco Augusto de Paula Caurin
  
  Departamento de Engenharia Aeronáutica
  

## Alunos:
* **Caique Augusto Cerqueira Dioceser**  *N° USP: 11232264*
* **Cristina Luciana Rodrigues Saraiva Leão** *N° USP: 10716696* 
* **João Vítor Viana Falcão** *N° USP: 11232413* 
* **Laura Queiroz Soares** *N° USP: 11372625* 
* **Natthan Wictor de Camargo** *N° USP: 11352702* 


# Introdução
Estima-se que existam cerca de 18.000 espécies de formigas no mundo, ao final deste será possível dizer que existe uma espécie nova de formiga, a robótica. Por meio de softwares e hardwares computacionais e mecatrônicos foi desenvolvido um robô de seis pernas capaz de se locomover de forma autônoma. A razão para o desenvolvimento de um robô hexápode é sua facilidade de locomoção em terrenos irregulares, se mantendo mais estável do que em comparação com dispositivos de aplicação parecida compostos por rodas.

## Objetivo
Desenvolver o acionamento e a coordenação de múltiplos servo atuadores de aeromodelismo para implementação de um padrão de caminhada para um robô de seis pernas.

## Materiais e Métodos
Utilizou-se um sistema de hardware, o qual consiste em uma placa Toradex Colibri VF61 embarcada na Viola Carrier Board, dois microcontroladores MBED LPC1768, um cartão micro SD e um cabo de adaptador serial RS232 para USB-A. Já o sistema operacional utilizado foi o Linux (Ubuntu no host e Angstrom na Colibri) e as linguagens de programação foram Python (VF61) e C (MBED). 
Além disso, foram usados dois servos motores em cada perna, totalizando doze em todo o robô.

<p align="center">
<img src="./Imagens/Módulo Colibri VF61.jpeg" width ="405" >
<img src="./Imagens/Placa Viola e MicroSD.jpeg" width="300">
</p>

<p align="center">
<img src="./Imagens/Placa Viola.jpeg" width ="355" >
<img src="./Imagens/Mbed.jpg" width="350">
</p>

Para a implementação, foram utilizadas saídas PWM para informar as posições dos servos e a comunicação dos microcontroladores (MBEDs) com a Toradex foi feita por meio da comunicação serial. A principal vantagem da comunicação serial é a diminuição dos gastos para que o sistema continue funcionando. Além disso, a transmissão de dados acontece de forma simplificada, onde é utilizado apenas um canal de comunicação.

# Desenvolvimento

## Instalação do Linux Angstrom na Colibri VF61

## Conexão SSH
O SSH pode ser usado para transferência de arquivos criptografados entre seu host e o módulo. Utilizamos o roteiro da Aula 3 (Build, Compile, Link) disponibilizado pelo professor como base para realizar a conexão com a placa Toradex.

Sabendo o endereço de IP do módulo utilizado (192.168.1.103), podemos realizar a conexão por meio das seguintes etapas:

<p align="left">
     ✔️ Enviar o código para Toradex:
</p>

```
> scp walk.py root@192.168.1.103/home/root
```

<p align="left">
     ✔️ Em outro terminal, executar o código dentro da Toradex:
</p>

```
> ssh root@192.168.1.103
> python walk.py
```

## Comunicação Serial Toradex - Mbed
Para a comunicação da Toradex com os microcontroladores MBEDs, optamos pela comunicação serial por ser mais simples e também devido à inexperiência dos integrantes do grupo com o protocolo CAN.  
A placa Viola é conectada às 2 MBEDs por meio de portas USB, de modo que ela  envia uma mensagem de caminhada às duas portas fazendo com que os dois controladores recebam e interpretem o sinal (traduzam a mensagem), executando o movimento desejado. 
Além disso, vale mencionar que a comunicação serial pela Colibri VF61 foi possível por meio da instalação da biblioteca pyserial, permitindo o envio de informações para as MBEDs por meio da execução de um código em python de conexão serial.


## Controle dos Motores e Padrão de Caminhada
Para este projeto foram utilizadas duas placas MBED LPC1768, sendo que para cada pata são necessários dois motores para lidar com o movimento horizontal e vertical de cada, totalizando 12 motores no projeto. Desta forma, cada MBED fica responsável pelo controle de 6 motores, ou seja, 3 pernas.
A lógica de caminhada consiste no movimento de 3 patas por vez, sendo elas alternadas (2 nas pontas de um lado e 1 no meio do outro lado), de forma que as outras 3 permaneçam no chão durante esse tempo para maior estabilidade da formiga. 
Uma vez que esse movimento é intercalado, cada MBED está conectado, por meio de portas PWM, a um conjunto de pernas (6 motores) que se movimentam ao mesmo tempo. O controle dos motores é feito através das portas PWM, por meio de códigos que foram escritos diretamente nos microcontroladores. 


# Resultados

Inicialmente, foram realizados testes com o robô movendo as pernas em cima de um suporte para evitar a possibilidade do robô quebrar ou ser danificado durante a execução do movimento por possiveis erros na elaboração do sistema embarcado.

https://user-images.githubusercontent.com/119769311/207974322-b9b8b9bb-30bd-4893-a7dd-93c34144b0fc.mp4

Posteriormente, quando os resultados no suporte se mostraram satisfatórios, colocamos ele no chão e o teste definitivo foi feito (sem a comunicação serial com a Toradex, apenas para verificação do funcionamento do padrão de caminhada).

https://user-images.githubusercontent.com/119769311/207929898-81dae449-8cf5-42a6-8e74-0f024d8560f7.mp4


# Conclusão
Apesar do projeto ter sido bem sucedido, vale ressaltar que a comunicação serial não fazia parte da ideia inicial, uma vez que, ao se trabalhar com MBEDs, é melhor usar o protocolo CAN para a comunicação, pois permite que outros dispositivos sejam conectados na mesma rede. Contudo, conforme apontado anteriormente, não foi possível a implementação desse tipo de comunicação, devido a falta de experiência da equipe com um protocolo tão robusto juntamente com o tempo limitado para tal. Portanto, optou-se pela comunicação serial, por sua simplicidade, permitindo a feitura do projeto proposto e dando a oportunidade de trabalhar com sistemas embarcados, logo, pode-se afirmar que o objetivo acadêmico da disciplina foi alcançado.
